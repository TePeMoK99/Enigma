#pragma once
#include <QMap>

class Comutator
{
public:
    Comutator();

    void add(const QString &symbol1, const QString &symbol2);
    void clear();
    QChar changeSymbol(const QChar &symbol);
    void setMap(const QMap<QChar, QChar> &map);

private:
    QMap<QChar, QChar> m_map;
};
