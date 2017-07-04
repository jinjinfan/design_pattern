#include <iostream>
#include "Product.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Product apple{"apple", Color::Green, Size::Small};
    Product tree{"tree", Color::Green, Size::Large};
    Product house{"house", Color::Blue, Size::Large};
    vector<Product*> all{&apple, &tree, &house};

    ProductFilter bf;
    ColorSpecification green{Color::Green};
    auto green_things = bf.filter(all, green);
    for (auto& p : green_things)
        cout << p->name << " is green "<< endl;

    SizeSpecification large{Size::Large};
    AndSpecification<Product> green_large{green, large};
    auto green_large_things =bf.filter(all, green_large);
    for (auto& p : green_large_things)
        cout << p->name << " is green and large "<< endl;
    return 0;
}