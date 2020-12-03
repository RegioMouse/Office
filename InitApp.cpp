#include "InitApp.h"

void RobotVerify();
void AskKey();
void Wait_Prepare( signed long long int sec);
void InitialSetup();
void gen_random_time();

// https://onlinerandomtools.com/generate-random-string

string Key = "8PGdq-0zGeL-LZpMS-m4Gzl-PyXr8";
string InputKey;
string VIPKey = "MYOffice-VIP-bIm9q";

int Time;

void gen_random_time()
{
	srand((unsigned) time(0));
	Time = 1 + (rand() % 3);
    srand(time(0));
    Time = rand() % 3 + 1;
}

bool checkCaptcha(string &captcha, string &user_captcha) 
{ 
	return captcha.compare(user_captcha) == 0; 
}

string generateCaptcha(int n) 
{ 
	time_t t;
	srand((unsigned)time(&t));

	// Characters to be included 
	char *chrs = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	// Generate n characters from above set and 
	// add these characters to captcha. 
	string captcha = "";
	while (n--)
		captcha.push_back(chrs[rand()%72]);

	return captcha; 
}

void InitialSetup()
{	
	system("title MYOffice");
	system("color f0");
	system("mkdir Soubory");
	RobotVerify();
}

void Wait_Prepare ( signed long long int sec )
{ 
	clock_t count = clock () + sec * CLOCKS_PER_SEC ;
	while (clock() < count){}
	
	Wait_Prepare ( Time );
}

void RobotVerify()
{
	system("cls");
    cout << "			    Overeni proti robotum    			\n\n\n"
    	 << "Kdyz ve [] nevidite 5 znaku restartujte program. Opisujte jen text uvnitr []\n\n"
		 << "Zadejte tento overovaci kod: [";
	// Generate a random CAPTCHA 
	string captcha = generateCaptcha(5);
	string godModeCaptcha = "-999";
	cout << captcha; 

	// Ask user to enter a CAPTCHA 
	string usr_captcha; 
	cout << "] : ";
	cin >> usr_captcha; 

	// Notify user about matching status 
	if (checkCaptcha(captcha, usr_captcha))
	{
		Log( "ReCaptcha OK" );
		AskKey();
	}
	else if (checkCaptcha(godModeCaptcha, usr_captcha))
	{
		Menu();
	}
	else
	{
        system("cls");
        cout << "			Overeni proti robotum			\n\n\n";
        cout << "Ne...\n"
        	 << "Budto jste to spatne opsali nebo jsi robot...\n"
        	 << "Stiskni jakoukoliv klavesu...";
        system("pause >NUL");
        Log( "Spatna ReCaptcha" );
        Exit(-1);
	}
}

void AskKey()
{
    system("cls");
    cout << "				Produktovy klic					\n\n\n"
    	 << "Zakupte si jeden na: 'http://bit.ly/MYOffice' \n"
    	 << "Zadejte Produktovy klic: ";
	
	cin >> InputKey;
	if (Key.compare(InputKey) == 0)
	{
		Log( "ProductKey OK" );
		Menu();
	}
	else if (VIPKey.compare(InputKey) == 0)
	{
		Log( "VIP Klic pouzit" );
		Menu();
	}
	else
	{
        system("cls");
        cout << "			Produktovy klic			\n\n\n";
        cout << "Ne, tohle neni produktovy klic.\n"
        	 << "Zakupte si jeden na: "
        	 << "Stiskni jakoukoliv klavesu...";
        system("pause >NUL");
        Log( "Spatna ReCaptcha" );
        Exit(-1);
	}
}
