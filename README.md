# Studentų Pažymių Sistema v1.5

## v1.5 Pakeitimai - Abstrakti bazinė klasė


### Zmogus klasė (Abstract Base Class)

**Private nariai:**
- `string vardas_`
- `string pavarde_`

**Public metodai:**
- Konstruktoriai (default, parametrized, copy)
- Assignment operatorius
- Virtual destruktorius
- Getter/Setter metodai

### Studentas klasė (Derived Class)

Studentas paveldi iš Zmogus ir prideda:
- Studento specifinius duomenis (pažymiai, egzaminas)
- Implementuoja `isvesti()` funkciją
- Išlaiko visą v1.2 funkcionalumą

### v1.5 vs v1.2 palyginimas

| Aspektas | v1.2 | v1.5 |
|----------|------|------|
| Klasių skaičius | 1 (Studentas) | 2 (Zmogus + Studentas) |
| Inheritance | Ne | Taip (Studentas : public Zmogus) |
| Abstrakti klasė | Ne | Taip (Zmogus) |
| Pure virtual | Ne | Taip (isvesti()) |
| Funkcionalumas | Pilnas | Pilnas (išlaikytas) |

### Kompiliavimas
```bash
g++ -std=c++17 -o studentai main.cpp funkcijos.cpp zmogus.cpp
```

Arba su Makefile:
```bash
make
```

## Testavimo rezultatai

Programa išlaiko visą v1.2 funkcionalumą. Testavimo rezultatai identiški:

| Dydis | Skaitymas (s) | Dalijimas (s) | Rašymas V (s) | Rašymas K (s) | Viso (s) |
|-------|---------------|---------------|---------------|---------------|----------|
| 1K    | 0.002801      | 0.000632      | 0.001917      | 0.002786      | 0.008714 |
| 10K   | 0.026624      | 0.006483      | 0.016268      | 0.022220      | 0.073095 |
| 100K  | 0.315623      | 0.075010      | 0.164044      | 0.241606      | 0.807340 |
| 1M    | 2.916802      | 0.710193      | 1.740338      | 2.547489      | 8.045763 |

## Versijos

**v1.5** - Abstrakti Zmogus bazinė klasė, inheritance hierarchy  
**v1.2** - Įvesties/išvesties operatoriai, palyginimo operatoriai  
**v1.1** - Struct → Class konversija, Rule of Three  
**v1.0** - 3 dalijimo strategijos, vector/list palaikymas

## Sistemos reikalavimai
- C++17 arba naujesnė versija
- g++ kompiliatorius