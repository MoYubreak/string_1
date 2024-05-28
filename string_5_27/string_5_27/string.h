#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

namespace moyu
{
	class string
	{
	public:
		string(const char* str = "");
		string(const string& str);
		size_t size();
		const char* c_str() const;
		char& operator[](size_t pos);
		const char& operator[] (size_t pos) const;
		~string();

		typedef char* iterator;
		iterator begin();
		iterator end();

		typedef const char* const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		void reserve(size_t n);
		void push_back(const char ch);
		string& append(const char* str);
		string& operator+=(const char* str);
		string& operator+=(const char ch);
		string& operator+=(string str);

		string& insert(size_t pos, const char ch);
		string& insert(size_t pos, const char* str);

		string& erase(size_t pos = 0, size_t len = npos);

		size_t find(const char ch, size_t pos = 0) const;
		size_t find(const char* str, size_t pos = 0) const;

		//传统写法
		//string& operator=(const string& str);
		//现代写法
		string& operator=(string str);
		string& operator=(const char* str);

		void swap(string& str);
		
		string substr(size_t pos = 0, size_t len = npos) const;

		bool operator<(const string& str);
		bool operator>(const string& str);
		bool operator<=(const string& str);
		bool operator>=(const string& str);
		bool operator==(const string& str);
		bool operator!=(const string& str);
		void clear();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos;
	};

	istream& operator>>(istream& in, string& str);
	ostream& operator<<(ostream& out, string& str);
}