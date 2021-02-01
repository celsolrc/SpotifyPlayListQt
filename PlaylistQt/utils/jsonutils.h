#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QJsonValue>
#include <QStringList>
#include <QJsonObject>

class JsonUtils
{
public:
    static QJsonValue getProperty(const QJsonObject &json, const QStringList &names);

private:
    JsonUtils() = default;
};

#endif // JSONUTILS_H
