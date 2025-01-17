#include "etat.h"
#include <iostream>

void Etat::Affiche() const {
    cout << "Etat " << name << endl;
}

bool Etat::Transition(Automate & automate, Symbole * s) {
    return false;
}

bool E0::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case NON_TERMINAL:
            automate.pushState(new E1);
            break;
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E1::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            return true;
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E2::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case NON_TERMINAL:
            automate.pushState(new E6);
            break;
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E3::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case PLUS:
            automate.pushSymbol(automate.popSymbol());
            return automate.reduction(1, s);
        case MULT:
            automate.pushSymbol(automate.popSymbol());
            return automate.reduction(1, s);
        case CLOSEPAR:
            automate.pushSymbol(automate.popSymbol());
            return automate.reduction(1, s);
        case FIN:
            automate.pushSymbol(automate.popSymbol());
            return automate.reduction(1, s);
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E4::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case NON_TERMINAL:
            automate.pushState(new E7);
            break;
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E5::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case NON_TERMINAL:
            automate.pushState(new E8);
            break;
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E6::Transition(Automate & automate, Symbole * s) {
    switch(* s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E7::Transition(Automate & automate, Symbole * s) {
    Symbole s1, s2;
    switch(* s) {
        case PLUS:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()+s2.GetValeur()));
            return automate.reduction(3, s);
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()+s2.GetValeur()));
            return automate.reduction(3, s);
        case FIN:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()+s2.GetValeur()));
            return automate.reduction(3, s);
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E8::Transition(Automate & automate, Symbole * s) {
    Symbole s1, s2;
    switch(* s) {
        case PLUS:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()*s2.GetValeur()));
            return automate.reduction(3, s);
        case MULT:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()*s2.GetValeur()));
            return automate.reduction(3, s);
        case CLOSEPAR:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()*s2.GetValeur()));
            return automate.reduction(3, s);
        case FIN:
            s1 = *automate.popSymbol();
            automate.popAndDestroySymbol();
            s2 = *automate.popSymbol();
            automate.pushSymbol(new Entier(s1.GetValeur()*s2.GetValeur()));
            return automate.reduction(3, s);
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}

bool E9::Transition(Automate & automate, Symbole * s) {
    Symbole * s1;
    switch(* s) {
        case PLUS:
            automate.popAndDestroySymbol();
            s1 = automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.pushSymbol(s1);
            return automate.reduction(3, s);
        case MULT:
            automate.popAndDestroySymbol();
            s1 = automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.pushSymbol(s1);
            return automate.reduction(3, s);
        case CLOSEPAR:
            automate.popAndDestroySymbol();
            s1 = automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.pushSymbol(s1);
            return automate.reduction(3, s);
        case FIN:
            automate.popAndDestroySymbol();
            s1 = automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.pushSymbol(s1);
            return automate.reduction(3, s);
        default:
            throw runtime_error("Erreur de syntaxe");
            break;
    }
    return false;
}
