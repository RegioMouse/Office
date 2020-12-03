#include "Chatting.h"

void Chatting()
{
	int SelMode;
	
	system("cls");
	cout << "				Chat				\n"
		 << "(1) Server \n"
		 << "(2) Klient \n";
		 
	cin >> SelMode;
	
	switch(SelMode)
	{
		case 1:
			system("cls");
			ChattingServer();
			break;
			
		case 2:
			system("cls");
			ChattingClient();
			break;
	}
}
