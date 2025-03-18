#include "glwidget.h"

#include "../controller/controller.h"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent), controller(new Controller()) {
  initSettings();
}

GLWidget::~GLWidget() { delete controller; }

void GLWidget::initSettings() {
  projectionMode = 0;
  vertexSize = 5;
  vertexMode = 1;
  lineWidth = 1;
  lineMode = 0;
  backgroundColor.setRgb(0, 0, 0);
  lineColor.setRgb(255, 255, 255);
  vertexColor.setRgb(255, 255, 255);
}

void GLWidget::initializeGL() {
  glClearDepth(1.0);
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);  // Setting the anchor point
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
               backgroundColor.blueF(), backgroundColor.alphaF());

  if (controller->isInitialized()) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScaled(0.5, 0.5, 0.5);
    glTranslatef(0, 0, -1);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    ProjectionMode();
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, controller->getVertexCoords().data());
    pointHandler();
    lineHandler();
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}

void GLWidget::lineHandler() {
  glLineWidth(lineWidth);
  glColor3d(lineColor.redF(), lineColor.greenF(), lineColor.blueF());
  if (lineMode == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x00F0);
  }

  for (int i = 0; i < controller->getPolygonAmount(); i++) {
    // qDebug() << "Количество индексов: " <<
    // (controller->getPolygonFaceAmount(i) + 1) * 2 << " ";
    glDrawElements(GL_LINES, (controller->getPolygonFaceAmount(i) + 2),
                   GL_UNSIGNED_INT, controller->getPolygonData(i).data());
  }

  if (lineMode == 1) {
    glDisable(GL_LINE_STIPPLE);
  }
}

void GLWidget::pointHandler() {
  if (vertexMode != 0) {
    glColor3d(vertexColor.redF(), vertexColor.greenF(), vertexColor.blueF());
    glPointSize(vertexSize);
    if (vertexMode == 1) {
      glEnable(GL_POINT_SMOOTH);
    }
    glDrawArrays(GL_POINTS, 0, controller->getVertexAmount());
    if (vertexMode == 1) {
      glDisable(GL_POINT_SMOOTH);
    }
  }
}

void GLWidget::ProjectionMode() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projectionMode == 0) {
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 1000);
  } else {
    glFrustum(-1, 1, -1, 1, 1, 99999);
    glTranslatef(0, 0, -2.8);
  }
}

void GLWidget::setProjectionMode(int mode) {
  projectionMode = mode;
  update();
}

void GLWidget::readObjFile(QString fileName) {
  controller->clearData();
  controller->parseFile(fileName);
  label_vertex = controller->getVertexAmount();
  label_polygons = controller->getPolygonAmount();
  update();
}

void GLWidget::rotateObjX(double value, double currentRotateX) {
  if (controller->isInitialized()) {
    controller->rotateX(value, currentRotateX);
    update();
  }
}

void GLWidget::rotateObjY(double value, double currentRotateY) {
  if (controller->isInitialized()) {
    controller->rotateY(value, currentRotateY);
    update();
  }
}

void GLWidget::rotateObjZ(double value, double currentRotateZ) {
  if (controller->isInitialized()) {
    controller->rotateZ(value, currentRotateZ);
    update();
  }
}

void GLWidget::moveObjX(double move) {
  if (controller->isInitialized()) {
    controller->moveX(move);
    update();
  }
}

void GLWidget::moveObjY(double move) {
  if (controller->isInitialized()) {
    controller->moveY(move);
    update();
  }
}

void GLWidget::moveObjZ(double move) {
  if (controller->isInitialized()) {
    controller->moveZ(move);
    update();
  }
}

void GLWidget::setScale(int value, int currentScale) {
  if (controller->isInitialized()) {
    qDebug() << value << " " << currentScale;
    controller->scale(value, currentScale);
    update();
  }
}

void GLWidget::setBackgroundColor(QColor color) {
  backgroundColor = color;
  update();
}

void GLWidget::setLineColor(QColor color) {
  lineColor = color;
  update();
}

void GLWidget::setVertexColor(QColor color) {
  vertexColor = color;
  update();
}

void GLWidget::setVertexSize(double value) {
  vertexSize = value;
  update();
}

void GLWidget::setVertexMode(int mode) {
  vertexMode = mode;
  update();
}

void GLWidget::setLineMode(int mode) {
  lineMode = mode;
  update();
}

void GLWidget::setLineWidth(double value) {
  lineWidth = value;
  update();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
  mPos = event->localPos();
  mLastRotX = xRot;
  mLastRotY = yRot;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
  yRot = mLastRotY + event->localPos().x() - mPos.x();
  xRot = mLastRotX + event->localPos().y() - mPos.y();
  update();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event) {
  mLastRotX = xRot;
  mLastRotY = yRot;
  mPos = event->localPos();
}
