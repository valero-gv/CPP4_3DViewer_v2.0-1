#include "./ui_mainwindow.h"
#include "mainwindow.h"

void MainWindow::initSettings() {
  ui->spinBox_moveX->setValue(0);
  ui->spinBox_moveY->setValue(0);
  ui->spinBox_moveZ->setValue(0);

  ui->spinBox_rotX->setValue(0);
  ui->spinBox_rotY->setValue(0);
  ui->spinBox_rotZ->setValue(0);

  ui->horizontalSlider_scale->setValue(0);
}

void MainWindow::saveSettings() {
  QColor color;
  settings->beginGroup("Colors");
  color = ui->label_BackColor->palette().color(QPalette::Window);
  settings->setValue("BackR", color.red());
  settings->setValue("BackG", color.green());
  settings->setValue("BackB", color.blue());
  settings->setValue("BackA", color.alpha());
  color = ui->label_LineColor->palette().color(QPalette::Window);
  settings->setValue("LineR", color.red());
  settings->setValue("LineG", color.green());
  settings->setValue("LineB", color.blue());
  color = ui->label_VertexColor->palette().color(QPalette::Window);
  settings->setValue("VertexR", color.red());
  settings->setValue("VertexG", color.green());
  settings->setValue("VertexB", color.blue());
  settings->endGroup();

  settings->beginGroup("Lines");
  settings->setValue("LineMode", ui->radioButton_LineSolid->isChecked());
  settings->setValue("LineWidth", ui->doubleSpinBox_LineSize->value());
  settings->endGroup();

  settings->beginGroup("Vertexes");
  settings->setValue("None", ui->radioButton_VertexNone->isChecked());
  settings->setValue("Circle", ui->radioButton_VertexCircle->isChecked());
  settings->setValue("Square", ui->radioButton_VertexSquare->isChecked());
  settings->setValue("Size", ui->doubleSpinBox_VertexSize->value());
  settings->endGroup();

  settings->beginGroup("Projection");
  settings->setValue("ProjectionMode", ui->radioButton_Central->isChecked());
  settings->endGroup();
}

void MainWindow::downloadSettings() {
  QColor color;
  int red, green, blue, alpha;
  settings->beginGroup("Colors");
  red = settings->value("BackR", -1).toInt();
  green = settings->value("BackG", -1).toInt();
  blue = settings->value("BackB", -1).toInt();
  alpha = settings->value("BackA", -1).toInt();
  color = QColor(red, green, blue, alpha);
  //    emit emitWidgetColorChange(color);
  changeWindowColors(color, 0);
  red = settings->value("LineR", -1).toInt();
  green = settings->value("LineG", -1).toInt();
  blue = settings->value("LineB", -1).toInt();
  alpha = settings->value("LineA", -1).toInt();
  color = QColor(red, green, blue, alpha);
  changeWindowColors(color, 1);
  //    emit emitLineColorChange(color);
  red = settings->value("VertexR", -1).toInt();
  green = settings->value("VertexG", -1).toInt();
  blue = settings->value("VertexB", -1).toInt();
  alpha = settings->value("VertexA", -1).toInt();
  color = QColor(red, green, blue, alpha);
  //    emit emitVertexColorChange(color);
  changeWindowColors(color, 2);
  settings->endGroup();

  settings->beginGroup("Lines");
  if (settings->value("LineMode", 1).toBool()) {
    ui->radioButton_LineSolid->setChecked(true);
  } else {
    ui->radioButton_LineDashed->setChecked(true);
  }
  ui->doubleSpinBox_LineSize->setValue(
      settings->value("LineWidth", 1).toDouble());
  settings->endGroup();

  settings->beginGroup("Vertexes");
  if (settings->value("None", 1).toBool()) {
    ui->radioButton_VertexNone->setChecked(true);
  } else if (settings->value("Circle", 1).toBool()) {
    ui->radioButton_VertexCircle->setChecked(true);
  } else if (settings->value("Square", 1).toBool()) {
    ui->radioButton_VertexSquare->setChecked(true);
  }
  ui->doubleSpinBox_VertexSize->setValue(
      settings->value("Size", ui->doubleSpinBox_VertexSize->value())
          .toDouble());
  settings->endGroup();

  settings->beginGroup("Projection");
  if (settings->value("ProjectionMode", 1).toBool()) {
    ui->radioButton_Central->setChecked(true);
  } else {
    ui->radioButton_Parallel->setChecked(true);
  }
  settings->endGroup();
}
