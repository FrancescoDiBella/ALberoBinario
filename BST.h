#pragma once
#include "Nodo.h"


template <class T>
class BST{
private:
//Nodo radice dell'albero
    Nodo<T>* root;
//Inorder privata
    void inorder(Nodo<T>* x);
//Metodo che permette di cambiare il sotto albero e quindi facilitare la Delete(), u è il nodo da eliminare e v è il nodo da sostituire
    void Trapianta(Nodo<T>* u, Nodo<T>* v);

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
    //Metodo di stampa inorder
    void Inorder();
    //Metodo che ricerca un nodo attraverso la sua chiave, se non è presente restituisce un puntatore null
    Nodo<T>* Search(T x) const;
    //Metodo che elimina un nodo passando il valore della chiave
    void Delete(T x);
    //Metodo che elimina un nodo passando il puntatore a tale nodo
    void Delete(Nodo<T>* x);
};
