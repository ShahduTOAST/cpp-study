#pragma once
#include<iostream>
#include"string.h"
using namespace st;

//这个是库函数测试
void test01() {
	string a("abc");
	string b(a);
	//cout << a.c_str() << b.c_str() << endl;
	cout << a << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i]++ << ' ';
	}
	const string s3("hello bit");
	for (size_t i = 0; i < s3.size(); i++) {
		cout << s3[i] << endl;
	}
	string::iterator it = a.begin();
	for (it; it < a.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	string::const_iterator it1 = s3.begin();
	for (it1; it1 < s3.end(); it1++) {
		cout << *it1;
	}
	//for遍历
	for (auto it : s3) {
		cout << it;
	}
}
//以下是自己的函数测试
void test02() {
	string a("hello world");
	/*a.push_back('!');
	a.push_back('!');
	a.push_back('!');
	a.push_back('!');*/
	string s("adda");
	/*for (int i = 0; i < 100000; i++) {
		s.append("aaaaaaaaa");
	}*/
	cout << endl;
	a.append("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	string b("small");
	b.append("test");
	cout << a << endl;
	cout << b << endl;
}
void test03() {
	string a("hello world!!!");
	a += '+';
	a += "lalalala";
	a.push_back('\0');
	a.append("1111111111111111");
	for (auto ch : a) {
		cout << ch;
	}
	cout << endl;
	cout << a << endl;//这个是识别'\0'的
}
void test04() {
	string a("hello word!");
	a.insert(0, '@');
	cout << a << endl;
	string b("hello word!");
	b.erase(2);
	cout << b << endl;
	string c("hello word!");
	c.erase(2, 100);
	cout << c << endl;
	string d("hello word!");
	//a.erase(5, '@');
	d.erase(6, 4);
	cout << d << endl;
	string e("hello word!");
	cout << e << endl;
	e.insert(10, "aaa");
	cout << e << endl;
	string s("hello world");
	s.insert(7, '\0');
	cout << s << endl;
}

void test05() {
	string a("hello world");
	int i = a.find('e');
	cout << i << endl;
	int j = a.find("ee");
	cout << j << endl;
	string b("hello");
	string c("hallo");
	string d("hello");
	string e("hello world");
	cout << (b == c) << endl;
	cout << (b != c) << endl;
	cout << (b <= c) << endl;
	cout << (b > c) << endl;
	cout << (b < c) << endl;
	cout << (b >= c) << endl;
	cout << endl;
	cout << (b == e) << endl;
	cout << (b != e) << endl;
	cout << (b > e) << endl;
	cout << (b < e) << endl;
	cout << (b >= e) << endl;
	cout << (b <= e) << endl;
	cout << (d == b) << endl;
	cout << (d >= b) << endl;
	cout << (d <= b) << endl;
}
void test07() {
	string a;
	string b;
	cin >> a >> b;
	cout << endl;
	cout << a << b << endl;
}
int main() {
	//test01();
	//test02();
	//test03();
	//test05();
	test07();
}