#include "Help.h"

void Help()
{
	int zpatky_z_napovedy;
	
	system("cls");
	cout << "Ahoj! \n\n"
		 << "Tohle je zakladni aplikace do kazde kancelare. \n\n\n"
		 << "Napiste 0 vsude kde se da psat, aby jste odesli z aplikace  \n"
		 << "Napiste 99 vsude kde se da psat, aby jste se vratili do Hlavniho Menu. \n\n";
	
	cout << "Prikaz: ";
	
	cin >> zpatky_z_napovedy;
	
	switch(zpatky_z_napovedy)
	{
		case 0:
			Exit(0);
			break;
			
		case 99:
			Menu();
			break;
			
		default:
			system("cls");
			cout << "Chyba! Zvolili jste spatnou volbu! \n"
				 << "Stiskni jakoukoliv klavesu na pokracovani \n";
			system("pause >NUL");
			Help();
			break;
	}
}
