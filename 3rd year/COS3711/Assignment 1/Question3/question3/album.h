#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

class Album
{
public:
    // Constructor
    Album(const QString &composer, const QString &albumName, double replacementValue, int rating);

    // Getters
    QString composer() const;
    QString albumName() const;
    double replacementValue() const;
    int rating() const;

private:
    QString m_composer;
    QString m_albumName;
    double m_replacementValue;
    int m_rating;
};

#endif // ALBUM_H
