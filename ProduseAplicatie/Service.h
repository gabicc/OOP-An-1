//
// Created by gabi on 6/20/26.
//

#ifndef PRODUSEAPLICATIE_SERVICE_H
#define PRODUSEAPLICATIE_SERVICE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "Produs.h"
#include "Repo.h"
#include "Validator.h"

using namespace std;

class Service {
private:
    Repo repo;
    Validator val;
public:
    Service(Repo repo, Validator val): repo{repo}, val{val} {};
    vector<Produs> get_all_srv() {
        // post: se returneaza lista de produyse
        vector<Produs> produse = repo.get_all_repo();
        for (int i = 0; i< produse.size() - 1; i++) {
            for (int j = i + 1; j < produse.size(); j++) {
                if (produse[i].getPret() > produse[j].getPret()) {
                    Produs aux = produse[i];
                    produse[i] = produse[j];
                    produse[j] = aux;
                }
            }
        }
        return produse;
    }
    void addProdus_srv(int id, string nume, string tip, double pret) {
        // pre: id - int, nume, tip - string, pret - double
        // post: se face un produs cu id nume tip si pret dat si
        // dupa ce se valideaza, se adauga in lista de produse
        Produs p(id, nume, tip, pret);
        try {
            val.validateProdus(p);
            repo.addProdus(p);
        } catch (RepoException& re) {
            throw RepoException(re.what());
        } catch (ValidatorException& ve) {
            throw ValidatorException(ve.what());
        }
    }
    void saveToFile_srv() {
        repo.saveToFile();
    }
};


#endif //PRODUSEAPLICATIE_SERVICE_H
