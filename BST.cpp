#include "BST.h"
#include "Nodo.h"
#include <iostream> 

template <class T> 
BST<T>::BST(T x){
    root = new Nodo<T>(x);
}

template <class T> 
BST<T>::~BST(){}

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
    nuovo->setPadre(NULL);
    nuovo->setLeft(NULL);
    nuovo->setRight(NULL);
    Nodo<T>* x = this->getRoot(); //Nodo Iteratore
    Nodo<T>* y = NULL;//NOdo risultato

    //il ciclo while determina il padre del nuovo nodo
    while(x!=NULL){
        y = x;
        if( l <= x->getKey() ) x = x->getLeft();
        else x = x->getRight();
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
    Nodo<T>* y = NULL;//Nodo risultato

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
void BST<T>::Inorder(){
    Nodo<T>* x = this->getRoot();
    std::cout << "Nodi dell'albero, visita inorder : [ ";
    inorder(root);
    std::cout << "]" <<std::endl;
}


template <class T>
void BST<T>::inorder(Nodo<T>* x){
    if(x!=NULL){
        inorder(x->getLeft());
        std::cout << x->getKey() << " ";
        inorder(x->getRight());
    }
}

template <class T>
void BST<T>::Trapianta(Nodo<T>* u, Nodo<T>* v){
    if(u->getPadre() == NULL)
        this->setRoot(v);
        
    else if(u == u->getPadre()->getLeft() )
        u->getPadre()->setLeft(v);
        
    else
        u->getPadre()->setRight(v);

    if(v!=NULL) v->setPadre(u->getPadre());
}

template <class T>
Nodo<T>* BST<T>::Search(T x) const{
    if(this->getRoot()->getKey() == x) return this->getRoot();

    Nodo<T>* iter = this->getRoot();

    while(iter!=NULL  && iter->getKey() != x){
       if(iter->getKey() < x) iter = iter->getRight();
       else iter = iter->getLeft();
    }

    return iter;
}

template <class T>
Nodo<T>* BST<T>::MinimumPrv(Nodo<T>* p){
    Nodo<T>* nuovo = p;

    while(nuovo->getLeft() != NULL)
        nuovo = nuovo->getLeft();

    return nuovo;
}

template <class T>
Nodo<T>* BST<T>::MaximumPrv(Nodo<T>* p){
    Nodo<T>* nuovo = p;

    while(nuovo->getRight() != NULL)
        nuovo = nuovo->getRight();

    return nuovo;
}

template <class T>
 Nodo<T>* BST<T>::Minimum(){
       return MinimumPrv(getRoot());
}

template <class T>
 Nodo<T>* BST<T>::Minimum(Nodo<T>* x){
       return MinimumPrv(x);
}

template <class T>
 Nodo<T>* BST<T>::Maximum(){
       return MaximumPrv(getRoot());
}

template <class T>
 Nodo<T>* BST<T>::Maximum(Nodo<T>* x){
       return MaximumPrv(x);
}

template <class T>
 Nodo<T>* BST<T>::getSuccesore(Nodo<T>* x){
       if(x->getRight() != NULL)
            return this->Minimum(x->getRight());

        Nodo<T>* y = x->getPadre();
        Nodo<T>* iter = x;
        while(y != NULL && iter == y->getRight()){
            iter = y;
            y = y->getPadre();
        }

        return y;
}

template <class T>
 Nodo<T>* BST<T>::getPredecessore(Nodo<T>* x){
       if(x->getLeft() != NULL)
            return this->Maximum(x->getLeft());

        Nodo<T>* y = x->getPadre();
        Nodo<T>* iter = x;
        while(y != NULL && iter == y->getLeft()){
            iter = y;
            y = y->getPadre();
        }

        return y;
}

template <class T>
void BST<T>::Delete(T x){
    Nodo<T>* nuovo = this->Search(x);

    if(nuovo->getLeft() == NULL)
        Trapianta(nuovo, nuovo->getRight());
    else if(nuovo->getRight() == NULL){
             Trapianta(nuovo, nuovo->getLeft());
    }
    else{
        Nodo<T>* y = Minimum(nuovo->getRight());
    
        if(y->getPadre() != nuovo){
            Trapianta(y, y->getRight());
            y->setRight(nuovo->getRight());
            y->getRight()->setPadre(y);
        }
        
        Trapianta(nuovo, y);
        y->setLeft(nuovo->getLeft());
        y->getLeft()->setPadre(y);
    }

    delete nuovo;
}

template <class T>
void BST<T>::Delete(Nodo<T>* nuovo){
    if(nuovo->getLeft() == NULL){
         Trapianta(nuovo, nuovo->getRight());
         
    }
       
    else if(nuovo->getRight() == NULL){
        Trapianta(nuovo, nuovo->getLeft());
    }
        
    else {
        Nodo<T>* y = Minimum(nuovo->getRight());

        if(y->getPadre() != nuovo){
            Trapianta(y, y->getPadre());
            y->setRight(nuovo->getRight());
            y->getRight()->setPadre(y);
        }

        Trapianta(nuovo, y);
        y->setLeft(nuovo->getLeft());
        y->getLeft()->setPadre(y);
    }

    delete nuovo;
}

