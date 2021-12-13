// UserVector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include"Vector3D.h"
using namespace std;
int main()
{
	Vector3D<float> V1(1, 2, 3);
	Vector3D<float> V2(4, 5, 6);
	cout << "\naffichage de V1 = > \n"; V1.print();
	cout << "\naffichage de V2 = > \n"; V2.print();

	cout << "\n\nle module de V1 = " << V1.module() << endl<< endl;
	cout << "\n\nle module de V2 = " << V2.module() << endl << endl;
	cout << V1.operator[](0)<<endl;

	if (V1.operator==(V2) == true)
		cout << "\n\nV1 = v2\n";
	else
		cout << "\n\nV1 != v2\n";
	cout << "\n\nle produit scalaire de V1 et V2 = > " << V1.scalaire(V2) << endl<<endl;


	V1.operator*(2)->print();
	cout << endl<< endl;
	V2.operator*(0.5)->print();


}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
