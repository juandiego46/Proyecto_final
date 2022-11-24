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
        if(mov==0){
            if(jugador1->getX() < (scene->height())-100){
                jugador1->setX(jugador1->getX() + jugador1->getVx());
                jugador1->setPos(jugador1->getX(), jugador1->getY());

            }
            else{
                event->ignore();
            }
       }
    }
    else if(event->key()==Qt::Key_A){
        if(mov==0){
            if(jugador1->getX() > 80){
                jugador1->setX(jugador1->getX() - jugador1->getVx());
                jugador1->setPos(jugador1->getX(), jugador1->getY());
            }
            else{
                event->ignore();
            }
        }
    }
    else if(event->key()==Qt::Key_W){
        if(mov==0){
            if(jugador1->getY() >= 0){
                jugador1->setY(jugador1->getY() - jugador1->getVy());
                jugador1->setPos(jugador1->getX(), jugador1->getY());
            }
            else{
                event->ignore();
            }
        }
    }
    else if(event->key()==Qt::Key_S){
        if(mov==0){
            if(jugador1->getY() < 450){
                jugador1->setVy(3);
                jugador1->setY(jugador1->getY() + jugador1->getVy());
                jugador1->setPos(jugador1->getX(), jugador1->getY());
            }
            else{
                 event->ignore();
            }
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    mapp = new mapa(nivel);
    mapp->posmapa(0,-2500);
    scene->addItem(mapp);

    jugador1 = new jugador(nivel);
    jugador1->posicion(230,450);
    scene->addItem(jugador1);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(colisiones()));
    timer->start(50);

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()),this,SLOT(crea_enemigos()));
    timer2->start(1500);

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()),this,SLOT(aceiteRandom()));
    timer3->start(6000);

    timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()),this,SLOT(turboRandom()));
    timer4->start(7000);

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),this,SLOT(level()));
    timer1->start(2000);


}

void MainWindow::level()
{

    if(jugador1->getY()<0 && mapp->getYy()>=0){
        sig_level();
        scene->removeItem(mapp);
        scene->removeItem(jugador1);
        destruir_tiempo();
        ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/Inicio/inicio.png").scaled(500,500))));      
        ui->pushButton->setText("Segundo nivel.");
        mov = 0;
        v1 = 0;
        v2 = 0;
        nivel++;
    }
    else if(mov>0 && vida >0){
        scene->removeItem(mapp);
        scene->removeItem(jugador1);
        vida--;
        mov = 0;
        v1 = 0;
        v2 = 0;
        delete jugador1;
        sig_level();
        destruir_tiempo();
        ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/Inicio/inicio.png").scaled(500,500))));
        ui->pushButton->setText("Intentar de nuevo.");
    }
    else if(mov>0 && vida == 0){
        destruir_tiempo();
        scene->removeItem(mapp);
        scene->removeItem(jugador1);     
        sig_level();
        vida = 3;
        mov = 0;
        v1 = 0;
        v2 = 0;
        nivel = 0;
        ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/Inicio/gameover.png").scaled(500,500))));
        ui->pushButton->setText("Volver a empezar");
    }
}

void MainWindow::normal()
{
    mapp->setVy(5);
    jugador1->setVy(7);
    jugador1->setVx(10);
    evil->setVy(7);
    nitro->setVel(5);
}

void MainWindow::efectoNitro()
{
    mancha->setVel(30);
    mapp->setVy(30);
    jugador1->setVy(30);
    //evil->setVy(30);
    for(auto it : vect_enemigos){
         it->setVy(30);
    }
    nitro->setVel(30);

}

void MainWindow::crea_enemigos()
{
    evil = new enemigos(coches,nivel);
    coches++;
    if(coches>6){
        coches = 1;
    }
    evil->posi();
    vect_enemigos.push_back(evil);
    scene->addItem(evil);
}

void MainWindow::aceiteRandom()
{
    mancha = new aceite();
    vect_aceite.push_back(mancha);
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
                colision_enemigos();
                connect(timer1, SIGNAL(timeout()),this,SLOT(normal()));
                mapp->setVy(0);
            }
            aceite *Aceite = dynamic_cast<aceite*>(c);
            if(Aceite){
                jugador1->giro();
                scene->removeItem(mancha);
                connect(timer1, SIGNAL(timeout()),this,SLOT(normal()));
            }
            turbo *Nitro = dynamic_cast<turbo*>(c);
            if(Nitro){
                scene->removeItem(nitro);
                jugador1->setVy(20);
                efectoNitro();
                connect(timer2, SIGNAL(timeout()),this,SLOT(normal()));
                timer2->start(1000);
           }
        }
    }
}

void MainWindow::turboRandom()
{
    nitro = new turbo();
    vect_turbo.push_back(nitro);
    nitro->movimiento();
    nitro->posAleatorio();
    scene->addItem(nitro);
}
void MainWindow::destruir_tiempo()
{
    timer->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer1->stop();
    delete timer;
    delete timer1;
    delete timer2;
    delete timer3;
    delete timer4;
}

void MainWindow::sig_level()
{
    if(!vect_enemigos.empty()){
        for(auto it : vect_enemigos){
             scene->removeItem(it);
             vect_enemigos.removeOne(it);
        }
    }
    if(!vect_aceite.empty()){
        for(auto it : vect_aceite){
             scene->removeItem(it);
             vect_aceite.removeOne(it);
        }
    }

    if(!vect_turbo.empty()){
        for(auto it : vect_turbo){
             scene->removeItem(it);
             vect_turbo.removeOne(it);
        }
    }
}

void MainWindow::colision_enemigos()
{
    mov++;
    v1 = ((evil->getMasa()*evil->getVy())-jugador1->getVy())/(2*(coss-(senn*cot)));
    v2 = (evil->getMasa()*v1*senn)/coss;
    for(auto it : vect_enemigos){
        if(jugador1->collidesWithItem(it)){
            it->setTransformOriginPoint(it->boundingRect().center());
            it->setRotation(45);
            it->setVy(v1*cos(30/180*3.14));
            it->setVx(v1*sin(30/180*314)-1);
        }
    }
    disconnect(timer3, SIGNAL(timeout()),this,SLOT(aceiteRandom()));

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()),this,SLOT(hmov()));
    timer3->start(50);
}

void MainWindow::hmov()
{
    jugador1->setTransformOriginPoint(jugador1->boundingRect().center());
    jugador1->setX(jugador1->getX()+(v2*sin(60/180*314)+1));
    jugador1->setY(jugador1->getY()+(v2*cos(60/180*314)));
    jugador1->posicion();
    jugador1->setRotation(90);

}
