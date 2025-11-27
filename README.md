# Studentų Pažymių Sistema v1.1

## Pakeitimai v1.1 versijoje

- Struct konvertuota į class su private nariais
- Realizuoti konstruktoriai
- Realizuotas destruktorius ir assignment operatorius
- Pridėti getter/setter metodai

## Įdiegimas
```bash
g++ -std=c++17 -O2 -o studentai main.cpp funkcijos.cpp
.\studentai
```

Arba su Makefile:
```bash
make O2
```

## Testavimo rezultatai

### Struct vs Class palyginimas (Vector, Strategija 3, -O3)

| Versija | 100K  (s)      | 1M       (s) |
|---------|----------------|--------------|
| Struct  | 0.526322       | 4.871349     |
| Class   | 0.577405       | 5.485323     |
| Skirtumas | +9.7%        | +12.6%       |

**Išvados:** Class versija ~10-13% lėtesnė dėl getter/setter, bet geresnė kodo kokybė ir saugumas.

### Optimizavimo flag'ų palyginimas (Class versija)

| Flag | 100K  (s)      | 1M  (s) |
|------|----------------|--------------|
| -O1  | 0.560891       | 5.494749     |
| -O2  | 0.587369       | 5.475452     |
| -O3  | 0.622032       | 5.619774     |

**Išvados:** O2 duoda geriausią rezultatą. O3 ne visada greičiausias.
