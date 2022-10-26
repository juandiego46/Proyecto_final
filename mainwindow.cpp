#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListIterator>
#include <QDebug>
#include <QKeyEvent>

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
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/Inicio/inicio.png").scaled(500,500))));
    jugador1 = nullptr;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_F4) {
        close();
    }
    else if(event->key()==Qt::Key_D){
        if(jugador1->getX() < (scene->height())-100){
            jugador1->setX(jugador1->getX() + jugador1->getVx());
            jugador1->setPos(jugador1->getX(), jugador1->getY());

        }
    }
    else if(event->key()==Qt::Key_A){
        if(jugador1->getX() > 80){
            jugador1->setX(jugador1->getX() - jugador1->getVx());
            jugador1->setPos(jugador1->getX(), jugador1->getY());

        }
    }
    else if(event->key()==Qt::Key_W){
        if(jugador1->getY() > 0){
            jugador1->setY(jugador1->getY() - jugador1->getVy());
            jugador1->setPos(jugador1->getX(), jugador1->getY());

        }
    }
    else if(event->key()==Qt::Key_S){
        if(jugador1->getY() < 450){
            jugador1->setY(jugador1->getY() + jugador1->getVy());
            jugador1->setPos(jugador1->getX(), jugador1->getY());

        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/mapa.png"))));

    mapp = new mapa();
    mapp->posmapa(0,-2500);
    scene->addItem(mapp);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(hmov()));
    timer->start(100);
    connect(timer, SIGNAL(timeout()),this,SLOT(colisiones()));

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this,SLOT(crea_enemigos()));
    timer2->start(2000);

    jugador1 = new jugador();
    jugador1->posicion(230,450);
    scene->addItem(jugador1);

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()),this,SLOT(aceiteRandom()));
    timer3->start(6000);

    timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()),this,SLOT(turboRandom()));
    timer4->start(7000);
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

void MainWindow::aceiteRandom()
{
    mancha = new aceite();
    mancha->movimiento();
    mancha->posAleatorio();
    scene->addItem(mancha);
}

void MainWindow::colisiones()
{

    QList <QGraphicsItem*> ElementosChoca = scene->collidingItems(jugador1);
    if(!ElementosChoca.isEmpty()){
        for(auto c : ElementosChoca){
            enemigos *Enemigos = dynamic_cast<enemigos*>(c);
            if(Enemigos){
                qDebug() << "Enemigos";
            }
            aceite *Aceite = dynamic_cast<aceite*>(c);
            if(Aceite){
                qDebug() << "Aceite";
            }
            turbo *Nitro = dynamic_cast<turbo*>(c);
            if(Nitro){
                qDebug() << "Nitro";
            }
        }
    }
}

void MainWindow::turboRandom()
{
    nitro = new turbo();
    nitro->movimiento();
    nitro->posAleatorio();
    scene->addItem(nitro);
}


void MainWindow::hmov(){
    if(mapp->getYy() < 0){
        mapp->setYy(mapp->getYy() + mapp->getVy());
        mapp->posmapa();
    }
}
