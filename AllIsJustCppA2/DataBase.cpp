#include "DataBase.h"




//*******************************************************************
//              function DataBase::add_account(const Account& acc)
//   Parameters: Account - account in our bank
//   Add account to the database
//   return void
//********************************************************************
void DataBase::add_account(const Account& acc)
{
	this->all_bank_accounts.push_back(acc);
}



//*******************************************************************
//                function DataBase::is_acc_exists(const string& acc)
//   Parameters: string - account number
//   Method checks if such account exists in database
//   return bool
//********************************************************************
bool DataBase::is_acc_exists(const string& acc)
{
	for (vector<Account>::iterator it = this->get_all_bank_accounts().begin(); it != this->get_all_bank_accounts().end(); ++it)
	{
		if (it->get_acc_number() == acc)
		{
			return true;
		}
	}

	return false;
}



//*******************************************************************
//               function DataBase::get_account(const string& acc)
//   Parameters: string - account number
//   Method returns account from database with number
//   return Account
//********************************************************************
Account& DataBase::get_account(const string& acc)
{
	for (vector<Account>::iterator it = this->get_all_bank_accounts().begin(); it != this->get_all_bank_accounts().end(); ++it)
	{
		if (it->get_acc_number() == acc)
		{
			return (*it);
		}
	}
}



//*******************************************************************
//               function DataBase::make_transaction(const string& from, const string& to, const double& sum)
//   Parameters: string from - account number from which withdrow money, 
//               string to - aaccount number in which deposit money, double sum - amount of money for transaction
//   Transfer money from one account to another
//   return void
//********************************************************************
void DataBase::make_transaction(const string& from, const string& to, const double& sum)
{
	if (this->is_acc_exists(from) && this->is_acc_exists(to))
	{
		this->withdraw(from, sum);
		this->deposit(to, sum);
	}
	else
	{
		cout << "Wrong information" << endl;
	}
}



//*******************************************************************
//                function DataBase::deposit(const string& acc, const double& sum)
//   Parameters: string  - account number for deposit, double sum - sum of the deposit
//   Deposit amount of money on account
//   return void
//********************************************************************
void DataBase::deposit(const string& acc, const double& sum)
{
	for (vector<Account>::iterator it = this->get_all_bank_accounts().begin(); it != this->get_all_bank_accounts().end(); ++it)
	{
		if (it->get_acc_number() == acc)
		{
			it->deposit(sum);
			return;
		}
	}

	cout << "No such account: " << acc << endl;

}



//*******************************************************************
//                function DataBase::withdraw(const string& acc, const double& sum)
//   Parameters: string  - account number for withdraw, double sum - sum of the withdraw
//   withdraw amount of money from account
//   return void
//********************************************************************
void DataBase::withdraw(const string& acc, const double& sum)
{
	for (vector<Account>::iterator it = this->get_all_bank_accounts().begin(); it != this->get_all_bank_accounts().end(); ++it)
	{
		if (it->get_acc_number() == acc)
		{
			it->withdraw(sum);
			return;
		}
	}

	cout << "No such account: " << acc << endl;
}



//*******************************************************************
//                function input_acc_info(DataBase& a)
//   Parameters: DataBase - database for saving accounts
//   This method gives a primitive graphical interface wich allows 
//	 input data for creating account
//   return void
//********************************************************************
void input_acc_info(DataBase& a)
{
		string name;
		char type;
		cout << "Input information for creationg new Acccount" << endl;
		cout << "Input account name:";
		cin >> name;
		cout << "Input account type: c(Checking) or s(Saving):";
		cin >> type;

		Account acc(name, type);
		a.add_account(acc);
		cout << "Congratulations! You have created Account in our bank." << endl;
		acc.show_info();
}



//*******************************************************************
//                function show_all_accs(DataBase& db)
//   Parameters: DabaBase - database where save all accounts 
//   Prints information about all account in the database to console
//   return void
//********************************************************************
void show_all_accs(DataBase& db)
{
	for (vector<Account>::iterator it = db.get_all_bank_accounts().begin(); it != db.get_all_bank_accounts().end(); ++it)
	{
		cout << "-------------------------------------------------------------------" << endl;
		it->show_info();
		cout << endl;
	}

}



//*******************************************************************
//                function input_interface(DataBase& db)
//   Parameters: DabaBase - database where save all accounts
//   Primitive graphical interface for working with database
//   return void
//********************************************************************
void input_interface(DataBase& db)
{
	int choice;
	char con = 'y';
	string acc_num_depos;
	string acc_num_with;
	string acc_num;
	double sum;
	string acc_num1;

	while (con != 'n')
	{
		cout << "+------------------------------------------------+" << endl;
		cout << "|Chose your action                               |" << endl;
		cout << "|1 - Create new account                          |" << endl;
		cout << "|2 - Withdraw money from account                 |" << endl;
		cout << "|3 - Deposit money on account                    |" << endl;
		cout << "|4 - Money transfer from one account to another  |" << endl;
		cout << "|5 - Show all accounts                           |" << endl;
		cout << "+------------------------------------------------+" << endl;
		cout << "Your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input_acc_info(db);
			cout << endl << "Continue(y/n):";
			cin >> con;
			cout << endl;
			break;
		case 2:
			cout << "Input account number: ";
			cin >> acc_num_with;
			cout << "Input sum:";
			cin >> sum;
			db.withdraw(acc_num_with, sum);
			db.get_account(acc_num_with).show_info();
			cout << endl << "Continue(y/n):";
			cin >> con;
			break;
		case 3:
			cout << "Input account number: ";
			cin >> acc_num_depos;
			cout  << "Input sum:";
			cin >> sum;
			db.deposit(acc_num_depos, sum);
			db.get_account(acc_num_depos).show_info();
			cout << endl << "Continue(y/n):";
			cin >> con;
			break;
		case 4:
			cout << "Input FROM account number:";
			cin >> acc_num;
			cout  << "Input TO account number:";
			cin >> acc_num1;
			cout << "Input sum of the transaction:";
			cin >> sum;
			db.make_transaction(acc_num, acc_num1, sum);
			db.get_account(acc_num).show_info();
			cout << endl;
			db.get_account(acc_num1).show_info();
			cout << endl << "Continue(y/n):";
			cin >> con;
			break;
		case 5:
			show_all_accs(db);
			cout << endl << "Continue(y/n):";
			cin >> con;
			break;
		default:
			cout << "No such action";
			break;
		}
	}
}



//*******************************************************************
//               function filler(DataBase& db)
//   Parameters: DataBase - database for saving accounts
//   It fills database with samples of accounts
//   return void
//********************************************************************
void filler(DataBase& db)
{
	const size_t acc_name = 6;
	const size_t ammount_of_accs = 35;

	
	string res("MAIN ACC");
	double sum;
	char n;
	for (size_t i = 0; i < ammount_of_accs; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		sum = (gen() % 50000);
		Account acc(res, 'c');
		acc.deposit(sum);
		db.add_account(acc);
	}
	
}