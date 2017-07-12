#include <iostream>
#include "SingletonDatabase.h"


int main() {
    std::cout << "Singleton instance count!" << std::endl;
    auto& db = SingletonDatabase::get();
    auto& db2 = SingletonDatabase::get();
    cout << "db instance count " << db.instance_count << endl;
    cout << "db2 instance count " << db2.instance_count << endl;

    std::cout << "Singleton database!" << std::endl;
    SingletonRecordFinder rf;
    int result = rf.total_population(vector<string>{"Seoul","Mexico City"});
    cout << "Population of Seoul and Mexico City: " << result << endl;

    std::cout << "Configurable database!" << std::endl;
    DummyDatabase dummyDatabase;
    ConfigurableRecordFinder recordFinder(dummyDatabase);
    int result1 = recordFinder.total_population(vector<string>{"alpha","gamma"});
    cout << "Population of Alpha and gamma: " << result1 << endl;
    return 0;
}