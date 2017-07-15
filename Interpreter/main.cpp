#include <iostream>
#include "Interpreter.h"
#include "OverMath.h"

int main() {
    string input {"(13-4)-(12+1)"};
    auto tokens = lex(input);
    for(auto& token:tokens) {
        cout << '~' << token << "~" <<"    "<< endl;
    }
    cout << endl;
    auto parsed = parse(tokens);
    cout << input << " = " << parsed->eval() << endl;

    wstring a{L"void f() {}"};
    auto res = overmath::parse(a.begin(), a.end());
    return 0;
}