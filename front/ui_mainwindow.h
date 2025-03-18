/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_openFile;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_info_name;
    QLabel *label_name;
    QLabel *label_info_vertex;
    QLabel *label_vertex;
    QLabel *label_info_polygons;
    QLabel *label_polygons;
    QTabWidget *mainMenuWidget;
    QWidget *tab_1;
    QSpinBox *spinBox_moveX;
    QSpinBox *spinBox_moveZ;
    QSpinBox *spinBox_rotX;
    QScrollBar *horizontalScrollBar_rotY;
    QLabel *labelSave;
    QScrollBar *horizontalScrollBar_moveZ;
    QLabel *labelMove;
    QLabel *labelRotate;
    QLabel *labelScale;
    QSpinBox *spinBox_rotY;
    QSpinBox *spinBox_rotZ;
    QPushButton *pushButton_screenshot;
    QPushButton *pushButton_screencast;
    QScrollBar *horizontalScrollBar_rotX;
    QSpinBox *spinBox_moveY;
    QSlider *horizontalSlider_scale;
    QScrollBar *horizontalScrollBar_moveY;
    QScrollBar *horizontalScrollBar_moveX;
    QScrollBar *horizontalScrollBar_rotZ;
    QLabel *label_rotY;
    QLabel *label_rotX;
    QLabel *label_rotZ;
    QLabel *label_moveZ;
    QLabel *label_moveX;
    QLabel *label_moveY;
    QWidget *tab_2;
    QPushButton *pushButton_BackColor;
    QRadioButton *radioButton_LineDashed;
    QLabel *labelColors;
    QLabel *labelVertexStyke;
    QRadioButton *radioButton_Central;
    QLabel *label_LabelSize;
    QLabel *label_BackColor;
    QLabel *label_LineColor;
    QRadioButton *radioButton_LineSolid;
    QRadioButton *radioButton_VertexNone;
    QLabel *label_VertexSize;
    QPushButton *pushButton_VertexColor;
    QLabel *labelScaleProjectionType;
    QRadioButton *radioButton_VertexCircle;
    QSlider *horizontalSlider_LineSize;
    QRadioButton *radioButton_VertexSquare;
    QDoubleSpinBox *doubleSpinBox_VertexSize;
    QRadioButton *radioButton_Parallel;
    QSlider *horizontalSlider_VertexSize;
    QLabel *labelLineStyle;
    QLabel *label_VertexColor;
    QPushButton *pushButton_LineColor;
    QDoubleSpinBox *doubleSpinBox_LineSize;
    GLWidget *glWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1026, 787);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_openFile = new QPushButton(centralwidget);
        pushButton_openFile->setObjectName(QString::fromUtf8("pushButton_openFile"));
        pushButton_openFile->setGeometry(QRect(800, 670, 201, 61));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(807, 592, 181, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_info_name = new QLabel(frame);
        label_info_name->setObjectName(QString::fromUtf8("label_info_name"));

        gridLayout->addWidget(label_info_name, 0, 0, 1, 1);

        label_name = new QLabel(frame);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        gridLayout->addWidget(label_name, 0, 1, 1, 1);

        label_info_vertex = new QLabel(frame);
        label_info_vertex->setObjectName(QString::fromUtf8("label_info_vertex"));

        gridLayout->addWidget(label_info_vertex, 1, 0, 1, 1);

        label_vertex = new QLabel(frame);
        label_vertex->setObjectName(QString::fromUtf8("label_vertex"));

        gridLayout->addWidget(label_vertex, 1, 1, 1, 1);

        label_info_polygons = new QLabel(frame);
        label_info_polygons->setObjectName(QString::fromUtf8("label_info_polygons"));

        gridLayout->addWidget(label_info_polygons, 2, 0, 1, 1);

        label_polygons = new QLabel(frame);
        label_polygons->setObjectName(QString::fromUtf8("label_polygons"));

        gridLayout->addWidget(label_polygons, 2, 1, 1, 1);

        mainMenuWidget = new QTabWidget(centralwidget);
        mainMenuWidget->setObjectName(QString::fromUtf8("mainMenuWidget"));
        mainMenuWidget->setGeometry(QRect(780, 0, 241, 581));
        mainMenuWidget->setTabShape(QTabWidget::Rounded);
        mainMenuWidget->setIconSize(QSize(12, 12));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        tab_1->setFocusPolicy(Qt::TabFocus);
        spinBox_moveX = new QSpinBox(tab_1);
        spinBox_moveX->setObjectName(QString::fromUtf8("spinBox_moveX"));
        spinBox_moveX->setGeometry(QRect(180, 33, 51, 20));
        spinBox_moveX->setMinimum(-500);
        spinBox_moveX->setMaximum(500);
        spinBox_moveZ = new QSpinBox(tab_1);
        spinBox_moveZ->setObjectName(QString::fromUtf8("spinBox_moveZ"));
        spinBox_moveZ->setGeometry(QRect(180, 93, 51, 21));
        spinBox_moveZ->setMinimum(-500);
        spinBox_moveZ->setMaximum(500);
        spinBox_rotX = new QSpinBox(tab_1);
        spinBox_rotX->setObjectName(QString::fromUtf8("spinBox_rotX"));
        spinBox_rotX->setGeometry(QRect(180, 188, 51, 20));
        spinBox_rotX->setMinimum(-180);
        spinBox_rotX->setMaximum(180);
        horizontalScrollBar_rotY = new QScrollBar(tab_1);
        horizontalScrollBar_rotY->setObjectName(QString::fromUtf8("horizontalScrollBar_rotY"));
        horizontalScrollBar_rotY->setGeometry(QRect(20, 220, 150, 16));
        horizontalScrollBar_rotY->setMinimum(-180);
        horizontalScrollBar_rotY->setMaximum(180);
        horizontalScrollBar_rotY->setOrientation(Qt::Horizontal);
        labelSave = new QLabel(tab_1);
        labelSave->setObjectName(QString::fromUtf8("labelSave"));
        labelSave->setGeometry(QRect(11, 444, 71, 21));
        QFont font;
        font.setPointSize(18);
        labelSave->setFont(font);
        labelSave->setMargin(0);
        horizontalScrollBar_moveZ = new QScrollBar(tab_1);
        horizontalScrollBar_moveZ->setObjectName(QString::fromUtf8("horizontalScrollBar_moveZ"));
        horizontalScrollBar_moveZ->setGeometry(QRect(20, 95, 150, 16));
        horizontalScrollBar_moveZ->setMinimum(-500);
        horizontalScrollBar_moveZ->setMaximum(500);
        horizontalScrollBar_moveZ->setOrientation(Qt::Horizontal);
        labelMove = new QLabel(tab_1);
        labelMove->setObjectName(QString::fromUtf8("labelMove"));
        labelMove->setGeometry(QRect(12, 5, 211, 21));
        labelMove->setFont(font);
        labelMove->setMargin(0);
        labelRotate = new QLabel(tab_1);
        labelRotate->setObjectName(QString::fromUtf8("labelRotate"));
        labelRotate->setGeometry(QRect(20, 160, 211, 21));
        labelRotate->setFont(font);
        labelRotate->setMargin(0);
        labelScale = new QLabel(tab_1);
        labelScale->setObjectName(QString::fromUtf8("labelScale"));
        labelScale->setGeometry(QRect(13, 321, 41, 21));
        labelScale->setFont(font);
        labelScale->setMargin(0);
        spinBox_rotY = new QSpinBox(tab_1);
        spinBox_rotY->setObjectName(QString::fromUtf8("spinBox_rotY"));
        spinBox_rotY->setGeometry(QRect(180, 218, 51, 21));
        spinBox_rotY->setMinimum(-180);
        spinBox_rotY->setMaximum(180);
        spinBox_rotZ = new QSpinBox(tab_1);
        spinBox_rotZ->setObjectName(QString::fromUtf8("spinBox_rotZ"));
        spinBox_rotZ->setGeometry(QRect(180, 248, 51, 21));
        spinBox_rotZ->setMinimum(-180);
        spinBox_rotZ->setMaximum(180);
        pushButton_screenshot = new QPushButton(tab_1);
        pushButton_screenshot->setObjectName(QString::fromUtf8("pushButton_screenshot"));
        pushButton_screenshot->setGeometry(QRect(7, 466, 221, 41));
        pushButton_screencast = new QPushButton(tab_1);
        pushButton_screencast->setObjectName(QString::fromUtf8("pushButton_screencast"));
        pushButton_screencast->setGeometry(QRect(7, 510, 221, 41));
        horizontalScrollBar_rotX = new QScrollBar(tab_1);
        horizontalScrollBar_rotX->setObjectName(QString::fromUtf8("horizontalScrollBar_rotX"));
        horizontalScrollBar_rotX->setGeometry(QRect(20, 190, 150, 16));
        horizontalScrollBar_rotX->setMinimum(-180);
        horizontalScrollBar_rotX->setMaximum(180);
        horizontalScrollBar_rotX->setOrientation(Qt::Horizontal);
        spinBox_moveY = new QSpinBox(tab_1);
        spinBox_moveY->setObjectName(QString::fromUtf8("spinBox_moveY"));
        spinBox_moveY->setGeometry(QRect(180, 63, 51, 21));
        spinBox_moveY->setMinimum(-500);
        spinBox_moveY->setMaximum(500);
        horizontalSlider_scale = new QSlider(tab_1);
        horizontalSlider_scale->setObjectName(QString::fromUtf8("horizontalSlider_scale"));
        horizontalSlider_scale->setGeometry(QRect(10, 370, 211, 25));
        horizontalSlider_scale->setMinimum(1);
        horizontalSlider_scale->setMaximum(50);
        horizontalSlider_scale->setSingleStep(2);
        horizontalSlider_scale->setValue(1);
        horizontalSlider_scale->setSliderPosition(1);
        horizontalSlider_scale->setOrientation(Qt::Horizontal);
        horizontalScrollBar_moveY = new QScrollBar(tab_1);
        horizontalScrollBar_moveY->setObjectName(QString::fromUtf8("horizontalScrollBar_moveY"));
        horizontalScrollBar_moveY->setGeometry(QRect(20, 65, 150, 16));
        horizontalScrollBar_moveY->setMinimum(-500);
        horizontalScrollBar_moveY->setMaximum(500);
        horizontalScrollBar_moveY->setOrientation(Qt::Horizontal);
        horizontalScrollBar_moveX = new QScrollBar(tab_1);
        horizontalScrollBar_moveX->setObjectName(QString::fromUtf8("horizontalScrollBar_moveX"));
        horizontalScrollBar_moveX->setGeometry(QRect(20, 35, 150, 16));
        horizontalScrollBar_moveX->setMinimum(-500);
        horizontalScrollBar_moveX->setMaximum(500);
        horizontalScrollBar_moveX->setOrientation(Qt::Horizontal);
        horizontalScrollBar_rotZ = new QScrollBar(tab_1);
        horizontalScrollBar_rotZ->setObjectName(QString::fromUtf8("horizontalScrollBar_rotZ"));
        horizontalScrollBar_rotZ->setGeometry(QRect(20, 250, 150, 16));
        horizontalScrollBar_rotZ->setMinimum(-180);
        horizontalScrollBar_rotZ->setMaximum(180);
        horizontalScrollBar_rotZ->setOrientation(Qt::Horizontal);
        label_rotY = new QLabel(tab_1);
        label_rotY->setObjectName(QString::fromUtf8("label_rotY"));
        label_rotY->setGeometry(QRect(7, 221, 16, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_rotY->setFont(font1);
        label_rotX = new QLabel(tab_1);
        label_rotX->setObjectName(QString::fromUtf8("label_rotX"));
        label_rotX->setGeometry(QRect(7, 190, 16, 16));
        label_rotX->setFont(font1);
        label_rotZ = new QLabel(tab_1);
        label_rotZ->setObjectName(QString::fromUtf8("label_rotZ"));
        label_rotZ->setGeometry(QRect(7, 250, 16, 16));
        label_rotZ->setFont(font1);
        label_moveZ = new QLabel(tab_1);
        label_moveZ->setObjectName(QString::fromUtf8("label_moveZ"));
        label_moveZ->setGeometry(QRect(6, 95, 16, 16));
        label_moveZ->setFont(font1);
        label_moveX = new QLabel(tab_1);
        label_moveX->setObjectName(QString::fromUtf8("label_moveX"));
        label_moveX->setGeometry(QRect(6, 35, 16, 16));
        label_moveX->setFont(font1);
        label_moveY = new QLabel(tab_1);
        label_moveY->setObjectName(QString::fromUtf8("label_moveY"));
        label_moveY->setGeometry(QRect(6, 66, 16, 16));
        label_moveY->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8("assets/eye.icns"), QSize(), QIcon::Normal, QIcon::Off);
        mainMenuWidget->addTab(tab_1, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_BackColor = new QPushButton(tab_2);
        pushButton_BackColor->setObjectName(QString::fromUtf8("pushButton_BackColor"));
        pushButton_BackColor->setGeometry(QRect(10, 40, 151, 32));
        radioButton_LineDashed = new QRadioButton(tab_2);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_LineDashed);
        radioButton_LineDashed->setObjectName(QString::fromUtf8("radioButton_LineDashed"));
        radioButton_LineDashed->setGeometry(QRect(98, 185, 71, 20));
        labelColors = new QLabel(tab_2);
        labelColors->setObjectName(QString::fromUtf8("labelColors"));
        labelColors->setGeometry(QRect(11, 15, 151, 21));
        labelColors->setFont(font);
        labelColors->setMargin(0);
        labelVertexStyke = new QLabel(tab_2);
        labelVertexStyke->setObjectName(QString::fromUtf8("labelVertexStyke"));
        labelVertexStyke->setGeometry(QRect(11, 296, 141, 21));
        labelVertexStyke->setFont(font);
        labelVertexStyke->setMargin(0);
        radioButton_Central = new QRadioButton(tab_2);
        buttonGroup_3 = new QButtonGroup(MainWindow);
        buttonGroup_3->setObjectName(QString::fromUtf8("buttonGroup_3"));
        buttonGroup_3->addButton(radioButton_Central);
        radioButton_Central->setObjectName(QString::fromUtf8("radioButton_Central"));
        radioButton_Central->setGeometry(QRect(9, 515, 99, 20));
        label_LabelSize = new QLabel(tab_2);
        label_LabelSize->setObjectName(QString::fromUtf8("label_LabelSize"));
        label_LabelSize->setGeometry(QRect(12, 213, 71, 16));
        label_BackColor = new QLabel(tab_2);
        label_BackColor->setObjectName(QString::fromUtf8("label_BackColor"));
        label_BackColor->setGeometry(QRect(179, 44, 41, 21));
        label_BackColor->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"background-color: white;"));
        label_LineColor = new QLabel(tab_2);
        label_LineColor->setObjectName(QString::fromUtf8("label_LineColor"));
        label_LineColor->setGeometry(QRect(179, 74, 41, 21));
        label_LineColor->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"background-color: white;"));
        radioButton_LineSolid = new QRadioButton(tab_2);
        buttonGroup->addButton(radioButton_LineSolid);
        radioButton_LineSolid->setObjectName(QString::fromUtf8("radioButton_LineSolid"));
        radioButton_LineSolid->setGeometry(QRect(10, 185, 61, 20));
        radioButton_LineSolid->setChecked(true);
        radioButton_VertexNone = new QRadioButton(tab_2);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_VertexNone);
        radioButton_VertexNone->setObjectName(QString::fromUtf8("radioButton_VertexNone"));
        radioButton_VertexNone->setGeometry(QRect(9, 325, 61, 20));
        label_VertexSize = new QLabel(tab_2);
        label_VertexSize->setObjectName(QString::fromUtf8("label_VertexSize"));
        label_VertexSize->setGeometry(QRect(14, 403, 71, 16));
        pushButton_VertexColor = new QPushButton(tab_2);
        pushButton_VertexColor->setObjectName(QString::fromUtf8("pushButton_VertexColor"));
        pushButton_VertexColor->setGeometry(QRect(10, 100, 151, 32));
        labelScaleProjectionType = new QLabel(tab_2);
        labelScaleProjectionType->setObjectName(QString::fromUtf8("labelScaleProjectionType"));
        labelScaleProjectionType->setGeometry(QRect(12, 460, 121, 21));
        labelScaleProjectionType->setFont(font);
        labelScaleProjectionType->setMargin(0);
        radioButton_VertexCircle = new QRadioButton(tab_2);
        buttonGroup_2->addButton(radioButton_VertexCircle);
        radioButton_VertexCircle->setObjectName(QString::fromUtf8("radioButton_VertexCircle"));
        radioButton_VertexCircle->setGeometry(QRect(9, 350, 71, 20));
        radioButton_VertexCircle->setChecked(true);
        horizontalSlider_LineSize = new QSlider(tab_2);
        horizontalSlider_LineSize->setObjectName(QString::fromUtf8("horizontalSlider_LineSize"));
        horizontalSlider_LineSize->setGeometry(QRect(9, 240, 151, 25));
        horizontalSlider_LineSize->setOrientation(Qt::Horizontal);
        radioButton_VertexSquare = new QRadioButton(tab_2);
        buttonGroup_2->addButton(radioButton_VertexSquare);
        radioButton_VertexSquare->setObjectName(QString::fromUtf8("radioButton_VertexSquare"));
        radioButton_VertexSquare->setGeometry(QRect(9, 375, 71, 20));
        doubleSpinBox_VertexSize = new QDoubleSpinBox(tab_2);
        doubleSpinBox_VertexSize->setObjectName(QString::fromUtf8("doubleSpinBox_VertexSize"));
        doubleSpinBox_VertexSize->setGeometry(QRect(100, 400, 62, 22));
        radioButton_Parallel = new QRadioButton(tab_2);
        buttonGroup_3->addButton(radioButton_Parallel);
        radioButton_Parallel->setObjectName(QString::fromUtf8("radioButton_Parallel"));
        radioButton_Parallel->setGeometry(QRect(9, 490, 99, 20));
        radioButton_Parallel->setChecked(true);
        horizontalSlider_VertexSize = new QSlider(tab_2);
        horizontalSlider_VertexSize->setObjectName(QString::fromUtf8("horizontalSlider_VertexSize"));
        horizontalSlider_VertexSize->setGeometry(QRect(9, 430, 151, 25));
        horizontalSlider_VertexSize->setOrientation(Qt::Horizontal);
        labelLineStyle = new QLabel(tab_2);
        labelLineStyle->setObjectName(QString::fromUtf8("labelLineStyle"));
        labelLineStyle->setGeometry(QRect(13, 155, 131, 21));
        labelLineStyle->setFont(font);
        labelLineStyle->setMargin(0);
        label_VertexColor = new QLabel(tab_2);
        label_VertexColor->setObjectName(QString::fromUtf8("label_VertexColor"));
        label_VertexColor->setGeometry(QRect(179, 105, 41, 20));
        label_VertexColor->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"background-color: white;"));
        pushButton_LineColor = new QPushButton(tab_2);
        pushButton_LineColor->setObjectName(QString::fromUtf8("pushButton_LineColor"));
        pushButton_LineColor->setGeometry(QRect(10, 70, 151, 32));
        doubleSpinBox_LineSize = new QDoubleSpinBox(tab_2);
        doubleSpinBox_LineSize->setObjectName(QString::fromUtf8("doubleSpinBox_LineSize"));
        doubleSpinBox_LineSize->setGeometry(QRect(100, 210, 62, 22));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("assets/paintbrush.icns"), QSize(), QIcon::Normal, QIcon::Off);
        mainMenuWidget->addTab(tab_2, icon1, QString());
        glWidget = new GLWidget(centralwidget);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));
        glWidget->setGeometry(QRect(0, -30, 768, 768));
        glWidget->setStyleSheet(QString::fromUtf8("background: black;"));
        MainWindow->setCentralWidget(centralwidget);
        pushButton_openFile->raise();
        frame->raise();
        glWidget->raise();
        mainMenuWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1026, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalScrollBar_rotY, SIGNAL(valueChanged(int)), spinBox_rotY, SLOT(setValue(int)));
        QObject::connect(spinBox_rotX, SIGNAL(valueChanged(int)), horizontalScrollBar_rotX, SLOT(setValue(int)));
        QObject::connect(spinBox_moveX, SIGNAL(valueChanged(int)), horizontalScrollBar_moveX, SLOT(setValue(int)));
        QObject::connect(spinBox_rotY, SIGNAL(valueChanged(int)), horizontalScrollBar_rotY, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_rotX, SIGNAL(valueChanged(int)), spinBox_rotX, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_moveZ, SIGNAL(valueChanged(int)), spinBox_moveZ, SLOT(setValue(int)));
        QObject::connect(spinBox_moveZ, SIGNAL(valueChanged(int)), horizontalScrollBar_moveZ, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_moveY, SIGNAL(valueChanged(int)), spinBox_moveY, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_rotZ, SIGNAL(valueChanged(int)), spinBox_rotZ, SLOT(setValue(int)));
        QObject::connect(spinBox_rotZ, SIGNAL(valueChanged(int)), horizontalScrollBar_rotZ, SLOT(setValue(int)));
        QObject::connect(spinBox_moveY, SIGNAL(valueChanged(int)), horizontalScrollBar_moveY, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_moveX, SIGNAL(valueChanged(int)), spinBox_moveX, SLOT(setValue(int)));

        mainMenuWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_openFile->setText(QCoreApplication::translate("MainWindow", "OPEN FILE", nullptr));
        label_info_name->setText(QCoreApplication::translate("MainWindow", "File name:", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "sample.obj", nullptr));
        label_info_vertex->setText(QCoreApplication::translate("MainWindow", "Vertexes:", nullptr));
        label_vertex->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_info_polygons->setText(QCoreApplication::translate("MainWindow", "Polygons:", nullptr));
        label_polygons->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(tooltip)
        mainMenuWidget->setToolTip(QCoreApplication::translate("MainWindow", "Appearance\n"
"", nullptr));
#endif // QT_CONFIG(tooltip)
        labelSave->setText(QCoreApplication::translate("MainWindow", "Save as:", nullptr));
        labelMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        labelRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        labelScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        pushButton_screenshot->setText(QCoreApplication::translate("MainWindow", "Take screenshot", nullptr));
        pushButton_screencast->setText(QCoreApplication::translate("MainWindow", "Record screencast", nullptr));
        label_rotY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_rotX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_rotZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_moveZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_moveX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_moveY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        mainMenuWidget->setTabText(mainMenuWidget->indexOf(tab_1), QCoreApplication::translate("MainWindow", "Overview", nullptr));
#if QT_CONFIG(tooltip)
        tab_2->setToolTip(QCoreApplication::translate("MainWindow", "Appearance", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_BackColor->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        radioButton_LineDashed->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        labelColors->setText(QCoreApplication::translate("MainWindow", "Colors", nullptr));
        labelVertexStyke->setText(QCoreApplication::translate("MainWindow", "Vertex Style", nullptr));
        radioButton_Central->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        label_LabelSize->setText(QCoreApplication::translate("MainWindow", "Line width:", nullptr));
        label_BackColor->setText(QString());
        label_LineColor->setText(QString());
        radioButton_LineSolid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        radioButton_VertexNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        label_VertexSize->setText(QCoreApplication::translate("MainWindow", "Vertex size:", nullptr));
        pushButton_VertexColor->setText(QCoreApplication::translate("MainWindow", "Vertex color", nullptr));
        labelScaleProjectionType->setText(QCoreApplication::translate("MainWindow", "Projection type", nullptr));
        radioButton_VertexCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        radioButton_VertexSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        radioButton_Parallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        labelLineStyle->setText(QCoreApplication::translate("MainWindow", "Line Style", nullptr));
        label_VertexColor->setText(QString());
        pushButton_LineColor->setText(QCoreApplication::translate("MainWindow", "Line color", nullptr));
        mainMenuWidget->setTabText(mainMenuWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Appearance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
