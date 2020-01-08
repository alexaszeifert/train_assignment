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
