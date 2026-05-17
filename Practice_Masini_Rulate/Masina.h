//
// Created by gabi on 5/14/26.
//

#ifndef PRACTICE_MASINI_RULATE_MASINA_H
#define PRACTICE_MASINI_RULATE_MASINA_H
#include <ratio>
#include <string.h>
#include <iostream>

using namespace std;

class Masina {
private:
        string nrMatricol;
        string model;
        string culoare;
        double kilometri;
public:
        Masina(char* nrMatricol, char* model, char* culoare, double kilometri): nrMatricol{nrMatricol}, model{model}, culoare{culoare}, kilometri{kilometri} {};
        ~Masina();
        string getNrMatricol() const {
                return this->nrMatricol;
        }
        string getModel() const {
                return this->model;
        }
        string getCuloare() const {
                return this->culoare;
        }
        double getKm() const {
                return this->kilometri;
        }
        void operator=(const Masina& m) {
                this->nrMatricol = m.getNrMatricol();
                this->model = m.getModel();
                this->culoare = m.getCuloare();
                this->kilometri = m.getKm();
        }
};


#endif //PRACTICE_MASINI_RULATE_MASINA_H
