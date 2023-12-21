//
// Created by Amila Huzbasic on 12/19/2023.
//
#include "Datum.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

Datum::Datum() {
    this->dan = 1;
    this->mjesec = 1;
    this->godina = 1900;
}

void Datum::postaviDatum() {
    cout << "**** UNOS DATUMA ****" << endl;
    this->setGodina();
    this->setMjesec();
    this->setDan();
}

void Datum::setGodina() {
    do {
        cout << "Unesi godinu: ";
        cin >> this->godina;
        if (this->godina < 1900) {
            cout << "GRSKA - pogresna godina\n";
        }
    } while (this->godina < 1900);
}

void Datum::setMjesec() {
    do {
        cout << "Unesi mjesec: ";
        cin >> this->mjesec;
        if (this->mjesec < 1 || this->mjesec > 12) {
            cout << "GRSKA - pogresna mjesec\n";
        }
    } while (this->mjesec < 1 || this->mjesec > 12);
}

void Datum::setDan() {
    switch (this->mjesec) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            this->postaviDan(1, 31);
            break;
        case 4: case 6: case 9: case 11:
            this->postaviDan(1, 30);
            break;
        case 2:
            if (this->godina % 4 == 0 && (this->godina % 100 != 0 || this->godina % 400 == 0)) {
                this->postaviDan(1, 29);
            }
            else {
                this->postaviDan(1, 28);
            }
            break;
        default:
            cout << "GRESKA - pogresan mjesec\n";
    }
}

int Datum::getDan() {
    return this->dan;
}

int Datum::getMjesec() {
    return this->mjesec;
}

int Datum::getGodina() {
    return this->godina;
}

void Datum::ispisDatum() {
    cout << setw(2) << setfill('0') << this->getDan() << "." << setw(2) << setfill('0') << this->getMjesec() << "." << this->getGodina() << endl;
}

string Datum::getDatum() {
    string stringDan, stringMjesec;
    if (this->dan < 10) {
        stringDan = "0" + to_string(this->dan);
    }
    else {
        stringDan = to_string(this->dan);
    }

    if (this->mjesec < 10) {
        stringMjesec = "0" + to_string(this->mjesec);
    }
    else {
        stringMjesec = to_string(this->mjesec);
    }

    string rezultat = stringDan + "." + stringMjesec + "." + to_string(this->godina);
    rezultat += "(" + this->nazivDana() + ")";

    return rezultat;
}

int Datum::zellerAlgoritam(int dan, int mjesec, int zadnjeDvijeCifre, int prveDvijeCifre) {
    int rezultat = dan + floor((13 * (mjesec + 1)) / 5) + zadnjeDvijeCifre + floor(zadnjeDvijeCifre / 4) + floor(prveDvijeCifre / 4) + 5 * prveDvijeCifre;
    return rezultat % 7;
};

string Datum::nazivDana() {
    string daniUSedmici[7] = { "Subota", "Nedjelja", "Ponedjeljak", "Utorak", "Srijeda", "Četvrtak", "Petak" };
    int mjesec;
    int godina = this->godina;
    if (this->mjesec > 2) {
        mjesec = this->mjesec;
    }
    else {
        mjesec = 12 + this->mjesec;
        godina -= 1;
    }

    int zadnjeDvijeCifre = godina % 100;
    int prveDvijeCifre = godina / 100;

    int danUSedmici = this->zellerAlgoritam(this->dan, mjesec, zadnjeDvijeCifre, prveDvijeCifre);

    return daniUSedmici[danUSedmici];
}

void Datum::postaviDan(int min, int max) {
    do {
        cout << "Unesi dan: ";
        cin >> this->dan;
        if (this->dan > max) {
            cout << "GRSKA - mjesec " << this->mjesec << " ima samo " << max << " dana";
        }
        else if (this->dan < min) {
            cout << "GRESKA - dan mora biti pozitivan\n";
        }
    } while (this->dan < min || this->dan > max);
}