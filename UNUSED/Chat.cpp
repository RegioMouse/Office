#include "Chat.h"
#include "ChatSocket.h"

using namespace std;

void Wait_SleepTo ( signed long long int sec )
{ 
	clock_t count = clock () + sec * CLOCKS_PER_SEC ;
	while (clock() < count){}
}

void Chat()
{
    int choice;
    int port = 9999;
    //char *ipAddress = "127.0.0.1";
    string ipAddress = "0.0.0.0";
    bool done = false;
    char recMessage[STRLEN];
    system("cls");
    cout << "			Chat			\n\n";
    cout << "(1) Spustit server\n";
    cout << "(2) Pripojit se k serveru\n";
    cin >> choice;
    if ( choice == 2 )
    {
        //Client
        system("cls");
        cout << "Zadejte adresu IP: ";
        cin >> ipAddress;
        cout << "\n";
        ClientSocket sockClient;
        cout << "Pripojovani...\n";
        sockClient.ConnectToServer( ipAddress.c_str(), port );
        //Connected
        while ( !done )
        {
			sockClient.GetAndSendMessage();
			while (sockClient.RecvData( recMessage, STRLEN ))
			{
				sockClient.GetAndSendMessage();
			}
            sockClient.RecvData( recMessage, STRLEN );
            cout << "Prijato > "<< recMessage <<endl;;
        }
        sockClient.CloseConnection();
    }
    else if ( choice == 1 )
    {
        //SERVER
        system("cls");
        ServerSocket sockServer;
        cout << "Server bezi, ceka se na pripojeni...\n";
        sockServer.StartHosting( port );
        //Connected
        while ( !done )
        {
			sockServer.GetAndSendMessage();
            sockServer.RecvData( recMessage, STRLEN );
            cout << "Prijato > "<<recMessage<<endl;
        }
    }
	else if ( choice == 0 )
    {
		Exit(0);
    }
    else if ( choice == 99 )
    {
    	system("cls");
		Menu();
    }
}
