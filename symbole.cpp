#include "symbole.h"
#include <iostream>


void Symbole::Affiche() {
   cout<<Etiquettes[ident]<<"("<<valeur<<")";
}