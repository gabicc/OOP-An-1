//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAUML_1_ASIB_H
#define DIAGRAMAUML_1_ASIB_H

#include <iostream>
#include <vector>

class A {
public:
    A() {
        std::cout << "A\n";
    }
    virtual ~A() {
        std::cout<<"~A\n";
    }
    virtual void print() {
        std::cout << "printA\n";
    }
    void print2() {
        std::cout << "printA22\n";
    }
    virtual void print333() = 0;
};


class B: public A {
public:
    B() {
        std::cout << "B\n";
    }
    virtual ~B() {
        std::cout<<"~B\n";
    }
    virtual void print() {
        std::cout << "printB\n";
    }
    void print2() {
        std::cout << "printB22\n";
    }
    virtual void print333() {
        std::cout << "BBB333\n";
    }
};
class C: public A {
public:
    C() {
        std::cout << "C\n";
    }
    virtual ~C() {
        std::cout<<"~C\n";
    }
    virtual void print333() override {
        std::cout << "CCC333\n";
    }
};


#endif //DIAGRAMAUML_1_ASIB_H
