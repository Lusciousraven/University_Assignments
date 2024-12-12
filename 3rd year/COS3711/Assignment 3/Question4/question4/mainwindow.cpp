#include "MainWindow.h"
#include <QLabel>
#include <QCloseEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), centralWidget(new QWidget(this)), layout(new QVBoxLayout(centralWidget)) {

    startEdit = new QLineEdit(this);
    endEdit = new QLineEdit(this);
    threadsEdit = new QLineEdit(this);
    startButton = new QPushButton("Start", this);

    layout->addWidget(new QLabel("Start Number:"));
    layout->addWidget(startEdit);
    layout->addWidget(new QLabel("End Number:"));
    layout->addWidget(endEdit);
    layout->addWidget(new QLabel("Number of Threads (max 4):"));
    layout->addWidget(threadsEdit);
    layout->addWidget(startButton);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startFindingPrimes);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    cleanUpThreads();
}

void MainWindow::startFindingPrimes() {
    cleanUpThreads();
    resultDisplays.clear();
    primeFinders.clear();

    int start = startEdit->text().toInt();
    int end = endEdit->text().toInt();
    int numThreads = threadsEdit->text().toInt();
    numThreads = qMin(numThreads, 4);

    int range = end - start + 1;
    int chunkSize = range / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int chunkStart = start + i * chunkSize;
        int chunkEnd = (i == numThreads - 1) ? end : chunkStart + chunkSize - 1;

        QTextEdit* resultDisplay = new QTextEdit(this);
        resultDisplay->setReadOnly(true);
        layout->addWidget(resultDisplay);
        resultDisplays.append(resultDisplay);

        PrimeFinder* finder = new PrimeFinder(chunkStart, chunkEnd, this);
        connect(finder, &PrimeFinder::primesFound, this, &MainWindow::handlePrimesFound);
        primeFinders.append(finder);
        finder->start();
    }
}

void MainWindow::handlePrimesFound(const QList<int>& primes) {
    // Display the primes in the appropriate QTextEdit
    QStringList primeStrings;
    for (int prime : primes) {
        primeStrings << QString::number(prime);
    }

    for (int i = 0; i < primeFinders.size(); ++i) {
        if (primeFinders[i]->isRunning()) {
            resultDisplays[i]->append("Thread " + QString::number(i+1) + ": " + primeStrings.join(", "));
        }
    }
}

void MainWindow::cleanUpThreads() {
    for (PrimeFinder* finder : primeFinders) {
        finder->stop();
        finder->wait();
        delete finder;
    }
}

void MainWindow::closeEvent(QCloseEvent* event) {
    cleanUpThreads();
    QMainWindow::closeEvent(event);
}
