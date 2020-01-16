#include "InitApp.h"

void InitApp()
{
	int Key;
	
	cout << "Prosim napiste vas Produktovy Klic: ";
	
	cin >> Key;
	
	switch(Key)
	{
		case 134679285:
			Menu();
			break;
			
		default:
			cout << "Zadali jste spatny Produktovy Klic. \n"
				 << "Stisknete jakoukoli klavesu. \n";
			
			system("pause >NUL");
			break;
	}
}
