#include "controller.h"

Controller::Controller() { Data_ = new Data(); }

Controller::~Controller() {
  clearData();
  delete Data_;
}

void Controller::clearData() {
  if (Data_) {
    Data_->clearData();
  }
}

void Controller::parseFile(const QString& fileName) {
  if (Data_) {
    Data_->parseFile(fileName.toStdString());
  }
}

void Controller::rotateX(double value, double currentRotateX) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_rotate_x(value, currentRotateX);
  }
}

void Controller::rotateY(double value, double currentRotateY) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_rotate_y(value, currentRotateY);
  }
}

void Controller::rotateZ(double value, double currentRotateZ) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_rotate_z(value, currentRotateZ);
  }
}

void Controller::scale(int value, int currentScale) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_scale(value, currentScale);
  }
}

void Controller::moveX(double move) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_move_x(move);
  }
}

void Controller::moveY(double move) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_move_y(move);
  }
}

void Controller::moveZ(double move) {
  if (Data_ && Data_->isInitialized()) {
    Data_->v.s21_move_z(move);
  }
}

bool Controller::isInitialized() const {
  return Data_ && Data_->isInitialized();
}

const std::vector<double>& Controller::getVertexCoords() const {
  return Data_->v.coord;
}

int Controller::getVertexAmount() const { return Data_->v.amount_vertex; }

int Controller::getPolygonAmount() const { return Data_->amount_poly; }

const std::vector<int>& Controller::getPolygonData(int index) const {
  return Data_->p[index].poly;
}

int Controller::getPolygonFaceAmount(int index) const {
  return Data_->p[index].amount_face;
}
