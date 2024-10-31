#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("entree.txt"); // Ouvrir le fichier d'entrée en mode lecture
    ofstream outputFile("sortie.txt"); // Ouvrir le fichier de sortie en mode écriture

    // Vérifier si le fichier d'entrée a été ouvert avec succès
    if (!inputFile) { 
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
        return 1;
    }

    string line; // Variable pour stocker chaque ligne lue
    int max1 = 26; // Nombre maximum pour le remplacement par 1_1
    int max2 = 90; // Nombre maximum pour le remplacement par 1_2
    int i = 0; // Compteur pour 1_1
    int j = 0; // Compteur pour 1_2

    while (getline(inputFile, line)) { // Lire le fichier ligne par ligne
        // Si la ligne est "0"
        if (line == "0") {
            if (i < max1) { // Vérifier si on peut encore écrire 1_1
                outputFile << "1" << endl; // Écrire 1_1 dans le fichier de sortie
                ++i; // Incrémenter le compteur pour 1_1
            } else if (j < max2) { // Vérifier si on peut encore écrire 1_2
                outputFile << "4" << endl; // Écrire 1_2 dans le fichier de sortie
                ++j; // Incrémenter le compteur pour 1_2
            }
        } else {
            outputFile << line << endl; // Écrire la ligne telle quelle si ce n'est pas "0"
        }
    }

    inputFile.close(); // Fermer le fichier d'entrée
    outputFile.close(); // Fermer le fichier de sortie
    return 0; // Terminer le programme
}
