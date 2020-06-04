#include "comutator.h"

Comutator::Comutator()
{ }

void Comutator::add(const QString &symbol1, const QString &symbol2)
{
    m_map[symbol1[0]] = symbol2[0];
    m_map[symbol2[0]] = symbol1[0];
}

void Comutator::clear()
{
    m_map.clear();
}

QChar Comutator::changeSymbol(const QChar &symbol)
{
    return m_map[symbol];
}

void Comutator::setMap(const QMap<QChar, QChar> &map)
{
    if (m_map == map)
        return;

    m_map = map;
}
