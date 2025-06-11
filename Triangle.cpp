//
// Created by Filip on 11.06.2025.
//

#include "Triangle.h"




Triangle::Triangle(string name,float a, float b, float c, float h) : Figure(name)
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_h = h;

}

float Triangle::Area() const {
    if (m_h > 0) {
        return 0.5 * m_a * m_h;
}
    else
        return 0.5 * m_a * m_b;

}

float Triangle::Perimeter() const {

    return m_a + m_b + m_c;

}

void Triangle::Info() const
{
    cout << "Triangle: " << Name() << endl;
    cout << "Height: " << m_h << endl;
    cout << "Dimensions: " << m_a << " x " << m_b << " x " << m_c << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}