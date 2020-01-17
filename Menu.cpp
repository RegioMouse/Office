#include "Menu.h"

void Menu()
{
	int myChoice;
	
	system("cls");
	cout << "			 Hlavni Menu 			\n" ;
	cout << "(0): Vypnout aplikaci \n";
	cout << "(1): Cas na zakazce \n";
	cout << "(2): Prichod / Odchod \n";
	cout << "(3): Zamestnanci \n";
	cout << "(4): Nastaveni \n";
	cout << "(5): Napoveda \n\n\n";
	
	cout << "Prikaz: ";
	cin >> myChoice;
	
	switch(myChoice)
	{
	case 0:
		Exit();
		break;
		
	case 1:
		// docasna hlaska
		system("cls");
		cout << "Funguje, zatim ale neni zprovoznen tento modul. \n Stisknete jakoukoli klavesu pro Hlavni Menu.";
		system("pause >NUL");
		Menu();
		break;
		
	case 2:
		// docasna hlaska
		system("cls");
		cout << "Funguje, zatim ale neni zprovoznen tento modul. \n Stisknete jakoukoli klavesu pro Hlavni Menu.";
		system("pause >NUL");
		Menu();
		break;
		
	case 3:
		// docasna hlaska
		system("cls");
		cout << "Funguje, zatim ale neni zprovoznen tento modul. \n Stisknete jakoukoli klavesu pro Hlavni Menu.";
		system("pause >NUL");
		Menu();
		break;
		
	case 4:
		Settings();
		break;

	case 5:
		Help();
		break;
			
	case -1:
		Debug();
		break;
			
	case 99:
			Menu();
			break;

	default:
		system("cls");
		cout << "Chyba! Zvolili jste spatnou volbu! \n"
			 << "Stisknete jakoukoliv klavesu na pokracovani \n";
		system("pause >NUL");
		Menu();
		break;
	}
}
