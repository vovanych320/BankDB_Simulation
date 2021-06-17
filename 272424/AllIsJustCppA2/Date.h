#pragma once


class Date
{

private:
	int year = 0;
	int month = 0;
	int day = 0;

public:
	Date()
	{
	
	};
	
//*******************************************************************
//               function  Date::get_year()
//   Parameters:
//   Return year from date of the transaction
//   return int
//********************************************************************
	int get_year() { return year; };

//*******************************************************************
//               function  Date::get_month() 
//   Parameters:
//   Return month from date of the transaction
//   return int
//********************************************************************
	int get_month() { return month; };

//*******************************************************************
//               function  Date::get_day()
//   Parameters:
//   Return day from date of the transaction
//   return void
//********************************************************************
	int get_day() { return day; };


//*******************************************************************
//               function  Date::set_year(int year)
//   Parameters:int - year
//   Sets year of the last transaction
//   return void
//********************************************************************
	void set_year(int year) { this->year = year; };

//*******************************************************************
//               function  Date::set_month(int month)
//   Parameters:int - month
//   Sets month of the last transaction
//   return void
//********************************************************************
	void set_month(int month) { this->month = month; };

//*******************************************************************
//               function  Date::set_day(int day)
//   Parameters:int - year
//   Sets day of the last transaction
//   return void
//********************************************************************
	void set_day(int day) { this->day = day; };

};