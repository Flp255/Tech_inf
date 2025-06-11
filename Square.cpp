//
// Created by Rafal Nowak on 28/05/2022.
//

#include "Square.h"

Square::Square(string name, float a) : Figure(name)
{
    m_a = a;
}

float Square::Area() const
{
    return  m_a * m_a;
}

float Square::Perimeter() const
{
    return 4 * m_a;
}

void Square::Info() const
{
    cout << "Square: " << Name() << endl;
    cout << "Dimension: " << m_a << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}