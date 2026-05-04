#pragma once
#include <vector>
#include <exception>
#include "IteratorLDI.h"

#define NULL_INDEX -1

using namespace std;

template <typename T> class IteratorLDI;
template <typename T> class LDI {
    friend class IteratorLDI<T>;
private:
    struct Node {
        T val;
        int prev;
        int next;
        Node(): val(T()), prev(NULL_INDEX), next(NULL_INDEX) {}
        Node(T v, int p = NULL_INDEX, int n = NULL_INDEX): val(v), prev(p), next(n) {}
    };

    std::vector<Node> nodes;
    int head;
    int tail;
    int firstFree;
    int capacity;
    int sz;

    void ensureCapacity() {
        if ((int)nodes.size() == capacity) {
            int oldCap = capacity;
            int newCap = capacity == 0 ? 4 : capacity * 2;
            nodes.resize(newCap);

            for (int i = oldCap; i < newCap; ++i) {
                nodes[i].next = (i + 1 < newCap) ? (i + 1) : firstFree;
                nodes[i].prev = NULL_INDEX;
            }
            firstFree = oldCap;
            capacity = newCap;
        }
    }

    int allocateNode(const T& v) {
        ensureCapacity();
        int idx = firstFree;
        firstFree = nodes[idx].next;
        nodes[idx].val = v;
        nodes[idx].prev = NULL_INDEX;
        nodes[idx].next = NULL_INDEX;
        sz++;
        return idx;
    }

    void freeNode(int idx) {
        nodes[idx].next = firstFree;
        nodes[idx].prev = NULL_INDEX;
        firstFree = idx;
        sz--;
    }

public:
    LDI() : nodes(), head(NULL_INDEX), tail(NULL_INDEX), firstFree(NULL_INDEX), capacity(0), sz(0) {
        ensureCapacity();
    }

    virtual ~LDI() {

    }

    bool adauga(T elem) {
        int idx = allocateNode(elem);
        if (head == NULL_INDEX) {
            head = tail = idx;
        } else {
            nodes[idx].prev = tail;
            nodes[tail].next = idx;
            tail = idx;
        }
        return true;
    }

    bool sterge(T elem) {
        int cur = head;
        while (cur != NULL_INDEX) {
            if (nodes[cur].val == elem) {
                int p = nodes[cur].prev;
                int n = nodes[cur].next;
                if (p != NULL_INDEX) nodes[p].next = n; else head = n;
                if (n != NULL_INDEX) nodes[n].prev = p; else tail = p;
                freeNode(cur);
                return true;
            }
            cur = nodes[cur].next;
        }
        return false;
    }

    bool cauta(T elem) const {
        int cur = head;
        while (cur != NULL_INDEX) {
            if (nodes[cur].val == elem) return true;
            cur = nodes[cur].next;
        }
        return false;
    }

    int dim() const { return sz; }
    bool vida() const { return sz == 0; }

    IteratorLDI<T> iterator() const {
        return IteratorLDI<T>(*this);
    }

    bool operator == (const LDI<T>& other) const {
        if (this->sz != other.sz) return false;
        int c1 = this->head;
        int c2 = other.head;
        while (c1 != NULL_INDEX && c2 != NULL_INDEX) {
            if (this->nodes[c1].val != other.nodes[c2].val) return false;
            c1 = this->nodes[c1].next;
            c2 = other.nodes[c2].next;
        }
        return c1 == NULL_INDEX && c2 == NULL_INDEX;
    }
};
