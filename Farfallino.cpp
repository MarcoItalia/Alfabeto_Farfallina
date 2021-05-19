
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
};

class ListaSemplice{
Nodo* testa;
public:
    ListaSemplice() {testa=nullptr;}
    ~ListaSemplice();
    Nodo* getTesta() {return testa;}

    // inserimento in testa
    void inserisci(int val);
    void inserisci(Nodo* precedente, Nodo* seguente, int val);
    void inserisci_in_coda(int val);

    Nodo* ricerca(int val);
    void rimuovi(int val);

    friend
    ostream& operator<<(ostream& out, const ListaSemplice& ls);
};

ListaSemplice::~ListaSemplice(){
    Nodo* iter = this->testa;

    while(iter!=nullptr){
        Nodo* temp = iter->succ;
        delete iter;
        iter = temp;
    }
}

ostream& operator<<(ostream& out, const ListaSemplice& ls){
    Nodo* iter=ls.testa;
    while(iter!=nullptr){
        out << iter->valore << " --> ";
        iter = iter->succ;
    }
    out << "NULL" << endl;
    return out;
}


void ListaSemplice::inserisci(int val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->succ = this->testa;
    this->testa = nuovo;
}
// TODO: eliminare il parametro 'seguente'
void ListaSemplice::inserisci(Nodo* precedente, Nodo* seguente, int val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->succ=seguente;
    precedente->succ = nuovo;
}

void ListaSemplice::inserisci_in_coda(int val){
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

Nodo* ListaSemplice::ricerca(int val){
    Nodo *p;

    for(p=this->testa;p!=nullptr;p = p->succ)
        if(p->valore==val)
            return p;

    return nullptr;
}

void ListaSemplice::rimuovi(int val){

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

    ListaSemplice lista;
    lista.inserisci(20);
    lista.inserisci(10);
    lista.inserisci(5);

    cout << lista;

    int x;
    cout << "Inserisci un numero da inserire dopo il 10: ";
    cin >> x;

    Nodo* p;
    p = lista.ricerca(10);
    if(p!=nullptr)
        lista.inserisci(p,p->succ,x);
    cout << lista;


    cout << "Inserisco tre elementi in coda..." << endl;
    for(int i=0;i<3;i++){
        cout << "Inserisci un elemento (in coda): ";
        cin >> x;
        lista.inserisci_in_coda(x);
        cout << lista;
    }

    cout << "Inserisci un elemento da eliminare: ";
    cin >> x;
    lista.rimuovi(x);
    cout << lista;

return 0;
}



