#include <iostream>
#include <sstream>
#include "Contact.h"
#include "Serialization.h"

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

    cout << "Boost serialization" << endl;

    NewContact lili;
    lili.name = "lili";
    lili.address = NewAddress{"123 East Dr", "London", 123};

    auto clone = [](NewContact c) {
        ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << c;
        string s = oss.str();
        NewContact result;
        istringstream is{s};
        boost::archive::text_iarchive ia(is);
        ia >> result;
        return result;
    };
    NewContact lucy = clone(lili);
    lucy.name = "lucy";
    lucy.address.street = "123 West Dr";

    cout << lili << endl << lucy << endl;
    return 0;
}