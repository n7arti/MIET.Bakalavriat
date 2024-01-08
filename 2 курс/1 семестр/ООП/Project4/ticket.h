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
    friend bool operator==(const ticket& tick1, const ticket& tick2);
    friend istream& operator>> (istream& in, ticket& Ticket);
    void InitTicket();
    void Print(ticket* tick);
    static void FromFile(ticket* tick);
    virtual void ToFile();
    virtual void ToString();
    static void Find(ticket* tick);
    char* Get_point_from() { return point_from; }
    char* Get_point_to() { return point_to; }
    double Get_price() { return price; }
    fio Get_Fio() { return Fio; }
    void Set_point_to(char* point_to_v);
    void Set_point_from(char* point_from_v);
    void Set_price(double price_v) { price = price_v; }
    static int Get_count() { return count; }
    static void Set_filename(string filename_v) { filename = filename_v; }
    friend void Sort(ticket* tick);
    friend class fio;

};