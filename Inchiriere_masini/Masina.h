#ifndef INCHIRIERE_MASINI_MASINA_H
#define INCHIRIERE_MASINI_MASINA_H

#include <string>

using namespace std;



class Masina {
private:
    string nrInmatriculare;
    string producator;
    string model;
    string tip;
public:
    Masina(const string& nrInmatriculare, const string& producator, const string& model, const string& tip);
    ~Masina();
    void change_nrInmatriculare(const string& nrInmatriculare);
    const string& get_nrInmatriculare();
    const string& get_producator() {
        return producator;
    }
    const string& get_model() {
        return model;
    }
    const string& get_tip() {
        return tip;
    }
    void afis();

};

#endif //INCHIRIERE_MASINI_MASINA_H
