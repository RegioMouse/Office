#include "Menu.h"
#define F1          59
#define F2          60
#define F3          61
#define F4          62
#define F5          63
#define F6          64
#define F7          65
#define F8          66
#define F9          67
#define F10         68
void Menu()
{
	char KeyStroke;
	
	system("cls");
	cout << "			 Hlavni Menu 			\n\n" ;
	cout << " ESC -> Vypnout aplikaci \n";
	cout << " F1  -> Cas na zakazce \n";
	cout << " F2  -> Prichody / Odchody \n";
	cout << " F3  -> Zamestnanci \n";
	cout << " F4  -> Chat \n";
	cout << " F5  -> Nastaveni \n";
	cout << " F6  -> Napoveda \n\n\n";
	
	do
	{
		KeyStroke =	getch();
		if (KeyStroke == 0)
		{
			KeyStroke = getch(); // Even though there are 2 getch() it reads one keystroke
			switch (KeyStroke)
			{
			case F1:
				CasNaZakazce();
				break;
			case F2:
				PrichodOdchod();
				break;
			case F3:
				Zamestnanci();
				break;
			case F4:
				Chatting();
				break;
			case F5:
				Settings();
				break;
			case F6:
				Help();
				break;
			}
		}
	} 
	while (KeyStroke != 27); // 27 = Escape key
}

