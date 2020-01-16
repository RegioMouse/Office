#include "Exit.h"

void Exit()
{
	exit(0);
	system("taskkill /f /im MYOffice.exe");
}
