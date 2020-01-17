#include "saveSettings.h"

void saveSettings()
{
	ofstream myfile ("Settings.txt");
	if (myfile.is_open())
  	{
    	myfile << CLR << "\n";
    	myfile.close();
	}
	else cout << "Unable to open file";
}
