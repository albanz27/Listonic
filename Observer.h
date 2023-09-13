#ifndef LISTONIC_OBSERVER_H
#define LISTONIC_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update() = 0;
};

#endif //LISTONIC_OBSERVER_H
