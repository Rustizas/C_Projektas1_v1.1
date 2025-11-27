#include "zmogus.h"

Zmogus::Zmogus() : vardas_(""), pavarde_("") {}

Zmogus::Zmogus(const string& v, const string& p) : vardas_(v), pavarde_(p) {}

Zmogus::Zmogus(const Zmogus& other) : vardas_(other.vardas_), pavarde_(other.pavarde_) {}

Zmogus& Zmogus::operator=(const Zmogus& other)
{
    if (this != &other)
    {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
    }
    return *this;
}

Zmogus::~Zmogus() {}