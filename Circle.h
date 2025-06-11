

#ifndef INHERITANCE_CIRCLE_H
#define INHERITANCE_CIRCLE_H


#include "Figure.h"

class Circle : public Figure
{
private:
    float m_a;
    float m_area;
    float m_perimeter;

public:
    Circle(string name = "", float a = 0);
    virtual ~Circle() {}
    virtual float Area() const;
    virtual float Perimeter() const;
    virtual void Info() const;
};


#endif //INHERITANCE_CIRCLE_H
