//
// Created by claudia on 2017/7/15.
//

#ifndef ITERATOR_BINARYTREE_H
#define ITERATOR_BINARYTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

template <typename T> struct BinaryTree;

template <typename T> struct Node {
    T value = T();
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
    Node<T>* parent = nullptr;
    BinaryTree<T>* tree = nullptr;

    explicit Node(T value) : value(value) {}

    Node(T value, Node *left, Node *right)
            : value(value), left(left), right(right) {
        this->left->tree = this->right->tree = tree;
        this->left->parent = this->right->parent = this;
    }

    void set_tree(BinaryTree<T>* t) {
        tree = t;
        if(left) left->set_tree(t);
        if(right) right->set_tree(t);
    }

    virtual ~Node() {
        if(left) delete left;
        if(right) delete right;
    }
};

template <typename T>
struct BinaryTree {
    Node<T>* root = nullptr;

    explicit BinaryTree(Node<T> *root) : root(root) {}

    virtual ~BinaryTree() {
        if (root) delete root;
    }

    template <typename U> struct BinaryTreeIterator {
        Node<U>* current;

        explicit BinaryTreeIterator(Node<U> *current) : current(current) {}
        bool operator!=(const BinaryTreeIterator& other) {
            return current != other.current;
        }
        BinaryTreeIterator<U>& operator++(){
            if (current->right) {
                current = current->right;
                while (current->left)
                    current = current->left;
            }
            else {
                Node<T>* p = current->parent;
                while (p && current== p->right) {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }
        Node<U>& operator*() { return *current; }
    };
    typedef BinaryTreeIterator<T> iterator;

    iterator end() {
        return iterator{nullptr};
    }

    iterator begin() {
        Node<T>* n = root;
        if (n)
            while(n->left)
                n = n->left;
        return iterator{n};
    }
};
#endif //ITERATOR_BINARYTREE_H
