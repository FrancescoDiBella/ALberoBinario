#pragma once

template <class T>
class Nodo{
    private:
        //Chiave del Nodo, tipo T
        T key;
        //Puntatore del Nodo, punta al Nodo Sinistro
        Nodo<T>* left;
        //Puntatore del Nodo, punta al Nodo Destro
        Nodo<T>* right;
        //Puntatore del Nodo, punta al Nodo Padre
        Nodo<T>* padre;
    
    public:
        //Costruttore del Nodo, prende come argomento un oggetto di tipo Generico T
        Nodo(T x);
        ~Nodo();
        //Metodo setter per Key, prende come argomento un oggetto di tipo T
        void setKey(T x);
        //Metodo setter del puntatore Left, prende come argomento un puntatore a tipo Nodo<T>
        void setLeft(Nodo<T>* x);
        //Metodo setter del puntatore del Right, prende come argomento un puntatore al tipo Nodo<T>
        void setRight(Nodo<T>* x);
        //Metodo setter del puntatore del Padre, prende come argomento un puntatore al tipo Nodo<T>
        void setPadre(Nodo<T>* x);

        //Metodo getter di Key, restituisce un oggetto di tipo T
        T getKey() const;
         //Metodo getter di left, restituisce un puntatore a tipo Nodo<T>
        Nodo<T>* getLeft() const;
         //Metodo getter di right, restituisce un puntatore a tipo Nodo<T>
        Nodo<T>* getRight() const;
         //Metodo getter di padre, restituisce un puntatore a tipo Nodo<T>
        Nodo<T>* getPadre() const;
};