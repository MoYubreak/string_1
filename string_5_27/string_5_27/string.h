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

		string& insert(size_t pos, const char ch);
		string& insert(size_t pos, const char* str);

		string& erase(size_t pos = 0, size_t len = npos);

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos;
	};
}