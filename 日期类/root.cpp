#define _CRT_SECURE_NO_WARNINGS
#include"root.h"

int Date::GetMonthDay(int year, int month) {
	static int day[13] = { -1, 31,28,31,30,31, 30,31,31,30,31,30,31 };
	//闰年
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
		return 29;
	}
	else {
		return day[month];
	}
}

Date& Date::operator=(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}

Date& Date::operator +=(int day) {
	if (day <= 0) {
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year,_month)) {
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month == 13) {
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator +(int day) {
	Date tmp(*this);
	if (day <= 0) {
		tmp -= -day;
		return tmp;
	}
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month)) {
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;

		if (tmp._month == 13) {
			tmp._month = 1;
			tmp._year++;
		}
	}
	return tmp;
}

Date& Date::operator -=(int day) {
	if (day <= 0) {
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day < 0) {
		_day += GetMonthDay(_year, _month);
		if (_month == 1) {
			_month = 13;
			_year--;
		}
		_month--;
	}
	return *this;
}

Date Date::operator -(int day) {
	Date tmp = *this;
	if (day <= 0) {
		tmp += -day;
	}
	else {
		tmp._day -= day;
		while (tmp._day < 0) {
			tmp._day += GetMonthDay(tmp._year, tmp._month);
			if (tmp._month == 1) {
				tmp._month = 13;
				tmp._year--;
			}
			tmp._month--;
		}
	}
	return tmp;

}

Date& Date::operator++() {
	*this += 1;
	return *this;
}

Date Date::operator++(int) {
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--() {
	*this -= 1;
	return *this;
}

Date Date::operator--(int) {
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
// >运算符重载
bool Date::operator>(const Date& d) {
	if (_year > d._year) {
		return true;
	}
	else if ((_year == d._year) && (_month > d._month)) {
		return true;
	}
	else if ((_year == d._year) && (_month == d._month) && (_day > d._day)) {
		return true;
	}
	return false;
}
// ==运算符重载
bool Date::operator==(const Date& d) {
	if (_year == d._year && _month == d._month && _day == d._day) {
		return true;
	}
	return false;
}
// >=运算符重载
bool Date::operator >= (const Date& d) {
	return ((*this) > d) || *this == d;
}
// <运算符重载
bool Date::operator < (const Date& d) {
	return !(*this >= d);
}
// <=运算符重载
bool Date::operator <= (const Date& d) {
	return !(*this > d);
}
// !=运算符重载
bool Date::operator != (const Date& d) {
	return !(*this == d);
}
// 日期-日期 返回天数
int Date::operator-(const Date& d) {
	Date max(*this), min(d);
	int day = 0, flag = 1;
	if (*this < d) {
		flag = -1;
		max = d;
		min = *this;
	}
	while (max > min) {
		day++;
		min++;
	}
	return day * flag;
}
//声明与定义分离
//ostream& operator<<(ostream& out, const Date& d) {
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
