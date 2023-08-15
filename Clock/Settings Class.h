#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <string_view>
#include <Windows.h>
#include <filesystem>
#include "CharToLPWSTR.h"
#include "FoutTime.h"
#include "Log Manager.h"

using namespace std;

class Settings
{
private:
	int consoleWidth;
	int consoleHeight;
	int consoleColor;
	int fontSize;
	int musicClock;
	int logMode;
	int startAndShutdownSound;
	int language;
public:
	Settings();
	~Settings();
	int GetMusicClock();
	int GetLogMode();
	int GetConsoleWidth();
	int GetConsoleHeight();
	int GetConsoleColor();
	int GetFontSize();
	int GetStartAndShutdownSound();
	int GetLanguage();
	void FixLanguage();
	void WriteOptionsInFile();
	void SetColor(int text, int bg);
	void SetConsoleSize(int width, int height);
	void SetFont(LPCSTR fontType, int fontSize);
	void SettingsInitializationError();
	bool GetSettings();
	bool SetSettings(string ioption, string ikey, string iprtr);
};
