#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <set>


using namespace std;

struct Termek{
string termek_neve;
string forrashely;
string celhely;
int kezdeti_darabszam;
};

struct Kocsi{
string azonosito;
int kapacitas;
string indulo_allomas;
int telitettseg=0;
};

struct Vonat{
string vonat_neve;
int kocsik_szama;
set<pair<string,int>> menetrend;
};

void beolvas(string fajlnev1,string fajlnev2, string fajlnev3){
Vonat v;
string allomas_seged;
int eltelt_ido_seged=0;
string seged;
stringstream ss;
ifstream in(fajlnev1);
getline(in, v.vonat_neve, ' ');
getline(in, seged);
ss<<seged;
ss>>v.kocsik_szama;
ss.clear();
while(in.good()){
getline(in,allomas_seged, ' ');
getline(in,seged);
ss<<seged;
ss>>eltelt_ido_seged;
ss.clear();
pair<string,int> p;
p.first=allomas_seged;
p.second=eltelt_ido_seged;
v.menetrend.insert(p);
allomas_seged.clear();
eltelt_ido_seged=0;
}
//osszes_vonat.push_back(v); itt nem lenne rossz feltölteni, de szintén nem tudjuk ellenõrizni, hogy nincse már benne az a vonat
in.close();


ifstream in2(fajlnev2);
while(in2.good()){
    Kocsi k;
    getline(in2,k.azonosito,' ');
    getline(in2,seged,' ');
    ss<<seged;
    ss>>k.kapacitas;
    getline(in2,k.indulo_allomas);
    ///osszes_kocsi.push_back(k); itt ha abba töltjük fel elõször, akkor nincs megvizsgálva, hogy vane olyan nevû kocsi már
    ss.clear();
}
in2.close();

ifstream in3(fajlnev3);
while(in3.good()){
    Termek t;
    getline(in3,t.termek_neve,' ');
    getline(in3,t.forrashely,' ');
    getline(in3,t.celhely,' ');
    getline(in3,seged);
    ss<<seged;
    ss>>t.kezdeti_darabszam;
    ss.clear();
}
in3.close();
}

int main()
{
    vector<Vonat> osszes_vonat;
    vector<Termek> osszes_termek;
    vector<Kocsi> osszes_kocsi;
    beolvas("menetrend1.txt", "kocsi1.txt", "termek1.txt");
    cout << "Hello world!" << endl;
    return 0;
}
