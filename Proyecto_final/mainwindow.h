#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "enemigos.h"
#include "mapa.h"
#include <QList>
#include <vector>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void hmov();
    void crea_enemigos();

private:
    int coches = 1;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    mapa *mapp;
    QTimer *timer;
    QTimer *timer2;
    enemigos *evil;
};
#endif // MAINWINDOW_H
