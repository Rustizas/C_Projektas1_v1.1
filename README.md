# Studentų Pažymių Sistema v2.0

## Aprašymas
Galutinė objektinio programavimo sistema studentų pažymių tvarkymui su pilna dokumentacija, unit testais ir abstrakcijomis.

### Kompiliavimas

**Tiesioginis kompiliavimas:**
```bash
g++ -std=c++17 -o studentai main.cpp funkcijos.cpp zmogus.cpp
```

**Makefile:**
```bash
make
```

### Dokumentacijos generavimas
```bash
doxygen Doxyfile
```

Dokumentacija: `docs/html/index.html`

### Unit testų paleidimas

**Windows:**
```bash
g++ -std=c++17 -isystem tests/googletest/googletest/include -Itests/googletest/googletest -pthread tests/test_zmogus.cpp zmogus.cpp funkcijos.cpp tests/googletest/googletest/src/gtest-all.cc -o test_zmogus.exe

.\test_zmogus.exe

g++ -std=c++17 -isystem tests/googletest/googletest/include -Itests/googletest/googletest -pthread tests/test_studentas.cpp zmogus.cpp funkcijos.cpp tests/googletest/googletest/src/gtest-all.cc -o test_studentas.exe

.\test_studentas.exe
```

**Linux/Mac:**
```bash
make test
```

## Naudojimas
```bash
.\studentai
```

### Meniu:
1. **Įvedimas ranka** - interaktyvus duomenų įvedimas
2. **Skaitymas iš failo** - nuskaityti ir padalinti studentus
3. **Generuoti failus** - sukurti testinių failų (1K-10M įrašų)
4. **Benchmarkai** - našumo testavimas su 3 kartojimais

## v2.0 Naujienos

### 1. Doxygen Dokumentacija

Pilna HTML dokumentacija visiems klasių metodams ir funkcijoms.

**Dokumentuotos klasės:**
- `Zmogus` - abstrakti bazinė klasė
- `Studentas` - išvestinė klasė su paveldėjimu
- Visos utility funkcijos

**Peržiūrėti:**
```bash
start docs/html/index.html  # Windows
```

### 2. Unit Testai (Google Test)

**Zmogus klasė:**
-  Abstraktumas (negalima instancijuoti)
-  Virtual destruktorius
-  Studentas paveldėjimas

**Studentas klasė:**
-  Default konstruktorius
-  Parametrizuotas konstruktorius
-  Copy konstruktorius
-  Assignment operatorius
-  Namų darbų pridėjimas
-  Vidurkio skaičiavimas 
-  Palyginimo operatoriai 

**Testavimo rezultatai:**
```
[==========] Running 4 tests from 1 test suite (ZmogusTest)
[  PASSED  ] 4 tests

[==========] Running 8 tests from 1 test suite (StudentasTest)
[  PASSED  ] 8 tests
```

## Versijų istorija

**v2.0** - Doxygen dokumentacija + Google Test unit testai  
**v1.5** - Abstrakti Zmogus bazinė klasė + inheritance  
**v1.2** - Input/output operatoriai (>>, <<) + palyginimo operatoriai  
**v1.1** - Struct → Class + Rule of Three  
**v1.0** - 3 strategijos + vector/list palaikymas  

## Dalijimo strategijos

**Strategija 1** - Kopijavimas (3x atmintis, greitas)  
**Strategija 2** - Trynimas (2x atmintis, greitas su list, lėtas su vector)  
**Strategija 3** - STL Partition (greičiausias su vector)  

## Performance (Vector + Strategija 3)

| Dydis | Skaitymas | Dalijimas | Rašymas V | Rašymas K | Viso    |
|-------|-----------|-----------|-----------|-----------|---------|
| 1K    | 0.003 s   | 0.001 s   | 0.002 s   | 0.003 s   | 0.009 s |
| 10K   | 0.027 s   | 0.006 s   | 0.016 s   | 0.022 s   | 0.073 s |
| 100K  | 0.316 s   | 0.075 s   | 0.164 s   | 0.242 s   | 0.807 s |
| 1M    | 2.917 s   | 0.710 s   | 1.740 s   | 2.547 s   | 8.046 s |

## Reikalavimai

- C++17
- g++ kompiliatorius
- Doxygen (dokumentacijai)
- Google Test (unit testams)