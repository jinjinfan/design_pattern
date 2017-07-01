//
// Created by claudia on 2017/7/1.
//

#ifndef DECORATOR_GEOMETRY_H
#define DECORATOR_GEOMETRY_H
#include <string>
#include <sstream>
using namespace std;

struct Shape {
    virtual  string str() const = 0;
};

struct Circle : Shape {
    float radius;
    Circle() {}
    explicit Circle(float radius) : radius(radius) {}

    string str() const override {
        ostringstream oss;
        oss << "A circle of radius = " << radius;
        return oss.str();
    }
};

struct Square : Shape {
    float side;

    explicit Square(float side) : side(side) {}

    string str() const override {
        ostringstream oss;
        oss << "A square of side = " << side;
        return oss.str();
    }
};

struct ColoredShape : Shape {
    Shape& shape;
    string color;

    ColoredShape(Shape &shape, const string &color) : shape(shape), color(color) {

    }

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape {
    Shape& shape;
    uint8_t transparency;

    TransparentShape(Shape &shape, uint8_t transparency) : shape(shape), transparency(transparency) {

    }

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) /255 *100
                <<"% transparency";
        return oss.str();
    }
};

template <typename T>
struct ColoredShape2 : T {
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a shape");
    string color;
    ColoredShape2() {}
    ColoredShape2(const string &color) : color(color) {}
    string str() const override {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

template <typename T>
struct TransparentShape2 : T {
    uint8_t transparency;

    template <typename...Args>
    TransparentShape2(uint8_t transparency, Args ...args)
            :transparency(transparency),T::T(args...)
    {
    }

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has " << static_cast<float>(transparency) /255 *100
            <<"% transparency";
        return oss.str();
    }
};
#endif //DECORATOR_GEOMETRY_H
