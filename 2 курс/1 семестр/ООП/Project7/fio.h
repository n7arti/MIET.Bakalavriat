#pragma once
class fio
{
    char* familia;
    char* imya;
    char* otchestvo;
    friend class ticket;
public:
    fio();//конструктор
    ~fio();//деструктор
    char* get_familia() { return familia; }
    char* get_imya() { return imya; }
    char* get_otchestvo() { return otchestvo; }
    void set_familia(char* familia_v);
    void set_imya(char* imya_v); 
    void set_otchestvo(char* otchestvo_v);

};