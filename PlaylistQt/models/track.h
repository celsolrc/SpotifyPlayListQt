#ifndef TRACK_H
#define TRACK_H

#include "../utils/jsonutils.h"

#include <QDateTime>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class Track
{
public:
    Track();
    explicit Track(const QJsonObject &item);

    QJsonObject toJson() const;

    QString id, album, albumId, artist, artistId, name, image;
    int duration = 0;
    bool isLocal = false;
    bool isPlayable = false;
    QDateTime addedAt;
};
#endif // TRACK_H
