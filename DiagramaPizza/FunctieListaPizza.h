//
// Created by gabi on 6/20/26.
//

#ifndef DIAGRAMAPIZZA_FUNCTIELISTAPIZZA_H
#define DIAGRAMAPIZZA_FUNCTIELISTAPIZZA_H

#endif //DIAGRAMAPIZZA_FUNCTIELISTAPIZZA_H

#include "Pizza.h"
#include "BasicPizza.h"
#include "PizzaCuCiuperci.h"
#include "PizzaCuPeperoni.h"
#include <vector>

vector<Pizza*> creeazaListaPizza() {
    Pizza* pizza_salami_ciuperci = new PizzaCuCiuperci(new BasicPizza("Salami", 15));
    Pizza* pizza_salami = new BasicPizza("Salami", 15);
    Pizza* pizza_diavola_peperoni_ciuperci = new PizzaCuPeperoni(new PizzaCuCiuperci(new BasicPizza("Diavola", 20)));
    vector<Pizza*> listaPizza;
    listaPizza.push_back(pizza_salami_ciuperci);
    listaPizza.push_back(pizza_salami);
    listaPizza.push_back(pizza_diavola_peperoni_ciuperci);
    return listaPizza;
}