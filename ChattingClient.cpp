#include "ChattingClient.h"

char szServerIPAddr[ 20 ];     // Put here the IP address of the server
int nServerPort = 65534 ;                    // The server port that will be used by                                            // clients to talk with the server

bool InitWinSock2_0( ) ;

void ChattingClient( )
{
    cout << "Enter the server IP Address: " ;
    cin >> szServerIPAddr ;
    cout << "Enter the server port number: " ;
    cin >> nServerPort ;

    if ( ! InitWinSock2_0( ) )
    {
        cout << "Nelze sputit prostredi Socketu" << WSAGetLastError( ) << endl;
        system("pause >NUL");
        Menu();
    }

    SOCKET hClientSocket ;

    hClientSocket = socket(
        AF_INET,        // The address family. AF_INET specifies TCP/IP
        SOCK_STREAM,    // Protocol type. SOCK_STREM specified TCP
        0               // Protoco Name. Should be 0 for AF_INET address family
        ) ;
    if ( hClientSocket == INVALID_SOCKET )
    {
        cout << "Nelze vytvorit Serverovy Socket." << endl ;
        // Cleanup the environment initialized by WSAStartup()
        WSACleanup( ) ;
        system("pause >NUL");
        Menu();
    }


    // Create the structure describing various Server parameters
    struct sockaddr_in serverAddr ;

    serverAddr . sin_family = AF_INET ;     // The address family. MUST be AF_INET
    serverAddr . sin_addr . s_addr = inet_addr( szServerIPAddr ) ;
    serverAddr . sin_port = htons( nServerPort ) ;

    // Connect to the server
    if ( connect( hClientSocket, ( struct sockaddr * ) &serverAddr, sizeof( serverAddr ) ) < 0 )
    {
        cout << "Nelze se pripojit na IP " << szServerIPAddr << " , port " << nServerPort << endl ;
        closesocket( hClientSocket ) ;
        WSACleanup( ) ;
        system("pause >NUL");
        Menu();
    }

    char szBuffer[ 4096 ] = "" ;

    while ( strcmp( szBuffer, "QUIT" ) != 0 )
    {
        cout << "Zprava: " ;
        cin >> szBuffer ;

        int nLength = strlen( szBuffer ) ;

        // send( ) may not be able to send the complete data in one go.
        // So try sending the data in multiple requests
        int nCntSend = 0 ;
        char *pBuffer = szBuffer ;

        while ( ( nCntSend = send( hClientSocket, pBuffer, nLength, 0 ) != nLength ) )
        {
            if ( nCntSend == -1 )
            {
                cout << "Chyba v odesilani dat." << endl ;
                break ;
            }
            if ( nCntSend == nLength )
                break ;

            pBuffer += nCntSend ;
            nLength -= nCntSend ;
        }

        strupr( szBuffer ) ;
        if ( strcmp( szBuffer, "QUIT" ) == 0 )
        {
            break ;
        }

        nLength = recv( hClientSocket, szBuffer, sizeof( szBuffer ), 0 ) ;
        if ( nLength > 0 )
        {
            szBuffer[ nLength ] = '\0' ;
            cout << " ==> " << szBuffer << endl ;
        }
    }

    closesocket( hClientSocket ) ;
    WSACleanup( ) ;
    Menu();
}

bool InitWinSock2_0( )
{
    WSADATA wsaData ;
    WORD wVersion = MAKEWORD( 2, 0 ) ;

    if ( ! WSAStartup( wVersion, &wsaData ) )
        return true ;

    return false ;
}
