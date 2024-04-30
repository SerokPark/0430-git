//
//240430, Serok, String
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 문자열이 숫자로만 이루어져 있는지 검사하는 함수
bool isNumber(const string& str) {
    for (char const& c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    string str1, str2;

    // 두 문자열이 모두 숫자일 때까지 반복
    do {
        cout << "두 개의 숫자 문자열을 입력하세요: ";
        cin >> str1 >> str2;

        if (!isNumber(str1) || !isNumber(str2)) {
            cout << "입력이 잘못되었습니다. 숫자로만 이루어진 문자열을 입력해주세요.\n";
        }
    } while (!isNumber(str1) || !isNumber(str2));

    cout << "올바른 입력: " << str1 << " " << str2 << endl;


    // 입력받은 두 숫자를 이어 붙여서 출력

    cout << "두 문자열 이어 붙인 string : " << str1 + str2 << endl;

    // 앞에서 입력 받은 두 숫자의 합을 출력

    cout << "두 숫자의 합은 : " << stoi(str1) + stoi(str2) << endl;

    return 0;
}
