#include <iostream>
#include "administrator.h"

using namespace std;
using namespace SavitchEmployees;

int main()
{
	Administrator admin;
	admin.readAdminData();
	admin.print();
	admin.printCheck();

	return 0;
}
