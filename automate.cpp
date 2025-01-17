#include "automate.h"
#include "etat.h"
#include <iostream>
#include "lexer.h"
using namespace std;

Automate::Automate(Lexer & l) {
    symbolestack = deque<Symbole *>();
    statestack = deque<Etat *>();
    lexer = &l;
}

Automate::~Automate() {

}

Symbole * Automate::popSymbol() {
    Symbole * s = symbolestack.back();
    symbolestack.pop_back();
    return s;
}        

void Automate::popAndDestroySymbol() {
    Symbole * s = symbolestack.back();
    symbolestack.pop_back();
    delete(s);
}

void Automate::pushState(Etat * e) {
    statestack.push_back(e);
}

void Automate::pushSymbol(Symbole * s) {
    symbolestack.push_back(s);
}


void Automate::decalage(Symbole * s, Etat * e) { 
    symbolestack.push_back(s);
    statestack.push_back(e); 
    if (s->isTerminal()) { 
        lexer->Avancer(); 
    } 

}

bool Automate::reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        delete(statestack.back());
        statestack.pop_back();
    }

    afficherEtats();
    afficherSymboles();

    statestack.back()->Transition(*this, new NonTerminal("E"));
    return statestack.back()->Transition(*this, s);
}

bool Automate::recognize() {
    Symbole * s;

    // Initialisation
    statestack.push_back(new E0);

    // Exécution de l'automate
    while(*(s=lexer->Consulter())!=FIN) {
        statestack.back()->Transition(*this, s);
   }
   return statestack.back()->Transition(*this, s);
}


void Automate::afficherSymboles() const {
    cout << "Contenu de symbolestack : " << endl;
    for (auto symbole : symbolestack) {
        symbole->Affiche();
        cout << " ";
    }
    cout << endl;
}

void Automate::afficherEtats() const {
    cout << "Contenu de statestack : " << endl;
    for (auto etat : statestack) {
        etat->Affiche();
        cout << " ";
    }
    cout << endl;
}
