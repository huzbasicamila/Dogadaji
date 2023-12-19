//
// Created by Amila Huzbasic on 12/19/2023.
//

#include "Gost.h"
#include <iostream>
#include <string.h>

Gost::Gost() {
    strcpy(this->ime, "Ime");
    strcpy(this->prezime, "Prezime");
    strcpy(this->email, "Email");
    this->dolaziSam=true;
}

void Gost::setIme() {
    std::cout<<"Unesite ime: "<< std::endl;
    std::cin.getline(this->ime, 20);
}

void Gost::setPrezime() {
    std::cout<<"Unesite prezime: "<< std::endl;
    std::cin.getline(this->prezime, 30);
}

void Gost::setEmail() {
    std::cout<<"Unesite email: "<< std::endl;
    std::cin.getline(this->email, 50);
}

void Gost::kakoDolazi() {
    int broj;
    std::cout<<"Kako gost dolazi? Sam ili +1?\n";
    std::cin>>broj;
    this->dolaziSam=broj ==0;
}
char* Gost::getIme() {
    return this->ime;
}

char* Gost::getPrezime() {
    return this->prezime;
}

char* Gost::getEmail() {
    return this->email;
}

bool Gost::getDolaziSam() {
    return this->dolaziSam;
}

std::string Gost::daLiDolaziSam() {
    if(this->dolaziSam) {
        return "Da";
    }
        return "+1";
}

void Gost::unesiGosta() {
    std::cout<<"Unos gosta: \n";
    this->setIme();
    this->setPrezime();
    this->kakoDolazi();
}

bool Gost::pretraziGosta(char *upit) {
    return _strcmpi(this->ime, upit) == 0
    || _strcmpi(this->prezime, upit) ==0
    || _strcmpi(this->email, upit) ==0;
}

bool Gost::pretraziPoEmailu(char *email) {
    return _strcmpi(this->email, email) ==0;
}