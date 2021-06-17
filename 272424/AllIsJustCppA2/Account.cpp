#include "Account.h"


//*******************************************************************
//               function  Account::withdraw(const double& bal)
//   Parameters:double  - amount of money to withdraw from account
//   Withdraw amount of money from account
//   return void
//********************************************************************
void Account::withdraw(const double& bal)
{
	if (this->acc_balance < bal)
	{
		cout << "Not enought money";
	}
	else
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		this->last_pmnt.set_year(now->tm_year + 1900);
		this->last_pmnt.set_month(now->tm_mon + 1);
		this->last_pmnt.set_day(now->tm_mday);


		this->acc_balance -= bal;
		cout << "Withdraw succsessfull" << endl;
	}
};



//*******************************************************************
//               function  Account::deposit(const double& bal)
//   Parameters:double  - amount of money to deposit on account
//   Deposit amount of money on account
//   return void
//********************************************************************
void Account::deposit(const double& bal)
{
	time_t t = time(0);
	tm* now = localtime(&t);
	this->last_pmnt.set_year(now->tm_year + 1900);
	this->last_pmnt.set_month(now->tm_mon + 1);
	this->last_pmnt.set_day(now->tm_mday);


	this->acc_balance += bal;
	cout << "Deposit succsessfull" << endl;
};



//*******************************************************************
//               function  Account::create_id(const size_t& size)
//   Parameters:size_t  - size of the generated string number
//   Genrate random string which use like id for account in data base
//   return string
//********************************************************************
string Account::create_id(const size_t& size)
{
	char a;
	string res;

	char* id = new char[size];

	random_device rd;
	mt19937 gen(rd());

	for (size_t i = 0; i < size; i++)
	{
		a = (gen() % 10) + 48;
		id[i] = a;
	}
	res.insert(0, id, size);
	delete[] id;

	return res;
}



//*******************************************************************
//               function  Account::show_info()
//   Parameters:
//   Print information about account to the console
//   return void
//********************************************************************
void Account::show_info()
{
	cout << "Information about account number " << this->acc_number << endl;
	cout << "  Name       Number         Type      Balance       Last transaction(dd:mm:yyyy)   " << endl;
	cout << this->acc_name << "   " << this->acc_number << "   ";
	if (this->acc_type =='c' || this->acc_type == 'C')
	{
		cout << "Checking     ";
	}
	else
	{
		cout << "Saving     ";
	}
	cout << this->acc_balance << "            " << this->last_pmnt.get_day() << ":" << this->last_pmnt.get_month() << ":" <<
		this->last_pmnt.get_year() << "   ";
}