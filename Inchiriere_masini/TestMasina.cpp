//
// Created by gabi on 3/30/26.
//

#include "TestMasina.h"
#include "Masina.h"
#include "Service.h"
#include "RepoMasini.h"
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

void test_masina() {
    string nrInmatriculare = "CJ19DGC", producator = "Hyundai", model = "Tucson", tip = "Diesel";
    Masina* m = new Masina(nrInmatriculare, producator, model, tip);
    //cout << nrInmatriculare << '\n';
    delete m;
}

void afis_masina(Masina& m) {
    const string& nrInm = m.get_nr_inmatriculare();
    //nrInm= "cucu";
    //cout << nrInm<<endl;
    //cout << m.get_nrInmatriculare();
}

void test_afis() {
    Masina m("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    afis_masina(m);
}


void test_service_adaugare_single() {
    RepoMasini repo;
    Service srv(&repo);
    Masina m("CJ19DGC", "Hyundai", "Tucson", "Diesel");

    srv.adaugaMasina_srv(m);
    assert(srv.nr_masini() == 1);

}


void test_service_adaugare_multiple() {
    RepoMasini repo;
    Service srv(&repo);
    Masina m1("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    Masina m2("CJ20XYZ", "Toyota", "Corolla", "Hybrid");

    srv.adaugaMasina_srv(m1);
    try {
        srv.adaugaMasina_srv(m2);
    } catch (ValidationException& ex) {
        cout << ex.what() << endl;
    }
    assert(srv.nr_masini() == 2);

}


void test_service_sterge_existing() {
    RepoMasini repo;
    Service srv(&repo);
    Masina m1("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    Masina m2("CJ20XYZ", "Toyota", "Corolla", "Hybrid");

    srv.adaugaMasina_srv(m1);
    srv.adaugaMasina_srv(m2);

    assert(srv.nr_masini() == 2);
    srv.stergeMasina_srv("CJ19DGC");
    assert(srv.nr_masini() == 1);
}


void test_service_sterge_nonexistent() {
    RepoMasini repo;
    Service srv(&repo);
    Masina m("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    srv.adaugaMasina_srv(m);

    try {
        srv.stergeMasina_srv("INVALID123");
    } catch (ValidationException& ex) {
        cout << ex.what() << endl;
    }

    assert(srv.nr_masini() == 1);
}


void test_service_modifica_existing() {
    RepoMasini repo;
    Service srv(&repo);
    Masina m("CJ19DGC", "Hyundai", "Tucson", "Diesel");

    srv.adaugaMasina_srv(m);
    srv.modificaMasina_srv("CJ19DGC", "CJ21NEW");


}


void test_service_modifica_nonexistent() {
    RepoMasini repo;
    Service srv(&repo);

    try {
        srv.modificaMasina_srv("INVALID", "NEWPLATE");
    } catch (ValidationException& ex) {
        cout << ex.what() << endl;
    }


}

void test_service_filtrare_dupa_producator() {
    RepoMasini repo;
    Service srv(&repo);
    srv.adaugaMasina_srv(Masina("CJ10AAA", "Audi", "A4", "Sedan"));
    srv.adaugaMasina_srv(Masina("CJ11BBB", "BMW", "X3", "SUV"));
    srv.adaugaMasina_srv(Masina("CJ12CCC", "Audi", "Q7", "SUV"));

    const vector<Masina> rezultat = srv.filtreaza_dupa_producator_srv("Audi");
    assert(rezultat.size() == 2);
    assert(rezultat[0].get_producator() == "Audi");
    assert(rezultat[1].get_producator() == "Audi");
}

void test_service_filtrare_dupa_tip() {
    RepoMasini repo;
    Service srv(&repo);
    srv.adaugaMasina_srv(Masina("CJ10AAA", "Audi", "A4", "Sedan"));
    srv.adaugaMasina_srv(Masina("CJ11BBB", "BMW", "X3", "SUV"));
    srv.adaugaMasina_srv(Masina("CJ12CCC", "Audi", "Q7", "SUV"));

    const vector<Masina> rezultat = srv.filtreaza_dupa_tip_srv("SUV");
    assert(rezultat.size() == 2);
    assert(rezultat[0].get_tip() == "SUV");
    assert(rezultat[1].get_tip() == "SUV");
}

void test_service_sortare_dupa_nr_inmatriculare() {
    RepoMasini repo;
    Service srv(&repo);
    srv.adaugaMasina_srv(Masina("CJ30ZZZ", "VW", "Golf", "Hatchback"));
    srv.adaugaMasina_srv(Masina("CJ10AAA", "Audi", "A4", "Sedan"));
    srv.adaugaMasina_srv(Masina("CJ20MMM", "BMW", "X3", "SUV"));

    const vector<Masina> rezultat = srv.sorteaza_dupa_nr_inmatriculare_srv();
    assert(rezultat.size() == 3);
    assert(rezultat[0].get_nr_inmatriculare() == "CJ10AAA");
    assert(rezultat[1].get_nr_inmatriculare() == "CJ20MMM");
    assert(rezultat[2].get_nr_inmatriculare() == "CJ30ZZZ");
}

void test_service_sortare_dupa_tip() {
    RepoMasini repo;
    Service srv(&repo);
    srv.adaugaMasina_srv(Masina("CJ30ZZZ", "VW", "Golf", "SUV"));
    srv.adaugaMasina_srv(Masina("CJ10AAA", "Audi", "A4", "Sedan"));
    srv.adaugaMasina_srv(Masina("CJ20MMM", "BMW", "X3", "SUV"));

    const vector<Masina> rezultat = srv.sorteaza_dupa_tip_srv();
    assert(rezultat.size() == 3);
    assert(rezultat[0].get_tip() == "SUV");
    assert(rezultat[0].get_nr_inmatriculare() == "CJ20MMM");
    assert(rezultat[1].get_tip() == "SUV");
    assert(rezultat[1].get_nr_inmatriculare() == "CJ30ZZZ");
    assert(rezultat[2].get_tip() == "Sedan");
}

void test_service_sortare_dupa_producator_model() {
    RepoMasini repo;
    Service srv(&repo);
    srv.adaugaMasina_srv(Masina("CJ30ZZZ", "BMW", "X5", "SUV"));
    srv.adaugaMasina_srv(Masina("CJ10AAA", "Audi", "A4", "Sedan"));
    srv.adaugaMasina_srv(Masina("CJ20MMM", "BMW", "X3", "SUV"));

    const vector<Masina> rezultat = srv.sorteaza_dupa_producator_model_srv();
    assert(rezultat.size() == 3);
    assert(rezultat[0].get_producator() == "Audi");
    assert(rezultat[0].get_model() == "A4");
    assert(rezultat[1].get_producator() == "BMW");
    assert(rezultat[1].get_model() == "X3");
    assert(rezultat[2].get_producator() == "BMW");
    assert(rezultat[2].get_model() == "X5");
}

void test_constructor_copiere() {
    Masina a("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    Masina b(a);
    assert(a.get_nr_inmatriculare() == b.get_nr_inmatriculare());
}

void test_operator_copiere() {
    Masina m("CJ19DGC", "Hyundai", "Tucson", "Diesel");
    Masina n("CJ20XYZ", "Toyota", "Corolla", "Hybrid");
    n = m;
    assert(n.get_nr_inmatriculare() == m.get_nr_inmatriculare());
    assert(n.get_nr_inmatriculare() == "CJ19DGC");
    n = "CJ91DGC";
    assert(n.get_nr_inmatriculare() == "CJ91DGC");
}

void test_masina_all() {
    test_masina();
    test_afis();
    test_constructor_copiere();
    test_operator_copiere();
}

void test_masina_serviciu_all() {
    test_service_adaugare_single();
    test_service_adaugare_multiple();
    test_service_sterge_existing();
    test_service_sterge_nonexistent();
    test_service_modifica_existing();
    test_service_modifica_nonexistent();
    test_service_filtrare_dupa_producator();
    test_service_filtrare_dupa_tip();
    test_service_sortare_dupa_nr_inmatriculare();
    test_service_sortare_dupa_tip();
    test_service_sortare_dupa_producator_model();
}