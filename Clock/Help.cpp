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
		cout << "Это основное меню программы." << endl << "Управление осуществляется при помощи текстовых команд." << endl << "Список команд, используемых в программе:" << endl;
		cout << "*run [MODULE] - запуск модуля ...(Например, run clock)" << endl;
		cout << "*set [OPTION] [PARAMETER] - установка параметра PARAMETER настройки OPTION (например, set console width 69)" << endl;
		cout << "*exit - прекращение работы программы" << endl;
		cout << "*restart - перезапуск программы" << endl;
		cout << "Все изменения вступят в силу после перезапуска программы." << endl << "Параметры команд вводятся только цифрами!" << endl;
		break;
	}
	default:
	{
		UnknownLanguage(settings);
		break;
	}
	}
}