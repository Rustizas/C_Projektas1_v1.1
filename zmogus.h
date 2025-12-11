#ifndef ZMOGUS_H
#define ZMOGUS_H

/**
 * @file zmogus.h
 * @brief Abstrakti bazine klase Zmogus
 */

#include <string>
using namespace std;

/**
 * @class Zmogus
 * @brief Abstrakti bazine klase reprezentuojanti bendrą zmogaus objekta
 * 
 * Si klase negali buti tiesiogiai instancijuota del grynosios virtualios funkcijos.
 * Ji teikia bendra funkcionaluma visoms isvestinems klasems.
 */
class Zmogus
{
protected:
    string vardas_;   ///< Zmogaus vardas
    string pavarde_;  ///< Zmogaus pavarde

public:
    /**
     * @brief Numatytasis konstruktorius
     */
    Zmogus();
    
    /**
     * @brief Konstruktorius su parametrais
     * @param v Vardas
     * @param p Pavarde
     */
    Zmogus(const string& v, const string& p);
    
    /**
     * @brief Kopijavimo konstruktorius
     * @param other Kitas Zmogus objektas
     */
    Zmogus(const Zmogus& other);
    
    /**
     * @brief Priskyrimo operatorius
     * @param other Kitas Zmogus objektas
     * @return Nuoroda i si objekta
     */
    Zmogus& operator=(const Zmogus& other);
    
    /**
     * @brief Virtualus destruktorius
     */
    virtual ~Zmogus();

    /**
     * @brief Grynoji virtuali funkcija duomenu isvedimui
     * 
     * Si funkcija privalo buti implementuota isvestinese klasese.
     */
    virtual void isvesti() const = 0;

    /**
     * @brief Gauti varda
     * @return Zmogaus vardas
     */
    string getVardas() const { return vardas_; }
    
    /**
     * @brief Gauti pavarde
     * @return Zmogaus pavarde
     */
    string getPavarde() const { return pavarde_; }
    
    /**
     * @brief Nustatyti varda
     * @param v Naujas vardas
     */
    void setVardas(const string& v) { vardas_ = v; }
    
    /**
     * @brief Nustatyti pavarde
     * @param p Nauja pavarde
     */
    void setPavarde(const string& p) { pavarde_ = p; }
};

#endif