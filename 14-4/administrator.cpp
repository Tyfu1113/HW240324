//
//  administrator.cpp
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//
#include <iostream>
#include <string>
#include "administrator.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace SavitchEmployees
{
	Administrator::Administrator() : SalariedEmployee(), title("No title"), area("No area"), supervisor("No supervisor") {}

	Administrator::Administrator(const string& theName, const string& theSsn, double theSalary,
								 const string& theTitle, const string& theArea, const string& theSupervisor)
		: SalariedEmployee(theName, theSsn, theSalary), title(theTitle), area(theArea), supervisor(theSupervisor) {}

	void Administrator::setSupervisor(const string& newSupervisor)
	{
		supervisor = newSupervisor;
	}

	void Administrator::readAdminData()
	{
		cout << "Enter administrator's title: ";
		cin >> title;
		cout << "Enter company area of responsibility: ";
		cin >> area;
		cout << "Enter supervisor's name: ";
		cin >> supervisor;
		cout << "Enter administrator's annual salary: ";
		cin >> salary;
	}

	void Administrator::print() const
	{
		cout << "Administrator: " << getName() << endl;
		cout << "SSN: " << getSsn() << endl;
		cout << "Title: " << title << endl;
		cout << "Area of responsibility: " << area << endl;
		cout << "Immediate supervisor: " << supervisor << endl;
		cout << "Annual salary: " << salary << endl;
	}

	void Administrator::printCheck() const
	{
		cout << "\n_____________________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
		cout << "_______________________________________________\n";
		cout << "Check Stub NOT NEGOTIABLE \n";
		cout << "Employee Number: " << getSsn() << endl;
		cout << "Administrator. Title: " << title << endl;
		cout << "Area of responsibility: " << area << endl;
		cout << "Immediate supervisor: " << supervisor << endl;
		cout << "Annual Salary: " << salary << endl;
		cout << "_______________________________________________\n";
	}
} // SavitchEmployees
