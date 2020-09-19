#pragma once

#include <QObject>
#include <QColor>
#include <QMap>
#include <QVector>
#include <QQueue>
#include <windows.h>

#include "rotor.h"
#include "comutator.h"

class Enigma : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString button READ button WRITE setButton NOTIFY buttonChanged)
    Q_PROPERTY(QChar rotor1Current READ rotor1Current WRITE setRotor1Current NOTIFY rotor1CurrentChanged)
    Q_PROPERTY(QChar rotor2Current READ rotor2Current WRITE setRotor2Current NOTIFY rotor2CurrentChanged)
    Q_PROPERTY(QChar rotor3Current READ rotor3Current WRITE setRotor3Current NOTIFY rotor3CurrentChanged)
    Q_PROPERTY(int active_rotor1 READ active_rotor1 WRITE setActive_rotor1 NOTIFY active_rotor1Changed)
    Q_PROPERTY(int active_rotor2 READ active_rotor2 WRITE setActive_rotor2 NOTIFY active_rotor2Changed)
    Q_PROPERTY(int active_rotor3 READ active_rotor3 WRITE setActive_rotor3 NOTIFY active_rotor3Changed)

public:
    explicit Enigma(QObject *parent = nullptr);

    QString button() const         { return m_button;        }
    QChar rotor1Current() const    { return m_rotor1Current; }
    QChar rotor2Current() const    { return m_rotor2Current; }
    QChar rotor3Current() const    { return m_rotor3Current; }
    int active_rotor1() const      { return m_active_rotor1; }
    int active_rotor2() const      { return m_active_rotor2; }
    int active_rotor3() const      { return m_active_rotor3; }

public slots:
    void press(const QString &symbol);
    void setButton(const QString &button);
    void connectSymbols(const QString &symbol1, const QString &symbol2);
    void resetComutator();
    void moveRotors(const int &position);
    void moveOneRotor(const int &index_on_view,
                      const int &index_in_array, const int &position);

    QColor randColor();
    QString intToChar(const int &code);

    void setRotor1Current(const QChar &rotor1Current);
    void setRotor2Current(const QChar &rotor2Current);
    void setRotor3Current(const QChar &rotor3Current);

    void setActive_rotor1(const int &active_rotor1);
    void setActive_rotor2(const int &active_rotor2);
    void setActive_rotor3(const int &active_rotor3);
    void setActiveReflector(const int &index);

signals:
    void buttonChanged(QString button);
    void rotor1CurrentChanged(QChar rotor1Current);
    void rotor2CurrentChanged(QChar rotor2Current);
    void rotor3CurrentChanged(QChar rotor3Current);

    void active_rotor1Changed(int active_rotor1);
    void active_rotor2Changed(int active_rotor2);
    void active_rotor3Changed(int active_rotor3);

private:
    void inicializeRotors();
    void inicializeComutator();
    void inicializeColorQueue();

    QString m_button {""};
    QChar m_rotor1Current;
    QChar m_rotor2Current;
    QChar m_rotor3Current;

    QVector<Rotor> rotors;
    QQueue<QColor> color_queue;
    Comutator comutator;

    int m_active_rotor1 {0};
    int m_active_rotor2 {1};
    int m_active_rotor3 {2};
    int active_reflector {8};
};
