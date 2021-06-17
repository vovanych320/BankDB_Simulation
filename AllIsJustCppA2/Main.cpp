#include "DataBase.h"

//**************************************************************
//                    	Assignment #2
//                    Student 1:
//                    Data Structures Date: 10/23/2020 (M/D/Y)
//***************************************************************
//    This is simulation of Babk data base. There are three classes:
//  - Date - saves information about last transaction: day:month:year;
//  - Account - saves information about account in our bank:
//		account name, type, number, balance, last transaction date
//      and gives additional methods for work with this class;
//  - DataBase - saves objects of class Account in STL vector and gives
//      methods for work with this data base;
//*****************************************************************



//*******************************************************************
//               function  main()
//   Parameters:
//   Main function - starts our program
//   return int
//********************************************************************
int main()
{
	DataBase data("BankDB");
	filler(data);

	input_interface(data);
	
	return 1;
}