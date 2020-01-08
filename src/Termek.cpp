#include "Termek.hpp"

string Termek::getTermekNeve () const {
    return termek_neve;
}

string Termek::getForrasHely () const {
    return allomas;
}

string Termek::getCelhely () const {
    return celhely;
}

int Termek::getKezdetiDarabszam () const {
    return kezdeti_darabszam;
}

void Termek::frissit (string allomas) {
    this->allomas = allomas;
}
