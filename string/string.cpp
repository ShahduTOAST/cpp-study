#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
using namespace std;
namespace st {
	string& string::operator=(const string& s) {
		int len = s.size();
		if (len > _capacity) {
			reserve(len);
		}
		return *this;
	}

	//const size_t string::npos = -1;//这里比较特殊，可以直接不用声明定义分离
	//istream& operator>>(istream& in, st::string& str) {
	//	in >> str._str >> endl;	
	//}
	ostream& operator<<(ostream& out, const string& str) {
		for (size_t i = 0; i < str.size() ; i++) {
			out << str[i];
		}
		return out;
	} 
	istream& operator>>(istream& in, string& string) {
		char* tmp = new char[256];
		char ch;
		int i = 0;
		ch = in.get();
		while (ch != ' ' && ch != '\n') {
			tmp[i++] = ch;
			if (i == 255) {//更新数据
				tmp[i] = '\0';
				string += tmp;
				i = 0;
			}
			ch = in.get();
		}
			if (i) {
				tmp[i] = '\0';
				string += tmp;
			}
		delete[] tmp;	
		return in;
	}
	// access
	char& string::operator[](size_t i) {
		assert(i < _size);
		return _str[i];
	}

	const char& string::operator[](size_t i)const {
		assert(i < _size);
		return _str[i];
	}

	// iterator
	string::iterator string::begin() {
		return _str;
	}

	string::const_iterator string::begin() const{
		return _str;
	}

	string::iterator string::end() {
		return _str + _size;
	}

	string::const_iterator string::end() const{
		return _str + _size;
	}


	// modify
	void string::push_back(char c) {
		//扩容
		if (_size + 1 > _capacity) {
			int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	string& string::operator+=(char c) {
		push_back(c);
		return *this;
	}
	void string::append(const char* str) {
		size_t len = strlen(str);
		if (_size + len > _capacity) {
			int newcapacity = _size + len > _capacity ? _size + len : _capacity;//扩容这里看你想咋扩
			//int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		memcpy(_str + _size, str, strlen(str) + 1);
		_size = _size + len;
	}
	string& string::operator+=(const char* str) {
		append(str);
		return *this;
	}

	void string::clear() {
		_str[0] = '\0';
		_size = 0; 
		_capacity = 0;
	}

	void string::swap(string& s) {
		char* tmp = _str;
		_str = s._str;
		s._str = tmp;
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	// capacity
	size_t string::size()const{
		return _size;
	}

	size_t string::capacity()const{
		return _capacity;
	}

	bool string::empty()const{
		return _size == 0;
	}

	void string::resize(size_t n, char c){
		if (n > _capacity) {//扩容
			reserve(n);
		}
		for (size_t pos = _size; pos < n; ++pos) {//填充，如果不符合进不来没事
			_str[pos] = c;
		}
		_str[n] = '\0';
		_size = n;
	}

	void string::reserve(size_t n) {
		if (n > _capacity) {
			char* tmp = new char[n + 1];
			if (_str) {//别给空指针解引用
				memcpy(tmp, _str, _size + 1);
				delete[] _str;
			}
			_str = tmp;
			_capacity = n;
		}
	}
	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	string& string::insert(size_t pos, char c) {
		assert(pos < _size);//防越界
		if (_size + 1 > _capacity) {
			reserve(_capacity ? 2 * _capacity : 4);//别写反了
		}
		size_t end = _size + 1;
		while (end > pos) {
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		++_size;
		return *this;
	}

	string& string::insert(size_t pos, const char* str) {
		assert(pos < _size);
		size_t len = strlen(str);
		if (_size + len > _capacity) {//扩容
			reserve(2 * _capacity > _size + len ? 2 * _capacity : _size + len);
		}
		//memmove(_str + pos + len, _str + pos, _size - pos + 1);
		//挪数据
		for (size_t end = _size + len; end > pos + len; end--) {
			_str[end] = _str[end - len];
		}

		for (int i = pos; i < pos + len; i++) {
			_str[i + 1] = str[i - pos];
		}
		_size += len;
		return *this;
	}
	// 删除pos位置开始长度为len的串，并返回该元素的下一个位置
	string& string::erase(size_t pos, size_t len) {
		assert(pos < _size);
		if (len == npos || len >= _size - pos) {
			_str[pos] = '\0';
			_size = pos;
		}
		else {
			memmove(_str + pos, _str + pos + len, _size - pos - len + 1);
			_size -= len;
		}
		return *this;

	}
	//relational operators
	bool string::operator<(const string& s) {
		size_t len1 = strlen(_str), len2 = strlen(s._str);
		int i = 0, j = 0;
		for (i, j;  i < len1 && j < len2; i++, j++) {
			if (s[j] < _str[i]) return false;
		}
		if (j < len2) return true;//没走完
		return false;
	}
	bool string::operator<=(const string& s) {
		return *this < s || (*this == s);
	}
	bool string::operator>(const string& s) {
		return !(*this <= s);
	}
	bool string::operator>=(const string& s) {
		return !(*this < s);
	}
	bool string::operator==(const string& s) {
		if (_size != s._size) return false;
		for (int i = 0, j = 0; i < _size; i++, j++) {
			if (_str[i] != s[j])return false;
		}
		return true;
	}
	bool string::operator!=(const string& s) {
		return !(*this == s);
	}
	size_t string::find(char c, size_t pos) const {
		assert(pos < _size);
		size_t i = pos;//从pos位置开始
		for (i; i < _size; i++) {
			if (_str[i] == c) return i;
		}
		return -1;
	}
	size_t string::find(const char* s, size_t pos) const {
		assert(pos < _size);
		size_t i = pos;
		int len = strlen(s);
		for (i; i < _size; i++) {
			if (memcmp(_str + i, s, len) == 0) return i;
		}
		return - 1;
	}


}
	
