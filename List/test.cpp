#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;

namespace shahdu{
	void test01() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		
		list<int>::iterator it = lt.begin();
		while (it != lt.end()) {
			cout << *it << ' ';
			++it;
		}
		cout << "\n";
	}
	
	void test02() {
		list<int> lt;
		lt.insert(lt.end(), 1);
		lt.insert(lt.end(), 2);
		lt.insert(lt.end(), 3);
		lt.insert(lt.end(), 4);
		lt.insert(lt.end(), 5);
		lt.insert(lt.begin(), 5);

		for (auto& e : lt) {
			cout << e << ' ';
		}
		cout << "\t";

		list<int> lt2;
		lt2.push_front(1);
		lt2.push_front(3);
		lt2.push_front(2);
		lt2.push_front(4);
		for (auto& e : lt2) {
			cout << e << ' ';
		}
		cout << "\t";

		lt2.pop_front();
		lt2.pop_back();
		for (auto& e : lt2) {
			cout << e << ' ';
		}
		cout << lt2.size() << "\t";
	}

	//void test_list4()
	//{
	//	//AA aa1 = { 1,1 };
	//	std::vector<AA> v1;
	//	v1.push_back({ 1,1 });
	//	v1.push_back({ 2,2 });
	//	v1.push_back({ 3,3 });
	//	vector<AA>::iterator it1 = v1.begin();
	//	while (it1 != v1.end())
	//	{
	//		cout << it1->_a1 << ":" << it1->_a2 << endl;
	//		++it1;
	//	}
	//	cout << endl;
	
	//	list<AA> lt1;
	//	lt1.push_back({ 1,1 });
	//	lt1.push_back({ 2,2 });
	//	lt1.push_back({ 3,3 });
	//	list<AA>::iterator lit1 = lt1.begin();
	//	while (lit1 != lt1.end())
	//	{
	//		//cout << (*lit1)._a1 <<":"<< (*lit1)._a2 << endl;
	//		// 特殊处理，省略了一个->,为了可读性
	//		cout << lit1->_a1 << ":" << lit1->_a2 << endl;
	//		cout << lit1.operator->()->_a1 << ":" << lit1.operator->()->_a2 << endl;
	
	//		++lit1;
	//	}
	//	cout << endl;
	//}
}

int main() {
	//shahdu::test01();
	shahdu::test02();
	return 0;
}
