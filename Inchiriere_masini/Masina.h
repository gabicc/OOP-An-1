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
    Masina(const Masina& other);
    ~Masina();
    void change_nrInmatriculare(const string& nrInmatriculare);
    const string& get_nr_inmatriculare() const;
    const string& get_producator() const{
        return producator;
    }
    const string& get_model() const{
        return model;
    }
    const string& get_tip() const{
        return tip;
    }
    void afis();
    Masina& operator=(const Masina& other);
    Masina& operator=(const char* other);
    bool operator==(const Masina& other);
};

#endif //INCHIRIERE_MASINI_MASINA_H
