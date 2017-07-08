#include "Maybe.h"

void print_house_name(Person* p) {
    maybe(p).With([](auto x) {return x->address;})
            .With([](auto x) {return x->house_name;})
                    .Do([](auto x) {cout << *x << endl;});
};

int main() {
    Person p;
    p.address = new Address;
    p.address->house_name = new string("name");
    print_house_name(&p);
    delete p.address->house_name;
    delete p.address;
    return 0;
}