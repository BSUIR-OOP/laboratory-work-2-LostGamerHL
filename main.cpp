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
	glOrtho(0, width(), 0, height(), -1, 1);

	
	Rectangle *rect = new Rectangle(1080, 15);
	rect->setOrigin(vector2D(100, 50));
	rect->setStatic(true);
	
	Rectangle *rect2 = new Rectangle(15, 400);
	rect2->setOrigin(vector2D(100, 80));
	rect2->setStatic(true);

	Rectangle *rect3 = new Rectangle(15, 400);
	rect3->setOrigin(vector2D(1165, 80));	
	rect3->setStatic(true);
	
	entities.addEntity(rect3);	
	entities.addEntity(rect2);
	entities.addEntity(rect);
	
	for( int i = 0; i < 100;i++ )
	{
		Circle *circle = new Circle(30);
		circle->setOrigin(vector2D((i % 2 == 0) ? 200 : 230,300+100*i));
		circle->setMass(0.02f);
		entities.addEntity(circle);		
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
	
	glViewport(0, 0, width()*retinaScale, height()*retinaScale);
	
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	entities.processPhysics();	
	entities.render();
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

