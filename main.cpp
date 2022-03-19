#include <QGuiApplication>
#include <QOpenGLShaderProgram>
#include <QScreen>
#include <QOpenGLWindow>
#include "glwindow.h"
#include "baseentity.h"
#include "circle.h"
#include "rectangle.h"
#include "entity_list.h"
#include <math.h>
#include <QMouseEvent>
#include <unistd.h>

class MainWindow : public OpenGLWindow
{
public:	
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;
	void mouseMoveEvent(QMouseEvent *e);
	
	EntityList entities;

private:
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;
};

void MainWindow::initialize()
{
	float aspect = float(width())/height();
	glOrtho(0, width(), 0, height(), -1, 1);
	
	srand(123);

	for( int i = 1; i < 12; i++ )
	{
		for( int j = 1; j < 7; j++ )
		{
			Circle *circ = new Circle(rand()%40+10);
			circ->setMass(10);
			circ->setGravity(0);
			circ->setOrigin(vector2D(100*i, 100*j));
			circ->setVelocity(vector2D((rand()%200-100)/40.f, (rand()%200-100)/40.f));
		
			entities.addEntity(circ);
		}
	}
	
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
	if(e->button() == Qt::LeftButton)
    {
        qDebug() << "Right mouse click!" << endl;
    }
}

void MainWindow::render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

	glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
	
	entities.processPhysics();

	for( int i = 0; i < entities.getCount(); i++)
	{
		entities[i]->step();
		entities[i]->render();
	}
}

int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(60);

    MainWindow window;
    window.setFormat(format);
    window.resize(1280, 720);
    window.show();
	
    return app.exec();
}
