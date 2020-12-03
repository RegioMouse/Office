#include "WorkFunctions.h"

void CasNaZakazce();
void PrichodOdchod();
void Zamestnanci();

void CasNaZakazce()
{
	/* TODO (#5#): Dodelat */
	
	ofstream CasNaZakazce_Save;
	string CasNaZakazce_Cas_Write;
	string CasNaZakazce_Zamestnanec_Write;
	
	system("cls");
	cout << "				Casy na zakazkach					\n\n\n";
	cout << "Zadejte jmeno zamestnance: ";
	CasNaZakazce_Zamestnanec_Write = "";
	cin >> CasNaZakazce_Zamestnanec_Write;
	cout << endl;
	cout << "Zadejte cas na zakazce: ";
	CasNaZakazce_Cas_Write = "";
	cin >> CasNaZakazce_Cas_Write;
	cout << endl;
	
	CasNaZakazce_Save.open("Soubory\\Cas-Na-Zakazkach.csv",ios::app);
	CasNaZakazce_Save << CasNaZakazce_Zamestnanec_Write << ";" << CasNaZakazce_Cas_Write << ";" << endl;
	CasNaZakazce_Save.close();
	cout << "Hotovo, podivejte se do slozky 'Soubory'";
	system("pause >NUL");
	Menu();
}

void PrichodOdchod()
{	
	ofstream PrichodOdchod_Save;
	
	string PrichodOdchod_Jmeno_Write;
	string PrichodOdchod_Datum_Write;
	string PrichodOdchod_Prichod_Write;
	string PrichodOdchod_Odchod_Write;
	
	system("cls");
	cout << "				Prichody / Odchody					\n\n\n";
	
	cout << "Zadejte jmeno: ";
	cin >> PrichodOdchod_Jmeno_Write;
	cout << endl;
	cout << "Zadejte datum: ";
	cin >> PrichodOdchod_Datum_Write;
	cout << endl;
	cout << "Zadejte cas prichodu: ";
	cin >> PrichodOdchod_Prichod_Write;
	cout << endl;
	cout << "Zadejte cas odchodu: ";
	cin >> PrichodOdchod_Odchod_Write;
	cout << endl;
	
	PrichodOdchod_Save.open("Soubory\\Prichody-Odchody.csv",ios::app);
	PrichodOdchod_Save << PrichodOdchod_Jmeno_Write << ";" << PrichodOdchod_Datum_Write << ";" << PrichodOdchod_Prichod_Write << ";" << PrichodOdchod_Odchod_Write << ";" << endl;
	PrichodOdchod_Save.close();
	cout << "Hotovo, podivejte se do slozky 'Soubory'";
	system("pause >NUL");
	Menu();
}

void Zamestnanci()
{	
	string Zamestnanci_Write;
	
	cout << "Zadejte jmeno zamestnance: ";
	cin >> Zamestnanci_Write;
	
	
	ofstream Zamestnanci_Save;
	Zamestnanci_Save.open("Soubory\\Zamestnanci.csv");
	Zamestnanci_Save << Zamestnanci_Write << ";" << endl;
	Zamestnanci_Save.close();
	cout << "Hotovo, podivejte se do slozky 'Soubory'";
	system("pause >NUL");
	Menu();
}
