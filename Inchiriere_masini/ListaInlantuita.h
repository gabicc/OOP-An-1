//
// Created by gabi on 4/5/26.
//

#ifndef INCHIRIERE_MASINI_LISTAINLANTUITA_H
#define INCHIRIERE_MASINI_LISTAINLANTUITA_H
#include <cstddef>

template <typename T>  class Node {
private:
    T val;
    Node* next;
public:
    Node(T valoare, Node* urm): val(valoare), next(urm){}
    virtual ~Node(){}
    T getVal() {
        return this->val;
    }
    Node* getNext() {
        return this->next;
    }

    void setNext(Node* newNext) {
        this->next = newNext;
    }

    void setVal(T newVal) {
        this->val = newVal;
    }
};

template <typename TT> class ListaInlantuita {
private:
    Node<TT>* head;
    int lung;
public:
    ListaInlantuita() {
        head = NULL;
        lung = 0;
    }
    ~ListaInlantuita() {
        Node<TT>* curent = head;
        while (curent != NULL) {
            Node<TT>* next = curent->getNext();
            delete curent;
            curent = next;
        }
    }
    ListaInlantuita(const ListaInlantuita& other):head(NULL) {
        Node<TT>* curent = other.head;
        while (curent != NULL) {
            add(curent->getVal());
            curent = curent->getNext();
        }
    }
    void add(const TT &val) {
        Node<TT>* newNode = new Node<TT>(val, head);
        head = newNode;
        lung++;
    }
    void remove(const TT& val) {
        Node<TT>* curent = head;
        Node<TT>* prev = NULL;
        while (curent != NULL) {
            Node<TT>* copy = curent;
            if (curent->getVal() == val) {
                if (prev == NULL) {
                    head = curent->getNext();
                    delete curent;
                    curent = head;
                }
                else if (curent->getNext() == NULL) {
                    prev->setNext(NULL);
                    delete curent;
                    curent = NULL;
                }
                else {
                    prev->setNext(curent->getNext());
                    delete curent;
                    curent = prev->getNext();
                }
                lung--;
            }
            else {
                prev = curent;
                curent = curent->getNext();
            }
        }
    }

    void change(const TT& val, const TT& newValue) {
        Node<TT>* curent = head;
        while (curent != NULL) {
            if (curent->getVal() == val) {
                curent->setVal(newValue);
            }
            curent = curent->getNext();
        }
    }

    int getLung() {
        return this->lung;
    }

    Node<TT>* getHead() {
        return head;
    }
    bool find(const TT& m) {
        Node<TT>* curent = head;
        while (curent != NULL) {
            if (curent->getVal() == m) {
                return true;
            }
            curent = curent->getNext();
        }
        return false;
    }
};



#endif //INCHIRIERE_MASINI_LISTAINLANTUITA_H
