//
//240430, Serok, String
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ���ڿ��� ���ڷθ� �̷���� �ִ��� �˻��ϴ� �Լ�
bool isNumber(const string& str) {
    for (char const& c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    string str1, str2;

    // �� ���ڿ��� ��� ������ ������ �ݺ�
    do {
        cout << "�� ���� ���� ���ڿ��� �Է��ϼ���: ";
        cin >> str1 >> str2;

        if (!isNumber(str1) || !isNumber(str2)) {
            cout << "�Է��� �߸��Ǿ����ϴ�. ���ڷθ� �̷���� ���ڿ��� �Է����ּ���.\n";
        }
    } while (!isNumber(str1) || !isNumber(str2));

    cout << "�ùٸ� �Է�: " << str1 << " " << str2 << endl;


    // �Է¹��� �� ���ڸ� �̾� �ٿ��� ���

    cout << "�� ���ڿ� �̾� ���� string : " << str1 + str2 << endl;

    // �տ��� �Է� ���� �� ������ ���� ���

    cout << "�� ������ ���� : " << stoi(str1) + stoi(str2) << endl;

    return 0;
}
