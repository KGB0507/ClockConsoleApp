/////////////////////////////////////////////////////////////////////////////
//Clock Console Application, v. 1.6
/////////////////////////////////////////////////////////////////////////////
//Copyright (c) Kirill Belozerov, 2021-2023. All Rights Reserved
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//Notes: 
// add updating from web-site (with agreement) - may be in later versions
/////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
//Information about this Program Build. It is doubled in Clock Module.h
#define VERSION "Version 1.6"
<<<<<<< Updated upstream
#define AUTHOR "Copyright (c) Kirill Belozerov, 2021-2023. All Rights Reserved"
#define UNDERCONSTR "Under construction"
//#define DEBUG 1.5.2 //It is doubled in Command Stream.h
=======
#define AUTHOR "Copyright (c) Kirill Belozerov, 2021-2024. All Rights Reserved"

#define UNDERCONSTR "Under construction" //It is doubled in Clock Module.h
#define DEBUG 1.6 //It is doubled in Command Stream.h
//#define DEBUGSKIPINTRO
>>>>>>> Stashed changes

#include <iostream>
#include <Windows.h>
#include <string>
#include "CharToLPWSTR.h"
#include "Command Stream.h"
#include "Settings Class.h"
#include "Log Manager.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");//adding russian language
	Settings settings;//object of the  Settings Class
	settings.GetSettings();
	system("cls");
	LogManager logManager;
	logManager.SetLogMode(settings.GetLogMode());
	logManager.Start();
#ifndef DEBUG
	int t = 0;//startup time counter
	cout << "Clock Console Application" << endl << VERSION << endl << AUTHOR << endl << endl << UNDERCONSTR << endl << endl;
	switch (settings.GetLanguage())
	{
	case 0:
	{
		cout << "Starting Command Manager. Please wait";
		if (settings.GetStartAndShutdownSound())
			mciSendString(CharToLPWSTR("play music\\startup.mp3"), NULL, 0, NULL);//playing startup sound
		while (t <= 5000)
		{
			cout << ".";
			Sleep(1000);
			t += 1000;
		}
		break;
	}
	case 1:
	{
		cout << "Запуск программы. Пожалуйста, подождите";
		if (settings.GetStartAndShutdownSound())
			mciSendString(CharToLPWSTR("play music\\startup.mp3"), NULL, 0, NULL);//playing startup sound
	    while (t <= 5000)
		{
			cout << ".";
			Sleep(1000);
			t += 1000;
		}
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
	system("cls");
#endif
	cout << "Clock Console Application" << endl << VERSION << endl << AUTHOR << endl << endl << UNDERCONSTR << endl << endl;
	CommandStream(settings);
	if (settings.GetStartAndShutdownSound())
		mciSendString(CharToLPWSTR("play music\\shutdown.mp3 wait"), NULL, 0, NULL);
	logManager.Shutdown();
	return 0;
}