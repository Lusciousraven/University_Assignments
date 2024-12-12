#include "reviewdata.h"
#include <QDate>

ReviewData::ReviewData(const QString &softwareName, const QDate &reviewDate, bool recommended)
    : m_softwareName(softwareName), m_reviewDate(reviewDate), m_recommended(recommended)
{
}

QString ReviewData::softwareName() const
{
    return m_softwareName;
}

QDate ReviewData::reviewDate() const
{
    return m_reviewDate;
}

bool ReviewData::isRecommended() const
{
    return m_recommended;
}
