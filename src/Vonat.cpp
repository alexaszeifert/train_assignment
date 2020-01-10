#include "Vonat.hpp"
#include <iostream>

string Vonat::getVonatNeve () const {
    return vonat_neve;
}

int Vonat::getKocsikSzama () const {
    return kocsik_szama;
}

list<pair<string,int>> Vonat::getMenetrend () const {
    return menetrend;
}

string Vonat::getAllomas () const {
    return allomas;
}

void Vonat::felcsatol (Kocsi* kocsi) {
    if (kocsik.size () < (unsigned)kocsik_szama) {
        kocsik.insert (kocsi);
        kocsi->setFelcsatolva (true);
    }
    else
        cout << "error\n";
}

void Vonat::lecsatol (Kocsi* kocsi) {
    kocsik.erase (kocsi);
    kocsi->setFelcsatolva(false);
}

///megnezi/beallitja, hogy adott idopontban hol van a vonatunk
///az ido elteleset szimulalja
///ciklikussagot szimulal, megnezi, hogy a ciklusban hanyadik elemnel tart, utana vegigmegy a menetrenden és hogy abban az oraban valamelyik megalloban van e a vonat
///frissitest meghivja a rakotott kocsikra is
///mivel az allomast mar tudjuk, igy ott mar nem kell kiszamolni az idot, csak frissiti a kocsik aktualis allomasat is

void Vonat::frissit (int ido) {
    int menet_ido = ido == 0 ? 0 : ido %  menetrend.back().second == 0 ? menetrend.back().second : ido %  menetrend.back().second;
    allomas = "";
    for (pair<string,int> a: menetrend) {
        if (a.second == menet_ido) {
            allomas = a.first;
            break;
        }
    }
    ///cout << ido << " " << vonat_neve << " " << allomas << "\n";

    for (Kocsi* kocsi: kocsik) {
        kocsi->frissit (allomas);
    }
}
