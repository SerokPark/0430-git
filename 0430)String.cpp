//
//240430, Serok, String
//
#include <iostream>
#include <string>

using namespace std;

// getline 사용 이유
// cin은 공백, 띄워쓰기 기준으로 나뉘어짐
// cin >> abc def  // abc까지 나옴
// char는 |0 마지막에 꼭 넣어줘야지 돌아감
// 문자열이 끝났다는 표현
// char s[] = {'c', 'o', 'd', 'e', '|0'}



int main()
{
	// 1. 문자열 입력
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";
	
	// 2. 길이 출력
	cout << s.length() << endl;

	// 3. 100번째 문자 출력
	cout << s.at(100) << endl;

	// 4. two라는 문자가 처음 나오는 index
	string two = "two";
	cout << s.find(two)<< endl;

	// 5. two라는 문자가 두번쨰 나오는 index
	cout << s.find(two, 20) << endl;
	
}