#ifndef TERMEK_H
#define TERMEK_H

#include <string>

using namespace std;

class Termek
{
public:
    Termek(string termek_neve, string forrashely, string celhely, int kezdeti_darabszam):termek_neve(termek_neve),forrashely(forrashely),celhely(celhely),kezdeti_darabszam(kezdeti_darabszam){};

    string getTermekNeve () const;
    string getForrasHely () const;
    string getCelhely () const;
    int getKezdetiDarabszam () const;

private:
    string termek_neve;
    string forrashely;
    string celhely;
    int kezdeti_darabszam;
};

#endif // TERMEK_H
