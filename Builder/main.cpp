#include <iostream>
#include "HTMLBuilder.h"
#include "GroovyStyle.h"
#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main() {
    std::cout << "Normal builder pattern" << std::endl;
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello").add_child("li", "world");
    cout<< builder.str()<<endl;

    std::cout << "Fluent builder pattern" << std::endl;
    HtmlElement e = HtmlElement::build("ul").add_child("li", "hello");
    cout<< e.str()<<endl;

    HtmlElement ee = HtmlElement::create("ul")->add_child("li", "world");
    cout<< ee.str()<<endl;

    std::cout << "Groovy style builder pattern" << std::endl;
    cout << P {
            IMG {"http://a.com/b.png"}
    } << endl;

    std::cout << "Builder facets" << std::endl;
    Person p = Person::create()
            .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
            .works().at("PragmaSoft").as_a("Consultant").earning(10e6);
    cout << p << endl;
    return 0;
}

