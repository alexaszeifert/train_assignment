#include <iostream>
#include <vector>
#include <list>


using namespace std;

struct Termek{
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
vector<Kocsi> szerelveny;
list<pair<string,int>> menetrend;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
