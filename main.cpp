
#include <iostream>
#include <memory>

using namespace std;

int main() {

    unique_ptr<int> nombre_de_ligne = make_unique<int> ();
    unique_ptr<int> nombre_de_colonne = make_unique<int> ();



    cout << "Donner le nombre des lignes : ";
    cin >> (*nombre_de_ligne);

    cout << "Donner le nombre des colonne : ";
    cin >> (*nombre_de_colonne);

    // Allocation dynamique avec smart pointers
    auto A = make_unique<int[]>((*nombre_de_ligne) * (*nombre_de_colonne));
    auto B = make_unique<int[]>((*nombre_de_ligne) * (*nombre_de_colonne));
    auto S = make_unique<int[]>((*nombre_de_ligne) * (*nombre_de_colonne));
    auto P = make_unique<int[]>((*nombre_de_ligne) * (*nombre_de_colonne));

    // Saisie matrice A
    cout << endl<< "Saisir la matrice A :" <<endl;
 
    for(int i = 0; i <(*nombre_de_ligne); i++) {

        for(int j = 0; j < (*nombre_de_colonne); j++) {
            
           cout << "Element " << (i + 1) << " :" << " - " << (j + 1) <<" :";
            cin >> A[i * (*nombre_de_colonne) + j];
        }
    }

    // Saisie matrice B
    cout << endl <<  "Saisir la matrice B :" <<endl;

    for(int i = 0; i  < (*nombre_de_ligne); i++) {

        for(int j = 0; j < (*nombre_de_colonne); j++) {

           cout << "Element " << (i + 1) << " :" << " - " << (j + 1) <<" :";
             
            cin >> B[i *  (*nombre_de_colonne)+ j];
        }
    }

    // Somme des matrices
    for(int i = 0; i < (*nombre_de_ligne); i++) {

        for(int j = 0; j < (*nombre_de_colonne); j++) {

            S[i * (*nombre_de_colonne) + j] =
            A[i * (*nombre_de_colonne) + j] + B[i * (*nombre_de_colonne) + j];
        }
    }

    // Affichage somme
    cout << endl << "Somme des matrices :" << endl;;

    for(int i = 0; i < (*nombre_de_ligne); i++) {

        for(int j = 0; j < (*nombre_de_colonne); j++) {

            cout << S[i * (*nombre_de_colonne) + j] << " ";
        }

        cout << endl;
    }

    // Produit des matrices
    for(int i = 0; i < (*nombre_de_ligne); i++) {

        for(int j = 0; j < (*nombre_de_colonne); j++) {

            P[i * (*nombre_de_colonne) + j] = 0;

            for(int k = 0; k < (*nombre_de_colonne); k++) {

                P[i * (*nombre_de_colonne) + j] +=
                A[i * (*nombre_de_colonne) + k] * B[k * (*nombre_de_colonne) + j];
            }
        }
    }

    // Affichage produit
    cout << endl << "Produit des matrices :" <<endl;

    for(int i = 0; i < (*nombre_de_ligne); i++) {

        for(int j = 0; j < (*nombre_de_colonne); j++) {

            cout << P[i * (*nombre_de_colonne) + j] << " ";
        }

        cout << endl;
    }

    return 0;
}