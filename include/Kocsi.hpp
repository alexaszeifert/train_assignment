#ifndef KOCSI_H
#define KOCSI_H

#include <string>

using namespace std;

class Kocsi
{
public:
    Kocsi();

private:
    string azonosito;
    int kapacitas;
    string indulo_allomas;
    int telitettseg = 0;
};

#endif // KOCSI_H
