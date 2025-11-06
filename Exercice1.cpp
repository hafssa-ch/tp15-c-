
#include <iostream>
using namespace std;


class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int val) : valeur(val), suivant(nullptr) {}
};

class ListeChainee {
private:
    Noeud* tete;

public:
    
    ListeChainee() : tete(nullptr) {}

   
    ~ListeChainee() {
        Noeud* courant = tete;
        while (courant != nullptr) {
            Noeud* temp = courant;
            courant = courant->suivant;
            delete temp;
        }
        cout << "Mémoire libérée." << endl;
    }

   
    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        nouveau->suivant = tete;
        tete = nouveau;
    }

   
    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        if (tete == nullptr) {
            tete = nouveau;
            return;
        }

        Noeud* courant = tete;
        while (courant->suivant != nullptr)
            courant = courant->suivant;

        courant->suivant = nouveau;
    }

    void supprimer(int valeur) {
        if (tete == nullptr) return;

        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            return;
        }

        Noeud* courant = tete;
        while (courant->suivant != nullptr && courant->suivant->valeur != valeur)
            courant = courant->suivant;

        if (courant->suivant != nullptr) {
            Noeud* temp = courant->suivant;
            courant->suivant = temp->suivant;
            delete temp;
        }
    }

    void afficher() const {
        Noeud* courant = tete;
        cout << "Liste : ";
        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        cout << "NULL" << endl;
    }

    int taille() const {
        int compteur = 0;
        Noeud* courant = tete;
        while (courant != nullptr) {
            compteur++;
            courant = courant->suivant;
        }
        return compteur;
    }

    class Iterator {
    private:
        Noeud* courant;
    public:
        Iterator(Noeud* n) : courant(n) {}

        bool operator!=(const Iterator& other) const { return courant != other.courant; }
        int operator*() const { return courant->valeur; }
        Iterator& operator++() {
            if (courant) courant = courant->suivant;
            return *this;
        }
    };

    Iterator begin() const { return Iterator(tete); }
    Iterator end() const { return Iterator(nullptr); }
};

int main() {
    ListeChainee liste;

    liste.ajouterDebut(10);
    liste.ajouterDebut(20);
    liste.ajouterFin(30);
    liste.ajouterFin(40);

    liste.afficher();
    cout << "Taille : " << liste.taille() << endl;

    liste.supprimer(20);
    liste.afficher();

    cout << "Itération avec itérateur : ";
    for (int val : liste) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
