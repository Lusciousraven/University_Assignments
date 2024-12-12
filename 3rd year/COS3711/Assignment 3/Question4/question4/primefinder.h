#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class PrimeFinder : public QThread {
    Q_OBJECT

public:
    PrimeFinder(int start, int end, QObject* parent = nullptr);
    void run() override;
    void stop();

signals:
    void primesFound(const QList<int>& primes);

private:
    bool isPrime(int number);
    int m_start;
    int m_end;
    bool m_stop;
    QMutex m_mutex;
    QWaitCondition m_condition;
};

#endif // PRIMEFINDER_H
