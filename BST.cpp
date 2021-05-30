#include "BST.h"
#include <iostream> 

template <class T> 
BST<T>::BST(T x){
    root = new Nodo<T>(x);
}

template <class T> 
BST<T>::BST(){
    root = NULL;
}

template <class T> 
Nodo<T>* BST<T>::getRoot() const {
    return this->root;
}

template <class T> 
void BST<T>::setRoot(Nodo<T>* x){
    this->root= x;
}

template <class T> 
//Ogni nuovo nodo aggiunto è sempre una fogla ----> left & right == NULL
void BST<T>::Insert(T l){

    Nodo<T>* nuovo = new Nodo<T>(l);//Nodo da aggiungere
    Nodo<T>* x = this->getRoot(); //Nodo Iteratore
    Nodo<T>* y = NULL;//NOdo risultato

    //il ciclo while determina il padre del nuovo nodo
    while(x!=NULL){
        y = x;
        if( l <= x->getKey() ) x = x->getRight();
        else x = x->getLeft();
    }

    //settato il padre
    nuovo->setPadre(y);
    //settare nuovo come figlio destro o sinistro di y
    if(y==NULL) this->setRoot(nuovo);
    else if(nuovo->getKey() <= y->getKey() ) y->setLeft(nuovo);
    else y->setRight(nuovo);
}

template <class T> 
void BST<T>::Insert(Nodo<T>* l){
    if(l==NULL) {
        std::cout << "Errore, passare un nodo non NULL.\n";
        return;
    }

    Nodo<T>* x = this->getRoot(); //Nodo Iteratore
    Nodo<T>* y = NULL;//NOdo risultato

    //il ciclo while determina il padre del nuovo nodo
    while(x!=NULL){
        y = x;
        if( l->getKey() <= x->getKey() ) x = x->getRight();
        else x = x->getLeft();
    }
    
    //settato il padre
    l->setPadre(y);
    //settare nuovo come figlio destro o sinistro di y
    if(y==NULL) this->setRoot(l);
    else if(l->getKey() <= y->getKey() ) y->setLeft(l);
    else y->setRight(l);
}

template <class T>
void BST<T>::inorder(){
    Nodo<T>* x = this->getRoot();
    inorder(root);
}


template <class T>
void BST<T>::inorder(Nodo<T>* x){
    if(x){
        inorder(x->getLeft());
        std::cout << x->getKey();
        inorder(x->getRight());
    }
}


