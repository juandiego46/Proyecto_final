#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListIterator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,1000);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(500,500,510,1010);
    //scene->addRect(scene->sceneRect());
    scene->addRect(0,0,500,1000);
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/mapa1.png"))));
}

MainWindow::~MainWindow()
{
    delete ui;
}

