//
// Created by gabi on 3/30/26.
//

#include "Console.h"
#include <iostream>
#include "Service.h"
using namespace std;

void print_menu() {
    cout << "1. Adauga masina\n";
    cout << "2. Sterge masina\n";
    cout << "3. Cauta masina\n";
    cout << "4. Afiseaza toate masinile\n";
    cout << "0. Iesire\n";
}
void adauga_masina_consola(Service srv) {
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
    srv.adaugaMasina_srv(m);

}

void sterge_masina_consola(Service srv) {
    string nrInmatriculare;
    cout << "Introud nrInmatriculare de sters: ";
    cin >> nrInmatriculare;
    srv.stergeMasina_srv(nrInmatriculare);
}
void modifica_masina_consola(Service srv) {
    string nrInmatriculare_vechi;
    string nrInmatriculare_nou;
    cout << "Introdu nrInmatriculare vechi: ";
    cin >> nrInmatriculare_vechi;
    cout << "Introdu nrInmatriculare nou: ";
    cin >> nrInmatriculare_nou;
    srv.modificaMasina_srv(nrInmatriculare_vechi, nrInmatriculare_nou);
}
void afis_masini_consola(Service srv) {
    srv.afis_Masini_srv();
}

void run_console() {
    RepoMasini repo;
    Service srv(repo);
    while (true) {
        int choice;
        print_menu();
        cout << "Introdu o optiine: ";
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
            case 0:
                //cout << "La revedere!\n";
                return;
            default:
                cout << "Optiune invalida. Incearca din nou.\n";
        }
    }
}
