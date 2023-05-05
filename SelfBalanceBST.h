#ifndef SELFBALANCEBST_H
#define SELFBALANCEBST_H
class SelfBalanceBST {
    private:
        int value;
        int lDescendants;
        int rDescendants;
        SelfBalanceBST* lChild;
        SelfBalanceBST* rChild;

        SelfBalanceBST* decideRotation(SelfBalanceBST* node);
        SelfBalanceBST* rotateL();
        SelfBalanceBST* rotateR();

    public:
        SelfBalanceBST(int num);

        SelfBalanceBST* insert (int num);
        int getValue (void) const;
        bool removeNum (int num);

        void display(void) const;

        

};
#endif