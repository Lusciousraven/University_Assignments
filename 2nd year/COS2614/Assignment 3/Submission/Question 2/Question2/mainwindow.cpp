#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentLightIndex(0)
{
    lightColors << "C:\\Users\\Jaymeen\\Desktop\\UnisaComputerScience\\2nd year\\COS2614\\Assignment 3\\Submission\\Question 2\\Question2\\green.jpg";
    lightColors << "C:\\Users\\Jaymeen\\Desktop\\UnisaComputerScience\\2nd year\\COS2614\\Assignment 3\\Submission\\Question 2\\Question2\\yellow.jpg";
    lightColors << "C:\\Users\\Jaymeen\\Desktop\\UnisaComputerScience\\2nd year\\COS2614\\Assignment 3\\Submission\\Question 2\\Question2\\red.jpg";

    trafficLightLabel = new QLabel(this);
    trafficLightLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(trafficLightLabel);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    timeInterval = QInputDialog::getInt(this, "Time Interval", "Enter time interval (seconds):", 0, 0, 100, 1);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::changeLight);
    changeLight();
    timer->start(timeInterval * 1000);
}

void MainWindow::changeLight()
{
    if (currentLightIndex >= lightColors.size())
        currentLightIndex = 0;

    QString lightColor = lightColors[currentLightIndex];
    QPixmap pixmap(lightColor);

    if (pixmap.isNull()) {
        qDebug() << "Error loading image: " << lightColor;
        return;
    }

    trafficLightLabel->setPixmap(pixmap);

    currentLightIndex++;

    if (currentLightIndex >= lightColors.size())
        currentLightIndex = 0;
}



