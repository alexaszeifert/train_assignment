#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <set>


using namespace std;

struct Termek
{
    string termek_neve;
    string forrashely;
    string celhely;
    int kezdeti_darabszam;
};

struct Kocsi
{
    string azonosito;
    int kapacitas;
    string indulo_allomas;
    int telitettseg=0;
};

struct Vonat
{
    string vonat_neve;
    int kocsik_szama;
    set<pair<string,int>> menetrend;
};

vector<Vonat> beolvas_vonat(string fajlnev1)
{
    Vonat v;
    vector<Vonat> segedv;
    string allomas_seged;
    int eltelt_ido_seged=0;
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
            in>>allomas_seged;
            in>>eltelt_ido_seged;
            pair<string,int> p;
            p.first=allomas_seged;
            p.second=eltelt_ido_seged;
            v.menetrend.insert(p);
            allomas_seged.clear();
            eltelt_ido_seged=0;
        }
        segedv.push_back(v);
    }
    ///itt nem lenne rossz feltölteni, de szintén nem tudjuk ellenőrizni, hogy nincse már benne az a vonat
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
        ///osszes_kocsi.push_back(k); itt ha abba töltjük fel először, akkor nincs megvizsgálva, hogy vane olyan nevű kocsi már
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
    vector<Vonat> osszes_vonat;
    vector<Termek> osszes_termek;
    vector<Kocsi> osszes_kocsi;
    osszes_vonat = beolvas_vonat("menetrend1.txt");
    osszes_kocsi = beolvas_kocsi("kocsi1.txt");
    osszes_termek = beolvas_termek("termek1.txt");
    cout << "Hello world!" << endl;
    return 0;
}
