#include <iostream>
#include <vector>
#include <memory>

#include "Dogadaji.h"

int glavniMeni() {
    std::cout<<"1. Unesi dogadaj\n";
    std::cout<<"2. Ispisi dogadaj\n";
    std::cout<<"3. Rad sa dogadajem\n";
    std::cout<<"4. Kraj\n";

    int izbor;
    do {
        std::cout<<"Izbor: ";
        std::cin>>izbor;
    } while (izbor<1 || izbor > 4);

    std::cin.ignore();
    return izbor;
}

int radSaDogadajemMeni () {
    std::cout<<"1. Unesi gosta\n";
    std::cout<<"2. Ispisi dogadaj\n";
    std::cout<<"3. Rad sa dogadajem\n";
    std::cout<<"4. Kraj\n";

    int izbor;
    do {
        std::cout<<"Izbor: ";
        std::cin>>izbor;
    } while (izbor<1 || izbor>4);

    std::cin.ignore();
    return izbor;
}

int main() {
    std::vector<Dogadaj> dogadaji;
    int izbor;

    do {
        std::shared_ptr<Dogadaj> dogadaj = std::make_shared<Dogadaj>();
        izbor = glavniMeni();

        switch (izbor) {
            case 1:
                dogadaj->unesiDogadjaj();
                dogadaji.push_back(*dogadaj);
                break;

            case 2:
                if (dogadaji.size() == 0) {
                    std::cout << "Trenutno nema dogadaja! ";
                    break;
                }
                std::cout << "Dogadaji" << std::endl;
                std::cout << "R. broj\tNaziv\t\tMaksimalan broj gostiju\t\tTrenutno gostiju\n";
                for (int i = 0; i < dogadaji.size(); i++) {
                    *dogadaj = dogadaji[i];
                    std::cout << i + 1 << "\t";
                    std::cout << dogadaj->getNaziv() << "\t\t";
                    std::cout << dogadaj->getMaxBrojGostiju() << "\t\t\t\t";
                    std::cout << dogadaj->dajTrenutniBrojGostiju() << "\n";
                }
                break;

            case 3:
                unsigned int redniBroj;
                std::cout << "Unesi redni broj dogadaja \n";
                std::cin >> redniBroj;

                if (redniBroj > dogadaji.size()) {
                    std::cout << "Ne postoji dogadaj na tom rednom broju! ";
                    break;
                }

                std::shared_ptr<Dogadaj> nadjeniDogadaj = std::make_shared<Dogadaj>();
                *nadjeniDogadaj = dogadaji[redniBroj - 1];

                int izbor2;
                do {
                    izbor2 = radSaDogadajemMeni();
                    switch (izbor2) {
                        case 1:
                            nadjeniDogadaj->dodajGosta();
                            break;

                        case 2:
                            nadjeniDogadaj->dodajGosta();
                            break;

                        case 3:
                            nadjeniDogadaj->nadjiGoste();
                            break;

                        case 4:
                            nadjeniDogadaj->ispisDogadjaj();
                            break;
                    }
                } while (izbor2 != 5);

                break;
        }

    } while (izbor != 4);
}