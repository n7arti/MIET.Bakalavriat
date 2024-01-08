#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include "fio.h"
fio::fio()
{
    familia = new char[50];
    strcpy(familia, " ");
    imya = new char[50];
    strcpy(imya, " ");
    otchestvo = new char[50];
    strcpy(otchestvo, " ");
}
fio::~fio()
{
    delete[] familia;
    delete[] imya;
    delete[] otchestvo;
}
void fio::set_familia(char* familia_v)
{ 
    if (familia != nullptr)
        delete[] familia;
    familia = new char[strlen(familia_v) + 1];
    strcpy(familia, familia_v);
}
void fio::set_imya(char* imya_v)
{
    if (imya != nullptr)
        delete[] imya;
    imya = new char[strlen(imya_v) + 1];
    strcpy(imya, imya_v);
}
void fio::set_otchestvo(char* otchestvo_v)
{
    if (otchestvo != nullptr)
        delete[] otchestvo;
    otchestvo = new char[strlen(otchestvo_v) + 1];
    strcpy(otchestvo, otchestvo_v);
}