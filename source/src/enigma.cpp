#include "enigma.h"

Enigma::Enigma(QObject *parent) : QObject(parent)
{
    srand(GetTickCount());
    inicializeRotors();
    inicializeComutator();
    inicializeColorQueue();

    setRotor1Current(rotors[0].getCurrentSymbol());
    setRotor2Current(rotors[1].getCurrentSymbol());
    setRotor3Current(rotors[2].getCurrentSymbol());
}

QColor Enigma::randColor()
{
    QColor color {color_queue.front()};
    color_queue.pop_front();
    color_queue.enqueue(color);
    return color;
}

QString Enigma::intToChar(const int &code)
{
    if (code == 'Z' + 1)
        return QString {"A"};
    if (code == 'A' - 1)
        return QString {"Z"};
    return QString {code};
}

void Enigma::press(const QString &symbol)
{
    moveRotors(1);

    QChar exitSymbol {symbol[0]};

    // input -> comut
    exitSymbol = comutator.changeSymbol(exitSymbol);

    // comut -> rot1
    exitSymbol = rotors[m_active_rotor1].rightToLeft(exitSymbol, 'A');

    // rot1 -> rot2
    exitSymbol = rotors[m_active_rotor2].rightToLeft(exitSymbol,
                                                     rotors[m_active_rotor1].getCurrentSymbol());
    // rot2 -> rot3
    exitSymbol = rotors[m_active_rotor3].rightToLeft(exitSymbol,
                                                     rotors[m_active_rotor2].getCurrentSymbol());
    // rot3 -> refl
    exitSymbol = rotors[active_reflector].rightToLeft(exitSymbol,
                                                      rotors[m_active_rotor3].getCurrentSymbol());
    // refl -> rot3
    exitSymbol = rotors[m_active_rotor3].leftToRight(exitSymbol, 'A');

    // rot3 -> rot2
    exitSymbol = rotors[m_active_rotor2].leftToRight(exitSymbol,
                                                     rotors[m_active_rotor3].getCurrentSymbol());
    // rot2 -> rot1
    exitSymbol = rotors[m_active_rotor1].leftToRight(exitSymbol,
                                                     rotors[m_active_rotor2].getCurrentSymbol());
    // rot1 -> comut
    char delta = rotors[m_active_rotor1].getCurrentSymbol().toLatin1() - 'A';

    // comut -> output
    exitSymbol = comutator.changeSymbol((exitSymbol.toLatin1() - delta - 'A' + 26) % 26 + 'A');

    setButton(exitSymbol);
}

void Enigma::connectSymbols(const QString &symbol1, const QString &symbol2)
{
    comutator.add(symbol1, symbol2);
}

void Enigma::resetComutator()
{
    comutator.clear();
    inicializeComutator();
}

void Enigma::moveRotors(const int &position)
{
    rotors[m_active_rotor1].rotateOn(position);

    if (rotors[m_active_rotor1].isFinishingCircle() == true)
        rotors[m_active_rotor2].rotateOn(position);

    if (rotors[m_active_rotor2].isFinishingCircle() == true &&
            rotors[m_active_rotor1].isFinishingCircle() == true)
        rotors[m_active_rotor3].rotateOn(position);

    setRotor1Current(rotors[m_active_rotor1].getCurrentSymbol());
    setRotor2Current(rotors[m_active_rotor2].getCurrentSymbol());
    setRotor3Current(rotors[m_active_rotor3].getCurrentSymbol());
}

void Enigma::moveOneRotor(const int &index_on_view,
                          const int &index_in_array, const int &position)
{
    rotors[index_in_array].rotateOn(position);
    if (index_on_view == 1)
        setRotor1Current(rotors[index_in_array].getCurrentSymbol());
    else if (index_on_view == 2)
        setRotor2Current(rotors[index_in_array].getCurrentSymbol());
    else if (index_on_view == 3)
        setRotor3Current(rotors[index_in_array].getCurrentSymbol());
}

void Enigma::setButton(const QString &button)
{
    if (m_button == button)
        return;

    m_button = button;
    emit buttonChanged(m_button);
}

void Enigma::setRotor1Current(const QChar &rotor1Index)
{
    if (m_rotor1Current == rotor1Index)
        return;

    m_rotor1Current = rotor1Index;
    emit rotor1CurrentChanged(m_rotor1Current);
}

void Enigma::setRotor2Current(const QChar &rotor2Index)
{
    if (m_rotor2Current == rotor2Index)
        return;

    m_rotor2Current = rotor2Index;
    emit rotor2CurrentChanged(m_rotor2Current);
}

void Enigma::setRotor3Current(const QChar &rotor3Index)
{
    if (m_rotor3Current == rotor3Index)
        return;

    m_rotor3Current = rotor3Index;
    emit rotor3CurrentChanged(m_rotor3Current);
}

void Enigma::setActiveReflector(const int &index)
{
    if (active_reflector == index)
        return;
    active_reflector = index;
}

void Enigma::setActive_rotor1(const int &active_rotor1)
{
    if (m_active_rotor1 == active_rotor1)
        return;

    m_active_rotor1 = active_rotor1;
    emit active_rotor1Changed(m_active_rotor1);
}

void Enigma::setActive_rotor2(const int &active_rotor2)
{
    if (m_active_rotor2 == active_rotor2)
        return;

    m_active_rotor2 = active_rotor2;
    emit active_rotor2Changed(m_active_rotor2);
}

void Enigma::setActive_rotor3(const int &active_rotor3)
{

    if (m_active_rotor3 == active_rotor3)
        return;

    m_active_rotor3 = active_rotor3;
    emit active_rotor3Changed(m_active_rotor3);
}

void Enigma::inicializeRotors()
{
    for (int i = 0; i < 10; i++)
        rotors.append(Rotor {});

    QVector<QPair<QChar, QChar>> vector;
    // 1 rotor
    vector.append(qMakePair('A', 'E'));
    vector.append(qMakePair('B', 'K'));
    vector.append(qMakePair('C', 'M'));
    vector.append(qMakePair('D', 'F'));
    vector.append(qMakePair('E', 'L'));
    vector.append(qMakePair('F', 'G'));
    vector.append(qMakePair('G', 'D'));
    vector.append(qMakePair('H', 'Q'));
    vector.append(qMakePair('I', 'V'));
    vector.append(qMakePair('J', 'Z'));
    vector.append(qMakePair('K', 'N'));
    vector.append(qMakePair('L', 'T'));
    vector.append(qMakePair('M', 'O'));
    vector.append(qMakePair('N', 'W'));
    vector.append(qMakePair('O', 'Y'));
    vector.append(qMakePair('P', 'H'));
    vector.append(qMakePair('Q', 'X'));
    vector.append(qMakePair('R', 'U'));
    vector.append(qMakePair('S', 'S'));
    vector.append(qMakePair('T', 'P'));
    vector.append(qMakePair('U', 'A'));
    vector.append(qMakePair('V', 'I'));
    vector.append(qMakePair('W', 'B'));
    vector.append(qMakePair('X', 'R'));
    vector.append(qMakePair('Y', 'C'));
    vector.append(qMakePair('Z', 'J'));
    rotors[0].setVector(vector);
    vector.clear();

    // 2 rotor
    vector.append(qMakePair('A', 'A'));
    vector.append(qMakePair('B', 'J'));
    vector.append(qMakePair('C', 'D'));
    vector.append(qMakePair('D', 'K'));
    vector.append(qMakePair('E', 'S'));
    vector.append(qMakePair('F', 'I'));
    vector.append(qMakePair('G', 'R'));
    vector.append(qMakePair('H', 'U'));
    vector.append(qMakePair('I', 'X'));
    vector.append(qMakePair('J', 'B'));
    vector.append(qMakePair('K', 'L'));
    vector.append(qMakePair('L', 'H'));
    vector.append(qMakePair('M', 'W'));
    vector.append(qMakePair('N', 'T'));
    vector.append(qMakePair('O', 'M'));
    vector.append(qMakePair('P', 'C'));
    vector.append(qMakePair('Q', 'Q'));
    vector.append(qMakePair('R', 'G'));
    vector.append(qMakePair('S', 'Z'));
    vector.append(qMakePair('T', 'N'));
    vector.append(qMakePair('U', 'P'));
    vector.append(qMakePair('V', 'Y'));
    vector.append(qMakePair('W', 'F'));
    vector.append(qMakePair('X', 'V'));
    vector.append(qMakePair('Y', 'O'));
    vector.append(qMakePair('Z', 'E'));
    rotors[1].setVector(vector);
    vector.clear();

    // 3 rotor
    vector.append(qMakePair('A', 'B'));
    vector.append(qMakePair('B', 'D'));
    vector.append(qMakePair('C', 'F'));
    vector.append(qMakePair('D', 'H'));
    vector.append(qMakePair('E', 'G'));
    vector.append(qMakePair('F', 'L'));
    vector.append(qMakePair('G', 'C'));
    vector.append(qMakePair('H', 'P'));
    vector.append(qMakePair('I', 'R'));
    vector.append(qMakePair('J', 'T'));
    vector.append(qMakePair('K', 'X'));
    vector.append(qMakePair('L', 'V'));
    vector.append(qMakePair('M', 'Z'));
    vector.append(qMakePair('N', 'N'));
    vector.append(qMakePair('O', 'Y'));
    vector.append(qMakePair('P', 'E'));
    vector.append(qMakePair('Q', 'I'));
    vector.append(qMakePair('R', 'W'));
    vector.append(qMakePair('S', 'J'));
    vector.append(qMakePair('T', 'A'));
    vector.append(qMakePair('U', 'K'));
    vector.append(qMakePair('V', 'M'));
    vector.append(qMakePair('W', 'U'));
    vector.append(qMakePair('X', 'S'));
    vector.append(qMakePair('Y', 'Q'));
    vector.append(qMakePair('Z', 'O'));
    rotors[2].setVector(vector);
    vector.clear();

    // 4 rotor
    vector.append(qMakePair('A', 'I'));
    vector.append(qMakePair('B', 'S'));
    vector.append(qMakePair('C', 'O'));
    vector.append(qMakePair('D', 'V'));
    vector.append(qMakePair('E', 'P'));
    vector.append(qMakePair('F', 'Z'));
    vector.append(qMakePair('G', 'J'));
    vector.append(qMakePair('H', 'A'));
    vector.append(qMakePair('I', 'Y'));
    vector.append(qMakePair('J', 'Q'));
    vector.append(qMakePair('K', 'U'));
    vector.append(qMakePair('L', 'I'));
    vector.append(qMakePair('M', 'R'));
    vector.append(qMakePair('N', 'H'));
    vector.append(qMakePair('O', 'X'));
    vector.append(qMakePair('P', 'L'));
    vector.append(qMakePair('Q', 'N'));
    vector.append(qMakePair('R', 'F'));
    vector.append(qMakePair('S', 'T'));
    vector.append(qMakePair('T', 'J'));
    vector.append(qMakePair('U', 'K'));
    vector.append(qMakePair('V', 'D'));
    vector.append(qMakePair('W', 'S'));
    vector.append(qMakePair('X', 'M'));
    vector.append(qMakePair('Y', 'W'));
    vector.append(qMakePair('Z', 'B'));
    rotors[3].setVector(vector);
    vector.clear();

    // 5 rotor
    vector.append(qMakePair('A', 'V'));
    vector.append(qMakePair('B', 'Z'));
    vector.append(qMakePair('C', 'B'));
    vector.append(qMakePair('D', 'R'));
    vector.append(qMakePair('E', 'G'));
    vector.append(qMakePair('F', 'I'));
    vector.append(qMakePair('G', 'T'));
    vector.append(qMakePair('H', 'Y'));
    vector.append(qMakePair('I', 'U'));
    vector.append(qMakePair('J', 'P'));
    vector.append(qMakePair('K', 'S'));
    vector.append(qMakePair('L', 'D'));
    vector.append(qMakePair('M', 'N'));
    vector.append(qMakePair('N', 'H'));
    vector.append(qMakePair('O', 'L'));
    vector.append(qMakePair('P', 'X'));
    vector.append(qMakePair('Q', 'A'));
    vector.append(qMakePair('R', 'W'));
    vector.append(qMakePair('S', 'M'));
    vector.append(qMakePair('T', 'J'));
    vector.append(qMakePair('U', 'Q'));
    vector.append(qMakePair('V', 'O'));
    vector.append(qMakePair('W', 'F'));
    vector.append(qMakePair('X', 'E'));
    vector.append(qMakePair('Y', 'S'));
    vector.append(qMakePair('Z', 'K'));
    rotors[4].setVector(vector);
    vector.clear();

    // 6 rotor
    vector.append(qMakePair('A', 'J'));
    vector.append(qMakePair('B', 'P'));
    vector.append(qMakePair('C', 'G'));
    vector.append(qMakePair('D', 'V'));
    vector.append(qMakePair('E', 'O'));
    vector.append(qMakePair('F', 'U'));
    vector.append(qMakePair('G', 'M'));
    vector.append(qMakePair('H', 'S'));
    vector.append(qMakePair('I', 'Y'));
    vector.append(qMakePair('J', 'Q'));
    vector.append(qMakePair('K', 'B'));
    vector.append(qMakePair('L', 'E'));
    vector.append(qMakePair('M', 'N'));
    vector.append(qMakePair('N', 'H'));
    vector.append(qMakePair('O', 'Z'));
    vector.append(qMakePair('P', 'R'));
    vector.append(qMakePair('Q', 'D'));
    vector.append(qMakePair('R', 'K'));
    vector.append(qMakePair('S', 'A'));
    vector.append(qMakePair('T', 'S'));
    vector.append(qMakePair('U', 'X'));
    vector.append(qMakePair('V', 'L'));
    vector.append(qMakePair('W', 'I'));
    vector.append(qMakePair('X', 'C'));
    vector.append(qMakePair('Y', 'T'));
    vector.append(qMakePair('Z', 'W'));
    rotors[5].setVector(vector);
    vector.clear();

    // 7 rotor
    vector.append(qMakePair('A', 'N'));
    vector.append(qMakePair('B', 'Z'));
    vector.append(qMakePair('C', 'J'));
    vector.append(qMakePair('D', 'H'));
    vector.append(qMakePair('E', 'G'));
    vector.append(qMakePair('F', 'R'));
    vector.append(qMakePair('G', 'C'));
    vector.append(qMakePair('H', 'X'));
    vector.append(qMakePair('I', 'M'));
    vector.append(qMakePair('J', 'Y'));
    vector.append(qMakePair('K', 'S'));
    vector.append(qMakePair('L', 'W'));
    vector.append(qMakePair('M', 'B'));
    vector.append(qMakePair('N', 'O'));
    vector.append(qMakePair('O', 'U'));
    vector.append(qMakePair('P', 'F'));
    vector.append(qMakePair('Q', 'A'));
    vector.append(qMakePair('R', 'I'));
    vector.append(qMakePair('S', 'V'));
    vector.append(qMakePair('T', 'L'));
    vector.append(qMakePair('U', 'P'));
    vector.append(qMakePair('V', 'E'));
    vector.append(qMakePair('W', 'K'));
    vector.append(qMakePair('X', 'Q'));
    vector.append(qMakePair('Y', 'D'));
    vector.append(qMakePair('Z', 'T'));
    rotors[6].setVector(vector);
    vector.clear();

    // 8 rotor
    vector.append(qMakePair('A', 'F'));
    vector.append(qMakePair('B', 'K'));
    vector.append(qMakePair('C', 'Q'));
    vector.append(qMakePair('D', 'H'));
    vector.append(qMakePair('E', 'T'));
    vector.append(qMakePair('F', 'L'));
    vector.append(qMakePair('G', 'X'));
    vector.append(qMakePair('H', 'O'));
    vector.append(qMakePair('I', 'C'));
    vector.append(qMakePair('J', 'B'));
    vector.append(qMakePair('K', 'J'));
    vector.append(qMakePair('L', 'S'));
    vector.append(qMakePair('M', 'P'));
    vector.append(qMakePair('N', 'D'));
    vector.append(qMakePair('O', 'Z'));
    vector.append(qMakePair('P', 'R'));
    vector.append(qMakePair('Q', 'A'));
    vector.append(qMakePair('R', 'M'));
    vector.append(qMakePair('S', 'E'));
    vector.append(qMakePair('T', 'W'));
    vector.append(qMakePair('U', 'N'));
    vector.append(qMakePair('V', 'I'));
    vector.append(qMakePair('W', 'U'));
    vector.append(qMakePair('X', 'Y'));
    vector.append(qMakePair('Y', 'G'));
    vector.append(qMakePair('Z', 'V'));
    rotors[7].setVector(vector);
    vector.clear();

    // B reflector
    vector.append(qMakePair('A', 'Y'));
    vector.append(qMakePair('B', 'R'));
    vector.append(qMakePair('C', 'U'));
    vector.append(qMakePair('D', 'H'));
    vector.append(qMakePair('E', 'Q'));
    vector.append(qMakePair('F', 'S'));
    vector.append(qMakePair('G', 'L'));
    vector.append(qMakePair('H', 'D'));
    vector.append(qMakePair('I', 'P'));
    vector.append(qMakePair('J', 'X'));
    vector.append(qMakePair('K', 'N'));
    vector.append(qMakePair('L', 'G'));
    vector.append(qMakePair('M', 'O'));
    vector.append(qMakePair('N', 'K'));
    vector.append(qMakePair('O', 'M'));
    vector.append(qMakePair('P', 'I'));
    vector.append(qMakePair('Q', 'E'));
    vector.append(qMakePair('R', 'B'));
    vector.append(qMakePair('S', 'F'));
    vector.append(qMakePair('T', 'Z'));
    vector.append(qMakePair('U', 'C'));
    vector.append(qMakePair('V', 'W'));
    vector.append(qMakePair('W', 'V'));
    vector.append(qMakePair('X', 'J'));
    vector.append(qMakePair('Y', 'A'));
    vector.append(qMakePair('Z', 'T'));
    rotors[8].setVector(vector);
    vector.clear();

    // С reflector
    vector.append(qMakePair('A', 'F'));
    vector.append(qMakePair('B', 'V'));
    vector.append(qMakePair('C', 'P'));
    vector.append(qMakePair('D', 'J'));
    vector.append(qMakePair('E', 'I'));
    vector.append(qMakePair('F', 'A'));
    vector.append(qMakePair('G', 'O'));
    vector.append(qMakePair('H', 'Y'));
    vector.append(qMakePair('I', 'E'));
    vector.append(qMakePair('J', 'D'));
    vector.append(qMakePair('K', 'R'));
    vector.append(qMakePair('L', 'Z'));
    vector.append(qMakePair('M', 'X'));
    vector.append(qMakePair('N', 'W'));
    vector.append(qMakePair('O', 'G'));
    vector.append(qMakePair('P', 'C'));
    vector.append(qMakePair('Q', 'T'));
    vector.append(qMakePair('R', 'K'));
    vector.append(qMakePair('S', 'U'));
    vector.append(qMakePair('T', 'Q'));
    vector.append(qMakePair('U', 'S'));
    vector.append(qMakePair('V', 'B'));
    vector.append(qMakePair('W', 'N'));
    vector.append(qMakePair('X', 'M'));
    vector.append(qMakePair('Y', 'H'));
    vector.append(qMakePair('Z', 'L'));
    rotors[9].setVector(vector);
    vector.clear();
}

void Enigma::inicializeComutator()
{
    QMap<QChar, QChar> map;
    map['A'] = 'A';
    map['B'] = 'B';
    map['C'] = 'C';
    map['D'] = 'D';
    map['E'] = 'E';
    map['F'] = 'F';
    map['G'] = 'G';
    map['H'] = 'H';
    map['I'] = 'I';
    map['J'] = 'J';
    map['K'] = 'K';
    map['L'] = 'L';
    map['M'] = 'M';
    map['N'] = 'N';
    map['O'] = 'O';
    map['P'] = 'P';
    map['Q'] = 'Q';
    map['R'] = 'R';
    map['S'] = 'S';
    map['T'] = 'T';
    map['U'] = 'U';
    map['V'] = 'V';
    map['W'] = 'W';
    map['X'] = 'X';
    map['Y'] = 'Y';
    map['Z'] = 'Z';
    comutator.setMap(map);
}

void Enigma::inicializeColorQueue()
{
    color_queue.enqueue("DeepPink");
    color_queue.enqueue("DarkRed");
    color_queue.enqueue("OrangeRed");
    color_queue.enqueue("Gold");
    color_queue.enqueue("MediumPurple");
    color_queue.enqueue("Aqua");
    color_queue.enqueue("Navy");
    color_queue.enqueue("DimGray");
    color_queue.enqueue("DarkGreen");
    color_queue.enqueue("MistyRose");
    color_queue.enqueue("GreenYellow");
    color_queue.enqueue("IndianRed");
    color_queue.enqueue("Khaki");
}
