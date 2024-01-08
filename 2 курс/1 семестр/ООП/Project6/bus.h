#pragma once
#include "date.h"
#include "ticket.h"
class bus : public ticket
{
    int regnumb;
    int numbbus;
    int numbplace;
    date time;
    static int countb;
    static string filenameb;
public:
    bus();
    //train& operator = (const train& train_v);
    void AddInfoB(ticket* tick);
    static void Print(ticket* tick, bus* b);
    void ToFile();
    void ToString();
    static void FromFile(bus* b);
    int get_regnumb() { return regnumb; }
    int get_numbbus() { return numbbus; }
    int get_numbplace() { return numbplace; }
    date get_time() { return time; }
    static int get_countb() { return countb; }
    void set_regnumb(int regnumb_v) { regnumb = regnumb_v; }
    void set_numbbus(int numbbus_v) { numbbus = numbbus_v; }
    void set_numbplace(int numbplace_v) { numbplace = numbplace_v; }
    void set_time(date time_v) { time = time_v; }
    static void set_filenameb(string filenameb_v) { filenameb = filenameb_v; }
};
