#include "Nodo.h"
#include <iostream>

template <class T>
Nodo<T>::Nodo(T x) : key(x), left(NULL), right(NULL), padre(NULL) {;}

template <class T>
Nodo<T>::Nodo() : left(NULL), right(NULL), padre(NULL) {;}


template <class T>
Nodo<T>::~Nodo(){;}

template <class T>
void Nodo<T>::setKey(T x){
    this->key = x;
}

template <class T>
void Nodo<T>::setLeft(Nodo<T>* x){
    this->left = x;
}

template <class T>
void Nodo<T>::setRight(Nodo<T>* x){
    this->right = x;
}

template <class T>
void Nodo<T>::setPadre(Nodo<T>*  x){
    this->padre = x;
}

template <class T>
T Nodo<T>::getKey() const{
    return this->key;
}

template <class T>
Nodo<T> * Nodo<T>::getLeft()const{
    return this->left;
}

template <class T>
Nodo<T> * Nodo<T>::getRight() const{
    return this->right;
}

template <class T>
Nodo<T>* Nodo<T>::getPadre() const{
    return this->padre;
}


