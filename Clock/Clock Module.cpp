#include "Clock Module.h"

void PlayClockMusic(Settings& settings)
{
	switch (settings.GetMusicClock())
	{
	case 0:
	{
		break;
	}//w/o music
	case 1:
	{
		mciSendString(CharToLPWSTR("play music\\RelaxStandard.mp3 repeat"), NULL, 0, NULL);//playing the background music
		break;
	}
	case 2:
	{
		mciSendString(CharToLPWSTR("play music\\CalmStandard.mp3 repeat"), NULL, 0, NULL);
		break;
	}
	}
}

bool Clock(Settings& settings)
{
	SYSTEMTIME st;
	while (true)
	{
		int width = settings.GetConsoleWidth();
		int halfWidth = (width - 7) / 2;
		int count = 0;
		for (int i = 0; i <= halfWidth; i++)
		{
			cout << "=";
			++count;
		}
		switch (settings.GetLanguage())
		{
		case 0:
		{
			cout << "/Clock\\";
			break;
		}
		case 1:
		{
			cout << "/Часы\\=";
			break;
		}
		default:
		{
			settings.FixLanguage();
			cout << "/Clock\\";
			//UnknownLanguage();
			break;
			break;
		}
		}
		count += 7;
		for (int i = 0; i <= halfWidth; i++)
		{
			cout << "=";
			++count;
		}
		if (count < width)
			cout << "=";
		cout << endl;
		for (int i = 0; i <= width; i++)
		{
			cout << "=";
		}
		PlayClockMusic(settings);
		GetLocalTime(&st);
		cout << endl;
		cout << endl << st.wHour << ":";
		if (st.wMinute < 10)
			cout << "0" << st.wMinute << ":";
		else
			cout << st.wMinute << ":";
		if (st.wSecond < 10)
			cout << "0" << st.wSecond << endl;
		else
			cout << st.wSecond << endl;
		cout << endl << endl << VERSION << endl << AUTHOR << endl << endl << UNDERCONSTR << endl;
		Sleep(1000);
		system("cls");
	}
}