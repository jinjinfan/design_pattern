#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#include <boost/algorithm/string.hpp>
#include "Geometry.h"

vector<shared_ptr<VectorObject>> vectorObject {
    make_shared<VectorRectangle>(10, 10, 100, 100),
    make_shared<VectorRectangle>(30, 30, 60, 60)
};

class MyString {
    string s;
public:
    MyString(const string &s) : s(s) {}
    MyString to_lower() const {
        string ss{s};
        boost::to_lower(ss);
        return {ss};
    }
    vector<string> split(const string& delimiter = " ") const {
        vector<string> result;
        boost::split(result, s, boost::is_any_of(delimiter), boost::token_compress_on);
        return result;
    }
};

void DrawPoints(vector<Point>::iterator begin, vector<Point>::iterator end) {
    for (auto i = begin; i != end; ++i) {
        cout << "(" << i->x << ", " << i->y << ")";
    }

}

void DrawRectangle() {
    for (auto& o : vectorObject) {
        for (auto& l : *o) {
            LineToPointAdapter lpo{l};
            DrawPoints(lpo.begin(), lpo.end());
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    MyString s{"Hello     World"};
    auto parts = s.to_lower().split();
    for (const auto& p : parts)
        cout<< "<" << p << ">" << endl;
    DrawRectangle();
    return 0;
}