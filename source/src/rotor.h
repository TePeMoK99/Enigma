#pragma once

#include <QVector>
#include <QVector>
#include <QPair>

class Rotor
{
public:
    Rotor();

    QChar rightToLeft(const QChar &prev_symb, const QChar &prev_cur);
    QChar leftToRight(const QChar &prev_symb, const QChar &prev_cur);
    QChar getCurrentSymbol();
    void setVector(const QVector<QPair<QChar, QChar>> &vector);
    void rotateOn(const int &steps);
    bool isFinishingCircle() const  { return m_isFinishingCircle; }

private:
    QVector<QPair<QChar, QChar>> m_vector;
    bool m_isFinishingCircle {false};
    int current_index{0};
    int indexOf(const QChar &symbol, const int &pos_in_pair);
};

