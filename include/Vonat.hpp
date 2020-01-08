#ifndef VONAT_H
#define VONAT_H

#include <string>
#include <set>
#include "Kocsi.hpp"

using namespace std;

class Vonat
{
public:
    Vonat(string vonat_neve, int kocsik_szama, set<pair<string,int>> menetrend):vonat_neve(vonat_neve),kocsik_szama(kocsik_szama),menetrend(menetrend){};

    string getVonatNeve () const;
    int getKocsikSzama () const;
    set<pair<string,int>> getMenetrend () const;

    void felcsatol (Kocsi* kocsi);
    void lecsatol (Kocsi* kocsi);
    void frissit (int ido);

private:
    string vonat_neve;
    int kocsik_szama;
    string allomas;
    set<pair<string,int>> menetrend;
    set<Kocsi*> kocsik;
};

#endif // VONAT_H
