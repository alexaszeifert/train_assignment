#ifndef KOCSI_H
#define KOCSI_H

#include <string>
#include <set>
#include "Termek.hpp"

using namespace std;

class Kocsi
{
public:
    Kocsi(string azonosito, int kapacitas, string allomas):azonosito(azonosito),kapacitas(kapacitas),allomas(allomas),telitettseg(0), felcsatolva (false){};

    string getAzonosito () const;
    int getKapacitas () const;
    string getAllomas () const;
    int getSzabadHely () const;
    bool getFelcsatolva () const;
    void setFelcsatolva (bool csatolva);
    set<Termek*> getTermekek () const;

    void felpakol (Termek* termek);
    void lepakol (Termek* termek);
    void frissit (string allomas);

    bool operator== (const Kocsi& kocsi);

private:
    string azonosito;
    int kapacitas;
    string allomas;
    int telitettseg;
    set<Termek*> termekek;
    bool felcsatolva;
};

#endif // KOCSI_H
