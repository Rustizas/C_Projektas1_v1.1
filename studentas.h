#ifndef STUDENTAS_H
#define STUDENTAS_H

/**
 * @file studentas.h
 * @brief Studento klases deklaracija
 */

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
#include "zmogus.h"

using namespace std;

/**
 * @class Studentas
 * @brief Studento klase paveldinti is Zmogus
 * 
 * Si klase reprezentuoja studenta su pazymiais ir galutiniais balais.
 * Paveldi bendrą funkcionaluma is Zmogus klases.
 */
class Studentas : public Zmogus
{
private:
    vector<int> namudarbai_;  ///< Namu darbu pazymiai
    int egzaminas_;           ///< Egzamino pazymys
    double balasVid_;         ///< Galutinis balas (vidurkis)
    double balasMed_;         ///< Galutinis balas (mediana)

public:
    /**
     * @brief Numatytasis konstruktorius
     */
    Studentas();
    
    /**
     * @brief Konstruktorius su vardu ir pavarde
     * @param v Vardas
     * @param p Pavarde
     */
    Studentas(const string& v, const string& p);
    
    /**
     * @brief Konstruktorius su visais duomenimis
     * @param v Vardas
     * @param p Pavarde
     * @param nd Namu darbu pazymiai
     * @param egz Egzamino pazymys
     */
    Studentas(const string& v, const string& p, const vector<int>& nd, int egz);
    
    /**
     * @brief Kopijavimo konstruktorius
     * @param other Kitas Studentas objektas
     */
    Studentas(const Studentas& other);
    
    /**
     * @brief Priskyrimo operatorius
     * @param other Kitas Studentas objektas
     * @return Nuoroda i si objekta
     */
    Studentas& operator=(const Studentas& other);
    
    /**
     * @brief Destruktorius
     */
    ~Studentas();

    /**
     * @brief Gauti namu darbu pazymius
     * @return Namu darbu pazymiu vektorius
     */
    vector<int> getNamudarbai() const { return namudarbai_; }
    
    /**
     * @brief Gauti egzamino pazymi
     * @return Egzamino pazymys
     */
    int getEgzaminas() const { return egzaminas_; }
    
    /**
     * @brief Gauti galutini bala (vidurkis)
     * @return Galutinis balas
     */
    double getBalasVid() const { return balasVid_; }
    
    /**
     * @brief Gauti galutini bala (mediana)
     * @return Galutinis balas (mediana)
     */
    double getBalasMed() const { return balasMed_; }

    /**
     * @brief Prideti namu darbo pazymi
     * @param nd Namu darbo pazymys
     */
    void addNamuDarbas(int nd) { namudarbai_.push_back(nd); }
    
    /**
     * @brief Nustatyti namu darbu pazymius
     * @param nd Namu darbu pazymiu vektorius
     */
    void setNamudarbai(const vector<int>& nd) { namudarbai_ = nd; }
    
    /**
     * @brief Isvalyti namu darbu pazymius
     */
    void clearNamudarbai() { namudarbai_.clear(); }
    
    /**
     * @brief Nustatyti egzamino pazymi
     * @param egz Egzamino pazymys
     */
    void setEgzaminas(int egz) { egzaminas_ = egz; }
    
    /**
     * @brief Nustatyti galutini bala (vidurkis)
     * @param b Galutinis balas
     */
    void setBalasVid(double b) { balasVid_ = b; }
    
    /**
     * @brief Nustatyti galutini bala (mediana)
     * @param b Galutinis balas
     */
    void setBalasMed(double b) { balasMed_ = b; }

    /**
     * @brief Apskaiciuoti galutini bala pagal vidurki
     */
    void skaiciuotiVidurki();
    
    /**
     * @brief Apskaiciuoti galutini bala pagal mediana
     */
    void skaiciuotiMediana();
    
    /**
     * @brief Isvesti studento duomenis
     */
    void isvesti() const override;

    /**
     * @brief Palyginimo operatorius (maziau)
     * @param other Kitas studentas
     * @return true jei sio studento balas mazesnis
     */
    bool operator<(const Studentas& other) const { return balasVid_ < other.balasVid_; }
    
    /**
     * @brief Palyginimo operatorius (daugiau)
     * @param other Kitas studentas
     * @return true jei sio studento balas didesnis
     */
    bool operator>(const Studentas& other) const { return balasVid_ > other.balasVid_; }
    
    /**
     * @brief Palyginimo operatorius (lygu)
     * @param other Kitas studentas
     * @return true jei vardas ir pavarde sutampa
     */
    bool operator==(const Studentas& other) const { return vardas_ == other.vardas_ && pavarde_ == other.pavarde_; }
};

/**
 * @brief Bubble sort algoritmas vektoriui
 * @param v Vektorius rusiavimui
 */
void bubbleSort(vector<int> &v);

/**
 * @brief Generuoti atsitiktini pazymi
 * @param gen Random number generator
 * @return Atsitiktinis pazymys nuo 1 iki 10
 */
int randomPazymys(mt19937 &gen);

/**
 * @brief Generuoti studentu faila
 * @param failoVardas Failo pavadinimas
 * @param kiekis Studentu skaicius
 */
void generuotiFaila(const string &failoVardas, int kiekis);

/**
 * @brief Generuoti visus testavimo failus
 */
void generuotiVisusFailus();

void padalintiStudentus_strategija1(const vector<Studentas>& visi,
                        double& tRusiavimas, double& tWriteVargs, double& tWriteKiet);
void padalintiStudentus_strategija1(const list<Studentas>& visi,
                        double& tRusiavimas, double& tWriteVargs, double& tWriteKiet);

void padalintiStudentus_strategija2(vector<Studentas>& visi,
                        double& tRusiavimas, double& tWriteVargs, double& tWriteKiet);
void padalintiStudentus_strategija2(list<Studentas>& visi,
                        double& tRusiavimas, double& tWriteVargs, double& tWriteKiet);

void padalintiStudentus_strategija3(vector<Studentas>& visi,
                        double& tRusiavimas, double& tWriteVargs, double& tWriteKiet);

/**
 * @brief Ivesties operatorius
 * @param is Input stream
 * @param s Studentas objektas
 * @return Input stream
 */
istream& operator>>(istream& is, Studentas& s);

/**
 * @brief Isvesties operatorius
 * @param os Output stream
 * @param s Studentas objektas
 * @return Output stream
 */
ostream& operator<<(ostream& os, const Studentas& s);

#endif