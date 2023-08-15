#pragma once

//Information about this Program Build
#define VERSION "Version 1.5.2"
#define AUTHOR "Copyright (c) Kirill Belozerov, 2021-2023. All Rights Reserved"
#define UNDERCONSTR ""

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "CharToLPWSTR.h"
#include "Settings Class.h"
#include "Command Stream.h"

using namespace std;

void PlayClockMusic(Settings& settings);

bool Clock(Settings& settings);