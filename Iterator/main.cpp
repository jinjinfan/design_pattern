#include <iostream>
#include "BinaryTree.h"
#include "SingleList.h"

int main() {
    std::cout << "Binary tree iterator!" << std::endl;
    BinaryTree<string> family {
            new Node<string>{"me",
                new Node<string> { "mother",
                    new Node<string>{"grandmother"},
                    new Node<string>{"grandfather"}
                },
                new Node<string> { "father"}
            }
    };
    for (auto it = family.begin(); it!= family.end(); ++it)
        cout << (*it).value << endl;

    std::cout << "Single list iterator!" << std::endl;
    NodeSingle alpha{"alpha"};
    NodeSingle beta{"beta", &alpha};
    NodeSingle gama{"gama", &beta};
    for_each(ListIterator{&alpha}, ListIterator{},
    [](const NodeSingle& node){
        cout << node.value << endl;
    });
    return 0;
}