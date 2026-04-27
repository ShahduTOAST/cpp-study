#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year),
		_month(month),
		_day(day) {
		if (year<0 || month < 1 || month>12 || day>GetMonthDay(year, month) || day < 0) {
			cout << "日期非法" << endl;
			exit(1);
		}
	}

	Date(const Date& A)
		:_year(A._year),
		_month(A._month),
		_day(A._day) {}

	~Date() {
		//按需写
	}

	int GetMonthDay(int year, int month);
	void print() {
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
	Date& operator +=(int day);//+=重载
	Date operator +(int day);
	Date& operator -=(int day);
	Date operator -(int day);
	Date& operator=(const Date& d);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};