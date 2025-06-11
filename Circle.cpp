
#include "Circle.h"
#include <cmath>
Circle::Circle(string name, float a) : Figure(name)
{
    m_a = a;
}

float Circle::Area() const
{
    return M_PI * m_a * m_a;
}

float Circle::Perimeter() const
{
    return 2 * M_PI * m_a;
}

void Circle::Info() const
{
    cout << "Circle: " << Name() << endl;
    cout << "Range: " << m_a << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}