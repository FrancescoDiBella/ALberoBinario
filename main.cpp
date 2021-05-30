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
    Nodo<int>* x = p->Search(22);
    cout << x->getKey() ;
    delete p;


    
    return 0;
}