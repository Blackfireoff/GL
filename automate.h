#pragma once

#include "symbole.h"
#include "etat.h"
#include <string>
#include <deque>
#include "lexer.h"
using namespace std;

class Etat;

class Automate {
    public:
        Automate();
        Automate(Lexer& lexer);
        virtual ~Automate();
        Symbole * popSymbol();
        void popAndDestroySymbol();
        void pushState(Etat * e);
        void pushSymbol(Symbole * s);
        void decalage(Symbole * s, Etat * e);
        bool reduction(int n, Symbole * s);
        bool recognize();

        void afficherSymboles() const; // Pour afficher symbolestack
        void afficherEtats() const;    // Pour afficher statestack


    protected:
        deque<Symbole *> symbolestack;
        deque<Etat *> statestack;
        Lexer * lexer;
};