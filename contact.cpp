#include <iostream>
#include <algorithm>
#include "contact.h"
#include <stdio.h>
#include <ctype.h>
#include <ctime>

using namespace std; 

Contact::Contact(){
	nom= "";
	prenom= "";
	for (int i= 0; i< 4; i++) 
		num[i] = "";
	nb_num= 0;
	numero= "";
	type_appel= 0;
}

Contact::~Contact(){
}

string Contact::get_nom(){
	return nom;
}

string Contact::get_prenom(){
	return prenom;
}

int Contact::get_type(){
	return type_appel;
}

void Contact::set_type(){
	cin>> type_appel;
}

void Contact:: get(){
	cout<<"--"<<endl;
	cout<< "nom: " << nom<< endl;
	cout<< "prenom: " << prenom<< endl;
	for (int i = 0; i < nb_num; ++i)
		cout << "num"<< i+1 <<": "<< num[i]<< endl;
}

void Contact::set(){
	cout << "entrez le nom: ";
	cin>> nom;
	cout << "entrez le prenom: ";
	cin>> prenom;
	cout << "nombre de numéro: ";
	cin>> nb_num;
	for (int i = 0; i < nb_num; ++i){
		cout << "entrez le num_"<< i+1 <<": ";
			cin>> num[i];
	}
}

void Contact::getsans(){
	cout<< numero << endl;
}

void Contact::setsans(string number){
	nom= "";
	numero= number;
}

int Liste::exist(Contact cont){
	for (auto it = c.begin(); it != c.end(); ++it){
		Contact courant= *it;
		if ((courant.get_nom()== cont.get_nom()) && (courant.get_prenom()== cont.get_prenom()))
			return 1;
	}
	return 0;
}

void Liste::ajouter (){
	std::cout << "*AJOUT DE CONTACT*" << std::endl;
	Contact nouveau;
	nouveau.set();
	if (exist(nouveau))
		cout << "Ce contact est dejà existant!"<< endl;
	else
		c.push_back(nouveau);
}

bool sortByName(Contact &c1, Contact &c2){
    return c1.get_nom() < c2.get_nom();
}

void Liste::afficher (){
	//a faire: ordre alphabetique
	c.sort(sortByName);
	for (auto it = c.begin(); it != c.end(); ++it){
		Contact courant= *it;
		courant.get();
	}
}

void Liste::afficher_un(){
	c.sort(sortByName);
	std::list<Contact>::iterator it= c.begin();
	while (it != c.end()){
		Contact courant= *it;
		courant.get();
		string reponse;
		cout<< "voulez-vous voir le suivant? (O/N):"<< endl;	
		cin>> reponse;
		if (reponse== "O")
			++it;
		else
			break;
	}
}

//peut etre inutile de faire une fonction chapeau, a revoir
void Liste::rechercher_chap(list <Contact> resultats, int nb_resultats){
	string recherche;
	cin>> recherche;
	for (auto it = c.begin(); it != c.end(); ++it){
		Contact courant= *it;
		auto itnom = courant.get_nom().find(recherche);
		auto itprenom = courant.get_prenom().find(recherche);
		if ((itnom != std::string::npos)||(itprenom != std::string::npos)){
			resultats.push_back(courant);
		}
		++nb_resultats;
	}
	resultats.sort(sortByName);
	if (nb_resultats != 0){
		cout<< "--"<< resultats.size()<<" résultats trouvés--"<<endl;
		int acc=1;
		for (auto it = resultats.begin(); it != resultats.end(); ++it){
			cout<< acc <<".\n";
			Contact courant= *it;
			courant.get();
			++acc;
		}
	}
	else
		cout << "Aucun contact existant";
}

void Liste::rechercher(){
	list <Contact> resultats;
	rechercher_chap(resultats,0);
}

void Liste::supprimer(){
	cout<< "quel contact voulez-vous supprimer?"<< endl;
	list <Contact> resultats;
	int nb_resultats=0;
	rechercher_chap(resultats, nb_resultats);
	cout<< "selectionnez votre choix:" << endl;
	int choix;
	cin>> choix;
	list<Contact>::iterator it = resultats.begin();
	advance(it, choix);
	Contact choisi= *it;
	for (auto itbis = c.begin(); itbis != c.end(); ++itbis){
		Contact courant= *itbis;
		if ((courant.get_nom()== choisi.get_nom())&& (courant.get_prenom()== choisi.get_prenom()));
			c.erase(itbis);
	}	
}

void Liste::modifier(){
	cout<< "quel contact voulez-vous modifier?"<< endl;
	list <Contact> resultats;
	int nb_resultats;
	rechercher_chap(resultats, nb_resultats);
	cout<< "selectionnez votre choix:" << endl;
	int choix;
	cin>> choix;
	list<Contact>::iterator it = resultats.begin();
	advance(it, choix);
	Contact choisi= *it;
	for (auto itbis = c.begin(); itbis != c.end(); ++itbis){
		Contact courant= *itbis;
		if ((courant.get_nom()== choisi.get_nom())&& (courant.get_prenom()== choisi.get_prenom())){
			Contact nouveau;
			nouveau.set();
			courant=nouveau;
			}	
	}

}

void Appel_en_absence::ajouter(string num){
	a.push(num);
}
int Appel_en_absence::afficher_nb(){
	a.size();
}

void heure(){
	time_t rawtime;
	time (&rawtime);
	cout << "date et heure: "<<ctime(&rawtime)<< endl;
} 

void Appel_en_absence::consulter(){
	while (!a.empty()){
		cout<< a.size()<< "." << a.front()<< endl;
		heure();
		a.pop();
	}
}

void Appel_en_absence::supprimer(){
	while(!a.empty())
		a.pop();
}

void Appel::ajouterbis(Liste contact){
	cout<< "Cet appel est: \n1.entrant \n2.sortant?"<< endl;
	Contact nouveau;
	nouveau.set_type();
	if (nouveau.get_type()==1){
		cout<< "entrez un numéro:"<< endl;
		string num;
		cin>> num;
		nouveau.setsans(num);
		a.push_front(nouveau);
	}
	if (nouveau.get_type()==2){
		cout << "Vous voulez: \n 1.Appeler un contact existant \n 2.Composer un nouveau numéro" <<endl;
		int num;
		cin>>num;
		if (num==1){
			nouveau.set();
			if (contact.exist(nouveau))
				a.push_front(nouveau);
			else
				cout<< "Ce contact n'est pas présent dans votre liste."<< endl;
		}
		if (num==2){
			cout<< "entrez un numéro:"<< endl;
			string num;
			cin>> num;
			nouveau.setsans(num);
			a.push_front(nouveau);
		}
	}
}

int Appel::afficher_nbbis(){
	a.size();
}

void Appel::consulterbis(){
	int acc= 1;
	for (auto it = a.begin(); it != a.end(); ++it){
		Contact courant= *it;
		cout<< acc << "."<< endl;
		if (courant.get_nom()==""){
			cout<< "---"<< endl;
			courant.getsans();
			if(courant.get_type()==1)
				cout<< "type: entrant"<< endl;
			else
				cout<< "type: sortant"<< endl;
			heure();
			cout<< "---"<< endl;
			acc++;
		}
		else {
			cout<< "---"<< endl;
			courant.get();
			if(courant.get_type()==1)
				cout<< "type: entrant"<< endl;
			else
				cout<< "type: sortant"<< endl;
			heure();
			cout<< "---"<< endl;
			acc++;
		}
	}
}


void Appel::supprimerbis(){
	for (auto it = a.begin(); it != a.end(); ++it){
		a.erase(it);
	}
}