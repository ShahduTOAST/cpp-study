#pragma once
#include<assert.h>
#include<iostream>
namespace shahdu {
	template<class T>
	struct list_node {
		list_node* _prev;
		list_node* _next;
		T _data;

		list_node(const T& x = T()) 
		:_prev(nullptr),
		_next(nullptr),
		_data(x) {}
	};

	template<class T, class Ref>
	struct list_iterator {//重载节点	
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref> Self;//这里的ref是返回类型是否加const，例如const int 和int
		Node* _node;

		list_iterator(Node* node):
		_node(node){}

		Ref operator*() {
			return _node->_data;
		}
		Ref& operator ->() {
			return &_node->_data;
		}
		Self& operator++() {
			_node = _node->_next;
			return *this;
		}
		Self operator++(int) {
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--() {
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int) {
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator ==(const Self& s) const{
			return _node == s._node;
		}
		bool operator !=(const Self& s) const {
			return _node != s._node;
		}
	};

	template<class T>//list
	class list {
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T, T&> iterator;//这里不能让typedef前后名字相同
		typedef list_iterator<T, const T&> const_iterator;//这俩其实就是减少工作量，让编译器自己生成
		void empty_init() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list() {
			empty_init();
		}

		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear() {
			auto it = begin();
			while(it != end()) {
				it = erase(it);
			}
		}
		iterator begin() {//这里得强转，不是迭代器类型
			return iterator(_head->_next);
		}
		iterator end() {
			return iterator(_head);
		}
		const_iterator begin() const{//这里得强转，不是迭代器类型
			return const_iterator(_head->_next);
		}
		const_iterator end() const{
			return const_iterator(_head);
		}
		T operator = (const T t) {
			swap(t);
			return *this;
		}
		void swap(const T& t) {
			std::swap(_head, t._head);
		}
		void push_back(const T& n) {
			/*Node* tail = _head->_prev;
			Node* newnode = new Node(n);

			_head->_prev = newnode;
			newnode->_next = _head;
			newnode->_prev = tail;
			tail->_next = newnode;
			_size++;*/
			insert(end(), n);
		}
		void push_front(const T& n) {
			insert(begin(), n);
		}
		void pop_back() {
			erase(--end());
		}
		void pop_front() {
			erase(begin());
		}
		void insert(iterator pos, const T& x) {
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* tmp = new Node(x);
			
			prev->_next = tmp;
			tmp->_prev = prev;
			cur->_prev = tmp;
			tmp->_next = cur;

			++_size;
		}
		iterator erase(iterator pos){
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			Node* cur = pos._node;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			
			--_size;

			return next;
		}
		size_t size() const{
			return _size;
		}
	private:
		Node* _head;
		int _size;
	};
}