#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <set>

#include "Termek.hpp"
#include "Kocsi.hpp"
#include "Vonat.hpp"

using namespace std;

vector<Vonat> beolvas_vonat(string fajlnev1)
{
    Vonat v;
    vector<Vonat> segedv;
    string allomas_seged;
    string seged;
    stringstream ss;
    ifstream in(fajlnev1);
    int hany_allomas;
    while(in.good())
    {
        in>> v.vonat_neve;
        in>> v.kocsik_szama;
        in>> hany_allomas;
        for(int i=0; i<hany_allomas; i++)
        {
            pair<string,int> p;
            in>>p.first;
            in>>p.second;
            v.menetrend.insert(p);
        }
        segedv.push_back(v);
    }
    in.close();
    return segedv;
}

vector<Kocsi> beolvas_kocsi(string fajlnev2)
{
    vector<Kocsi> segedk;
    ifstream in2(fajlnev2);
    while(in2.good())
    {
        Kocsi k;
        in2>>k.azonosito;
        in2>>k.kapacitas;
        in2>>k.indulo_allomas;
        segedk.push_back(k);
    }
    in2.close();
    return segedk;
}

vector<Termek> beolvas_termek(string fajlnev3)
{
    ifstream in3(fajlnev3);
    vector<Termek> segedt;
    while(in3.good())
    {
        Termek t;
        in3>>t.termek_neve;
        in3>>t.forrashely;
        in3>>t.celhely;
        in3>>t.kezdeti_darabszam;
        segedt.push_back(t);
    }
    in3.close();
    return segedt;
}

int main()
{
    vector<Vonat> osszes_vonat = beolvas_vonat("menetrend1.txt");
    vector<Kocsi> osszes_termek = beolvas_kocsi("kocsi1.txt");
    vector<Termek> osszes_kocsi = beolvas_termek("termek1.txt");

    return 0;
}
