#pragma once
#include "date.h"
#include "ticket.h"
class train: public ticket
{
    int regnumb;
	int numbrailcar;
	int numbplace;
	date time;
    static int counttr;
    static string filenametr;
public:
    train();
    void AddInfoTr(ticket* tick);
    static void Print(ticket* tick, train* tr);
    static void FromFile(train* tr);
    void ToFile();
    void ToString();
    int get_regnumb() { return regnumb; }
    int get_numbrailcar() { return numbrailcar; }
    int get_numbplace() { return numbplace; }
    date get_time() { return time; }
    static int get_counttr() { return counttr; }
    void set_regnumb(int regnumb_v) { regnumb = regnumb_v; }
    void set_numbrailcar(int numbrailcar_v) { numbrailcar = numbrailcar_v; }
    void set_numbplace(int numbplace_v) { numbplace = numbplace_v; }
    void set_time(date time_v) { time = time_v; }
    static void set_filenametr(string filenametr_v) { filenametr = filenametr_v; }
};