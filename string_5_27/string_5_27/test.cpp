#include"string.h"

namespace moyu
{
	void teststring1()
	{
		moyu::string str1;
		cout << str1.c_str() << endl;
		moyu::string str2("hello world!");
		cout << str2.c_str() << endl;
		for (size_t i = 0; i < str2.size(); i++)
		{
			cout << str2[i] << ' ';
		}
		cout << endl;
		for (size_t i = 0; i < str2.size(); i++)
		{
			str2[i] = 'H';
			cout << str2[i] << ' ';
		}
		cout << endl;
		cout << str2.c_str() << endl;

		string::iterator begin = str2.begin();
		string::iterator end = str2.end();
		while (begin < end)
		{
			cout << *begin << ' ';
			++begin;
		}
		cout << endl;

		for (auto ch : str2)
		{
			cout << ch << ' ';
		}
		cout << endl;

		const moyu::string str3("return");
		string::const_iterator const_begin = str3.begin();
		string::const_iterator const_end = str3.end();

		while (const_begin < const_end)
		{
			cout << *const_begin << ' ';
			++const_begin;
		}
		cout << endl;

		for (auto ch : str3)
		{
			ch = '1';
			cout << ch << ' ';
		}
		cout << endl;
		cout << str3.c_str() << endl;
	}

	void teststring2()
	{
		string str1;
		str1.push_back('1');
		str1.push_back('2');
		str1.push_back('3');
		str1.push_back('4');
		str1.push_back('5');
		for (size_t i = 0; i < str1.size(); i++)
		{
			cout << str1[i] << ' ';
		}
		cout << endl;

		string str2; 
		str2.append("hello world");
		cout << str2.c_str() << endl;

		str2.insert(6, '-');
		cout << str2.c_str() << endl;
		str2.insert(0, 'L');
		cout << str2.c_str() << endl;

		string str3;
		str3.push_back('K');
		str3.insert(0, "hello world");
		cout << str3.c_str() << endl;

		str3.erase(6, 5);
		cout << str3.c_str() << endl;
	}

	void teststring3()
	{
		string str1("hello world");
		cout << str1.find('o') << endl;

		cout << str1.find("rl") << endl;
	}

	void teststring4()
	{
		string str1("hello world");
		string str2(str1);
		cout << str2.c_str() << endl;

		string str3;
		str3 = str2;
		cout << str3.c_str() << endl;
		str3 = "hello ";
		cout << str3.c_str() << endl;

		cout << "-------------------------" << endl;
		cout << str1.c_str() << endl;
		cout << str3.c_str() << endl;
		str3.swap(str1);
		cout << str1.c_str() << endl;
		cout << str3.c_str() << endl;
		cout << "-------------------------" << endl;
		string str4("hello world");
		string str5 = str4.substr();
		cout << str5.c_str() << endl;
		string str6 = str4.substr(3);
		cout << str6.c_str() << endl;
		str6 = str4.substr(0, 3);
		cout << str6.c_str() << endl;

	}

	void teststring5()
	{
		string str1("hello world");
		cin >> str1;
		cout << str1;

	}

	void teststring6()
	{
		string str1("hello world");
		string str2(str1);
		cout << str2.c_str() << endl;

		string str3;
		str3 = str2;
		cout << str3.c_str() << endl;
		str3 = "hello ";
		cout << str3.c_str() << endl;
	}
}
using namespace moyu;
int main()
{
	//teststring1();
	//teststring2();
	//teststring3();
	//teststring4();
	//teststring5();
	teststring6();
}