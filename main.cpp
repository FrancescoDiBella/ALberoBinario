#include "BST.h"

#include <iostream>

int main(){
    BST<int> p;
    p.Insert(5);
    p.Insert(2);
    p.Insert(9);
    p.Insert(7);
    p.Insert(10);
    p.Insert(0);
    p.Insert(3);

    p.inorder();
    return 0;
}