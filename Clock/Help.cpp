#include "Help.h"

using namespace std;

void Help(Settings &settings)
{
	switch (settings.GetLanguage())
	{
	case 0:
	{
		cout << "This is the start menu of the program." << endl << "The control is carried out by entering text commands" << endl << "List of commands used in the program : " << endl;
		cout << "*run [MODULE] - start module MODULE of the program (#run clock)" << endl;
		cout << "*set [OPTION] [PARAMETER] - set the parameter PARAMETER of the option OPTION (#set console width 69)" << endl;
		cout << "*exit - stops program's work" << endl;
		cout << "*restart - restarts the program" << endl;
		cout << "The changes will take effect after restarting the program" << endl << "Command parameters are entered only in numbers!" << endl;
		break;
	}
	case 1:
	{
		cout << "��� �������� ���� ���������." << endl << "���������� �������������� ��� ������ ��������� ������." << endl << "������ ������, ������������ � ���������:" << endl;
		cout << "*run [MODULE] - ������ ������ ...(��������, run clock)" << endl;
		cout << "*set [OPTION] [PARAMETER] - ��������� ��������� PARAMETER ��������� OPTION (��������, set console width 69)" << endl;
		cout << "*exit - ����������� ������ ���������" << endl;
		cout << "*restart - ���������� ���������" << endl;
		cout << "��� ��������� ������� � ���� ����� ����������� ���������." << endl << "��������� ������ �������� ������ �������!" << endl;
		break;
	}
	default:
	{
		UnknownLanguage(settings);
		break;
	}
	}
}