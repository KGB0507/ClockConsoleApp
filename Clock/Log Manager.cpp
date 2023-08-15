#include "Log Manager.h"

LogManager::LogManager()
{
	logMode = 0;
	exception excep;
	try
	{
		logFile.open("logs\\log.txt", ios_base::app);
		if (!logFile.is_open())
			throw excep;
	}
	catch (exception& excep)
	{
		bool isDirLogsCreated = CreateDirectory(L"logs", NULL);
		logFile.open("logs\\log.txt", ios_base::app);
	}
}

LogManager::~LogManager()
{
	logFile.close();
}

void LogManager::SetLogMode(int sLogMode)
{
	logMode = sLogMode;
}

void LogManager::Restart()
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Restart" << endl;
	}
}

void LogManager::Shutdown()
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Shutdown" << endl << endl;
	}
}

void LogManager::Start()
{
	if (logMode == 1)
	{
		FoutTime(logFile);
	    logFile << "Start" << endl;
	}
}

void LogManager::FontSize(int nprtr, int oprtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Changing font size from " << oprtr << " to " << nprtr << endl;
	}
}

void LogManager::ConsoleColor(int nprtr, int oprtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Changing console color from " << oprtr << " to " << nprtr << endl;
	}
}

void LogManager::ConsoleHeight(int nprtr, int oprtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Changing console height from " << oprtr << " to " << nprtr << endl;
	}
}

void LogManager::ConsoleWidth(int nprtr, int oprtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Changing console width from " << oprtr << " to " << nprtr << endl;
	}
}

void LogManager::InterfaceLanguage(int nprtr, int prtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		switch (nprtr)
		{
		case 0:
		{
			logFile << "Changing interface language to English" << endl;
			break;
		}
		case 1:
		{
			logFile << "Changing interface language to Russian" << endl;
			break;
		}
		}
	}
}

void LogManager::StartAndShutdownSound(int nprtr, int prtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		switch (nprtr)
		{
		case 0:
		{
			logFile << "Start and shutdown sound was switched off" << endl;
			break;
		}
		case 1:
		{
			logFile << "Start and shutdown sound was switched on" << endl;
			break;
		}
		}
	}
}

void LogManager::LogMode(int nprtr, int oprtr)
{
	FoutTime(logFile);
	switch (nprtr)
	{
	case 0:
	{
		logFile << "Log Manager was switched off" << endl << endl;
		break;
	}
	case 1:
	{
		logFile << "Log Manager was switched on" << endl;
		break;
	}
	}
	logMode = nprtr;
}

void LogManager::ClockBackgroundMusic(int nprtr, int oprtr)
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Changing clock background music from " << oprtr << " to " << nprtr << endl;
	}
}

void LogManager::RunningClock()
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Running clock module" << endl << endl;
	}
}

void LogManager::SettingsInitializationError()
{
	FoutTime(logFile);
	logFile << "Settings initialization error" << endl;
}

void LogManager::SuccessfulInitialization()
{
	if (logMode == 1)
	{
		FoutTime(logFile);
		logFile << "Settings initialization was successful" << endl;
	}
}