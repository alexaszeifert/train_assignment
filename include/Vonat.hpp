#ifndef VONAT_H
#define VONAT_H

#include <string>
#include <set>

using namespace std;

class Vonat
{
public:
    Vonat(string vonat_neve,int kocsik_szama,set<pair<string,int>> menetrend):vonat_neve(vonat_neve),kocsik_szama(kocsik_szama),menetrend(menetrend){};

private:
    string vonat_neve;
    int kocsik_szama;
    set<pair<string,int>> menetrend;
};

#endif // VONAT_H
