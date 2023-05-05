#include "SelfBalanceBST.h"
#include <iostream>
#include <cmath>

SelfBalanceBST::SelfBalanceBST(int num) {
    value = num;
    lDescendants = 1;
    rDescendants = 1;
    lChild = nullptr;
    rChild = nullptr;
}

int SelfBalanceBST::getValue(void) const {
    return value;
}

SelfBalanceBST* SelfBalanceBST::decideRotation(SelfBalanceBST* node) {

    //compares how many children are on the left vs the right. is positive is there are more on the right than on the left. 
    //Is greater than abs(1) if it is unbalanced in either direction
    float temp = log(node->rDescendants) / log(2) - log(node->lDescendants) / log(2);

    if(temp > 1) {
        return node->rotateL();
    }
    if(temp < -1) {
        return node->rotateR();
    }
    return node;
}

SelfBalanceBST* SelfBalanceBST::insert(int num) {
    if(num > value) {
        rDescendants++;

        if(rChild != nullptr) {
            rChild = rChild->insert(num);
        }
        else {

            SelfBalanceBST* node = new SelfBalanceBST(num);
            rChild = node;
        }

    }
    else {
        lDescendants++;
        if(lChild != nullptr) {
            lChild = lChild->insert(num);
        }
        else {
            SelfBalanceBST* node = new SelfBalanceBST(num);
            lChild = node;
        }
    }

    return decideRotation(this);
    
}

SelfBalanceBST* SelfBalanceBST::rotateL() {
    if(rChild == nullptr) {
        return this;
    }

    //adjusting descendants
    rDescendants -= rChild->rDescendants ;

    rChild->lDescendants += lDescendants;

    //shift nodes
    SelfBalanceBST* newRoot = rChild;

    rChild = newRoot->lChild;
    newRoot->lChild = this;

    return newRoot;
}

SelfBalanceBST* SelfBalanceBST::rotateR() {
    if(lChild == nullptr) {
        return this;
    }

    //adjusting descendants
    lDescendants -= lChild->lDescendants;

    lChild->rDescendants += rDescendants;

    //shift nodes
    SelfBalanceBST* newRoot = lChild;

    lChild = newRoot->rChild;
    newRoot->rChild = this;

    return newRoot;
}

void SelfBalanceBST::display(void) const {
    if(lChild != nullptr) lChild->display();
    std::cout << value << " ";
    if(rChild != nullptr) rChild->display();
}
