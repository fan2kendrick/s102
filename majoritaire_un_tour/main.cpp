#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string lireLigne()
{
    string ligne;
    while (true)
    {
        getline(cin, ligne);
        // cout << ligne << endl;
        if (ligne.substr(0, 2) != "//")
            break;
    }
    return ligne;
}

int lireEntier()
{
    string ligne;
    while (true)
    {
        getline(cin, ligne);
        if (isdigit(ligne[0]))
            break;
    }
    return stoi(ligne);
}

struct participant
{
    string nom;
    string prenom;
    int choix;
};

void displayPlayers(vector<participant> tab)
{
    for (unsigned i = 0; i <= tab.size() - 1; ++i)
    {
        if (tab[i].nom == tab[i].prenom)
            continue;
        cout << tab[i].nom << " " << tab[i].prenom << " " << tab[i].choix << endl;
    }
}

void displayStringTable(vector<string> tab)
{
    for (int i = 0; i <= tab.size() - 1; ++i)
    {
        cout << tab[i] << endl;
    }
}

void afficherGlacesEtVotes(vector<string> glaces, vector<int> votes)
{
    cout << "Il y a " << glaces.size() << " glaces dispo :" << endl;
    for (unsigned i = 0; i <= glaces.size() - 1; ++i)
    {
        cout << "- " << glaces[i] << " avec " << votes[i] << " votes. " << endl;
    }
}


int main()
{
    vector<participant> listeParticipants;
    vector<string> glaces = {lireLigne(), lireLigne(), lireLigne(), lireLigne()};
    vector<int> choixDesGlaces = {0, 0, 0, 0};

    for (unsigned i = 0; i < 116; ++i)
    {
        string nom = lireLigne();
        string prenom = lireLigne();
        int choix = lireEntier();
        // cout << prenom << nom << choix << endl;
        listeParticipants.push_back(participant{nom, prenom, choix});
    }

    for (participant p : listeParticipants)
    {
        choixDesGlaces[p.choix-1] += 1;
    }

    int gagnant = 0;
    int voteLePlusHaut = choixDesGlaces[0];
    for(int i = 1; i < choixDesGlaces.size(); i++) 
    {
        if(choixDesGlaces[i] > voteLePlusHaut)
        {
            voteLePlusHaut = choixDesGlaces[i]; 
            gagnant = i; 
        }
    }


    cout << "c'est la glace " << glaces[gagnant] << " qui a gagne" << endl;

    return 0;
}

// int main()
// {
//     vector <player> playerList;
//     vector <string> creams;
//     vector <int> creamsVoted = {0,0,0};

//     for(int j = 0; j < 3; ++j)
//     {
//         creams.push_back(lireLigne());
//     }

//     for(int line = 0; line < 1/*16*/; ++line)
//     {
//         string lastName = lireLigne();
//         string firstName = lireLigne();
//         int choice = lireEntier();
//         cout << lastName << firstName << choice << endl;
//         playerList.push_back(player{lastName, firstName, choice});
//     }

//     // displayIntTable(creamsVoted);
//     for(int j = 1; j <= creamsVoted.size(); ++j)
//     {
//         // cout << "Iteration j=" << j << endl;
//         for(player i: playerList)
//         {
//             if(i.choice == 0 || i.choice != j) continue;
//             creamsVoted[j-1] += 1;
//             // cout << i.choice << endl;
//         }
//     }

//     // displayIntTable(creamsVoted);
//     // voteAlternatif(creamsVoted, creams, playerList.size());
// }

/*
Progression actuelle :
creams c'est les gouts dispo, et playerList c'est la sturcture des participants en tableau grace a la deuxiueme boucle.
a faire : ajouter le systeme de quel choice correspond a quelle glace
a faire : ajouter le systeme de vote a majorité
a faire : trouver quelle glace a gagné a combien de voies, et qui a voté pour quoi (le lastNamebre)
*/