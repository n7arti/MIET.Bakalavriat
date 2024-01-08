#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class except
{
public:
    char msg[80];
    except() { msg[0] = '\0'; }
    except(const char* s) { strcpy(msg, s); }
};