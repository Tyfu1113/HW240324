//
//  Administrator.h
//  hw0620
//
//  Created by 傅梓崵 on 2024/6/16.
//

#ifndef Administrator_h
#define Administrator_h

#include<string>
#include "salariedemployee.h"

using std::string;
namespace SavitchEmployees
{
	class Administrator : public SalariedEmployee
	{
	public:
		Administrator();
		Administrator(const string& theName, const string& theSsn, double theSalary,
					  const string& theTitle, const string& theArea, const string& theSupervisor);
		
		void setSupervisor(const string& newSupervisor);
		void readAdminData();
		void print() const;
		void printCheck() const;

	private:
		string title;
		string area;
		string supervisor;
	};
} // SavitchEmployees

#endif /* Administrator_h */
