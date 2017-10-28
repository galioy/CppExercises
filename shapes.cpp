#include "shapes.h"
#include <cmath>
#include <math.h>

double Shape::area() { return 0; }

double Shape::perimeter() { return 0; }

double Shape::height() { return 0; }

double Shape::width() { return 0; }

void Shape::rotate() {};

/*
 * Rectangle methods
 */
Rectangle::Rectangle(double height, double width) {
    this->h = height;
    this->w = width;
}

double Rectangle::area() {
    return this->h * this->w;
}

double Rectangle::perimeter() {
    return 2 * (this->h + this->w);
}

double Rectangle::height() {
    return this->h;
}

double Rectangle::width() {
    return this->w;
}

void Rectangle::rotate() {
    double temp = this->h;

    this->h = this->w;
    this->w = temp;
}

/*
 * Square methods
 */
Square::Square(double length) {
    this->l = length;
}

double Square::area() {
    return pow(this->l, 2);
}

double Square::perimeter() {
    return 4 * this->l;
}

double Square::height() {
    return this->l;
}

double Square::width() {
    return this->l;
}

void Square::rotate() {
    // NaN
}

/*
 * Circle methods
 */
Circle::Circle(double radius) {
    this->r = radius;
}

double Circle::area() {
    return M_PI * pow(this->r, 2);
}

double Circle::perimeter() {
    return 2 * M_PI * this->r;
}

double Circle::height() {
    return this->r * 2;
}

double Circle::width() {
    return this->r * 2;
}

void Circle::rotate() {
    // NaN
}
