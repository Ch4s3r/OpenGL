#include <QtGui/QMouseEvent>
#include "GLWidget.h"

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
}

void GLWidget::initializeGL() {
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 0);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluOrtho2D(0, w, 0, h); // set origin to bottom left corner
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(test,1,1,0);

    //bot
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(-0.5,-0.5,0);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0);
    glEnd();
    //back
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    //right
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(0.5,-0.5,0);
    glVertex3f(0.5,0.5,0);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glEnd();
    //front
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(-0.5,-0.5,0);
    glVertex3f(-0.5,0.5,0);
    glVertex3f(0.5,0.5,0);
    glVertex3f(0.5,-0.5,0);
    glEnd();
    //left
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(-0.5,-0.5,0);
    glVertex3f(-0.5,0.5,0);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glEnd();
    //top
    glBegin(GL_POLYGON);
    glColor3f(1,0,1);
    glVertex3f(-0.5,0.5,0);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(0.5,0.5,0);
    glEnd();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    printf("%d, %d\n", event->x(), event->y());
    test = event->x()*0.01;
    paintGL();
}
void GLWidget::mouseMoveEvent(QMouseEvent *event) {

}

void GLWidget::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        event->ignore();
        break;
    }
}
