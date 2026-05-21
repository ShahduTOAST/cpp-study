#pragma once
#include<iostream>
#include<assert.h>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::endl;
using std::strlen;
//using namespace std;
namespace st {
	class string {
	public:
		//这里是cpp特殊处理，只有static const可以这样(疑似只能用给整形，现在浮点啥的好像都可以了)
		static const size_t npos = -1;
		typedef char* iterator;
		typedef const char* const_iterator;
		friend istream& operator>>(istream& in, string& str);
		friend ostream& operator<<(ostream& out, const string& str);
		/*string() :
			_size(0),
			_capacity(0) {//先走初始化再走函数，所以new放后面
			_str = new char[1] {""};//这里给空串直接就是/0
		}*///下面有二合一的

		string(const char* str = "") ://这里注意别用混了
			_size(strlen(str)) {
			_capacity = _size;
			_str = new char[_size + 1];//存储多个/0
			memcpy(_str, str, _size + 1);///0也要传，不然没结束标志
		}

		string(const string& str) :
			_size(str._size),
			_capacity(str._capacity) {
			_str = new char[_size + 1];
			memcpy(_str, str._str, _size + 1);//这里是第二个元素不是char*，其他解决方法 1.复用=，2.用函数获取地址
		}
		string& operator=(const string& s);

		~string() {
			delete[] _str;
			_size = 0;
			_capacity = 0;
			_str = nullptr;
		}
		// access
		char& operator[](size_t i);
		const char& operator[](size_t i)const;
		// iterator
		iterator begin();
			//这里要注意一下，const啥不能修改，是迭代器本身不能修改
			//const iterator begin()const;错误样例
			//还有个好玩的，就是const会越过typedef
		const_iterator begin()const;
		iterator end();
		const_iterator end()const;

		// modify
		void push_back(char c);
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void clear();
		void swap(string& s);
		const char* c_str()const {//这里有个知识点，const对象只能用const函数
			return _str;
		}

		// capacity
		size_t size()const;
		size_t capacity()const;
		bool empty()const;
		void resize(size_t n, char c = '\0');
		void reserve(size_t n);
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len = npos);
		//relational operators
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;

	private:
		int _size;
		int _capacity;
		char* _str;
	};

}