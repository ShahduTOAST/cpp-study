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
}

int main() {
	//shahdu::test01();
	shahdu::test02();
	return 0;
}