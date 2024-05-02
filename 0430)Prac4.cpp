//
//240430, Serok, String_Practice4
//
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

bool isNumber(string str)
{
    // str = "123ab321"; str[0], str[4]
    for (char c : str) // for-each
    {
        // c가 숫자가 아닌 문자일 경우 == 0
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

bool isAlpha(string str)
{
    // str = "123ab321"; str[0], str[4]
    for (char c : str) // for-each
    {
        // c가 문자가 아닌 숫자일 경우 == 0
        if (isalpha(c) == 0)
            return false;
    }
    return true;
}

struct student {
    string name;
    string age;
    string birthday; // "YYYY-MM-DD" 형식
};



int main()
{
    // 1. 학생 수 입력
    int studentnum;
    cout << "학생 수를 입력하세요 : " << endl;
    cin >> studentnum;

    // 2. 이름 나이 생일 순서로 입력 받기

    vector<student> v_student(studentnum);
    string age;
    string birthday;
    string name;


    for (int i = 0; i < studentnum; ++i)
    {
        cout << i << "번째 학생 이름 입력 : ";

        while (1) {
            cin >> v_student[i].name;
            if (isAlpha(name))
            {
                break;
            }
            cout << "이름은 문자입니다. 숫자를 제외하고 다시 입력해주세요." << endl;
        }

        cout << i+1 << "번째 학생 나이 입력 : ";

        while (1) {
            cin >> v_student[i].age;
            if (isNumber(age))
            {
                break;
            }
            cout << "나이는 숫자입니다. 문자를 제외하고 다시 입력해주세요." << endl;
        }
        
        cout << i << "번째 학생 생일 입력(MMDD) : ";


        while (1) {
            cin >> v_student[i].birthday;
            if (isNumber(birthday))
            {
                break;
            }
            cout << "생일은 숫자입니다. 문자를 제외하고 다시 입력해주세요." << endl;
        }
    }
    //3.
    // case 0: 종료
    // case 1: 학생 정보 출력
    // case 2: 평균 나이
    // case 3: 가장 빠른 생일

    int choose = 0;
    float totalAge = 0;
    while (1)
    {
        cout << "case를 고르세요" << endl;
        cout << "case 0: 종료" << endl;
        cout << "case 1: 학생 정보 출력" << endl;
        cout << "case 2: 평균 나이" << endl;
        cout << "case 3: 가장 빠른 생일" << endl;
        cin >> choose;

        switch (choose)
        {
        case 0 :
            cout << "종료!" << endl;
            break;
        case 1 :
            cout << "학생 정보 출력 : " << endl;
            for (student& v : v_student)
            {
                cout << "이름: " << v.name << " " << "나이: " << v.age << " " << "생일: " << v.birthday << endl;
            }
            break;
        case 2 :
            
            for (student& v : v_student)
            {
                totalAge += stoi(v.age);
            }
            cout << "평균 나이는 : " << totalAge / float(studentnum) << endl;
            break;
        case 3 :
            vector<string> v_birth(studentnum);
            for (student& v : v_student)
            {
                for (int i = 0; i < studentnum; i++)
                {
                    v_birth[i] = v.birthday;
                }
             }
            cout << "가장 빠른 생일은 : " << *min_element(v_birth.begin(), v_birth.end()) << endl;
            break;
        }
        
    }
    
}



    


    