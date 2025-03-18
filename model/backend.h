//
// Created by valero on 9/1/24.
//

#ifndef VIEWERS_BACKEND_H
#define VIEWERS_BACKEND_H


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "validation.h"
#include <limits>

using namespace std;

#define SIZE 256

class Vertex {
public:
    int amount_vertex;
    vector<double> coord;
    double minMax_x[2];  // minMax[0] = min, minMax[1] = max
    double minMax_y[2];
    double minMax_z[2];

    Vertex();
    ~Vertex() = default;

    void applyVertex(string& tmp, bool& flag);

    void applyMinMax();

    void s21_move_x(double move);
    void s21_move_y(double move);
    void s21_move_z(double move);

    void s21_rotate_x(double angle, double angle_prev);
    void s21_rotate_y(double angle, double angle_prev);
    void s21_rotate_z(double angle, double angle_prev);

    void s21_alignment();

    void s21_scale(double scale, double scale_prev);

    static double s21_degrees_to_radians(double angle);
private:
    double maxDouble = numeric_limits<double>::max();
    double minDouble = numeric_limits<double>::min();
};

class Polygons {
public:
    vector<int> poly;
    // индексы вершин для этого полигона
    int amount_face;  // кол-во граней в одной полигоне

    Polygons();
    ~Polygons();
};

class Data {
public:
vector<double> max_coord;
    Vertex v;
    vector<Polygons> p;
    int amount_poly;  // кол-во всех полигонов

    void applyPolygon(string& tmp);


    Data();
    ~Data();

    bool parseFile(const string& filename);
    bool parseString(const std::string& string_file);
    static void calculateArrayMinMax(Data& data, double *max_coord);
    bool isInitialized() const;
    void clearData();
};

#endif //VIEWERS_BACKEND_H
