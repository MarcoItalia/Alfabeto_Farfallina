
/* Implementazione lista concatenata semplice:

- inserimento in testa
- inserimento in posto determinato
- inserimento in coda
- ricerca
- rimozione
*/

#include <iostream>
using namespace std;

class Nodo{
public:
    int valore;
    Nodo* succ;
    Nodo* prec;
};

class Lista{
Nodo* testa;
public:
    Lista() {testa=nullptr;}
    ~Lista();
    Nodo* getTesta() {return testa;}

    // inserimento in testa
    void inserisci(int val);
    void inserisci(Nodo* precedente, int val);
    void inserisci_in_coda(int val);

    Nodo* ricerca(int val);
    void rimuovi(int val);

    friend ostream& operator<<(ostream& out, const Lista& ls);
};

Lista::~Lista(){
    Nodo* iter = this->testa;

    while(iter!=nullptr){
        Nodo* temp = iter->succ;
        delete iter;
        iter = temp;
    }
}

ostream& operator<<(ostream& out, const Lista& ls){
    Nodo* iter=ls.testa; //get testa
    while(iter!=nullptr){
        if(iter->prec==nullptr)
            out << "NULL <-- ";
        else
            out << iter->prec->valore << " <-- ";
        out << iter->valore << endl;
      /*  if(iter->succ)
            out<< iter->succ->valore << endl;*/
        iter = iter->succ;
    }
    out << "NULL" << endl;
    return out;
}


void Lista::inserisci(int val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->prec=nullptr;
    nuovo->succ = this->testa;
    if(this->testa)
        this->testa->prec=nuovo;

    this->testa = nuovo;
}
// TODO: eliminare il parametro 'seguente'
void Lista::inserisci(Nodo* precedente, int val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->succ=precedente->succ;
    precedente->succ = nuovo;
}

void Lista::inserisci_in_coda(int val){
    Nodo* nuovo = new Nodo;
    Nodo* iter = this->testa;

    nuovo->valore = val;

    if(this->testa == nullptr){
        nuovo->succ = nullptr;
        this->testa = nuovo;
    }
    else{
        while(iter->succ!=nullptr)
            iter = iter->succ;
        iter->succ=nuovo;
        nuovo->succ=nullptr;

    }

}

Nodo* Lista::ricerca(int val){
    Nodo *p;

    for(p=this->testa;p!=nullptr;p = p->succ)
        if(p->valore==val)
            return p;

    return nullptr;
}

void Lista::rimuovi(int val){

    Nodo* prec;
    Nodo* current;

    if(this->testa == nullptr)
        cout << "Lista vuota: impossibile rimuovere elementi."<<endl;
    else if(this->testa->valore == val){
        prec = this->testa;
        this->testa = this->testa->succ;
        delete prec;
    }
    else{
        prec = this->testa;
        current = this->testa->succ;
        while((current!=nullptr)&&(current->valore!= val)){
            prec = prec->succ;
            current = current->succ;
        }

        if(current!=nullptr){
            prec->succ = current->succ;
            delete current;
        }
        else
            cout << "Elemento non presente nella lista." << endl;

    }
}


int main(){

    Lista lista;
    
    lista.inserisci(20);
    lista.inserisci(15);
    lista.inserisci(10);
    lista.inserisci(5);

    cout<< lista;
    
return 0;
}



