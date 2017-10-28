#ifndef __shapes__
#define __shapes__

class Shape {

public:
    virtual double area();

    virtual double perimeter();

    virtual double height();

    virtual double width();

    virtual void rotate();
};

class Rectangle : public Shape {
public:
    Rectangle(double h, double w);

    double area();

    double perimeter();

    double height();

    double width();

    void rotate();

private:
    double h;
    double w;
};

class Square : public Shape {
public:
    Square(double l);

    double area();

    double perimeter();

    double height();

    double width();

    void rotate();

private:
    double l;
};

class Circle : public Shape {
public:
    Circle(double r);

    double area();

    double perimeter();

    double height();

    double width();

    void rotate();

private:
    double r;
};

#endif
