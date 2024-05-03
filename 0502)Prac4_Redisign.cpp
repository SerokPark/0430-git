#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct student_info {
    string name;
    string age;
    string birthday; // "MM-DD" ����
};

bool CheckInputNumber(string& str)
{
    // str = "123ab321"; str[0], str[4]
    cin >> str;
    for (char c : str) // for-each
    {
        // c�� ���ڰ� �ƴ� ������ ��� == 0
        if (isdigit(c) == 0)
        {
        cout << "���ڸ� �����ϰ� �ٽ� �Է����ּ���.\n" << endl;
        return false;
        }
    }
    return true;
}

bool CheckInputAlpha(string& str)
{
    // str = "123ab321"; str[0], str[4]
    cin >> str;
    for (char c : str) // for-each
    {
        // c�� ���ڰ� �ƴ� ������ ��� == 0
        if (isalpha(c) == 0)
        {
            cout << "���ڸ� �����ϰ� �ٽ� �Է����ּ���.\n" << endl;
            return false;

        }
    }
    return true;
}

//int getValidatedInput(function<bool(const string&)> validate, const string& errorMessage, string& input) {
//    cin >> input;
//    if (validate(input)) {
//        return 0;
//    }
//    cout << errorMessage << endl;
//    return -1;
//}

void inputStudentData(vector<student_info>& students) {
    for (int i = 0; i < students.size(); ++i) {
        cout << i + 1 << "��° �л� �̸� �Է�: ";
        while(!CheckInputAlpha(students[i].name));

        cout << i + 1 << "��° �л� ���� �Է�: ";
        while(!CheckInputNumber(students[i].age));

        cout << i + 1 << "��° �л� ���� �Է�(MMDD): ";
        while (!CheckInputNumber(students[i].birthday));
    }
}

void printStudentInfo(const vector<student_info>& students) {
    for (const auto& student : students) {
        cout << "�̸�: " << student.name << " ����: " << student.age << " ����: " << student.birthday << endl;
    }
}

float calculateAverageAge(const vector<student_info>& students) 
{
    float totalAge = 0;
    for (const auto& student : students) {
        totalAge += stoi(student.age);
    }
    return totalAge / students.size();
}

string findEarliestBirthday(vector<student_info>& students) {
    vector<string> v_birth;
    for (const auto& student : students) {
        v_birth.push_back(student.birthday);
    }
    return *min_element(v_birth.begin(), v_birth.end());
}
int main() {
    int studentNum;
    cout << "�л� ���� �Է��ϼ���: ";
    cin >> studentNum;
    vector<student_info> students(studentNum);

    inputStudentData(students);

    int choose;
    while (true) {
        cout << "case�� ������ (0: ����, 1: �л� ���� ���, 2: ��� ����, 3: ���� ���� ����): ";
        cin >> choose;

        if (choose == 0) {
            cout << "����!" << endl;
            break;
        }

        if (choose == 1) {
            printStudentInfo(students);
        }
        else if (choose == 2) {
            cout << "��� ���̴�: " << calculateAverageAge(students) << endl;
        }
        else if (choose == 3) {
            cout << "���� ���� ������: " << findEarliestBirthday(students) << endl;
        }
    }

    return 0;
}
