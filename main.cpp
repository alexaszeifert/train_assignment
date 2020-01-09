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

int main()
{
    vector<Vonat> osszes_vonat = beolvas_vonat("input_files/menetrend1.txt");
    vector<Kocsi> osszes_kocsi = beolvas_kocsi("input_files/kocsi1.txt");
    vector<Termek> osszes_termek = beolvas_termek("input_files/termek1.txt");

    kiir_adatok(osszes_vonat,osszes_termek,osszes_kocsi);

    int ido = 0;

    while (ido < 40) {
        for (Vonat& vonat: osszes_vonat) {
            vonat.frissit (ido);
        }

        set<string> pakolva; // ezekbe pakoltunk, ezeket nem csatolhatjuk ebben a korben mar

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
                        cout << ido << " pakol " << kocsi.getAzonosito() << " " << uj.getTermekNeve() << " " << uj.getDarabszam() << " (elosztva)\n";
                    }
                }
            }
        }

        for (Kocsi& kocsi: osszes_kocsi) {
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

        ///ezek bepakolja a term�keket abba a kocsikba, amelyek nincsenek felcsatolva
        ///getFelcsatolva fel true, lecsatolva false meg kell �rni
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
                                /* megnezni jo-e
                                if (kocsi.getSzabadHely() >= termek.getDarabszam()) {
                                    kocsi.felpakol(&termek);
                                    pakolva.insert(kocsi.getAzonosito());
                                    cout << ido << " pakol " << kocsi.getAzonosito() << " " << termek.getTermekNeve() << " " << termek.getDarabszam() << "\n";
                                } else if (kocsi.getSzabadHely() != 0 && kocsi.getFelcsatolva() == false && pakolva.count (kocsi.getAzonosito()) == 0) {
                                    Termek uj = termek.eloszt(kocsi.getSzabadHely());
                                    osszes_termek.push_back(uj);
                                    kocsi.felpakol(&osszes_termek[osszes_termek.size () - 1]);
                                    pakolva.insert(kocsi.getAzonosito());
                                    cout << ido << " pakol " << kocsi.getAzonosito() << " " << uj.getTermekNeve() << " " << uj.getDarabszam() << " (elosztva)\n";
                                }*/
                                break;
                            }
                        }
                    }
                }
            }
        }
            ///ez a kocsi felcsatol�sa, kb ugyanaz mint az el�z�, azaz a fenti

        ido++;
        pakolva.clear();
    }

    for (Termek& termek: osszes_termek) {
        cout << termek.getTermekNeve() << " leszallitva: " << termek.getLeszallitva() << endl;
    }

    return 0;
}
