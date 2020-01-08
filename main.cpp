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
    vector<Vonat> segedv;
    string vonat_neve;
    int kocsik_szama;
    list<pair<string,int>> menetrend;
    string allomas_seged;
    string seged;
    ifstream in(fajlnev1);
    int hany_allomas;
    while(in.good())
    {
        in>> vonat_neve;
        in>> kocsik_szama;
        in>> hany_allomas;
        for(int i=0; i<hany_allomas; i++)
        {
            pair<string,int> p;
            in>>p.first;
            in>>p.second;
            menetrend.push_back(p);
        }
        segedv.push_back(Vonat (vonat_neve, kocsik_szama, menetrend));
    }
    in.close();
    return segedv;
}

vector<Kocsi> beolvas_kocsi(string fajlnev2)
{
    vector<Kocsi> segedk;
    string azonosito;
    int kapacitas;
    string indulo_allomas;
    ifstream in2(fajlnev2);
    while(in2.good())
    {
        in2>>azonosito;
        in2>>kapacitas;
        in2>>indulo_allomas;
        segedk.push_back(Kocsi (azonosito, kapacitas, indulo_allomas));
    }
    in2.close();
    return segedk;
}

vector<Termek> beolvas_termek(string fajlnev3)
{
    ifstream in3(fajlnev3);
    string termek_neve;
    string forrashely;
    string celhely;
    int kezdeti_darabszam;
    vector<Termek> segedt;
    while(in3.good())
    {
        in3>>termek_neve;
        in3>>forrashely;
        in3>>celhely;
        in3>>kezdeti_darabszam;
        segedt.push_back(Termek (termek_neve, forrashely, celhely, kezdeti_darabszam));
    }
    in3.close();
    return segedt;
}

int main()
{
    vector<Vonat> osszes_vonat = beolvas_vonat("input_files/menetrend1.txt");
    vector<Kocsi> osszes_termek = beolvas_kocsi("input_files/kocsi1.txt");
    vector<Termek> osszes_kocsi = beolvas_termek("input_files/termek1.txt");

    int ido = 0;

    while (ido < 100) {
        for (Vonat& vonat: osszes_vonat) {
            vonat.frissit (ido);
        }

        ido++;
    }

    return 0;
}
