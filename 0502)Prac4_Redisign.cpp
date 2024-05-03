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
    string birthday; // "MM-DD" 형식
};

bool CheckInputNumber(string& str)
{
    // str = "123ab321"; str[0], str[4]
    cin >> str;
    for (char c : str) // for-each
    {
        // c가 숫자가 아닌 문자일 경우 == 0
        if (isdigit(c) == 0)
        {
        cout << "문자를 제외하고 다시 입력해주세요.\n" << endl;
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
        // c가 문자가 아닌 숫자일 경우 == 0
        if (isalpha(c) == 0)
        {
            cout << "숫자를 제외하고 다시 입력해주세요.\n" << endl;
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
        cout << i + 1 << "번째 학생 이름 입력: ";
        while(!CheckInputAlpha(students[i].name));

        cout << i + 1 << "번째 학생 나이 입력: ";
        while(!CheckInputNumber(students[i].age));

        cout << i + 1 << "번째 학생 생일 입력(MMDD): ";
        while (!CheckInputNumber(students[i].birthday));
    }
}

void printStudentInfo(const vector<student_info>& students) {
    for (const auto& student : students) {
        cout << "이름: " << student.name << " 나이: " << student.age << " 생일: " << student.birthday << endl;
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
    cout << "학생 수를 입력하세요: ";
    cin >> studentNum;
    vector<student_info> students(studentNum);

    inputStudentData(students);

    int choose;
    while (true) {
        cout << "case를 고르세요 (0: 종료, 1: 학생 정보 출력, 2: 평균 나이, 3: 가장 빠른 생일): ";
        cin >> choose;

        if (choose == 0) {
            cout << "종료!" << endl;
            break;
        }

        if (choose == 1) {
            printStudentInfo(students);
        }
        else if (choose == 2) {
            cout << "평균 나이는: " << calculateAverageAge(students) << endl;
        }
        else if (choose == 3) {
            cout << "가장 빠른 생일은: " << findEarliestBirthday(students) << endl;
        }
    }

    return 0;
}
