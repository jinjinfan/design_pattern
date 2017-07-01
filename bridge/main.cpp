#include <iostream>
#include "person.h"
#include "Shape.h"
using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    Person p;
    p.name = "John";
    p.greet();

    RasterRender rr;
    Circle raster_circle{rr, 10, 10, 5};
    raster_circle.draw();
    raster_circle.resize(2);
    raster_circle.draw();
    return 0;
}