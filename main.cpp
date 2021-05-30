#include "BST.h"

#include <iostream>
using namespace std;

int main(){
    BST<int>* p = new BST<int> ;
    p->Insert(5);
    p->Insert(2);
    p->Insert(9);
    p->Insert(7);
    p->Insert(10);
    p->Insert(0);
    p->Insert(3);

    p->inorder();
    delete p;
    return 0;
}