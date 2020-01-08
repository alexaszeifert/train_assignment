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

void Vonat::felcsatol (Kocsi* kocsi) {
    if (kocsik.size () < (unsigned)kocsik_szama)
        kocsik.insert (kocsi);
}

void Vonat::lecsatol (Kocsi* kocsi) {
    kocsik.erase (kocsi);
}

void Vonat::frissit (int ido) {
    cout <<"itt";
    ido = ido % menetrend.back ().second;
    allomas = "";
    for (pair<string,int> a: menetrend) {
        if (a.second == ido) {
            allomas = a.first;
            break;
        }
    }

    for (Kocsi* kocsi: kocsik) {
        kocsi->frissit (allomas);
        cout << ido << " " << allomas << "\n";
    }
}
