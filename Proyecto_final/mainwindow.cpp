#include "mainwindow.h"
#include "enemigos.h"
#include "ui_mainwindow.h"
#include <QListIterator>
#include <QDebug>

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
    mapp->posmapa(0,-2500);
    scene->addItem(mapp);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(hmov()));
    timer->start(100);
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this,SLOT(crea_enemigos()));
    timer2->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crea_enemigos()
{
    evil = new enemigos(coches);
    coches++;
    if(coches>6){
        coches = 1;
    }
    evil->posi();
    scene->addItem(evil);
}

void MainWindow::hmov(){
    if(mapp->getYy() < 0){
        mapp->setYy(mapp->getYy()+5);
        mapp->posmapa();
    }
}
