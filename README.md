# Studentų Pažymių Sistema v1.2

## Aprašymas
Programa skirta studentų pažymių tvarkymui, skaičiavimui ir analizei. Sistema leidžia įvesti duomenis ranka, nuskaityti iš failų, ir atlikti našumo testus su skirtingomis strategijomis.

## Įdiegimas
```bash
g++ -std=c++17 -o studentai main.cpp funkcijos.cpp
```

## Naudojimas
```bash
.\studentai
```

### Meniu opcijos:
1. **Įvedimas ranka** - rankinis studentų duomenų įvedimas
2. **Nuskaitymas iš failo** - vienkartinis failo skaitymas ir dalijimas
3. **Sugeneruoti failus** - sukuria 5 testinių failų (1K, 10K, 100K, 1M, 10M įrašų)
4. **Benchmarkai** - našumo testavimas

## v1.2 Pakeitimai - Operatorių realizacija

### Realizuoti operatoriai:

**Rule of Three (v1.1):**
- Copy konstruktorius
- Assignment operatorius
- Destruktorius

**Nauji operatoriai (v1.2):**

**1. Įvesties operatorius (>>)**
```cpp
istream& operator>>(istream& is, Studentas& s);
```
Naudojimas: failo skaitymas ir rankinis įvedimas
```cpp
cin >> studentas;
fileStream >> studentas;
```

**2. Išvesties operatorius (<<)**
```cpp
ostream& operator<<(ostream& os, const Studentas& s);
```
Naudojimas: duomenų išvedimas į failą arba ekraną
```cpp
cout << studentas;
fileStream << studentas;
```

**3. Palyginimo operatoriai**
```cpp
bool operator<(const Studentas& other) const;   pagal balą
bool operator>(const Studentas& other) const;   pagal balą
bool operator==(const Studentas& other) const;  pagal vardą ir pavardę
```

### Operatorių panaudojimas programoje

#### Įvestis:
- **Rankinė** - `setVardas()`, `setPavarde()`, `addNamuDarbas()`
- **Iš failo** - `>>` operatorius vardui/pavardei nuskaityti
- **Automatinė** - `random` biblioteka + setter metodai

#### Išvestis:
- **Į ekraną** - `cout` su formatuotais skaičiais
- **Į failą** - `<<` operatorius (vargsiukai.txt, kietiakiai.txt)

## Testavimo rezultatai

### Vector + Strategija 3 (STL partition)

| Dydis | Skaitymas (s) | Dalijimas (s) | Rašymas V (s) | Rašymas K (s) | Viso (s) |
|-------|---------------|---------------|---------------|---------------|----------|
| 1K    | 0.002801      | 0.000632      | 0.001917      | 0.002786      | 0.008714 |
| 10K   | 0.026624      | 0.006483      | 0.016268      | 0.022220      | 0.073095 |
| 100K  | 0.315623      | 0.075010      | 0.164044      | 0.241606      | 0.807340 |
| 1M    | 2.916802      | 0.710193      | 1.740338      | 2.547489      | 8.045763 |

### Išvados:
- Class implementacija su operatoriais veikia sklandžiai
- Strategija 3 (STL partition) išlieka greičiausia
- Operatoriai << ir >> supaprastina kodą ir pagerina skaitomumą

## Programos vaizdai

### Pagrindinis meniu
![Menu](menu.png)

### Išvesties failas
![Output](output.png)
