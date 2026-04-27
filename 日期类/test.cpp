#define _CRT_SECURE_NO_WARNINGS
#include"root.h"
using namespace std;
void test01() {
	Date d1(2000,5,3);
	d1 += -5;
	//int a = d.GetMonthDay(400, 2);
	Date d2 = d1 + 5000;
	Date d3 = d1;
	d3 -= 5000;
	Date d4 = d3 - 266;
	d1.print();
	d2.print();
	d3.print();
	d4.print();
	/*++d3;
	++d3;
	++d3;
	++d3;
	++d3;
	++d3;
	++d3;
	++d3;*/
	d3 += 5;
	++d3;
	d3.print();
	int day = d1 - d2;
	cout << day << endl;
}

int main() {
	test01();
	return 0;
}