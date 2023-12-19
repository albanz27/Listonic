#ifndef LISTONIC_SUBJECT_H
#define LISTONIC_SUBJECT_H

#include "Observer.h"
#include "list"
using namespace std;

class Subject {
public:
    virtual ~Subject() = default;

    virtual void addObserver(Observer* observer) = 0;

    virtual void removeObserver(Observer* observer) = 0;

    virtual void notify() = 0;
};

#endif //LISTONIC_SUBJECT_H
