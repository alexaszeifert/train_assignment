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
    string allomas_seged;
    string seged;
    ifstream in(fajlnev1);
    int hany_allomas;
    while(in.good())
    {
        list<pair<string,int>> menetrend;
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

void kiir_adatok(vector<Vonat> a, vector<Termek> c,  vector<Kocsi> b)
{
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i].getVonatNeve()<<", ";
        cout<<a[i].getKocsikSzama()<<", ";
        list<pair<string, int>> menetrend = a[i].getMenetrend();
        cout<<menetrend.size()<<", ";
        for(auto it= menetrend.begin(); it != menetrend.end(); it++)
        {
            cout<<it->first<<", ";
            cout<<it->second<<", ";
        }
        cout<<endl;
    }
    for(int j=0; j<b.size(); j++)
    {
        cout<<b[j].getAzonosito()<<", ";
        cout<<b[j].getKapacitas()<<", ";
        cout<<b[j].getAllomas()<<endl;
    }
    for(int k=0; k<c.size(); k++)
    {
        cout<<c[k].getTermekNeve()<<", ";
        cout<<c[k].getAllomas()<<", ";
        cout<<c[k].getCelhely()<<", ";
        cout<<c[k].getDarabszam()<<endl;
    }
}

bool lehetetlen_kocsi(vector<Vonat> a, vector<Kocsi> b){
    bool eredmeny;

for(int i=0; i<b.size();i++){
    for(int j=0; j<a.size();j++){
        list<pair<string, int>> menetrend = a[j].getMenetrend();
        for(auto it = menetrend.begin(); it!=menetrend.end(); it++){
             if(b[i].getAllomas() == it->first) {eredmeny=true; break;}
             else eredmeny=false;
        }
        if(eredmeny==true) break;
    }
}
return eredmeny;
}

bool lehetetlen_termek(vector<Vonat> a, vector<Termek> c){
    bool eredmeny_allomas;
    bool eredmeny_celhely;
    bool eredmeny;

for(int i=0; i<c.size();i++){
    for(int j=0; j<a.size();j++){
        list<pair<string, int>> menetrend = a[j].getMenetrend();
        for(auto it = menetrend.begin(); it!=menetrend.end(); it++){
             if(c[i].getAllomas() == it->first) {eredmeny_allomas=true;break;}
             else eredmeny_allomas=false;
        }
         for(auto it = menetrend.begin(); it!=menetrend.end(); it++){
             if(c[i].getCelhely() == it->first) {eredmeny_celhely=true;break;}
             else eredmeny_celhely=false;
        }
        if(eredmeny_allomas==true && eredmeny_celhely==true) {eredmeny=true; break;}
        else eredmeny=false;
    }
}
return eredmeny;
}

int main()
{
    /*vector<Vonat> osszes_vonat = beolvas_vonat("input_files/menetrend1.txt");
    vector<Kocsi> osszes_kocsi = beolvas_kocsi("input_files/kocsi1.txt");
    vector<Termek> osszes_termek = beolvas_termek("input_files/termek1.txt");*/
    vector<Vonat> osszes_vonat = beolvas_vonat("input_files/ket_vonat_menetrend5.txt");
    vector<Kocsi> osszes_kocsi = beolvas_kocsi("input_files/ket_vonat_kocsi5.txt");
    vector<Termek> osszes_termek = beolvas_termek("input_files/ket_vonat_termek5.txt");

    kiir_adatok(osszes_vonat,osszes_termek,osszes_kocsi);

    int ido = 0;

    ///ciklus az ido szimulalasara
    bool lefussone_kocsi;
    bool lefussone_termek;

    lefussone_kocsi = lehetetlen_kocsi(osszes_vonat, osszes_kocsi);
    lefussone_termek = lehetetlen_termek(osszes_vonat, osszes_termek);

    if(lefussone_kocsi==true && lefussone_termek==true){
    while (ido < 40) { ///frissitjuk a vonatok aktualis poziciojat az ido elteltevel
        for (Vonat& vonat: osszes_vonat) {
            vonat.frissit (ido);
        }

        set<string> pakolva; // ezekbe pakoltunk, ezeket nem csatolhatjuk ebben a korben mar

///osszehasonlitja az arukat, megnezi, hogy ugyanazon az allomason vannak e a kocsiparok, hogy nincsenek e felcsatolva, ha nincs, akkor megprobal ra felpakolni

        for (Kocsi& kocsi: osszes_kocsi) {
            for (Termek& termek: osszes_termek) {
                if (kocsi.getAllomas() == termek.getAllomas() && kocsi.getFelcsatolva() == false && termek.getLeszallitva() == false) {
                    if (kocsi.getSzabadHely() >= termek.getDarabszam()) {
                        kocsi.felpakol(&termek);
                        pakolva.insert(kocsi.getAzonosito());
                        cout << ido << " pakol " << kocsi.getAzonosito() << " " << termek.getTermekNeve() << " " << termek.getDarabszam() << "\n";
                    } else if (kocsi.getSzabadHely() != 0 && kocsi.getFelcsatolva() == false && pakolva.count (kocsi.getAzonosito()) == 0) {
                        Termek uj = termek.eloszt(kocsi.getSzabadHely());
                        osszes_termek.push_back(uj);
                        kocsi.felpakol(&osszes_termek[osszes_termek.size () - 1]);
                        pakolva.insert(kocsi.getAzonosito());
                        cout << ido << " pakol " << kocsi.getAzonosito() << " " << uj.getTermekNeve() << " " << uj.getDarabszam() << "\n";
                    }
                }
            }
        }

        for (Kocsi& kocsi: osszes_kocsi) { //vegigmegy az osszes kocsin, ha epp allomason van akkor vegigmegy az osszes termeken, ami allomason van
            if (kocsi.getAllomas() != "") {
                for (Termek* termek: kocsi.getTermekek()) {
                    if (termek->getCelhely() == kocsi.getAllomas() && kocsi.getFelcsatolva() == false) {
                        kocsi.lepakol(termek);
                        termek->setLeszallitva(true);
                        pakolva.insert(kocsi.getAzonosito());
                        cout << ido << " kipakol " << kocsi.getAzonosito() << " " << termek->getTermekNeve() << " " << termek->getDarabszam() << "\n";
                    }
                }
            }
        }

        ///ez bepakolja a termekeket abba a kocsikba, amelyek nincsenek felcsatolva
        for (Vonat& vonat: osszes_vonat) {
            for (Kocsi& kocsi: osszes_kocsi) {
                if (pakolva.count (kocsi.getAzonosito()) == 0 && kocsi.getFelcsatolva() == false && vonat.getAllomas() == kocsi.getAllomas()) {
                    vonat.felcsatol(&kocsi);
                    cout << ido << " felcsatol " << kocsi.getAzonosito() << " " << vonat.getVonatNeve() << "\n";
                }
                if (pakolva.count (kocsi.getAzonosito()) == 0 && kocsi.getFelcsatolva() == true && vonat.getAllomas() == kocsi.getAllomas()) {
                    for (Termek* termek: kocsi.getTermekek()) {
                        if (termek->getCelhely() == kocsi.getAllomas()) {
                            vonat.lecsatol(&kocsi);
                            cout << ido << " lecsatol " << kocsi.getAzonosito() << " " << vonat.getVonatNeve() << "\n";
                            break;
                        }
                    }
                    if (kocsi.getFelcsatolva() == true && kocsi.getSzabadHely() > 0) {
                        for (Termek& termek: osszes_termek) {
                            if (termek.getAllomas() == kocsi.getAllomas() && termek.getLeszallitva() == false) {
                                vonat.lecsatol(&kocsi);
                                cout << ido << " lecsatol " << kocsi.getAzonosito() << " " << vonat.getVonatNeve() << "\n";
                                // megnezni jo-e
                                if (kocsi.getSzabadHely() >= termek.getDarabszam()) {
                                    kocsi.felpakol(&termek);
                                    pakolva.insert(kocsi.getAzonosito());
                                    cout << ido << " pakol " << kocsi.getAzonosito() << " " << termek.getTermekNeve() << " " << termek.getDarabszam() << "\n";
                                } else if (kocsi.getSzabadHely() != 0 && kocsi.getFelcsatolva() == false && pakolva.count (kocsi.getAzonosito()) == 0) {
                                    Termek uj = termek.eloszt(kocsi.getSzabadHely());
                                    osszes_termek.push_back(uj);
                                    kocsi.felpakol(&osszes_termek[osszes_termek.size () - 1]);
                                    pakolva.insert(kocsi.getAzonosito());
                                    cout << ido << " pakol " << kocsi.getAzonosito() << " " << uj.getTermekNeve() << " " << uj.getDarabszam() << "\n";
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
            ///ez a kocsi felcsatolasa, kb ugyanaz mint az elozo, azaz a fenti

        ido++;
        pakolva.clear();

    int szamlalo = 0;
    for (Termek& termek: osszes_termek) {
        if(termek.getLeszallitva()==true)
        {
            szamlalo++;
        }
    }
    if(szamlalo==osszes_termek.size())
    {
        break;
    }
    }
    }
    else cout<<"LEHETETLEN!!!"<<endl;

    /*for (Termek& termek: osszes_termek) {
        cout << termek.getTermekNeve() << " leszallitva: " << termek.getLeszallitva() << endl;
    }*/

    return 0;
}
