//
//240430, Serok, String
//
#include <iostream>
#include <string>

using namespace std;

// getline ��� ����
// cin�� ����, ������� �������� ��������
// cin >> abc def  // abc���� ����
// char�� |0 �������� �� �־������ ���ư�
// ���ڿ��� �����ٴ� ǥ��
// char s[] = {'c', 'o', 'd', 'e', '|0'}



int main()
{
	// 1. ���ڿ� �Է�
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";
	
	// 2. ���� ���
	cout << s.length() << endl;

	// 3. 100��° ���� ���
	cout << s.at(100) << endl;

	// 4. two��� ���ڰ� ó�� ������ index
	string two = "two";
	cout << s.find(two)<< endl;

	// 5. two��� ���ڰ� �ι��� ������ index
	cout << s.find(two, 20) << endl;
	
}