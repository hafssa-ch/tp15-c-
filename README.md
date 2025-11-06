#  TP 15 – Structures de Données en C++

## Objectif

Ce TP a pour objectif de mettre en pratique la **programmation orientée objet (POO)** en **C++** à travers l’implémentation manuelle de structures de données classiques :  
**liste chaînée**, **file d’attente**, **table de hachage** et **pile générique**.  

Chaque exercice illustre :
- la gestion **dynamique de la mémoire**  
- l’**encapsulation**  
- et l’**utilisation des exceptions**

---

##  Exercice 1 : Liste Chaînée Personnalisée

###  Objectif
Implémenter une **liste chaînée simple** avec insertion, suppression et affichage.

###  Classes
- **Noeud** : représente un élément de la liste (valeur + pointeur vers le suivant)  
- **ListeChainee** : gère les opérations sur la liste

###  Méthodes principales

| Méthode | Description |
|----------|-------------|
| `ajouterDebut(int valeur)` | Ajoute un élément au début |
| `ajouterFin(int valeur)` | Ajoute un élément à la fin |
| `supprimer(int valeur)` | Supprime la première occurrence d’une valeur |
| `afficher()` | Affiche tous les éléments |
| `taille()` | Retourne le nombre d’éléments |
| `~ListeChainee()` | Libère la mémoire allouée dynamiquement |

 **Bonus :**  
Implémenter un **itérateur personnalisé** pour parcourir la liste.

<img width="668" height="216" alt="image" src="https://github.com/user-attachments/assets/fc1a0724-d696-4a14-b4d7-418e26d10f01" />

---

##  Exercice 2 : File d’Attente (Queue) Orientée Objet

###  Objectif
Créer une **file FIFO** gérée dynamiquement avec gestion d’exceptions.

###  Classes
- **Noeud** : élément de la file  
- **File** : gère les opérations de la file  

###  Méthodes principales

| Méthode | Description |
|----------|-------------|
| `enfiler(int valeur)` | Ajoute un élément à la fin |
| `defiler()` | Retire un élément du début (avec exception si vide) |
| `estVide()` | Vérifie si la file est vide |
| `estPleine()` | Vérifie si la file a atteint la capacité maximale |
| `afficher()` | Affiche le contenu de la file |
| `taille()` | Retourne le nombre d’éléments actuels |

 **Gestion d’erreur :**  
Lève une exception `runtime_error` lors d’un défilement sur une file vide.

 **Interface :**  
Une **interface texte (menu)** permet d’ajouter, retirer et afficher les éléments facilement.

<img width="676" height="643" alt="image" src="https://github.com/user-attachments/assets/737196c5-af05-44ca-99a2-6829e04a0716" />

---

##  Exercice 3 : Table de Hachage Simple

###  Objectif
Implémenter une **table de hachage** avec **chaînage** pour résoudre les collisions.

###  Classe
- **TableHachage**

###  Structure
Chaque case du tableau contient une **liste chaînée de paires (clé, valeur)**.

###  Méthodes principales

| Méthode | Description |
|----------|-------------|
| `inserer(int cle, string valeur)` | Insère une paire clé-valeur |
| `rechercher(int cle)` | Recherche la valeur associée à une clé |
| `supprimer(int cle)` | Supprime une clé de la table |
| `afficher()` | Affiche le contenu de toutes les cases |
| `redimensionner(int nouvelleTaille)` | *(Optionnel)* agrandit la table |


# Exercice 4 : Pile Générique avec Template
##  Objectif

Créer une pile LIFO générique avec un template de classe et gestion d’exception.

## Classe

Pile<T> — générique, peut contenir des int, string, double, etc.

## Méthodes principales
Méthode	Description
empiler(T element)	Ajoute un élément au sommet
depiler()	Retire le sommet (avec exception si vide)
sommet() const	Renvoie l’élément au sommet sans le retirer
estVide() const	Vérifie si la pile est vide
inverser()	Inverse l’ordre des éléments
afficher()	Affiche la pile du haut vers le bas

## Gestion d’erreur :
Lève une exception runtime_error si on tente de dépiler une pile vide.
