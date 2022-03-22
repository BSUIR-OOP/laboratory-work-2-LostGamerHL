#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QWindow>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = nullptr);
    ~OpenGLWindow();

	virtual void render();
    virtual void initialize();

public slots:
	void renderNow();

protected:
    bool event(QEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QOpenGLContext *m_context = nullptr;
    QOpenGLPaintDevice *m_device = nullptr;
};

#endif // GLWINDOW_H
