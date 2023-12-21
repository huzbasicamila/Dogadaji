//
// Created by Amila Huzbasic on 12/19/2023.
//

#ifndef DOGADAJI_DOGADAJI_H
#define DOGADAJI_DOGADAJI_H
#include "Datum.h"
#include "Gost.h"
#include <vector>
#include <string>

class Dogadaj {
private:
    char naziv[100], grad[50], opis[1000];
    unsigned int maxBrojGostiju;
    Datum datum;
    vector<Gost> gosti;

public:
    Dogadaj();
    void setNaziv();
    void setOpis();
    void setGrad();
    void setMaxBrojGostiju();
    void setDatum();
    void dodajGosta();
    char* getNaziv();
    char* getOpis();
    char* getGrad();
    unsigned int getMaxBrojGostiju();
    Datum getDatum();
    string danOdrzavanja();
    std::vector<Gost>& dajGoste();
    void nadjiGoste();
    void unesiDogadjaj();
    void ispisDogadjaj();
    void dodajGoste();
    bool daLiImaGostiju();
    unsigned int dajTrenutniBrojGostiju();
    ~Dogadaj() = default;
};
#endif //DOGADAJI_DOGADAJI_H
