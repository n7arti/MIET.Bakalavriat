#pragma once
#include <fstream>
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
    ticket& operator = (const ticket& ticket_v);
    friend istream& operator>> (istream& in, ticket& Ticket);
    void InitTicket();
    static void Print(ticket* tick);
    static void FromFile(ticket* tick);
    static void Find(ticket* tick);
    char* Get_point_from() { return point_from; }
    char* Get_point_to() { return point_to; }
    double Get_price() { return price; }
    int Get_count() { return count; }
    static string Get_filename() { return filename; }
    static void Set_filename(string filename_v) { filename = filename_v; }
    friend void Sort(ticket* tick);
    friend class fio;

};