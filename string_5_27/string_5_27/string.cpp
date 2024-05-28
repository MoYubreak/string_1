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
	//��ͳд��
	//string::string(const string& str)
	//{
	//	_str = new char[str._capacity + 1];
	//	strcpy(_str, str._str);
	//	_capacity = str._capacity;
	//	_size = str._size;
	//}
	
	//�ִ�д��
	string::string(const string& str)
	{
		string str1(str._str);
		swap(str1);
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
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	string& string::operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(string str)
	{
		append(str._str);
		return *this;
	}

	const size_t string::npos = -1;

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

	size_t string::find(const char ch, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos) const
	{
		assert(pos < _size);
		char* ppos = strstr(_str + pos, str);
		return ppos - _str;
	}

	//��ͳд��
	//string& string::operator=(const string& str)
	//{
	//	if (this != &str)
	//	{
	//		if (_capacity < str._capacity)
	//			reserve(str._capacity);
	//		memcpy(_str, str._str, str._size + 1);
	//		_size = str._size;
	//	}
	//	return *this;
	//}

	//�ִ�д��
	string& string::operator=(string str)
	{
		swap(str);
		return *this;
	}

	string& string::operator=(const char* str)
	{
		size_t len = strlen(str);
		if (_capacity < len)
			reserve(len);
		memcpy(_str, str, len + 1);
		_size = len;
		return *this;
	}

	string string::substr(size_t pos, size_t len) const
	{
		assert(pos < _size);
		string str;
		if (len == npos)
			len = _size;
		for (size_t i = 0; i < len; i++)
		{
			str += _str[pos + i];
		}
		return str;
	}

	void string::swap(string & str)
	{
		std::swap(_str, str._str);
		std::swap(_size , str._size);
		std::swap(_capacity , str._capacity);
	}

	bool string::operator<(const string& str)
	{
		return strcmp(_str, str._str) < 0;
	}
	bool string::operator>(const string& str)
	{
		return !((*this) <= str);
	}
	bool string::operator<=(const string& str)
	{
		return (*this) < str || (*this) == str;
	}
	bool string::operator>=(const string& str)
	{
		return !((*this) < str);
	}
	bool string::operator==(const string& str)
	{
		return strcmp(_str, str._str) == 0;
	}
	bool string::operator!=(const string& str)
	{
		return !((*this) == str);
	}

	void string::clear()
	{
		*this = "";
	}
	istream& operator>>(istream& in, string& str)
	{
		str.clear();
		char tmp[128];
		char ch;
		size_t i = 0;
		in.get(ch);
		while (ch != ' ' && ch != '\n')
		{
			tmp[i++] = ch;
			if (i == 127)
			{
				tmp[i] = '\0';
				str += tmp;
				i = 0;
			}
			in.get(ch);
		}
		if (i != 0)
		{
			tmp[i] = '\0';
			str += tmp;
		}
		return in;
	}
	ostream& operator<<(ostream& out, string& str)
	{
		out << str.c_str();
		return out;
	}
}