//
// Created by gabi on 3/30/26.
//

#include "TestMasina.h"
#include "Masina.h"
#include <iostream>


void test_masina() {
    string nrInmatriculare = "CJ19DGC", producator = "Hyundai", model = "Tucson", tip = "Diesel";
    Masina* m = new Masina(nrInmatriculare, producator, model, tip);
    cout << nrInmatriculare << '\n';
    delete m;
}

void afis_masina(Masina& m) {
    const string& nrInm = m.get_nrInmatriculare();
    //nrInm= "cucu";
    cout << nrInm<<endl;
    cout << m.get_nrInmatriculare();
}

void test_afis() {
    Masina m("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    afis_masina(m);
}

