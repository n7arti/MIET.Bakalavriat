#pragma once
#include <fstream>
#include <vector>
#include "fio.h"

using namespace std;

class ticket
{
    char* point_from;
    char* point_to;
    fio Fio;
    double price;
    static int count;
    static string filename;
public:
    ticket();
    ~ticket();
    ticket(fio Fio_v, char* point_from_v, char* point_to_v, double price_v);
    ticket& operator = (const ticket& ticket_v);
    void InitTicket(vector<ticket> tick);
    static void Print(vector<ticket> tick);
    static void Delete(vector<ticket> tick);
    static void FromFile(vector<ticket> tick);
    static void Find(vector<ticket> tick);
    char* Get_point_from() { return point_from; }
    char* Get_point_to() { return point_to; }
    double Get_price() { return price; }
    int Get_count() { return count; }
    static string Get_filename() { return filename; }
    static void Set_filename(string filename_v) { filename = filename_v; }
    friend void Sort(vector<ticket> tick);
    friend class fio;

};