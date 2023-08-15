#include "FoutTime.h"

void FoutTime(ofstream &logFile)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	if (st.wDay < 10)
		logFile << "0" << st.wDay << ".";
	else
		logFile << st.wDay << ".";
	if (st.wMonth < 10)
		logFile << "0" << st.wMonth << ".";
	else
		logFile << st.wMonth << ".";
	logFile << st.wYear << "   ";
	logFile << st.wHour << ":";
	if (st.wMinute < 10)
		logFile << "0" << st.wMinute << ":";
	else
		logFile << st.wMinute << ":";
	if (st.wSecond < 10)
		logFile << "0" << st.wSecond << "   ";
	else
		logFile << st.wSecond << "   ";
}