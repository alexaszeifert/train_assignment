#ifndef TERMEK_H
#define TERMEK_H

#include <string>

using namespace std;

class Termek
{
public:
    Termek(string termek_neve, string allomas, string celhely, int darabszam):termek_neve(termek_neve),allomas(allomas),celhely(celhely),darabszam(darabszam){};

    string getTermekNeve () const;
    string getAllomas () const;
    string getCelhely () const;
    int getDarabszam () const;

    void frissit (string allomas);
    Termek eloszt (int mennyit);

private:
    string termek_neve;
    string allomas;
    string celhely;
    int darabszam;
};

#endif // TERMEK_H
