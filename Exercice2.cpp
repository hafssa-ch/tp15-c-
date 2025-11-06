
#include <iostream>
#include <stdexcept> 
using namespace std;

class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int v) : valeur(v), suivant(nullptr) {}
};

class File {
private:
    Noeud* debut;  
    Noeud* fin;    
    int capacite;  
    int nbElements;

public:
    
    File(int cap = 0) : debut(nullptr), fin(nullptr), capacite(cap), nbElements(0) {}

    
    ~File() {
        while (!estVide())
            defiler();
        cout << "Mémoire libérée." << endl;
    }

    
    bool estVide() const {
        return debut == nullptr;
    }

   
    bool estPleine() const {
        return (capacite != 0 && nbElements >= capacite);
    }

    
    void enfiler(int valeur) {
        if (estPleine()) {
            cout << "⚠️ La file est pleine !" << endl;
            return;
        }

        Noeud* nouveau = new Noeud(valeur);
        if (estVide()) {
            debut = fin = nouveau;
        } else {
            fin->suivant = nouveau;
            fin = nouveau;
        }
        nbElements++;
        cout << valeur << " a été ajouté à la file." << endl;
    }

    
    int defiler() {
        if (estVide()) {
            throw runtime_error("Erreur : tentative de defilement sur une file vide !");
        }

        Noeud* temp = debut;
        int valeur = temp->valeur;
        debut = debut->suivant;
        delete temp;
        nbElements--;

        if (debut == nullptr) fin = nullptr; 
        cout << valeur << " a été retiré de la file." << endl;
        return valeur;
    }

    void afficher() const {
        if (estVide()) {
            cout << "La file est vide." << endl;
            return;
        }

        cout << "Contenu de la file : ";
        Noeud* courant = debut;
        while (courant != nullptr) {
            cout << courant->valeur << " <- ";
            courant = courant->suivant;
        }
        cout << "FIN" << endl;
    }

    int taille() const {
        return nbElements;
    }
};

int main() {
    File file(5); 
    int choix, valeur;

    do {
        cout << "\n=== MENU FILE D'ATTENTE ===" << endl;
        cout << "1. Enfiler (ajouter un élément)" << endl;
        cout << "2. Défiler (retirer un élément)" << endl;
        cout << "3. Afficher la file" << endl;
        cout << "4. Vérifier si vide / pleine" << endl;
        cout << "5. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        try {
            switch (choix) {
                case 1:
                    cout << "Entrez une valeur : ";
                    cin >> valeur;
                    file.enfiler(valeur);
                    break;
                case 2:
                    file.defiler();
                    break;
                case 3:
                    file.afficher();
                    break;
                case 4:
                    cout << "File vide ? " << (file.estVide() ? "Oui" : "Non") << endl;
                    cout << "File pleine ? " << (file.estPleine() ? "Oui" : "Non") << endl;
                    cout << "Taille actuelle : " << file.taille() << endl;
                    break;
                case 5:
                    cout << "Fin du programme." << endl;
                    break;
                default:
                    cout << "Choix invalide !" << endl;
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }

    } while (choix != 5);

    return 0;
}
