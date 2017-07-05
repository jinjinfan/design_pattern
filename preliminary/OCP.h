//
// Created by claudia on 2017/7/3.
//

#ifndef SPECIFICATION_PRODUCT_H
#define SPECIFICATION_PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product {
    string name;
    Color color;
    Size size;
};

template <typename T>
struct ISpecification {
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct IFilter {
    virtual vector<T*> filter(vector<T*> items, ISpecification<T>& spec) = 0;
};

struct ProductFilter : IFilter<Product> {
    typedef vector<Product*> Items;

    vector<Product*> filter(vector<Product*> items, ISpecification<Product>& spec) override {
        Items result;
        for (auto& p : items) {
            if (spec.is_satisfied(p)) {
                result.push_back(p);
            }
        }
        return result;
    }
};

struct ColorSpecification : ISpecification<Product> {
    Color color;

    ColorSpecification(Color color) : color(color) {}

    bool is_satisfied(Product *item) override {
        return item->color == color;
    }
};

struct SizeSpecification : ISpecification<Product> {
    Size size;

    SizeSpecification(Size size) : size(size) {}

    bool is_satisfied(Product *item) override {
        return item->size == size;
    }
};

template <typename T>
struct AndSpecification : ISpecification<T> {
    ISpecification<T>& first;
    ISpecification<T>& second;

    AndSpecification(ISpecification<T> &first, ISpecification<T> &second) : first(first), second(second) {}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

#endif //SPECIFICATION_PRODUCT_H
