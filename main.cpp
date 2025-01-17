#include <iostream>
#include <string>
#include "lexer.h"
#include "automate.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Vérifie si un argument est passé
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <chaine>" << endl;
        return 1; // Retourne une erreur
    }

    string chaine = argv[1]; // Récupère la chaîne passée en argument

    Lexer l(chaine);
    Automate a(l);
    bool isRecognise = false;

    try {
        isRecognise = a.recognize();
    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
    }

    if (isRecognise) {
        Symbole s = *a.popSymbol();
        cout << "\x1B[32m" << "Le mot \"" << chaine << "\" est reconnu, la valeur calculé est : " << s.GetValeur() << "\033[0m\t\t" << endl;
    } else {
        cerr << "\x1B[31m" << "Le mot \"" << chaine << "\" n'est pas reconnu." << "\033[0m\t\t" << endl;
    }

    return 0;
}
