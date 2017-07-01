//
// Created by claudia on 2017/6/30.
//

#ifndef BRIDGE_SHAPE_H
#define BRIDGE_SHAPE_H

#include <iostream>
struct Renderer {
    virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRender : Renderer {
    void render_circle(float x, float y, float radius) override {
        std::cout << "Drawing a vector circle of radius " << radius << std::endl;
    }
};

struct RasterRender : Renderer {
    void render_circle(float x, float y, float radius) override {
        std::cout << "Rasterizing a circle of radius " << radius << std::endl;
    }
};

struct Shape {
protected:
    Renderer &renderer;
    Shape(Renderer &renderer) : renderer(renderer) {}
public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape {
    Circle(Renderer &renderer, float x, float y, float radius) : Shape(renderer), x(x), y(y), radius(radius) {}

    void draw() override{
        renderer.render_circle(x, y, radius);
    }
    void resize(float factor) override {
        radius *= factor;
    }
    float x, y, radius;
};

#endif //BRIDGE_SHAPE_H
