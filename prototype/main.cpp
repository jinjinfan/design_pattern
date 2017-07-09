#include <iostream>
#include "Contact.h"

int main() {
    cout << "Prototype" << endl;
    Contact employee{"", new Address{"123 Dr", "London", 0}};
    Contact jane{employee};
    jane.work_address->suite = 100;
    Contact john{employee};
    john.work_address->suite = 123;
    cout << jane << endl << john << endl;

    cout << endl;

    cout << "Prototype factory" << endl;
    auto john1 = EmployeeFactory::NewMainOfficeEmployee("John", 100);
    auto jane1 = EmployeeFactory::NewAuxOfficeEmployee("Jane", 123);
    cout << *jane1 << endl << *john1 << endl;

    return 0;
}