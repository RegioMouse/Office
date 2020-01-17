#include "InitApp.h"

void ReCaptcha();
void AskKey();

void ReCaptcha()
{
	int ReCaptcha;

	
	srand((unsigned) time(0));
	ReCaptcha = 1 + (rand() % 10);

    srand(time(0));

    ReCaptcha = rand() % 10 + 1;

    int ReCaptcha_Result;
	
	long long int ReCaptcha_Real = ReCaptcha*2;
	
    do {
    	system("cls");
		cout << "			Overeni proti robotum			\n\n";
    	cout << "Kolik je " << ReCaptcha << " x2: ";

        cin >> ReCaptcha_Result;

        if (ReCaptcha_Result < ReCaptcha_Real)
            cout << "Ne. \n";
            
        else if (ReCaptcha_Result > ReCaptcha_Real)
            cout << "Ne. \n";
            
        else
            AskKey();
            
    } while (ReCaptcha_Result != ReCaptcha_Real);
}

void AskKey()
{
	signed int Key;
	signed int RealKey;
	
	RealKey = -1;
	
	system("cls");
	cout << "			Zadani Produktoveho Klice			\n\n";
	cout << "Prosim napiste vas Produktovy Klic: ";
	
	cin >> Key;
	
	do
	{
		if (Key == RealKey)
			Menu();
			
		else
			Exit();
	}
	while (Key != RealKey);
	
}
