#include <iostream>
#include "administrator.h"

using namespace std;
using namespace SavitchEmployees;

int main()
{
	//test inheritance
	Administrator admin;
	admin.readAdminData();
	admin.print();
	admin.printCheck();

	return 0;
}
