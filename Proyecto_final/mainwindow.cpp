#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListIterator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(0,0,510,510);
    scene->addRect(0,0,500,500);
    mapp = new mapa();
    mapp->posmapa(0,-500);
    scene->addItem(mapp);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(hmov()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hmov(){
    if(mapp->getYy() < 0){
        mapp->setYy(mapp->getYy()+5);
        mapp->posmapa();
    }
}
