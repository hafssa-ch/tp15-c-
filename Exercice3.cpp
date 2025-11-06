
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class TableHachage {
private:
    int taille;
    vector<list<pair<int, string>>> table;

    int fonctionHachage(int cle) const {
        return cle % taille;
    }

public:
   
    TableHachage(int t = 10) : taille(t) {
        table.resize(taille);
    }

   
    void inserer(int cle, const string& valeur) {
        int index = fonctionHachage(cle);

        
        for (auto& paire : table[index]) {
            if (paire.first == cle) {
                paire.second = valeur; 
                cout << "Clé " << cle << " mise à jour avec la valeur \"" << valeur << "\"." << endl;
                return;
            }
        }

        table[index].push_back({cle, valeur});
        cout << "Clé " << cle << " insérée à l’index " << index << "." << endl;
    }

    string rechercher(int cle) const {
        int index = fonctionHachage(cle);
        for (const auto& paire : table[index]) {
            if (paire.first == cle)
                return paire.second;
        }
        return "Clé introuvable.";
    }

    void supprimer(int cle) {
        int index = fonctionHachage(cle);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == cle) {
                table[index].erase(it);
                cout << "Clé " << cle << " supprimée de l’index " << index << "." << endl;
                return;
            }
        }
        cout << "Clé " << cle << " introuvable, suppression impossible." << endl;
    }

    void afficher() const {
        cout << "\n=== Contenu de la Table de Hachage ===" << endl;
        for (int i = 0; i < taille; ++i) {
            cout << "[" << i << "] -> ";
            if (table[i].empty()) {
                cout << "vide";
            } else {
                for (const auto& paire : table[i]) {
                    cout << "(" << paire.first << ", " << paire.second << ") -> ";
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }

    
    void redimensionner(int nouvelleTaille) {
        vector<list<pair<int, string>>> nouvelleTable(nouvelleTaille);

        
        for (int i = 0; i < taille; ++i) {
            for (const auto& paire : table[i]) {
                int nouvelIndex = paire.first % nouvelleTaille;
                nouvelleTable[nouvelIndex].push_back(paire);
            }
        }

        table = move(nouvelleTable);
        taille = nouvelleTaille;

        cout << "Table redimensionnée à " << taille << " cases." << endl;
    }
};

int main() {
    TableHachage table(5);
    int choix, cle;
    string valeur;

    do {
        cout << "\n=== MENU TABLE DE HACHAGE ===" << endl;
        cout << "1. Insérer un élément" << endl;
        cout << "2. Rechercher une clé" << endl;
        cout << "3. Supprimer une clé" << endl;
        cout << "4. Afficher la table" << endl;
        cout << "5. Redimensionner la table" << endl;
        cout << "6. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Entrez la clé (int) : ";
                cin >> cle;
                cout << "Entrez la valeur (string) : ";
                cin >> valeur;
                table.inserer(cle, valeur);
                break;

            case 2:
                cout << "Entrez la clé à rechercher : ";
                cin >> cle;
                cout << "Résultat : " << table.rechercher(cle) << endl;
                break;

            case 3:
                cout << "Entrez la clé à supprimer : ";
                cin >> cle;
                table.supprimer(cle);
                break;

            case 4:
                table.afficher();
                break;

            case 5:
                cout << "Nouvelle taille : ";
                cin >> cle;
                table.redimensionner(cle);
                break;

            case 6:
                cout << "Fin du programme." << endl;
                break;

            default:
                cout << "Choix invalide !" << endl;
        }

    } while (choix != 6);

    return 0;
}
