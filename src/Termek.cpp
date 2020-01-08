#include "Termek.hpp"

string Termek::getTermekNeve () const {
    return termek_neve;
}

string Termek::getAllomas () const {
    return allomas;
}

string Termek::getCelhely () const {
    return celhely;
}

int Termek::getDarabszam () const {
    return darabszam;
}

void Termek::frissit (string allomas) {
    this->allomas = allomas;
}

Termek Termek::eloszt (int mennyit) {
    darabszam -= mennyit;
    return Termek (termek_neve, allomas, celhely, mennyit);
}
