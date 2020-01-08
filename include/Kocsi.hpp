#ifndef KOCSI_H
#define KOCSI_H

#include <string>

using namespace std;

class Kocsi
{
public:
    Kocsi(string azonosito,int kapacitas,string indulo_allomas,int telitettseg):azonosito(azonosito),kapacitas(kapacitas),indulo_allomas(indulo_allomas),telitettseg(telitettseg){};

private:
    string azonosito;
    int kapacitas;
    string indulo_allomas;
    int telitettseg;
};

#endif // KOCSI_H
