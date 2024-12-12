#ifndef REVIEWDATA_H
#define REVIEWDATA_H

#include <QMainWindow>
#include <QDate>

class ReviewData
{
public:
    ReviewData(const QString &softwareName, const QDate &reviewDate, bool recommended);
    QString softwareName() const;
    QDate reviewDate() const;
    bool isRecommended() const;

private:
    QString m_softwareName;
    QDate m_reviewDate;
    bool m_recommended;
};

#endif // REVIEWDATA_H
