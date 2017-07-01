#include <iostream>
#include "Expression.h"
#include <boost/accumulators/statistics.hpp>
#include <boost/accumulators/accumulators.hpp>
using namespace boost::accumulators;

#include "Geometry.h"
#include "Neuron.h"

int main() {
    std::cout << "Expression!" << std::endl;
    AdditionExpression sum {
            make_shared<Literal>(2),
            make_shared<AdditionExpression>(
                    make_shared<Literal>(3),
                    make_shared<Literal>(4)
            )
    };
    cout << "2 + (3+4) = " << sum.eval() <<endl;

    vector<double> v;
    sum.collect(v);
    for (auto x :v)
        cout << x << "\t";
    cout << endl;

    vector<double> values{1,2,3,4};
    double s = 0;
    for (auto x : values) s += x;
    cout << "Average is " << s/values.size() << endl;

    accumulator_set<double, stats<tag::mean>> acc;
    for (auto x : values) acc(x);
    cout << "average is " << mean(acc) << endl;

    std::cout << "Geometry!" << std::endl;
    Group root("root");
    Circle c1, c2;
    root.object.push_back(&c1);

    Group subgroup("sub");
    subgroup.object.push_back(&c2);
    root.object.push_back(&subgroup);

    root.draw();

    std::cout << "Neuron!" << std::endl;
    Neuron n1, n2;
    n1.connect_to(n2);
    cout << n1 << n2 << endl;

    NeuronLayer l1{5};
    Neuron n3;
    l1.connect_to(n3);

    cout << "Neuron " << n3.id << endl << n3 << endl;
    cout << "Layer " << endl << l1 << endl;

    NeuronLayer l2{2};
    NeuronLayer l3{3};
    l2.connect_to(l3);
    cout << "Layer l2" << endl <<l2;
    cout << "Layer l3" << endl <<l3;
    return 0;
}

