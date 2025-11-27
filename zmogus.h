#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
using namespace std;

class Zmogus
{
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus();
    Zmogus(const string& v, const string& p);
    Zmogus(const Zmogus& other);
    Zmogus& operator=(const Zmogus& other);
    virtual ~Zmogus();

    virtual void isvesti() const = 0;

    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }
    void setVardas(const string& v) { vardas_ = v; }
    void setPavarde(const string& p) { pavarde_ = p; }
};

#endif