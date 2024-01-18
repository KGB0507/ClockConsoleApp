#pragma once

//Information about this Program Build
#define VERSION "Version 1.6"
#define AUTHOR "Copyright (c) Kirill Belozerov, 2021-2024. All Rights Reserved"
#define UNDERCONSTR "Under construction"

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "CharToLPWSTR.h"
#include "Settings Class.h"
#include "Command Stream.h"

using namespace std;

void PlayClockMusic(Settings& settings);

bool Clock(Settings& settings);