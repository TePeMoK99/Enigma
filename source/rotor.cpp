#include "rotor.h"

Rotor::Rotor()
{ }

QChar Rotor::rightToLeft(const QChar &prev_symb, const QChar &prev_cur)
{
    char delta = prev_symb.toLatin1() + (getCurrentSymbol().toLatin1() - prev_cur.toLatin1());
    if (delta < 'A')
        delta += 26;
    else if (delta > 'Z')
        delta -= 26;

    return m_vector[indexOf(delta, 1)].second;
}

QChar Rotor::leftToRight(const QChar &prev_symb, const QChar &prev_cur)
{
    char delta = prev_symb.toLatin1() - (- getCurrentSymbol().toLatin1() + prev_cur.toLatin1());

    if (delta < 'A')
        delta += 26;
    else if (delta > 'Z')
        delta -= 26;

    return m_vector[indexOf(delta, 2)].first;
}

void Rotor::setVector(const QVector<QPair<QChar, QChar>> &vector)
{
    if (m_vector == vector)
        return;

    m_vector = vector;
}

void Rotor::rotateOn(const int &steps)
{
    if (steps > 0)
    {
        if (current_index == 25)
        {
            m_isFinishingCircle = true;
            current_index = 0;
        }
        else
        {
            m_isFinishingCircle = false;
            current_index++;
        }
    }
    if (steps < 0)
    {
        if (current_index == 0)
            current_index = 25;
        else
            current_index--;
    }
}

int Rotor::indexOf(const QChar &symbol, const int &pos_in_pair)
{
    const int size = m_vector.size();

    if (pos_in_pair == 1)
        for (int i = 0; i < size; i++)
        {
            if (m_vector[i].first == symbol)
                return i;
        }
    else
        for (int i = 0; i < size; i++)
            if (m_vector[i].second == symbol)
                return i;
    return {};
}

QChar Rotor::getCurrentSymbol()
{
    return current_index + 'A';
}
