#ifndef KOCSI_H
#define KOCSI_H

#include <string>

using namespace std;

class Kocsi
{
public:
    Kocsi(string azonosito, int kapacitas, string indulo_allomas):azonosito(azonosito),kapacitas(kapacitas),indulo_allomas(indulo_allomas),telitettseg(0){};

    string getAzonosito () const;
    int getKapacitas () const;
    string getInduloAallomas () const;
    int getTelitettseg () const;

private:
    string azonosito;
    int kapacitas;
    string indulo_allomas;
    int telitettseg;
};

#endif // KOCSI_H
