#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStackedWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QStringList>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void changeLight();

private:
    QLabel *trafficLightLabel;
    QPushButton *startButton;
    QTimer *timer;
    int currentLightIndex;
    QStringList lightColors;
    int timeInterval;
    //QStackedWidget *trafficLights;

};

#endif // MAINWINDOW_H

