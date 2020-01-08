#include "Vonat.hpp"

string Vonat::getVonatNeve () const {
    return vonat_neve;
}

int Vonat::getKocsikSzama () const {
    return kocsik_szama;
}

set<pair<string,int>> Vonat::getMenetrend () const {
    return menetrend;
}

void Vonat::felcsatol (Kocsi* kocsi) {
    if (kocsik.size () < (unsigned)kocsik_szama)
        kocsik.insert (kocsi);
}

void Vonat::lecsatol (Kocsi* kocsi) {
    kocsik.erase (kocsi);
}
