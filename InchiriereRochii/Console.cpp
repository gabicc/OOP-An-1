//
// Created by gabi on 5/12/26.
//

#include "Console.h"
#include <iostream>
#include <vector>
#include "Rochie.h"
#include "Repo.h"
#include "Service.h"
#include <string.h>
#include <fstream>

//ifstream fin("Rochii.txt");

using namespace std;

void print_menu() {
    cout << "1. Adauga rochie\n";
    cout << "2. Sterge rochie\n";
    cout << "3. Modifica rochie\n";
    cout << "4. Afiseaza lista rochii\n";
    cout << "0. Exit\n";
}

void add_rochie_consola(Service& srv) {
    int cod;
    string denumire;
    double marime;
    double pret;
    bool disponibil;
    cout << "Introdu cod: ";
    cin >> cod;
    cout << "Introdu denumire: ";
    cin >> ws;
    getline(cin, denumire);
    cout << "Introdu marime: ";
    cin >> marime;
    cout << "Introdu pret: ";
    cin >> pret;
    cout << "Disponibila (1/0): ";
    cin >> disponibil;
    Rochie r(cod, denumire, marime, pret, disponibil);
    srv.addRochie_srv(r);
}

void remove_rochie_consola(Service& srv) {
    int cod;
    cout << "Introdu codul rochiei de sters: ";
    cin >> cod;
    srv.removeRochie_srv(cod);
}

void update_rochie_consola(Service& srv) {
    int cod;
    string denumire;
    double marime;
    double pret;
    bool disponibil;
    cout << "Introdu codul rochiei de modificat: ";
    cin >> cod;
    cout << "Introdu noua denumire: ";
    cin >> denumire;
    cout << "Introdu noua marime: ";
    cin >> marime;
    cout << "Introdu noul pret: ";
    cin >> pret;
    cout << "Disponibila (1/0): ";
    cin >> disponibil;
    Rochie r(cod, denumire, marime, pret, disponibil);
    srv.updateRochie_srv(cod, r);
}

void afis_rochii_consola(Service& srv) {
    srv.afisRochii_srv();
}

// void run_console() {
//     Service& srv;
//     srv.load_from_file("Rochii.txt");
//     while (true) {
//         int choice;
//         print_menu();
//         cout << "Introdu o optiune: ";
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 add_rochie_consola(srv);
//                 break;
//             case 2:
//                 remove_rochie_consola(srv);
//                 break;
//             case 3:
//                 update_rochie_consola(srv);
//                 break;
//             case 4:
//                 afis_rochii_consola(srv);
//                 break;
//             case 0:
//                 return;
//             default:
//                 cout << "Optiune invalida. Incearca din nou\n";
//         }
//     }
// }