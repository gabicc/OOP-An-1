//
// Created by gabi on 3/30/26.
//

#include "Console.h"
#include <iostream>
#include <vector>
#include "Service.h"
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_menu() {
    cout << "1. Adauga masina\n";
    cout << "2. Sterge masina\n";
    cout << "3. Modifica masina\n";
    cout << "4. Afiseaza toate masinile\n";
    cout << "5. Filtreaza dupa producator\n";
    cout << "6. Filtreaza dupa tip\n";
    cout << "7. Sorteaza dupa nrInmatriculare\n";
    cout << "8. Sorteaza dupa tip\n";
    cout << "9. Sorteaza dupa producator + model\n";
    cout << "10. Golire masini\n";
    cout << "11. Genereaza lista cu masini random\n";
    cout << "0. Iesire\n";
}

void afiseaza_lista_masini(const vector<Masina>& masini) {
    for (const auto& masina : masini) {
        masina.afis();
    }
}
void adauga_masina_consola(Service& srv) {
    string nrInmatric, producator, model, tip;
    cout << "Introdu nrInmatriculare: ";
    cin >> nrInmatric;
    cout << "Introdu producator: ";
    cin >> producator;
    cout << "Introdu model: ";
    cin >> model;
    cout << "Introdu tip: ";
    cin >> tip;
    Masina m(nrInmatric, producator, model, tip);
    try {
        srv.adaugaMasina_srv(m);
    } catch (ValidationException& ex) {
        cout << ex.what() << endl;
    }

}

/*
char random_letter() {
    srand(time(0));
    char ch = 'A' + rand() % 26;
    return ch;
}*/

char random_letter(mt19937& mt) {
    static uniform_int_distribution<int> distLetter(0, 25);
    return static_cast<char>('A' + distLetter(mt));
}

Masina genereaza_masina(int index) {
    mt19937 mt{ random_device{}()};
    uniform_int_distribution<> dist(1, 100);
    int rndNr = dist(mt);
    char a = random_letter(mt), b = random_letter(mt), c = random_letter(mt), d = random_letter(mt), e = random_letter(mt);
    string result;
    result += a;
    result += b;
    result += to_string(rndNr);
    result += c;
    result += d;
    result += e;
    string producator;
    for (int i = 0; i < 5; i++) {
        char a = random_letter(mt);
        producator += a;
    }
    string model;
    for (int i = 0; i < 5; i++) {
        char a = random_letter(mt);
        model += a;
    }
    string tip;
    for (int i = 0; i < 5; i++) {
        char a = random_letter(mt);
        tip += a;
    }
    return Masina(result, producator, model, tip);
}

void genereaza_n_masini_random(Service& srv) {
    int n;
    cout << "Introdu numar de masini random de generat: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Masina m = genereaza_masina(i);
        srv.adaugaMasina_srv(m);
    }
}

void sterge_masina_consola(Service& srv) {
    string nrInmatriculare;
    cout << "Introud nrInmatriculare de sters: ";
    cin >> nrInmatriculare;
    try {
        srv.stergeMasina_srv(nrInmatriculare);
    }catch (ValidationException& ex) {
        cout << ex.what() << endl;
    }
}
void modifica_masina_consola(Service& srv) {
    string nrInmatriculare_vechi;
    string nrInmatriculare_nou;
    cout << "Introdu numar Inmatriculare vechi: ";
    cin >> nrInmatriculare_vechi;
    cout << "Introdu numar Inmatriculare nou: ";
    cin >> nrInmatriculare_nou;
    try {
        srv.modificaMasina_srv(nrInmatriculare_vechi, nrInmatriculare_nou);
    }catch (ValidationException& ex) {
        cout << ex.what() << endl;
    }
}
void afis_masini_consola(Service& srv) {
    srv.afis_Masini_srv();
}

void filtreaza_dupa_producator_consola(Service& srv) {
    string producator;
    cout << "Introdu producator: ";
    cin >> producator;
    afiseaza_lista_masini(srv.filtreaza_dupa_producator_srv(producator));
}

void filtreaza_dupa_tip_consola(Service& srv) {
    string tip;
    cout << "Introdu tip: ";
    cin >> tip;
    afiseaza_lista_masini(srv.filtreaza_dupa_tip_srv(tip));
}

void sorteaza_dupa_nr_inmatriculare_consola(Service& srv) {
    afiseaza_lista_masini(srv.sorteaza_dupa_nr_inmatriculare_srv());
}

void sorteaza_dupa_tip_consola(Service& srv) {
    afiseaza_lista_masini(srv.sorteaza_dupa_tip_srv());
}

void sorteaza_dupa_producator_model_consola(Service& srv) {
    afiseaza_lista_masini(srv.sorteaza_dupa_producator_model_srv());
}

void run_console() {
    RepoMasini repo;
    Service srv(repo);
    while (true) {
        int choice;
        print_menu();
        cout << "Introdu o optiune: ";
        cin >> choice;
        switch (choice) {
            case 1:
                adauga_masina_consola(srv);
                break;
            case 2:
                sterge_masina_consola(srv);
                break;
            case 3:
                modifica_masina_consola(srv);
                break;
            case 4:
                afis_masini_consola(srv);
                break;
            case 5:
                filtreaza_dupa_producator_consola(srv);
                break;
            case 6:
                filtreaza_dupa_tip_consola(srv);
                break;
            case 7:
                sorteaza_dupa_nr_inmatriculare_consola(srv);
                break;
            case 8:
                sorteaza_dupa_tip_consola(srv);
                break;
            case 9:
                sorteaza_dupa_producator_model_consola(srv);
                break;
            case 10:
                srv.golire_srv();
                break;
            case 11:
                genereaza_n_masini_random(srv);
                break;
            case 0:
                //cout << "La revedere!\n";
                return;
            default:
                cout << "Optiune invalida. Incearca din nou.\n";
        }
    }
}
