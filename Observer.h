#ifndef LISTONIC_OBSERVER_H
#define LISTONIC_OBSERVER_H

class Observer {
public:
    virtual ~Observer()=default;

    virtual void update(const string &oggetti) = 0;
};

#endif //LISTONIC_OBSERVER_H