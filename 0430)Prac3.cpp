//
//240430, Serok, String_Practice3
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string s = "Codingon";

int main()
{
	// 대문자->소문자
	s[0] = tolower(s[0]);
	cout << s << endl;

	// ding 반환
	cout << s.substr(2, 4) << endl;

	// coooooon변경
	cout << s.replace(2, 5, "oooo") << endl;

	// con 변경
	cout << s.erase(1, 4) << endl;
}