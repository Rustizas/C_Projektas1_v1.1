#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

using namespace std;

class Studentas
{
private:
    string vardas_;
    string pavarde_;
    vector<int> namudarbai_;
    int egzaminas_;
    double balasVid_;
    double balasMed_;

public:
    Studentas();
    Studentas(const string &v, const string &p);
    Studentas(const string &v, const string &p, const vector<int> &nd, int egz);
    Studentas(const Studentas &other);
    Studentas &operator=(const Studentas &other);
    ~Studentas();

    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }
    vector<int> getNamudarbai() const { return namudarbai_; }
    int getEgzaminas() const { return egzaminas_; }
    double getBalasVid() const { return balasVid_; }
    double getBalasMed() const { return balasMed_; }

    void setVardas(const string &v) { vardas_ = v; }
    void setPavarde(const string &p) { pavarde_ = p; }
    void addNamuDarbas(int nd) { namudarbai_.push_back(nd); }
    void setNamudarbai(const vector<int> &nd) { namudarbai_ = nd; }
    void clearNamudarbai() { namudarbai_.clear(); }
    void setEgzaminas(int egz) { egzaminas_ = egz; }
    void setBalasVid(double b) { balasVid_ = b; }
    void setBalasMed(double b) { balasMed_ = b; }

    void skaiciuotiVidurki();
    void skaiciuotiMediana();

    bool operator<(const Studentas& other) const { return balasVid_ < other.balasVid_; }
    bool operator>(const Studentas& other) const { return balasVid_ > other.balasVid_; }
    bool operator==(const Studentas& other) const { return vardas_ == other.vardas_ && pavarde_ == other.pavarde_; }
};

istream& operator>>(istream& is, Studentas& s);
ostream& operator<<(ostream& os, const Studentas& s);

void bubbleSort(vector<int> &v);
int randomPazymys(mt19937 &gen);
void generuotiFaila(const string &failoVardas, int kiekis);
void generuotiVisusFailus();

void padalintiStudentus_strategija1(const vector<Studentas> &visi,
                                    double &tRusiavimas, double &tWriteVargs, double &tWriteKiet);
void padalintiStudentus_strategija1(const list<Studentas> &visi,
                                    double &tRusiavimas, double &tWriteVargs, double &tWriteKiet);

void padalintiStudentus_strategija2(vector<Studentas> &visi,
                                    double &tRusiavimas, double &tWriteVargs, double &tWriteKiet);
void padalintiStudentus_strategija2(list<Studentas> &visi,
                                    double &tRusiavimas, double &tWriteVargs, double &tWriteKiet);

void padalintiStudentus_strategija3(vector<Studentas> &visi,
                                    double &tRusiavimas, double &tWriteVargs, double &tWriteKiet);

#endif