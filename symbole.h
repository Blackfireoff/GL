#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, NON_TERMINAL };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "NON_TERMINAL" };

class Symbole {
   public:
      Symbole() { }
      Symbole(int i, bool t) : ident(i), valeur(i), terminal(t) {  }
      Symbole(int i, int v, bool t) : ident(i), valeur(v), terminal(t) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      bool isTerminal() { return terminal; }
      int GetValeur() { return valeur; }
      virtual void Affiche();

   protected:
      int ident;
      int valeur;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT, v, true) { }
      ~Entier() { }
};

class NonTerminal : public Symbole {
   public:
      NonTerminal(string n) : Symbole(NON_TERMINAL, false), name(n) { }
      ~NonTerminal() { }
   protected:
      string name;
};