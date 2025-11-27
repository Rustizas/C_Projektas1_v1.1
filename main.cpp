#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iterator>
using namespace std;
#include "studentas.h"

template <typename Container>
const void *last_address(const Container &c)
{
    auto it = c.end();
    if (it == c.begin())
        return nullptr;
    --it;
    return static_cast<const void *>(&(*it));
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    cout << "Pasirinkite veiksmą:\n"
         << "1 - ivedimas ranka\n"
         << "2 - nuskaitymas is failo (vienkartinis)\n"
         << "3 - sugeneruoti 5 failus (tik kurimas)\n"
         << "4 - benchmarkai su esamais failais (Vector arba List, keli kartojimai)\n";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 3)
    {
        generuotiVisusFailus();
        return 0;
    }

    int kont = 1;
    if (pasirinkimas == 1 || pasirinkimas == 4)
    {
        cout << "Pasirinkite konteinerį: 1 - vector<Studentas>, 2 - list<Studentas>: ";
        cin >> kont;
    }

    if (pasirinkimas == 1)
    {
        int skaiciusstud;
        cout << "Iveskite studentu skaiciu: ";
        cin >> skaiciusstud;

        if (kont == 1)
        {
            vector<Studentas> studentaivisi;
            studentaivisi.reserve(skaiciusstud);

            for (int j = 0; j < skaiciusstud; j++)
            {
                Studentas stud;
                int ndSk;
                int ivestis;
                string v, p;
                cout << "Iveskite studento varda ir pavarde: ";
                cin >> v >> p;
                stud.setVardas(v);
                stud.setPavarde(p);
                cout << "Ar norite ivesti pazymius pats (1), ar generuoti atsitiktinai (2)? ";
                cin >> ivestis;
                if (ivestis == 1)
                {
                    cout << "Iveskite namu darbu skaiciu (0 jei nezinote): ";
                    cin >> ndSk;
                    cout << "Iveskite namu darbu rezultatus (0 jei baigete): ";
                    for (;;)
                    {
                        int n;
                        cin >> n;
                        if (n == 0)
                            break;
                        stud.addNamuDarbas(n);
                        if (ndSk != 0 && (int)stud.getNamudarbai().size() >= ndSk)
                            break;
                    }
                    cout << "Iveskite egzamino rezultata: ";
                    int egz;
                    cin >> egz;
                    stud.setEgzaminas(egz);
                }
                else
                {
                    cout << "Kiek namu darbu generuoti? ";
                    cin >> ndSk;
                    for (int i = 0; i < ndSk; i++)
                        stud.addNamuDarbas(dist(gen));
                    stud.setEgzaminas(dist(gen));
                    cout << "Sugeneruoti ND: ";
                    for (int x : stud.getNamudarbai())
                        cout << x << " ";
                    cout << " Egzaminas: " << stud.getEgzaminas() << "\n";
                }

                stud.skaiciuotiVidurki();
                stud.skaiciuotiMediana();

                studentaivisi.push_back(stud);

                cout << "Objekto adresas atmintyje: " << last_address(studentaivisi) << "\n";
            }
        }
        else
        {
            list<Studentas> studentaivisi;

            for (int j = 0; j < skaiciusstud; j++)
            {
                Studentas stud;
                int ndSk;
                int ivestis;
                string v, p;
                cout << "Iveskite studento varda ir pavarde: ";
                cin >> v >> p;
                stud.setVardas(v);
                stud.setPavarde(p);
                cout << "Ar norite ivesti pazymius pats (1), ar generuoti atsitiktinai (2)? ";
                cin >> ivestis;
                if (ivestis == 1)
                {
                    cout << "Iveskite namu darbu skaiciu (0 jei nezinote): ";
                    cin >> ndSk;
                    cout << "Iveskite namu darbu rezultatus (0 jei baigete): ";
                    for (;;)
                    {
                        int n;
                        cin >> n;
                        if (n == 0)
                            break;
                        stud.addNamuDarbas(n);
                        if (ndSk != 0 && (int)stud.getNamudarbai().size() >= ndSk)
                            break;
                    }
                    cout << "Iveskite egzamino rezultata: ";
                    int egz;
                    cin >> egz;
                    stud.setEgzaminas(egz);
                }
                else
                {
                    cout << "Kiek namu darbu generuoti? ";
                    cin >> ndSk;
                    for (int i = 0; i < ndSk; i++)
                        stud.addNamuDarbas(dist(gen));
                    stud.setEgzaminas(dist(gen));
                    cout << "Sugeneruoti ND: ";
                    for (int x : stud.getNamudarbai())
                        cout << x << " ";
                    cout << " Egzaminas: " << stud.getEgzaminas() << "\n";
                }

                stud.skaiciuotiVidurki();
                stud.skaiciuotiMediana();

                studentaivisi.push_back(stud);

                cout << "Objekto adresas atmintyje: " << last_address(studentaivisi) << "\n";
            }
        }
        return 0;
    }

    if (pasirinkimas == 2)
    {
        string Pav;
        cout << "Iveskite failo pavadinima: ";
        cin >> Pav;

        auto startViso = chrono::high_resolution_clock::now();
        auto startNuskaitymas = chrono::high_resolution_clock::now();

        ifstream in(Pav);
        string eilute;
        getline(in, eilute);
        int stulpeliai = 0;
        {
            string z;
            stringstream p(eilute);
            while (p >> z)
                stulpeliai++;
        }
        int ndSk = stulpeliai - 3;

        vector<Studentas> studentaivisi;
        while (true)
        {
            Studentas stud;
            if (!(in >> stud))
                break;
            stud.clearNamudarbai();
            for (int i = 0; i < ndSk; i++)
            {
                int paz;
                in >> paz;
                stud.addNamuDarbas(paz);
            }
            int egz;
            in >> egz;
            stud.setEgzaminas(egz);

            stud.skaiciuotiVidurki();
            stud.skaiciuotiMediana();

            studentaivisi.push_back(stud);
        }
        in.close();

        auto endNuskaitymas = chrono::high_resolution_clock::now();
        chrono::duration<double> tRead = endNuskaitymas - startNuskaitymas;
        cout << "Failo is " << studentaivisi.size()
             << " irasu nuskaitymo laikas: " << fixed << setprecision(6) << tRead.count() << " s\n";

        double tR, tWV, tWK;
        padalintiStudentus_strategija1(studentaivisi, tR, tWV, tWK);

        auto endViso = chrono::high_resolution_clock::now();
        chrono::duration<double> tTotal = endViso - startViso;
        cout << studentaivisi.size() << " irasu testo laikas: " << fixed << setprecision(6)
             << tTotal.count() << " s\n";
        return 0;
    }

    if (pasirinkimas == 4)
    {
        vector<int> dydziai = {1000, 10000, 100000, 1000000};
        int repeats = 3;

        cout << "Pasirinkite strategija:\n"
             << "1 - Strategija 1 (kopijuojami abu)\n"
             << "2 - Strategija 2 (trinami vargsiukai)\n"
             << "3 - Strategija 3 (STL partition - tik vector)\n";
        int strategija;
        cin >> strategija;

        ofstream csv("rezultatai.csv", ios::trunc);
        csv << "container,size,strategy,run,read_s,split_s,write_vargs_s,write_kiet_s,total_s\n";

        string contName = (kont == 1 ? "vector" : "list");
        cout << "\n=== BENCHMARK: " << contName << " ===\n";

        for (int dydis : dydziai)
        {
            string failoVardas = "studentai_" + to_string(dydis) + ".txt";

            vector<double> rRead, rSplit, rWV, rWK, rTotal;

            for (int r = 1; r <= repeats; r++)
            {
                auto startViso = chrono::high_resolution_clock::now();
                auto startNuskaitymas = chrono::high_resolution_clock::now();

                string eilute;
                ifstream in(failoVardas);
                if (!in)
                {
                    cerr << "Nepavyko atidaryti: " << failoVardas << "\n";
                    break;
                }
                getline(in, eilute);
                int stulpeliai = 0;
                {
                    string z;
                    stringstream p(eilute);
                    while (p >> z)
                        stulpeliai++;
                }
                int ndSk = stulpeliai - 3;

                double tRead = 0.0, tSplit = 0.0, tWV_s = 0.0, tWK_s = 0.0;

                if (kont == 1)
                {
                    vector<Studentas> visi;
                    visi.reserve(dydis);
                    while (true)
                    {
                        Studentas stud;
                        if (!(in >> stud))
                            break;
                        stud.clearNamudarbai();
                        for (int i = 0; i < ndSk; i++)
                        {
                            int paz;
                            in >> paz;
                            stud.addNamuDarbas(paz);
                        }
                        int egz;
                        in >> egz;
                        stud.setEgzaminas(egz);

                        stud.skaiciuotiVidurki();
                        stud.skaiciuotiMediana();

                        visi.push_back(stud);
                    }
                    auto endN = chrono::high_resolution_clock::now();
                    tRead = chrono::duration<double>(endN - startNuskaitymas).count();

                    if (strategija == 1)
                    {
                        const vector<Studentas> visiConst = visi;
                        padalintiStudentus_strategija1(visiConst, tSplit, tWV_s, tWK_s);
                    }
                    else if (strategija == 2)
                    {
                        padalintiStudentus_strategija2(visi, tSplit, tWV_s, tWK_s);
                    }
                    else if (strategija == 3)
                    {
                        padalintiStudentus_strategija3(visi, tSplit, tWV_s, tWK_s);
                    }
                }
                else
                {
                    list<Studentas> visi;
                    while (true)
                    {
                        Studentas stud;
                        if (!(in >> stud))
                            break;
                        stud.clearNamudarbai();
                        for (int i = 0; i < ndSk; i++)
                        {
                            int paz;
                            in >> paz;
                            stud.addNamuDarbas(paz);
                        }
                        int egz;
                        in >> egz;
                        stud.setEgzaminas(egz);

                        stud.skaiciuotiVidurki();
                        stud.skaiciuotiMediana();

                        visi.push_back(stud);
                    }
                    auto endN = chrono::high_resolution_clock::now();
                    tRead = chrono::duration<double>(endN - startNuskaitymas).count();

                    if (strategija == 1)
                    {
                        const list<Studentas> visiConst = visi;
                        padalintiStudentus_strategija1(visiConst, tSplit, tWV_s, tWK_s);
                    }
                    else if (strategija == 2)
                    {
                        padalintiStudentus_strategija2(visi, tSplit, tWV_s, tWK_s);
                    }
                    else if (strategija == 3 && kont == 1)
                    {
                        cout << "Strategija 3 nepalaiko list konteinerio\n";
                        return 1;
                    }
                }

                auto endViso = chrono::high_resolution_clock::now();
                double tTotal = chrono::duration<double>(endViso - startViso).count();

                rRead.push_back(tRead);
                rSplit.push_back(tSplit);
                rWV.push_back(tWV_s);
                rWK.push_back(tWK_s);
                rTotal.push_back(tTotal);

                cout << contName << " | " << dydis << " | S" << strategija << " | run " << r
                     << " | read=" << fixed << setprecision(6) << tRead
                     << " s | split=" << tSplit
                     << " s | write(v)=" << tWV_s
                     << " s | write(k)=" << tWK_s
                     << " s | total=" << tTotal << " s\n";

                csv << contName << "," << dydis << "," << strategija << "," << r << ","
                    << tRead << "," << tSplit << "," << tWV_s << "," << tWK_s << "," << tTotal << "\n";
            }

            auto avg = [](const vector<double> &v)
            {
                if (v.empty())
                    return 0.0;
                double s = 0;
                for (double x : v)
                    s += x;
                return s / v.size();
            };
            double aRead = avg(rRead), aSplit = avg(rSplit), aWV = avg(rWV), aWK = avg(rWK), aTotal = avg(rTotal);
            cout << "AVG -> " << contName << " | " << dydis << " | S" << strategija
                 << " | read=" << aRead << " s | split=" << aSplit
                 << " s | write(v)=" << aWV << " s | write(k)=" << aWK
                 << " s | total=" << aTotal << " s\n\n";

            csv << contName << "," << dydis << "," << strategija << ",avg,"
                << aRead << "," << aSplit << "," << aWV << "," << aWK << "," << aTotal << "\n";
        }

        cout << "Visi rezultatai įrašyti į rezultatai.csv\n";
        return 0;
    }

    cout << "Nesuprastas pasirinkimas.\n";
    return 0;
}