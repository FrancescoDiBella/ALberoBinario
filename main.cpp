#include "BST.h"
#include "BST.cpp"
#include "Nodo.h"
#include "Nodo.cpp"
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

    p->Inorder();
    Nodo<int>* xx  = p->Search(7);
    p->Delete(xx);
    p->Delete(0);
    p->Delete(10);
    p->Delete(5);
    cout << p->getRoot()->getKey() ;
    p->Inorder();

    delete p;


    return 0;
}