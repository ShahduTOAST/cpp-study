#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<assert.h>
using std::cin;
using std::cout;

namespace shahdu {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	vector()
		/*:_start(nullptr) 有缺省值可以不写初始化列表，除非是必须要赋值的
		,_finish(nullptr)
		,_end_of_storage(nullptr)*/{}

	vector(size_t n,const T& val = T()) {
		reserve(n);//优化效率，减少扩容次数
		size_t i = 0;
		while (i < n) {
			push_back(val);
			++i;
		}
	}
	vector(int n, const T& val = T()) {//这里有个匹配问题，如果不写int的构造的话，就会导致默认先用这个，也就是报错。因为有个int到size_t的强转（5，100）
		reserve(n);//优化效率，减少扩容次数
		int i = 0;
		while (i < n) {
			push_back(val);
			++i;
		}
	}
	template <class InputIterator>
	vector(InputIterator begin, InputIterator end){//可以使用其他容器的迭代器初始化
		assert(begin < end);
		reserve(end-begin);
		for (; begin < end; ++begin) {
			push_back(*begin);
		}
	}
	vector(std::initializer_list<T> il)
	{
		reserve(il.size());
		for (auto& e : il)
		{
			push_back(e);
		}
	}

	vector(const vector<T>& val)
		/*:_start(nullptr)
		, _finish(nullptr)
		, _end_of_storage(nullptr)*/ {
		reserve(val.capacity());
		for (auto& e : val) {
			push_back(e);
		}
	}

	~vector() {
		if(_start){
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
	}

	size_t capacity() const{
		return _end_of_storage - _start;
	}

	size_t size() const{
		return _finish - _start;
	}

	iterator start(){
		return _start;
	}

	iterator finish(){
		return _finish;
	}
	iterator begin() const{
		return _start;
	}

	iterator end() const{
		return _finish;
	}
	const_iterator start() const {
		return _start;
	}

	const_iterator finish() const {
		return _finish;
	}

	iterator find(iterator begin, iterator end, T& x)const {
		assert(end >= begin);
		iterator it = begin;
		while ((it < end) && (*it != x)) {
			++it;
		}
		return it;
	}

	void swap(vector<T>& v) {
		std::swap(_start, v._start);
		std::swap(_finish, v._finish);
		std::swap(_end_of_storage, v._end_of_storage);
	}

	T& operator[](size_t i) {//记着拷贝&，死循环了。
		assert(i >= 0);
		assert(i < capacity());
		return *(_start + i);
	}

	vector<T>& operator=(vector<T> v) {
		swap(v);
		return *this;
	}

	void reserve(const size_t n) {
		if (n > capacity()) {//不够再扩，缩容的话，记着删除空间(我记着在Linux会缩)
			size_t old_size = size();
			iterator tmp = new T[n];
			if (_start) {
				//memcpy(tmp, _start, old_size * sizeof(T));
				//delete[] _start;//这里在以string为例的，会由于扩容后原空间释放导致乱码，原来的string里面的指向不变，也就是我把他的_begin也搞过来了）
				for (size_t i = 0; i < old_size; i++) {
					tmp[i] = _start[i]
				}
				delete[] _start;
			}
			_start = tmp;
			_finish = tmp + old_size;
			_end_of_storage = _start + n;
		}
	}

	void push_back(const T& x) {//深拷贝内置类型记着加const
		if (_end_of_storage == _finish) {
			size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
			reserve(newcapacity);
		}
		*_finish = x;
		++_finish;
	}
	void pop_back(){
		assert(_start < _finish);
		--_finish;
	}
	iterator insert(iterator pos, const T& x) {
		assert(pos >= _start);
		assert(pos <= _end_of_storage);

		if (_end_of_storage == _finish) {
			size_t len = pos - _start;//更新pos（失效了）
			size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
			reserve(newcapacity);
			pos = _start + len;
		}

		if (pos < _finish) {
			iterator tmp = _finish;
			while (tmp > pos) {
				*tmp = *(tmp - 1);
				--tmp;
			}
			*pos = x;
			++_finish;
		}
		return pos;
	}
	
	iterator erase(iterator pos) {//(这里为了适应多平台，需要应对迭代器失效，即给个返回值)
		assert(pos >= _start);
		assert(pos <_finish);

		//assert(_start < _finish);//防止越界,多余了，if判断了
		iterator tmp = pos;
		while (tmp + 1 < _finish) {
			*tmp = *(tmp + 1);
			tmp++;//pos应该会在这里更改
		}
		--_finish;
		
		return pos;// 如果变化，pos随变化而变化，返回pos。
	}

	void resize(size_t n, T& val = T()) {
		if (n > size()) {
			reserve(n);
			while (_finish != _start + n) {
				*_finish = val;
				++_finish;
			}
		}
		else {
			_finish = _start + n;
		}
	}
	private:
		iterator _start			 = nullptr;
		iterator _finish		 = nullptr;
		iterator _end_of_storage = nullptr;
	};
}

