#include <iostream>
#include "contact.h"

using namespace std;

int  main(int argc, char const **argv){

	Liste contacts;
	Appel_en_absence appela;
	Appel appel;

	//SIMULATION APPELS EN ABSENCE
	appela.ajouter("0678027623");
	appela.ajouter("0734981457");
	appela.ajouter("0635986417");
	appela.ajouter("0614697580");

	//JE N'AI PAS VRAIMENT COMPRIS CE QUE VOUS VOULEZ DIRE PAR SIMULATION POUR LES APPELS, ET SURTOUT POUR LES APPELS 
	//ENTRANTS ET SORTANTS, DU COUP JE L'AI INTEGRE DANS LE MENU (CF CASE 10)
	
	


	while(1){


		std::cout << "\n MENU CONTACT \n" << std::endl;
		std::cout << "appels (entrants/sortants): "<< appel.afficher_nbbis() << std::endl;
		std::cout << "---Vous avez "<< appela.afficher_nb() << " appels en absence---\n" << std::endl;		
		
		std::cout << "-----------------------------------------------------------------" << std::endl;
		std::cout << "Que voulez vous faire? \n" ;
		std::cout << "1. Ajouter un contact. \n" ;
		std::cout << "2. Consulter la liste des contacts par ordre alphabetique. \n" ;
		std::cout << "3. Consulter un par un les contacts par ordre alphabétique.\n" ;
		std::cout << "4. Rechercher un contact. \n" ;
		std::cout << "5. Supprimer un contact. \n" ;
		std::cout << "6. Modifier un contact. \n" ;
		std::cout << "7. Consulter la liste des appels en absence. \n" ;
		std::cout << "8. Consulter la liste des appels (entrants/sortants). \n" ;
		std::cout << "9. Supprimer l'historique des appels (entrants/sortants). \n" ;
		std::cout << "10. Ajouter dans la liste d'appels (entrants/sortants). \n" ;
		std::cout << "11. Quitter. \n" ;
		std::cout << "-----------------------------------------------------------------" << std::endl;

		
		int choix;
		cin>> choix;
		switch(choix){
			case 1:
				contacts.ajouter();
				break;
			case 2:
				contacts.afficher();
				break;
			case 3:
				contacts.afficher_un();
				break;
			case 4:
				cout<< "quel contact voulez-vous chercher?"<< endl;
				contacts.rechercher();
				break;
			case 5:
				contacts.supprimer(); //pas fonctionnel(1)
				break;
			case 6:
				contacts.modifier(); //pas fonctionnel(1)
				break;
			case 7:
				appela.consulter();
				break;
			case 8:
				appel.consulterbis();
				break;
			case 9:
				appel.supprimerbis(); //pas fonctionne(1)
				break;	
			case 10:
				appel.ajouterbis(contacts);
				break;
			case 11:
				exit(0);
				break;
			default:
				cout<< "Cet action est indisponible, veuillez réessayer!";
		}
	}

	return 0;
}

//(1) je n'arrive pas à voir mes erreurs de pointeurs, et je ne sais pas comment y remedier
