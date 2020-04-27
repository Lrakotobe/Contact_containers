#include <string>
#include <queue>
#include <list>

using namespace std;

class Contact{
private:
	string nom, prenom;
	string num[5];
	int nb_num;
	string numero;
	int type_appel;

public:
	Contact();
	~Contact();
	string get_nom() ;
	string get_prenom() ;
	int get_type();
	void set_type();
	//getter affiche
	void get();
	//setter saisie
	void set();
	//getter s'il n'y a pas de nom et prenom;
	void getsans();
	//setter s'il n'y a pas de nom et prenom
	void setsans(string number);		
};

bool sortByName(Contact &c1, Contact &c2);
void heure();

class Liste{
private:
	list<Contact> c;

public:
	int exist(Contact cont);
	void ajouter ();
	void afficher ();
	void afficher_un();
	void rechercher_chap(list <Contact> resultats, int nb_resultats);
	void rechercher();
	void selectionner();
	void supprimer();
	void modifier();
};

class Appel_en_absence{
private:
	queue <string> a;

public:
	void ajouter(string num);
	int afficher_nb();
	void consulter();
	void supprimer();
};

class Appel{
private:
	list <Contact> a;


public:
	void ajouterbis(Liste contact);
	int afficher_nbbis();
	void consulterbis();
	void supprimerbis();
};


