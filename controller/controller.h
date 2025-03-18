#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/backend.h"
#include <QString>

class Controller {
 public:
  Controller();
  ~Controller();

  void clearData();
  void parseFile(const QString &fileName);

  void rotateX(double value, double currentRotateX);
  void rotateY(double value, double currentRotateY);
  void rotateZ(double value, double currentRotateZ);

  void scale(int value, int currentScale);

  void moveX(double move);
  void moveY(double move);
  void moveZ(double move);

  bool isInitialized() const;


  const std::vector<double>& getVertexCoords() const;
  int getVertexAmount() const;
  int getPolygonAmount() const;
  const std::vector<int>& getPolygonData(int index) const;
  int getPolygonFaceAmount(int index) const;

 private:
  Data *Data_;
};

#endif // CONTROLLER_H
