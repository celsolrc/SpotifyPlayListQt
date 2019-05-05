#ifndef LOCALINFOCONTROLLER_H
#define LOCALINFOCONTROLLER_H

#include <QString>

#define D_VERSION_INFO "0.01"
#define D_FILEINFO "PlaylistQt.inf"

class LocalInfoController
{
    QString m_Username;
    QString m_Password;

    QString m_LastPlayListName;

    bool m_haveLocalInfo = false;

public:
    LocalInfoController();

    // gets
    QString getUsername() { return m_Username; }
    QString getPassword() { return m_Password; }

    QString getLastPlayListName() { return m_LastPlayListName; }

    // sets
    void setUsername( QString username ) { m_Username = username; }
    void setPassword( QString password ) { m_Password = password; }

    void setLastPlayListName(QString lastPlayListName ) { m_LastPlayListName = lastPlayListName; }

    // Flags
    bool haveLocalInfo() { return m_haveLocalInfo; }

    // Other Methods

    bool save();
    bool load();
};

#endif // LOCALINFOCONTROLLER_H
