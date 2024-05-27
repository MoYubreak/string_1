#include"string.h"

namespace moyu
{
	string::string(const char* str)
		: _size(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	string::~string()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
			_size = 0; 
			_capacity = 0;
		}
	}

	size_t string::size()
	{
		return _size;
	}
	const char* string::c_str() const
	{
		return _str;
	}
	char& string::operator[](size_t pos)
	{
		return _str[pos];
	}



	string::iterator string::begin()
	{
		return _str;
	}
	string::iterator string::end()
	{
		return _str + _size;
	}

	string::const_iterator string::begin() const
	{
		return _str;
	}
	string::const_iterator string::end() const
	{
		return _str + _size;
	}

	void string::reserve(size_t n)
	{

		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

	}
	void string::push_back(const char ch)
	{
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		_str[_size] = ch;
		_str[_size + 1] = '\0';
		_size++;
	}
	string& string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
		return *this;
	}

	const static size_t npos = -1;
	string& string::insert(size_t pos, const char ch)
	{
		assert(pos < _size);
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		assert(pos < _size);
		size_t len = strlen(str);
		size_t end = _size + len;
		if (end > _capacity)
		{
			reserve(_size + len);
		}
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}
		memcpy(_str + pos, str, len);
		_size += len;
		return *this;
	}

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos; i < _size - len; i++)
			{
				_str[i] = _str[i + len];
			}
			_size -= len;
			_str[_size] = '\0';
		}
		return *this;
	}
}