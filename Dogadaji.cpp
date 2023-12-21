//
// Created by Amila Huzbasic on 12/19/2023.
//
#include "Dogadaji.h"
#include "Gost.h"
#include "Datum.h"

#include <memory>
#include <iostream>
#include <string.h>

Dogadaj::Dogadaj() {
    strcpy(this->naziv, "Naziv");
    strcpy(this->opis, "Opis");
    strcpy(this->grad, "Grad");
    this->maxBrojGostiju=100;
}

void Dogadaj::setNaziv() {
    std::cout<<"Unesite naziv dogadaja: \n";
    std::cin.getline(this->naziv, 10);
}

void Dogadaj::setOpis() {
    std::cout<<"Unesite opis dogadaja: \n";
    std::cin.getline(this->opis, 100);
}

void Dogadaj::setGrad() {
    std::cout<<"Unesite grad: \n";
    std::cin.getline(this->grad, 50);
}

void Dogadaj::setMaxBrojGostiju() {
    std::cout<<"Unesite max broj gostiju: \n";
    std::cin>>maxBrojGostiju;
}

void Dogadaj::setDatum() {
    std::cout<<"Unesite datum dogadaja: \n";
    this->datum.postaviDatum();
}

void Dogadaj::dodajGosta() {
    if(this->dajTrenutniBrojGostiju() >= this->getMaxBrojGostiju()) {
        std::cout<<"Nema dovoljno mjesta za sve goste!\n";
        return;
    }

    std::cout<<"Unos gosta: \n";
    std::shared_ptr<Gost> gost= std::make_shared<Gost>();
    gost->setEmail();

    bool gostPostoji =false;
    for (int i=0; i<this->dajGoste().size(); i++) {
        if(this->gosti[i].pretraziPoEmailu(gost->getEmail())) {
            gostPostoji=true;
            break;
        }
    }

    if(gostPostoji) {
        std::cout<<"Gost sa " << gost->getEmail() << "vec postoji \n";
        this->dodajGosta();
    }
    else {
        gost->unesiGosta();
        this->dajGoste().push_back(*gost);
    }

}

char* Dogadaj::getNaziv() {
    return this->naziv;
}

char* Dogadaj::getOpis() {
    return this->opis;
}

char* Dogadaj::getGrad() {
    return this->grad;
}

unsigned int Dogadaj::getMaxBrojGostiju() {
    return this->maxBrojGostiju;
}

Datum Dogadaj::getDatum() {
    return this->datum;
}

string Dogadaj::danOdrzavanja() {
    return this->getDatum().getDatum();
}

std::vector<Gost>& Dogadaj::dajGoste() {
    return this->gosti;
}

void Dogadaj::nadjiGoste() {
    if(this->daLiImaGostiju() == false) {
        std::cout<<"Trenutno nema gostiju! \n";
    }
    else {
        char upit[50];
        std::cout<<"Unesite ime, prezime ili email za pretragu: \n";
        std::cin.getline(upit, 50);
        std::shared_ptr<Dogadaj> dogadaj = std::make_shared<Dogadaj>();

        for(int i=0; this->dajGoste().size(); i++) {
            if(this->gosti[i].pretraziGosta(upit)) {
                dogadaj->dajGoste().push_back(this->dajGoste()[i]);

            }
        }
        if(dogadaj->daLiImaGostiju()) {
            dogadaj->ispisDogadjaj();
        }
        else {
            std::cout<< "Nema gosta sa navedenim upitom!";
        }
    }
}

void Dogadaj::unesiDogadjaj() {
    std::cout << "Unos dogadjaj" << std::endl;
    this->setNaziv();
    this->setOpis();
    this->setGrad();
    this->setMaxBrojGostiju();
    this->setDatum();
}

void Dogadaj::ispisDogadjaj() {
    std::cout << "Informacije o dogadjaju" << std::endl;
    std::cout << "Naziv: " << this->getNaziv() << std::endl;
    std::cout << "Opis: " << this->getOpis() << std::endl;
    std::cout << "Grad: " << this->getGrad() << std::endl;
    std::cout << "Maskimalan broj gostiju: " << this->getMaxBrojGostiju() << std::endl;
    if (this->daLiImaGostiju() == false) {
        std::cout << "Trenutno niko ne ide na ovaj dogadjaj." << std::endl;
    } else {
        std::shared_ptr<Gost> gost = std::make_shared<Gost>();
        std::cout << "GOSTI" << std::endl;
        std::cout << "R. broj\tIme\t\tPrezime\t\tEmail\t\tDolazi sam\n";
        for (int i = 0; i < this->dajGoste().size(); i++) {
            *gost = this->dajGoste()[i];
            std::cout << i + 1 << "\t";
            std::cout << gost->getIme() << "\t\t";
            std::cout << gost->getPrezime() << "\t\t";
            std::cout << gost->getEmail() << "\t\t";
            std::cout << gost->daLiDolaziSam() << "\n";
        }
    }
}

void Dogadaj::dodajGoste() {
    std::cout<<"Dodavanje gostiju. \n Unesite 0 za izlaz, unesite bilo koji drugi broj za nastavak: \n";
    int broj;
    std::cin>>broj;

    while(broj !=0) {
        this->dodajGosta();
        std::cout<<"Zelite li nastaviti? \n Unesite 0 za prekid ili bilo koji drugi broj za nastavak. \n";
        std::cin>>broj;
    }
}

bool Dogadaj::daLiImaGostiju() {
    return  this->dajGoste().size() >0;
}

unsigned  int Dogadaj::dajTrenutniBrojGostiju() {
    unsigned int brojGostiju=0;

    std::shared_ptr<Gost> gost= std::make_shared<Gost>();
    for(int i=0; i<dajGoste().size(); i++) {
        *gost=this->dajGoste()[i];
        if(gost->getDolaziSam()) {
            brojGostiju++;
        }
        else {
            brojGostiju+=2;
        }
    }
}