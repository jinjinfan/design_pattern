#include <iostream>
#include "Logger.h"
#include "Geometry.h"

template <typename Func>
Logger2<Func> make_logger2(Func func, const string& name) {
    return Logger2<Func>{func, name};
}

template <typename R, typename... Args>
Logger3<R(Args...)> make_logger3(R (*func)(Args...), const string& name){
    return Logger3<R(Args...)> {
            function<R(Args...)>(func),
            name
    };
};

double add(double a, double b) {
    cout << a << " + " << b << " = " << (a+b) << endl;
    return a+b;
}
int main() {
    cout << "Logging part decorator .... " << endl;
    Logger logger{[](){cout << "Hello world" << endl;}, "HelloFunc"};
    logger();
    cout << endl;
    auto logger2 = make_logger2([](){cout << "Hello world" << endl;}, "HelloFunc");
    logger2();

    cout << endl;
    auto logger3 = make_logger3(add, "Add");
    auto result = logger3(2, 3);

    cout << "Shaping part decorator .... " << endl;
    Circle circle{5};
    cout << circle.str() << endl;
    ColoredShape red_circle { circle, "red"};
    cout << red_circle.str() << endl;

    TransparentShape half_transparent_circle {circle, 128};
    cout << half_transparent_circle.str() << endl;

    TransparentShape half_transparent_red_circle {red_circle, 128};
    cout << half_transparent_red_circle.str() << endl;

    ColoredShape2<Circle> red_circle2 {"red"};
    red_circle2.radius = 5;
    cout << red_circle2.str() << endl;

//    TransparentShape2<Circle> trans_circle{128};
//    trans_circle.radius = 10;
//    cout << trans_circle.str() << endl;
//
//    TransparentShape2<ColoredShape2<Circle>> trans_red_circle{128};
//    trans_red_circle.color = "Red";
//    trans_red_circle.radius = 20;
//    cout << trans_red_circle.str() << endl;


//    struct NotAShape {
//        virtual string str() const { return string{}; }
//    };
//    ColoredShape2<NotAShape> legal;
    TransparentShape2<Square> hidden_square{0, 15};
    cout << hidden_square.str() << endl;

    return 0;
}