//
// Created by valero on 9/1/24.
//
#include "backend.h"

#include <cstring>
#include <fstream>

Vertex::Vertex() : amount_vertex(0) {
  minMax_x[0] = maxDouble;
  minMax_x[1] = minDouble;
  minMax_y[0] = maxDouble;
  minMax_y[1] = minDouble;
  minMax_z[0] = maxDouble;
  minMax_z[1] = minDouble;
}

Polygons::Polygons() : amount_face(0) {}

Polygons::~Polygons() { poly.clear(); }

Data::Data() : amount_poly(0) {}

Data::~Data() = default;

bool Data::parseFile(const string &file_name) {
  bool flag = false;
  ifstream file(file_name);
  if (!file) {
    cerr << "не удалось открыть файл" << endl;
    return false;
  }
  string line;
  while (getline(file, line)) {
    flag = parseString(line);
    if (flag)
      continue;
    else {
      flag = false;
      break;
    }
  }
  if (flag) {
    this->v.applyMinMax();
    this->v.amount_vertex /= 3;
  }
  file.close();
  return flag;
}

bool Data::parseString(const string &string_file) {
  bool flag = true;
  string tmp = string_file;
  if (string_file[0] == 'v' || string_file[0] == 'f') {
    char c = string_file[0];
    if (c == 'v') {
      if (string_file[1] == ' ') {
        if (!isValidString_v(string_file)) {
          flag = false;
        } else {
          this->v.applyVertex(tmp, flag);
        }
      }
    } else if (c == 'f') {
      int slash = isValidString_p(string_file);
      if (slash >= 0) {
        this->applyPolygon(tmp);
        if (flag == false) {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}

void Vertex::applyMinMax() {
  if (!this->coord.empty()) {
    double max_x = minDouble;
    double min_x = maxDouble;
    double max_y = minDouble;
    double min_y = maxDouble;
    double max_z = minDouble;
    double min_z = maxDouble;
    for (int i = 0; i < this->amount_vertex; i += 3) {
      if (this->coord[i] > max_x) {
        this->minMax_x[1] = this->coord[i];
        max_x = this->coord[i];
      }
      if (this->coord[i] < min_x) {
        this->minMax_x[0] = this->coord[i];
        min_x = this->coord[i];
      }
      if (this->coord[i + 1] > max_y) {
        this->minMax_y[1] = this->coord[i + 1];
        max_y = this->coord[i + 1];
      }
      if (this->coord[i + 1] < min_y) {
        this->minMax_y[0] = this->coord[i + 1];
        min_y = this->coord[i + 1];
      }
      if (this->coord[i + 2] > max_z) {
        this->minMax_z[1] = this->coord[i + 2];
        max_z = this->coord[i + 2];
      }
      if (this->coord[i + 2] < min_z) {
        this->minMax_z[0] = this->coord[i + 2];
        min_z = this->coord[i + 2];
      }
    }
  }
}

void Vertex::applyVertex(string &tmp, bool &flag) {
  string::iterator it = tmp.begin();
  it++;
  double x, y, z;
  std::istringstream iss(tmp.substr(1));
  if (iss >> x >> y >> z) {
    this->coord.push_back(x);
    this->coord.push_back(y);
    this->coord.push_back(z);
    flag = true;
  } else {
    flag = false;
    return;
  }
  this->amount_vertex += 3;

  flag = false;
}

void Data::applyPolygon(string &tmp) {
  Polygons m = Polygons();
  m.amount_face = -1;

  istringstream stream(tmp.substr(1));
  string token;

  while (stream >> token) {
    istringstream tokenStream(token);
    string vertexIndexStr;
    int vertexIndex = 0;

    getline(tokenStream, vertexIndexStr, '/');
    vertexIndex = stoi(vertexIndexStr) - 1;

    m.poly.push_back(vertexIndex);

    m.amount_face++;
  }
  m.poly.push_back(m.poly[0]);
  this->p.push_back(m);

  this->amount_poly++;
}

void Data::calculateArrayMinMax(Data &data, double *max_coord) {}

bool Data::isInitialized() const {
  if (amount_poly <= 0) {
    return false;
  }

  if (v.amount_vertex <= 0 || v.coord.empty()) {
    return false;
  }

  if (p.empty()) {
    return false;
  }

  return true;
}

void Data::clearData() {
  p.clear();
  amount_poly = 0;
  max_coord.clear();
  v.coord.clear();
  v.amount_vertex = 0;

  v.minMax_x[0] = 0;
  v.minMax_x[1] = 0;
  v.minMax_y[0] = 0;
  v.minMax_y[1] = 0;
  v.minMax_z[0] = 0;
  v.minMax_z[1] = 0;
}
