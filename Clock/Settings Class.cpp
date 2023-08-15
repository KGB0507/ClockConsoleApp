#include "Settings Class.h"

/*
MUSUC:
Without music = 0
RelaxStandard = 1
CalmStandard = 2

LANGUAGE:
English = 0
Russian = 1

COLOR:
BLACK = 0
BLUE = 1
GREEN = 2
CYAN = 3
RED = 4
PURPLE = 5
YELLOW = 6
WHITE = 7
GRAY = 8
LIGHTBLUE = 9
LIGHTGREEN = 10
LIGHTCYAN = 11
LIGHTRED = 12
LIGHTPURPLE = 13
LIGHTYELLOW = 14
LIGHTWHITE = 15
*/

Settings::Settings()
{
	consoleWidth = 61;
	consoleHeight = 40;
	consoleColor = 0;
	fontSize = 16;
	musicClock = 1;
	logMode = 0;
	startAndShutdownSound = 1;
	language = 0;
}

Settings::~Settings() {}

int Settings::GetMusicClock()
{
	return musicClock;
}

int Settings::GetLogMode()
{
	return logMode;
}

int Settings::GetConsoleWidth()
{
	return consoleWidth;
}

int Settings::GetStartAndShutdownSound()
{
	return startAndShutdownSound;
}

int Settings::GetConsoleHeight()
{
	return consoleHeight;
}
int Settings::GetConsoleColor()
{
	return consoleColor;
}

int Settings::GetFontSize()
{
	return fontSize;
}

int Settings::GetLanguage()
{
	return language;
}

void Settings::FixLanguage()
{
	language = 0;
}

void Settings::WriteOptionsInFile() //Bad sattings must be replaced by correct ones
{
	ofstream file;
	exception excep;
	try
	{
		file.open("config\\settings.ini", ios_base::out);//opening file settings.ini deleting all information there
		if (!file.is_open())
			throw excep;
	}
	catch (exception &excep)
	{
		bool isDirConfigCreated = CreateDirectory(L"config", NULL);
		file.open("config\\settings.ini", ios_base::app);
	}
	file << "CONSOLEWIDTH  " << consoleWidth << "\n";
	file << "CONSOLEHEIGHT " << consoleHeight << "\n";
	file << "CONSOLECOLOR  " << consoleColor << "\n";
	file << "FONTSIZE      " << fontSize << "\n";
	file << "MUSICCLOCK    " << musicClock << "\n";
	file << "LOGMODE       " << logMode << "\n";
	file << "SOUND         " << startAndShutdownSound << "\n";
	file << "LANGUAGE      " << language << "\n";
	file.close();
}

void Settings::SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void Settings::SetConsoleSize(int width, int height)
{
	COORD crd = {width, height};
	SMALL_RECT src = { 0, 0, crd.X, crd.Y };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &src);
}

void Settings::SetFont(LPCSTR fontType, int fontSize)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	wcscpy(fontInfo.FaceName, CharToLPWSTR(fontType));
	fontInfo.dwFontSize.Y = fontSize;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}

void Settings::SettingsInitializationError()
{
	SetColor(4, consoleColor);
	mciSendString(CharToLPWSTR("play music\\criticalError.mp3"), NULL, 0, NULL);
	cout << "Settings initialization error. The file \"settings.ini\" may have been corrupted or removed!" << endl;
	SetColor(7, consoleColor);
}

bool Settings::GetSettings()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	string s;
	string parameter;
	string option;
	int prtr;
	exception excep;//exception
	fstream file;
	LogManager logManager;
	try
	{
		file.open("config\\settings.ini");
		if (!file.is_open())
			throw excep;
	}
	catch (exception &excep)
	{
		logManager.SettingsInitializationError();
		SettingsInitializationError();
		bool isDirConfigCreated = CreateDirectory(L"config", NULL);
		file.open("config\\settings.ini", ios_base::app);
		WriteOptionsInFile();
		return false;
	}
	while (getline(file, s))
	{
		option = s.substr(0, 13);
		parameter = s.substr(14, 3);
		prtr = stoi(parameter);//transforming into int type from string type
		if (option == "CONSOLEWIDTH ")
		{
			if (prtr < 61 || prtr > 100)
			{
				consoleWidth = 61;
				WriteOptionsInFile();
			}
			else
				consoleWidth = prtr;
		}
		if (option == "CONSOLEHEIGHT")
		{
			if (prtr < 30 || prtr > 100)
			{
				consoleHeight = 40;
				WriteOptionsInFile();
			}
			else
				consoleHeight = prtr;
		}
		if (option == "CONSOLECOLOR ")
		{
			if (prtr > 15 || prtr < 0)
			{
				consoleColor = 0;
				WriteOptionsInFile();
			}
			else
				consoleColor = prtr;
		}
		if (option == "FONTSIZE     ")
		{
			if (prtr < 0 || prtr > 25)
			{
				fontSize = 16;
				WriteOptionsInFile();
			}
			else
				fontSize = prtr;
		}
		if (option == "MUSICCLOCK   ")
		{
			if (prtr > 2 || prtr < 0)
			{
				musicClock = 1;
				WriteOptionsInFile();
			}
			else
				musicClock = prtr;
		}
		if (option == "LOGMODE      ")
		{
			if (prtr > 1 || prtr < 0)
			{
				logMode = 0;
				WriteOptionsInFile();
			}
			else
				logMode = prtr;
		}
		if (option == "SOUND        ")
		{
			if (prtr > 1 || prtr < 0)
			{
				startAndShutdownSound = 1;
				WriteOptionsInFile();
			}
			else
				startAndShutdownSound = prtr;
		}
		if (option == "LANGUAGE     ")
		{
			if (prtr > 1 || prtr < 0)
			{
				language = 0;
				WriteOptionsInFile();
			}
			else
				language = prtr;
		}
	}
	SetConsoleSize(consoleWidth, consoleHeight);
	SetColor(7, consoleColor);//setting color of text and background 
	SetFont("Lucida Console", fontSize);//setting a Font Parameters
	file.close();
	logManager.SuccessfulInitialization();
	return true;
}

bool Settings::SetSettings(string ioption, string ikey, string iprtr)
{
	SYSTEMTIME st;
	fstream file;
	LogManager logManager;
	logManager.SetLogMode(logMode);
	string s;
	string opt;
	GetLocalTime(&st);
	exception excep;
	try
	{
		file.open("config\\settings.ini");
		if (!file.is_open())
			throw excep;
	}
	catch (exception &excep)
	{
		bool isDirConfigCreated = CreateDirectory(L"config", NULL);
		file.open("config\\settings.ini");
		WriteOptionsInFile();
		return false;
	}
	if (ioption == "console" && ikey == "width")
	{
		if (stoi(iprtr) < 61 || stoi(iprtr) > 100)
		{
			return false;
		}
		else
		{
			logManager.ConsoleWidth(stoi(iprtr), consoleWidth);
			consoleWidth = stoi(iprtr);
		}
	}
	else if (ioption == "console" && ikey == "height")
	{
		if (stoi(iprtr) < 30 || stoi(iprtr) > 100)
		{
			return false;
		}
		else
		{
			logManager.ConsoleHeight(stoi(iprtr), consoleHeight);
			consoleHeight = stoi(iprtr);
		}
	}
	else if (ioption == "console" && ikey == "color")
	{
		if (stoi(iprtr) > 15 || stoi(iprtr) < 0)
		{
			return false;
		}
		else
		{
			logManager.ConsoleColor(stoi(iprtr), consoleColor);
			consoleColor = stoi(iprtr);
		}
	}
	else if (ioption == "font" && ikey == "size")
	{
		if (stoi(iprtr) < 0 || stoi(iprtr) > 20)
		{
			return false;
		}
		else
		{
			logManager.FontSize(stoi(iprtr), fontSize);
			fontSize = stoi(iprtr);
		}
	}
	else if (ioption == "music" && ikey == "clock")
	{
		if (stoi(iprtr) > 2 || stoi(iprtr) < 0)
		{
			return false;
		}
		else
		{
			logManager.ClockBackgroundMusic(stoi(iprtr), musicClock);
			musicClock = stoi(iprtr);
		}
	}
	else if (ioption == "log" && ikey == "mode")
	{
		if (stoi(iprtr) == 0 || stoi(iprtr) == 1)
			logManager.LogMode(stoi(iprtr), logMode);
		else
			return false;
		logMode = stoi(iprtr);
	}
	else if (ioption == "sas" && ikey == "snd")
	{
		if (stoi(iprtr) == 0 || stoi(iprtr) == 1)
		{
			logManager.StartAndShutdownSound(stoi(iprtr), startAndShutdownSound);
			startAndShutdownSound = stoi(iprtr);
		}
		else
			return false;
	}
	else if (ioption == "interface" && ikey == "lang")
	{
		if (stoi(iprtr) == 0 || stoi(iprtr) == 1)
		{
			logManager.InterfaceLanguage(stoi(iprtr), language);
			language = stoi(iprtr);
		}
		else
			return false;
	}
	else
	{
		return false;
	}
	WriteOptionsInFile();
	file.close();
	GetSettings();
	return true;
}