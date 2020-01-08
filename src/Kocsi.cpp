#include "Kocsi.hpp"
#include <iostream>

string Kocsi::getAzonosito () const {
    return azonosito;
}

int Kocsi::getKapacitas () const {
    return kapacitas;
}

string Kocsi::getAllomas () const {
    return allomas;
}

int Kocsi::getSzabadHely () const {
    int szabad = kapacitas;
    for (Termek* termek: termekek)
        szabad -= termek->getDarabszam();
    return szabad;
}

bool Kocsi::operator== (const Kocsi& kocsi) {
    return azonosito == kocsi.azonosito && kapacitas == kocsi.kapacitas && allomas == kocsi.allomas && telitettseg == kocsi.telitettseg;
}

void Kocsi::felpakol (Termek* termek) {
    if (getSzabadHely() >= termek->getDarabszam())
        termekek.insert (termek);
    else
        cout << "error\n";
}

void Kocsi::lepakol (Termek* termek) {
    termekek.erase (termek);
}

void Kocsi::frissit (string allomas) {
    this->allomas = allomas;
    for (Termek* termek: termekek) {
        termek->frissit (allomas);
    }
}
