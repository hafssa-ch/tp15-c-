#include <iostream>
#include <vector>
#include <stdexcept> 
using namespace std;

template <typename T>
class Pile {
private:
    vector<T> elements; 

public:
    void empiler(const T& element) {
        elements.push_back(element);
        cout << element << " empilé." << endl;
    }

    T depiler() {
        if (estVide())
            throw runtime_error("Erreur : tentative de dépiler une pile vide !");
        T sommetElement = elements.back();
        elements.pop_back();
        cout << sommetElement << " dépilé." << endl;
        return sommetElement;
    }

    T sommet() const {
        if (estVide())
            throw runtime_error("Erreur : la pile est vide, pas de sommet !");
        return elements.back();
    }

    bool estVide() const {
        return elements.empty();
    }

    int taille() const {
        return elements.size();
    }

    void inverser() {
        int n = elements.size();
        for (int i = 0; i < n / 2; ++i)
            swap(elements[i], elements[n - i - 1]);
        cout << "Pile inversée." << endl;
    }

    void afficher() const {
        cout << "Pile (haut -> bas) : ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

int main() {
    try {
        cout << "=== Test avec int ===" << endl;
        Pile<int> pileInt;
        pileInt.empiler(10);
        pileInt.empiler(20);
        pileInt.empiler(30);
        pileInt.afficher();
        cout << "Sommet actuel : " << pileInt.sommet() << endl;
        pileInt.depiler();
        pileInt.afficher();
        pileInt.inverser();
        pileInt.afficher();

        cout << "\n=== Test avec string ===" << endl;
        Pile<string> pileStr;
        pileStr.empiler("Bonjour");
        pileStr.empiler("le");
        pileStr.empiler("monde");
        pileStr.afficher();
        pileStr.inverser();
        pileStr.afficher();

        cout << "\n=== Test avec double ===" << endl;
        Pile<double> pileDouble;
        pileDouble.empiler(3.14);
        pileDouble.empiler(2.71);
        pileDouble.empiler(1.41);
        pileDouble.afficher();
        cout << "Sommet : " << pileDouble.sommet() << endl;
        pileDouble.depiler();
        pileDouble.afficher();

        cout << "\n=== Test d'exception ===" << endl;
        Pile<int> pileVide;
        pileVide.depiler();  

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
