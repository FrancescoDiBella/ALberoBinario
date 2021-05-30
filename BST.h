#ifndef ALBERBINARIO_BST_H
#define ALBERBINARIO_BST_H

#include "Nodo.h"
#include <iostream>

template <class T>
class BST{
private:
//Nodo radice dell'albero
    Nodo<T>* root;
//Inorder privata
    void inorder(Nodo<T>* x);
public:
// Costruttore che permette di inizializzare la root del BST
    BST(T x); 
//Costruttore che crea un BST vuoto, cioè root==NULL
    BST(); 
    ~BST();
//Restituisce la root
    Nodo<T>* getRoot() const;
//Permette di settare la chiave di root
    void setRoot(Nodo<T>* x);
    //Metodo che permette di inserire un nuovo elemento nell'albero passando una chiave
    void Insert(T x); 
    //Metodo che permette di inserire un nuovo elemento nell'albero passando direttamente un nodo
    void Insert(Nodo<T>* x); 
    //Metodo di stampa inOrder
    void inorder();
};

#endif