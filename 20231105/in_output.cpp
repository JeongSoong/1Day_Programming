﻿#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	char op;
	int n1, n2, res;

	cout << "Á¾·á´Â Exit ÀÔ·ÂÇÏ±â" << endl;

	while (1)
	{
		cout << "? ";
		getline(cin, s);
		if (s == "Exit") break;

		int index = 0;

		index = s.find(' ');
		n1 = stoi(s);
		char op = s[index + 1];

		index = (s, index + 1);
		string sub = s.substr(index + 1);
		n2 = stoi(sub);

		switch (op)
		{
		case '+': res = n1 + n2; break;
		case '-': res = n1 - n2; break;
		case '*': res = n1 * n2; break;
		case '/': res = n1 / n2; break;

		default:break;
		}
		cout << n1 << ' ' << op << ' ' << n2 << "=" << res << endl;
	}
}