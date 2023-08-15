#pragma once

#include "FoutTime.h"
#include "Settings Class.h"

class LogManager
{
private:
	ofstream logFile;
	int logMode;
public:
	LogManager();
	~LogManager();
	void SetLogMode(int sLogMode);
	void Restart();
	void Shutdown();
	void Start();
	void FontSize(int nprtr, int oprtr);
	void ConsoleColor(int nprtr, int oprtr);
	void ConsoleHeight(int nprtr, int oprtr);
	void ConsoleWidth(int nprtr, int oprtr);
	void InterfaceLanguage(int nprtr, int prtr);
	void StartAndShutdownSound(int nprtr, int prtr);
	void LogMode(int nprtr, int prtr);
	void ClockBackgroundMusic(int nprtr, int prtr);
	void RunningClock();
	void SettingsInitializationError();
	void SuccessfulInitialization();
};