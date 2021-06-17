#pragma once
#include <vector>

using namespace std;

#include "Account.h"

class DataBase
{
private:
	vector<Account> all_bank_accounts;
public:
	DataBase(const string & name) 
	{
	
	};

	~DataBase() 
	{
	
	};

	void deposit(const string& acc, const double& sum);
	void withdraw(const string& acc, const double& sum);
	void make_transaction(const string& from, const string& to, const double& sum);

	bool is_acc_exists(const string& acc);

	void add_account(const Account& acc);
	Account& get_account(const string& acc);



//*******************************************************************
//                function DataBase::get_all_bank_accounts()
//   Parameters: 
//   return all account from our database
//   return vector<Account>&
//********************************************************************
	vector<Account>& get_all_bank_accounts() { return all_bank_accounts; };
};


void input_acc_info(DataBase& a);

void show_all_accs(DataBase& db);

void input_interface(DataBase& db);

void filler(DataBase& sb);