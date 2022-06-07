#include <QGuiApplication>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_2_1>
#include <QScreen>
#include <QOpenGLWindow>
#include <math.h>
#include <QMouseEvent>
#include <unistd.h>

#include "ents/baseentity.h"
#include "ents/circle.h"
#include "ents/rectangle.h"
#include "entity_list.h"
#include "glwindow.h"
#include "factory.h"

#define MAX_POINTS 256

class MainWindow : public OpenGLWindow
{
public:
	using OpenGLWindow::OpenGLWindow;

	void initialize() override;
	void render() override;
	void mousePressEvent(QMouseEvent *e) override;
	void keyPressEvent(QKeyEvent *e) override;
	
	EntityList entities; // Create entity list
private:
	GLint m_posAttr = 0;
	GLint m_colAttr = 0;
	GLint m_matrixUniform = 0;

	QOpenGLShaderProgram *m_program = nullptr;
	ObjectFactory<BaseEntity> factory;
	int m_frame = 0;
	
	
	vector2D points[MAX_POINTS];
	int point_count = 0;
	QString selected_object;
};


// Window initialization
// add some rectangles and circles to the entity list

void MainWindow::initialize()
{
	factory.add<Circle>("circle");
	factory.add<RectAngle>("rectangle");
	selected_object = factory.keys()[0];

	QOpenGLFunctions_2_1 *qGL = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_2_1>();
	qGL->glOrtho(0, width(), 0, height(), -1, 1);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
	points[point_count].x = e->x();
	points[point_count].y = height()-e->y();
	point_count++;
	
	if( point_count == 2 )
	{
		BaseEntity *ent = factory.create(selected_object);
		ent->updateDrawInfo(points);
		entities.addEntity(ent);
		point_count = 0;
	}
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
	if( e->text() >= '1' && e->text() <= '9' )
	{
		int i = e->text().toInt();
		if( i <= factory.keys().length() )
		{
			QList<QString> list = factory.keys();
			selected_object = list[i-1];
			qDebug() << "selected - " << selected_object;
		}
	}
}

void MainWindow::render()
{
	QOpenGLFunctions_2_1 *qGL = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_2_1>();
	const qreal retinaScale = devicePixelRatio();

	qGL->glViewport(0, 0, width()*retinaScale, height()*retinaScale);
	qGL->glClearColor(0.f, 0.f, 0.f, 1.f);
	qGL->glClear(GL_COLOR_BUFFER_BIT);

	entities.render(); // Draw entities
}

int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);

	QSurfaceFormat format;
	format.setSamples(1);

	MainWindow window;
	window.setFormat(format);
	window.resize(1280, 720);
	window.show();

	return app.exec();
}

