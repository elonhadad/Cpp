//
// Created by ELON HADAD on 15/12/2022.
//

#ifndef EX_04_POPULATION_H
#define EX_04_POPULATION_H
#include "Virus.h"
#include "Queue.h"

class Population {
public:
    explicit Population();                                  // default constructor.
    Population(const Population& p);                        // copy constructor.
    Population& operator=(const Population& p);             // copy assignment operator.
    ~Population();                                          // destructor.

    /**
     * insert copy of first element in population,
     * and remove the last (used for group update).
     * @param x - unused (just for postfix).
     */
    void operator++(__attribute__((unused)) int x);

    /**
     * open new population and call to operator* from Virus,
     * then insert the elements to new population.
     * and finally copy the new population to this.
     */
    Population& Individual_update();

    Queue<Virus> *getQueue() const;

private:
    Queue<Virus>* queue;
    bool flag;
};

#endif //EX_04_POPULATION_H