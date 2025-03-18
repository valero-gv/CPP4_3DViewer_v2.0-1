//
// Created by valero on 9/2/24.
//
#include "backend.h"

void Vertex::s21_move_x(double move) {
  for (int i = 0; i < this->amount_vertex * 3 && !this->coord.empty(); i += 3) {
    this->coord[i] += move;
  }
}

void Vertex::s21_move_y(double move) {
  for (int i = 1; i < this->amount_vertex * 3 && !this->coord.empty(); i += 3) {
    this->coord[i] += move;
  }
}

void Vertex::s21_move_z(double move) {
  for (int i = 2; i < this->amount_vertex * 3 && !this->coord.empty(); i += 3) {
    this->coord[i] += move;
  }
}

void Vertex::s21_rotate_x(double angle, double angle_prev) {
  angle = s21_degrees_to_radians(angle);
  angle_prev = s21_degrees_to_radians(angle_prev);

  for (int i = 0; !this->coord.empty() && i < this->amount_vertex * 3; i += 3) {
    double y = this->coord[i + 1];
    double z = this->coord[i + 2];

    this->coord[i + 1] =
        y * cos(angle - angle_prev) + z * sin(angle - angle_prev);
    this->coord[i + 2] =
        -y * sin(angle - angle_prev) + z * cos(angle - angle_prev);
  }
}

void Vertex::s21_rotate_y(double angle, double angle_prev) {
  angle = s21_degrees_to_radians(angle);
  angle_prev = s21_degrees_to_radians(angle_prev);

  for (int i = 0; !this->coord.empty() && i < this->amount_vertex * 3; i += 3) {
    double x = this->coord[i];
    double z = this->coord[i + 2];

    this->coord[i] = x * cos(angle - angle_prev) + z * sin(angle - angle_prev);
    this->coord[i + 2] =
        -x * sin(angle - angle_prev) + z * cos(angle - angle_prev);
  }
}

void Vertex::s21_rotate_z(double angle, double angle_prev) {
  angle = s21_degrees_to_radians(angle);
  angle_prev = s21_degrees_to_radians(angle_prev);

  for (int i = 0; !this->coord.empty() && i < this->amount_vertex * 3; i += 3) {
    double x = this->coord[i];
    double y = this->coord[i + 1];

    this->coord[i] = x * cos(angle - angle_prev) - y * sin(angle - angle_prev);
    this->coord[i + 1] =
        x * sin(angle - angle_prev) + y * cos(angle - angle_prev);
  }
}

void Vertex::s21_scale(double scale, double scale_prev) {
  for (int i = 0; !this->coord.empty() && i < this->amount_vertex * 3; i++) {
    this->coord[i] *= scale / scale_prev;
  }
}

void Vertex::s21_alignment() {
  double centerX =
      this->minMax_x[0] + (this->minMax_x[1] - this->minMax_x[0]) / 2;
  double centerY =
      this->minMax_y[0] + (this->minMax_y[1] - this->minMax_y[0]) / 2;
  double centerZ =
      this->minMax_z[0] + (this->minMax_z[1] - this->minMax_z[0]) / 2;
  printf("%f %f %f\n", centerX, centerY, centerZ);

  for (int i = 0; i < this->amount_vertex; i += 3) {
    this->coord[i] -= centerX;
    this->coord[i + 1] -= centerY;
    this->coord[i + 2] -= centerZ;
  }
}

double Vertex::s21_degrees_to_radians(double angle) {
  return angle * M_PI / 180.0;
}
