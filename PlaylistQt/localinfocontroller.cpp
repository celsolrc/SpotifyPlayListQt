#include "localinfocontroller.h"

#include <QFile>
#include<QTextStream>

LocalInfoController::LocalInfoController()
{

}

bool LocalInfoController::save()
{
    bool result = false;

    if (haveValues()) {
        QFile arquivo( D_FILEINFO );

        if (arquivo.open(QFile::WriteOnly|QFile::Text)){
            QTextStream saida(&arquivo);

            saida << D_VERSION_INFO;
            saida << m_Username;
            saida << m_Password;
            saida << m_LastPlayListName;

            arquivo.flush();
            arquivo.close();

            m_haveLocalInfo = true;
            result = true;
        }
    }

    return result;
}

bool LocalInfoController::load()
{
    bool result = false;
    QFile arquivo( D_FILEINFO );

    if (arquivo.open(QFile::ReadOnly|QFile::Text)){
        QTextStream entrada(&arquivo);

        QString versao = entrada.readLine();

        if (versao.compare(D_VERSION_INFO)==0)
        {
            m_Username = entrada.readLine();
            m_Password = entrada.readLine();
            m_LastPlayListName = entrada.readLine();

            m_haveLocalInfo = true;
            result = true;
        }

        arquivo.close();
    }

    return result;
}
