#include "Kocsi.hpp"

string Kocsi::getAzonosito () const {
    return azonosito;
}

int Kocsi::getKapacitas () const {
    return kapacitas;
}

string Kocsi::getInduloAallomas () const {
    return allomas;
}

int Kocsi::getTelitettseg () const {
    return telitettseg;
}

bool Kocsi::operator== (const Kocsi& kocsi) {
    return azonosito == kocsi.azonosito && kapacitas == kocsi.kapacitas && allomas == kocsi.allomas && telitettseg == kocsi.telitettseg;
}

void Kocsi::felpakol (Termek* termek) {
    if (termekek.size () + termek->getKezdetiDarabszam() < (unsigned)kapacitas)
        termekek.insert (termek);
}

void Kocsi::lepakol (Termek* termek){
    termekek.erase (termek);
}
