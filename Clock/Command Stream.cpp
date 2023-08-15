#include "Command Stream.h"

void CmdErrorMessage(Settings &settings)
{
	Settings tempSettings;
	tempSettings.SetColor(4, settings.GetConsoleColor());
	mciSendString(CharToLPWSTR("play music\\error.mp3"), NULL, 0, NULL);
	switch (settings.GetLanguage())
	{
	case 0:
	{
		cout << "Bad command or parameter of the command!" << endl;
		break;
	}
	case 1:
	{
		cout << "Неправильный ввод команды или параметра команды!" << endl;
		break;
	}
	default:
	{
		cout << "Bad command or parameter of the command!" << endl;
		settings.FixLanguage();
		UnknownLanguage(settings);
		break;
	}
	}
	tempSettings.SetColor(7, settings.GetConsoleColor());
}

void UnknownLanguage(Settings &settings)
{
	Settings tempSettings;
	tempSettings.SetColor(4, settings.GetConsoleColor());
	mciSendString(CharToLPWSTR("play music\\criticalError.mp3"), NULL, 0, NULL);
	cout << "Unknown language detected in settings.ini file!" << endl;
	tempSettings.SetColor(7, settings.GetConsoleColor());
}

void CmdSuccessfulChangingSettings(Settings &settings)
{
	Settings tempSettings;
	tempSettings.SetColor(2, settings.GetConsoleColor());
	switch (settings.GetLanguage())
	{
	case 0:
	{
		cout << "Settings were successfully changed!" << endl;
		break;
	}
	case 1:
	{
		cout << "Настройки были успешно применены!" << endl;
		break;
	}
	default:
	{
		settings.FixLanguage();
		UnknownLanguage(settings);
		break;
	}
	}	
	tempSettings.SetColor(7, settings.GetConsoleColor());
}

void CommandStream(Settings &settings)
{
	string cmd;
	string option;
	string key;
	string prtr;
	LogManager logManager;
#ifndef DEBUG
	int i;
	int l = settings.GetConsoleWidth() / 2 - 5;
	for (i = 0; i < l; i++)
	{
		cout << " ";
	}
	switch (settings.GetLanguage())
	{
	case 0:
	{
		cout << "Start Menu" << endl;
		break;
	}
	case 1:
	{
		cout << "Меню" << endl;
		break;
	}
	default:
	{
		cout << endl;
		settings.FixLanguage();
		UnknownLanguage(settings);
		break;
	}
	}
#endif
	while (true)
	{
		logManager.SetLogMode(settings.GetLogMode());
		cout << endl << ">";
		cin >> cmd;
		if (cmd == "help")
			Help(settings);
		else if (cmd == "run")
		{
			cin >> option;
			if (option == "clock")
			{
				logManager.RunningClock();
				Clock(settings);
				break;
			}
			else
			{
				CmdErrorMessage(settings);
				continue;
			}
		}
		else if (cmd == "set")
		{
			cin >> option;
			cin >> key;
			cin >> prtr;
			if (settings.SetSettings(option, key, prtr))
				CmdSuccessfulChangingSettings(settings);
			else
				CmdErrorMessage(settings);
		}
		else if (cmd == "exit")
		{
			if (settings.GetStartAndShutdownSound())
				mciSendString(CharToLPWSTR("play music\\shutdown.mp3 wait"), NULL, 0, NULL);
			logManager.Shutdown();
			exit(0);
		}
		else if (cmd == "restart")
		{
			if (settings.GetStartAndShutdownSound())
				mciSendString(CharToLPWSTR("play music\\shutdown.mp3 wait"), NULL, 0, NULL);
			logManager.Restart();
			DWORD dwPID = GetCurrentProcessId();
			ShellExecute(NULL, L"open", L"Clock.exe", NULL, NULL, SW_SHOWDEFAULT);
			TerminateProcess(OpenProcess(PROCESS_TERMINATE, FALSE, dwPID), 0);
			exit(0);
		}
		else
			CmdErrorMessage(settings);
	}
}