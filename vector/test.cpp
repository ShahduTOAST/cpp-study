#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"

namespace shahdu {
	void test01() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int> v1(5, 100);
		const vector<int> v2(v1.start(), v1.finish());
		//v2.start() = 1;
		const vector<int> vn;
		vn.start();
		//*it = 1; 
		vector<int>::iterator;
		vector<int> v3(v);
		for (auto e : v3) {
			cout << e << ' ';
		}
		vector<int> v4 = { 1,3,4,5,37,8 };
	}
	void print(const vector<int>& v) {     // 函数承诺：我不改 v
		vector<int>::const_iterator it = v.start();   // ❌ 如果返回普通 iterator...
		//*it = 10;                              //    那这里就能偷偷改 v 了！
	}
	void test02() {
		vector<int> v1(5, 100);
		int a = 5;
		v1[0] = a;
		v1[4] = a;
		for (auto e : v1) {
			cout << e <<' ';
		}
		v1.insert(v1.begin(), 3);
		for (auto e : v1) {//这里可能会有迭代器失效，即扩容后不用（insert，vs下erase也会认为失效）
			cout << e << ' ';
		}
		v1.erase(v1.begin());
		v1.erase(v1.begin());
		v1.erase(v1.begin());
		v1.erase(v1.begin());
		v1.erase(v1.begin());
		v1.erase(v1.begin());
		/*v1.erase(v1.begin()); */
		for (auto e : v1) {
			cout << e << ' ';
		}
	}
	void test03() {
		/*vector<std::string> st;
		st.push_back("张三");
		st.push_back("laowang");
		for (auto e : st) {
			cout << e << " ";
		}*/
		vector<int> v1(5, 100);
		vector<int> v2;
		v2 = v1;
		for (auto e : v2) {
			cout << e << ' ';
		}
	}
}

int main() {
	//shahdu::test01();
	/*shahdu::vector<int> v1(5, 100);
	shahdu::print(v1);*/
	//shahdu::test02();
	shahdu::test03();
	return 0;
}
