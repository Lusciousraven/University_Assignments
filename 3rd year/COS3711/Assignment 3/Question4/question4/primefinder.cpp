#include "PrimeFinder.h"
#include <QDebug>

PrimeFinder::PrimeFinder(int start, int end, QObject* parent)
    : QThread(parent), m_start(start), m_end(end), m_stop(false) {}

void PrimeFinder::run() {
    QList<int> primes;
    for (int num = m_start; num <= m_end; ++num) {
        QMutexLocker locker(&m_mutex);
        if (m_stop) break;
        if (isPrime(num)) {
            primes.append(num);
            emit primesFound(primes);
            msleep(10);  // Small delay to simulate work
        }
    }
}

void PrimeFinder::stop() {
    QMutexLocker locker(&m_mutex);
    m_stop = true;
    m_condition.wakeAll();
}

bool PrimeFinder::isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}
