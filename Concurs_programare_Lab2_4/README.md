# Lab 2 - 4 Concurs Programare

Proiect in C care gestioneaza participanti la un concurs, folosind alocare dinamica si o arhitectura pe straturi (`Entities` -> `Repo` -> `Service`).

## Functionalitati

- Adaugare participant
- Modificare participant existent
- Stergere participant
- Filtrare participanti dupa scor (`scor < prag`)
- Sortare participanti:
  - dupa nume (crescator/descrescator)
  - dupa scor (crescator/descrescator)
- Afisare lista curenta de participanti

Aplicatia ruleaza in consola, pe baza unui meniu interactiv.

## Structura proiectului

```text
.
|-- main.c                      # UI in consola (meniu + citire input)
|-- CMakeLists.txt              # configurare build principal
|-- concurs_lib/
|   |-- Entities.h/.c           # modelul Participant
|   |-- Validator.h/.c          # reguli de validare
|   |-- Repo.h/.c               # repo dinamic (CRUD, filtrare, sortare)
|   |-- Service.h/.c            # logica aplicatiei
|   `-- CMakeLists.txt          # biblioteca statica Concurs123_lib
`-- Google_tests/
	|-- UnitTest_concurs.cpp    # teste unitare
	`-- CMakeLists.txt          # target Google_Tests_run
```

## Model de date

Participantul este definit in `concurs_lib/Entities.h`:

```c
struct Participant {
	char surname[20];
	char first_name[20];
	int score;
};
```

Reguli de validare (`concurs_lib/Validator.c`):
- `surname` nenul si nevid
- `first_name` nenul si nevid
- `score >= 0`

## Arhitectura pe straturi

- `Entities` - defineste structurile de date
- `Validator` - valideaza un participant
- `Repo` - gestioneaza vectorul dinamic de participanti
  - `init_repo`, `destroy_repo`
  - `add_participant`, `change_participant`, `delete_participant`
  - `filter_by_score`, `sort_by_name`, `sort_by_score`
- `Service` - coordoneaza operatiile aplicatiei
  - construieste participantul din date brute
  - valideaza datele
  - delega catre `Repo`
- `main.c` - interfata utilizator (meniu + apeluri in `Service`)

## Cum rulezi proiectul

### 1) Build

```bash
cmake -S . -B build
cmake --build build
```

### 2) Rulare aplicatie

```bash
./build/gabi
```

## Meniu aplicatie

La rulare, aplicatia afiseaza:

- `1` - Adauga participant
- `2` - Schimbare participant
- `3` - Sterge participant
- `4` - Afisare dupa proprietate (filtrare dupa scor)
- `5` - Sortare crescatoare/descrescatoare dupa nume/scor
- `6` - Afiseaza participanti
- `0` - Exit

## Testare (GoogleTest)

Sunt incluse teste unitare in `Google_tests/UnitTest_concurs.cpp` pentru:
- validare participant
- adaugare
- modificare
- stergere

Build-ul principal include subdirectorul `Google_tests`.

Pentru a rula executabilul de teste dupa build:

```bash
./build/Google_tests/Google_Tests_run
```

## Observatii

- Repository-ul foloseste redimensionare dinamica (dublarea capacitatii cand este necesar).
- Sortarea este implementata in repo pentru nume si scor.
- Aplicatia este orientata pe exercitii de laborator: structura modulara, alocare dinamica, separarea responsabilitatilor.
