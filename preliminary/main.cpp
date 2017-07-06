#include <iostream>
#include "OCP.h"
#include "LSP.h"
#include "ISP.h"
#include "DI.h"

void process(Rectangle& r) {
    int w = r.getWidth();
    r.setHeight(10);
    std::cout << " Expected area = " << (w * 10) << ", got " << r.Area() << std::endl;
}

int main() {
    std::cout << "Open close principle!" << std::endl;
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

    std::cout << "Liskov Substitution principle!" << std::endl;

    Rectangle r {5,5};
    process(r);

    Square s {5};
    process(s);

    std::cout << "Normal injection" << std::endl;
    auto e = std::make_shared<Engine>();
    auto log = std::make_shared<Logger>();
    auto c = std::make_shared<Car>(e, log);
    std::cout << *c << std::endl;
    std::cout << std::endl;
    std::cout << "Boost DI injection" << std::endl;
    using namespace boost;
    auto injector = di::make_injector(
            di::bind<ILogger>().to<Logger>()
    );
    auto c1 = injector.create<std::shared_ptr<Car>>();
    std::cout << *c1 << std::endl;
    return 0;
    return 0;
}
