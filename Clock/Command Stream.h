#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "Help.h"
#include "Clock Module.h"
#include "Settings Class.h"
#include "Log Manager.h"

//#define DEBUG

void CmdErrorMessage(Settings &settings);

void CmdSuccessfulChangingSettings(Settings &settings);

void UnknownLanguage(Settings &settings);

void CommandStream(Settings &settings);
