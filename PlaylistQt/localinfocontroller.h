#ifndef LOCALINFOCONTROLLER_H
#define LOCALINFOCONTROLLER_H

#include <QString>

#define D_VERSION_INFO "0.01"
#define D_FILEINFO "PlaylistQt.inf"

class LocalInfoController
{
    QString m_LastPlayListName;

    bool m_haveLocalInfo = false;

public:
    LocalInfoController();

    QString getLastPlayListName() { return m_LastPlayListName; }

    void setLastPlayListName(QString lastPlayListName ) { m_LastPlayListName = lastPlayListName; }

    // Flags
    bool haveLocalInfo() { return m_haveLocalInfo; }

    // Other Methods

    bool save();
    bool load();
};

#endif // LOCALINFOCONTROLLER_H
