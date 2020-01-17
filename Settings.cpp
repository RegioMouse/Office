#include "Settings.h"

void Settings();
void Color();


void Color()
{
	int clrChoice;

	
	system("cls");
	
	cout << "(1) Bila barva \n"
		 << "(2) Cerna barva \n\n";
		 
	cout << "Prikaz: ";

	
	cin >> clrChoice;
	
	
	switch(clrChoice)
	{
		case 1:
			system("color f0");
			Settings();
			break;
		
		case 2:
			system("color 0f");
			Settings();
			break;
			
		case 99:
			Menu();
			break;
			
		default:
			system("cls");
			cout << "Chyba! Zvolili jste spatnou volbu! \n"
				 << "Stiskni jakoukoliv klavesu na pokracovani \n";
			system("pause >NUL");
			Color();
			break;
	}
	
	Menu();
}

void Settings()
{
	int settingsChoice;
	
	system("cls");
	
	cout << "			 Nastaveni 			\n\n" ;
	cout << "(1): Barva \n\n\n";
	
	cout << "Prikaz: ";
	cin >> settingsChoice;
	
	switch(settingsChoice)
	{
		case 1:
			Color();
			break;
		
		case 0:
			Exit();
			break;
			
		case 99:
			Menu();
			break;
			
		default:
			system("cls");
			cout << "Chyba! Zvolili jste spatnou volbu! \n"
				 << "Stiskni jakoukoliv klavesu na pokracovani \n";
			system("pause >NUL");
			Settings();
			break;
	}
	

}
