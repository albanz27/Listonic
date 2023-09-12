#ifndef LISTONIC_SUBJECT_H
#define LISTONIC_SUBJECT_H

#include "Observer.h"
#include "list"
using namespace std;

class Subject {
protected:
    list<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.remove(observer);
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

#endif //LISTONIC_SUBJECT_H
