//
// Created by claudia on 2017/7/9.
//

#ifndef FACTORY_POINT_H
#define FACTORY_POINT_H

#include <math.h>
#include <ostream>

class Point {
    float x;
    float y;
    Point(float x, float y) : x(x), y(y) {}

    class PointFactory {
    public:
        static Point NewCartesian(const float x, const float y) {
            return  {x, y};
        }
        static Point NewPolar(const float r, const float theta) {
            return {static_cast<float>(r*cos(theta)),
                    static_cast<float>(r*sin(theta))};
        }
    };

public:
    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
    static PointFactory Factory;

};

#endif //FACTORY_POINT_H
