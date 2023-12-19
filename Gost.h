//
// Created by Amila Huzbasic on 12/19/2023.
//

#ifndef DOGADAJI_GOST_H
#define DOGADAJI_GOST_H
#include <string>

class Gost {
private:
    char ime[20], prezime[30], email[50];
    bool dolaziSam;

public:
    Gost();
    void setIme();
    void setPrezime();
    void setEmail();
    void kakoDolazi();
    char* getIme();
    char* getPrezime();
    char* getEmail();
    bool getDolaziSam();
    std::string daLiDolaziSam(); // vraća Da ili +1
    void unesiGosta();
    bool pretraziGosta(char* upit);
    bool pretraziPoEmailu(char* email);
    ~Gost() {};

};

#endif //DOGADAJI_GOST_H
