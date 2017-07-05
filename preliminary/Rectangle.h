//
// Created by claudia on 2017/7/4.
//

#ifndef SPECIFICATION_RECTANGLE_H
#define SPECIFICATION_RECTANGLE_H
class Rectangle {
protected:
    int width, height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    virtual int getWidth() const {
        return width;
    }

    virtual int getHeight() const {
        return height;
    }

    virtual void setWidth(const int width) {
        this->width = width;
    }

    virtual void setHeight(const int height) {
        this->height = height;
    }

    int Area() const { return width * height; }
};

class Square : public Rectangle{
public:
    Square(int size) : Rectangle {size, size} {}

    void setWidth(const int width) override {
        this->width = this->height = width;
    }

    void setHeight(const int height) override {
        this->width = this->height = height;
    }
};
#endif //SPECIFICATION_RECTANGLE_H
