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

void Vonat::frissit (int ido) {
    int menet_ido = ido == 0 ? 0 : ido %  menetrend.back().second == 0 ? 7 : ido %  menetrend.back().second;
    allomas = "";
    for (pair<string,int> a: menetrend) {
        if (a.second == menet_ido) {
            allomas = a.first;
            break;
        }
    }
    cout << ido << " " << vonat_neve << " " << allomas << "\n";

    for (Kocsi* kocsi: kocsik) {
        kocsi->frissit (allomas);
    }
}
