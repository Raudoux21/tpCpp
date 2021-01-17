
#include "date.h"
#include <iostream>
#include <cassert>

bool Date::checkDate(int month, int day) const {
	bool status = true;

	if ((month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) && (day > 31 || day < 1)) {
		status = false;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& (day > 30 || day < 1)) {
		status = false;
	}
	else if ((month == 2) && (day > 28 || day < 1)) {
		status = false;
	}
	if ((month < 1) || (month > 12)) {
		status = false;
	}
	return status;
}

bool Date::operator>(Date date)
{
	if (_year < date.getYear())
		return false;
	else if (_month < date.getMonth())
		return false;
	else if (_day < date.getDay())
		return false;
	return true;
}


bool Date::operator<(Date date)
{
	if (_year > date.getYear())
		return false;
	else if (_month > date.getMonth())
		return false;
	else if (_day > date.getDay())
		return false;
	return true;
}

int Date::operator-(Date date)
{
	return (getYear() * 365 + getMonth() * 30 + getDay()) - (date.getYear() * 365 + date.getMonth() * 30 + date.getDay());
}

Date::Date(int month, int day, int year)
{
	bool status = checkDate(month, day);
	
	_year = year;
	_month = month;
	_day = day;
}

Date::~Date() {
	//std::cout << "  Destructor: " << _month << "/" << _day << '\n';
}
int Date::getMonth() {
	return _month;
}

int Date::getDay() {
	return _day;
}
int Date::getYear()
{
	return _year;
}
Date Date::nextDay() {
	Date next(_month, _day + 1, _year);
	return next;
}
void Date::setYear(int year)
{
	_year = year;
}
std::string Date::toString() {
	/*std::string month[12] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
	std::string to_display;
	to_display = month[_month - 1] + "/" + std::to_string(_day);
	return to_display;*/
	return std::to_string(getDay()) + "/" + std::to_string(getMonth()) + "/" + std::to_string(getYear());
}

void Date::setMonth(int month) {
	assert((month >= 1) && (month <= 12) && "Month is not valid");
	_month = month;
}

void Date::setDay(int day) {
	bool status = checkDate(_month, day);
	assert(status == true && "Day is not valid");
	_day = day;
}