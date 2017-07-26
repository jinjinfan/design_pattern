//
// Created by claudia on 2017/7/24.
//

#include "Visitor.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Model.h"

struct HtmlPrinter : Visitor {
    void visit(const Paragraph &p) override {
        oss << "<p>" << p.text << "</p>\n";
    }

    void visit(const ListItem &p) override {
        oss << "<li>" << p.text << "</li>\n";
    }

    void visit(const List &p) override {
        oss << "<ul>\n";
        for(auto x : p){
            x.accept(*this);
        }
        oss << "</ul>\n";
    }

    string str() const override {
        return oss.str();
    }

private:
    ostringstream oss;
};

void visitor() {
    Paragraph p{"Here are some colors:"};
    ListItem red{"Red"};
    ListItem green{"Green"};
    ListItem blue{"Blue"};
    List colors{ red, green, blue};
    vector<Element*> document {&p, &colors};
    HtmlPrinter pr;
    for(auto&x : document){
        x->accept(pr);
    }
    cout << pr.str()<<endl;
}