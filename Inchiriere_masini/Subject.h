//
// Created by gabi on 5/25/26.
//

#ifndef INCHIRIERE_MASINI_SUBJECT_H
#define INCHIRIERE_MASINI_SUBJECT_H
#include "Observer.h"
#include <vector>

using namespace std;

class Subject {
private:
    vector<Observer* > observers;
public:
    virtual ~Subject() {};

    void notifyObservers(const vector<Masina>& masini) {
        for (Observer* o: observers) {
            o->notify(masini);
        }
    }

    void registerObserver(Observer* o){
        observers.push_back(o);
    }
};


#endif //INCHIRIERE_MASINI_SUBJECT_H
