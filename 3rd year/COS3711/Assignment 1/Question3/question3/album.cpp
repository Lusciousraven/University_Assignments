#include "Album.h"

Album::Album(const QString &composer, const QString &albumName, double replacementValue, int rating)
    : m_composer(composer), m_albumName(albumName), m_replacementValue(replacementValue), m_rating(rating)
{
}

QString Album::composer() const
{
    return m_composer;
}

QString Album::albumName() const
{
    return m_albumName;
}

double Album::replacementValue() const
{
    return m_replacementValue;
}

int Album::rating() const
{
    return m_rating;
}
