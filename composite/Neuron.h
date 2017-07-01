//
// Created by claudia on 2017/6/30.
//

#ifndef COMPOSITE_NEURON_H
#define COMPOSITE_NEURON_H
#include <vector>
#include <iostream>
using namespace std;

struct Neuron {
    int id;
    vector<Neuron*> in,out;
    Neuron() {
        static int id = 1;
        this->id = id++;
    }
    void connect_to(Neuron& other) {
        out.push_back(&other);
        other.in.push_back(this);
    }

    Neuron* begin() { return this; }
    Neuron* end() { return this+1; }
    template <typename T>
    void connect_to(T &other) {
        for (Neuron& target : other) {
            connect_to(target);
        }
    }
    friend ostream& operator<<(ostream& os, const Neuron& obj){
        for (Neuron* n :obj.in) {
            os << n->id << "\t==>\t[" << obj.id << "]" << endl;
        }
        for (Neuron* n :obj.out) {
            os << "[" << obj.id << "]\t==>\t" << n->id << endl;
        }
        return os;
    }
};

struct NeuronLayer : vector<Neuron> {
    NeuronLayer(int count) {
        while (count-- >0) {
            emplace_back(Neuron{});
        }
    }

    friend ostream & operator<<(ostream &os, const NeuronLayer &layer) {
        for(auto& n : layer) os << n;
        return os;
    }

    template <typename T> void connect_to(T& other) {
        for (Neuron& from : *this) {
            for (Neuron& to : other)
                from.connect_to(to);
        }
    }
};

#endif //COMPOSITE_NEURON_H
