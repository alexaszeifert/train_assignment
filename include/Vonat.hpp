#ifndef VONAT_H
#define VONAT_H

#include <string>
#include <set>

using namespace std;

class Vonat
{
public:
    Vonat();

private:
    string vonat_neve;
    int kocsik_szama;
    set<pair<string,int>> menetrend;
};

#endif // VONAT_H
