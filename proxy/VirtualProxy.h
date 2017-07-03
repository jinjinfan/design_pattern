//
// Created by claudia on 2017/7/2.
//

#ifndef PROXY_VIRTUALPROXY_H
#define PROXY_VIRTUALPROXY_H
#include <iostream>
#include <string>
using namespace std;
struct Image {
    virtual ~Image() {}
    virtual void draw() = 0;
};

struct Bitmap : Image {
    Bitmap(const string& filename) {
        cout << "Loading a file from "<< filename << endl;
    }

    void draw() override {
        cout << "Drawing image " << endl;
    }
};

struct LazyBitmap : Image {
    LazyBitmap(const string &filename)
            : bitmap(nullptr), filename(filename) {}

    void draw() override {
        if(!bitmap)
            bitmap = new Bitmap{filename};
        bitmap->draw();
    }

    virtual ~LazyBitmap() {
        delete bitmap;
    }

private:
    Bitmap* bitmap;
    string filename;
};

#endif //PROXY_VIRTUALPROXY_H
