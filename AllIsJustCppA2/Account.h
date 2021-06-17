#pragma once
#pragma warning(disable : 4996)

#include <string>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
#include "Date.h"


class Account
{
private:
	string acc_number;
	char acc_type;
	string acc_name;
	double acc_balance;
	Date last_pmnt;
public:
	Account(const string& acc_n, const char& acc_t) :
		acc_type(acc_t), acc_name(acc_n), acc_balance(0)
	{
		this->acc_number = this->create_id(16);
	};

	~Account()
	{

	};


//*******************************************************************
//               function  Account::get_acc_number()
//   Parameters:
//   return account number
//   return string
//********************************************************************
	string get_acc_number() { return acc_number; };
	
//*******************************************************************
//               function  Account::get_acc_type()
//   Parameters:
//   return account type
//   return char
//********************************************************************
	char get_acc_type() { return acc_type; };

//*******************************************************************
//               function  Account::get_acc_name()
//   Parameters:
//   return account name
//   return string
//********************************************************************
	string get_acc_name() { return acc_name; };

//*******************************************************************
//               function  Account::get_acc_balance()
//   Parameters:
//   return account balance
//   return double
//********************************************************************
	double get_acc_balance() { return acc_balance; };

//*******************************************************************
//               function  Account::get_last_pmnt()
//   Parameters:
//   return account date of last transaction
//   return Date
//********************************************************************
	Date get_last_pmnt() { return last_pmnt; };



	void withdraw(const double& bal);
	void deposit(const double& bal);
	string create_id(const size_t& size);
	void show_info();
};