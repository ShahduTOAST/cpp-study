#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include"queue.h"
#include<iostream>
using std::cin;
using std::cout;
namespace shahdu {
	void test01() {
		shahdu::stack<int> st;
		st.push(1);
		st.push(2);
		st.pop();
		st.push(3);
		st.push(4);
		st.pop();
		st.push(5);
		while (!st.empty()) {
			cout << st.top() << ' ';
			st.pop();
		}
		cout << endl;
	}
	void test02() {
		shahdu::queue<int> st;
		st.push(1);
		st.push(2);
		st.pop();
		st.push(3);
		st.push(4);
		st.pop();
		st.push(5);
		while (!st.empty()) {
			cout << st.front() << ' ';
			st.pop();
		}
		cout << endl;
	}
}

int main() {
	//shahdu::test01();
	shahdu::test02();
	return 0;
}