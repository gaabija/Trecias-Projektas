/**
 *  @file irasasClass.cpp
 * Funkcijos reikalingos studento klases objektu veiklai
 */

#include "irasasClass.h"

Studentas::Studentas(ifstream& fd)
{
    readStudentas(fd);
}

/**
 * readStudentas funkcija reikalinga i klases objektus duomenu nuskaitymui
 */
void Studentas::readStudentas(ifstream &fd) {
    fd >> this->vardas_ >> this->pavarde_;
    this->pazymiai_.reserve(10);
  int pazymys;
    while (fd >> pazymys) {
      this->pazymiai_.push_back(pazymys);
    }
    this-> egzas_ = this->pazymiai_.back();
    this->pazymiai_.pop_back();
  }

/**
 * Galutinis funkcija reikalinga balo skaiciavimui, pagal ankciau naudotojo nurodyta buda, skaiciuoti
 * Funkcija kreipiasi i vidurkio ar medianos funkcija atitinkamai
 */
void Studentas::Galutinis(char budasIsvesti) {
  double galutinis;
  if (budasIsvesti == 'm') {
       galutinis = Mediana( ) * 0.4 +
        this-> egzas_ * 0.6;
  } else if (budasIsvesti == 'v') {
      galutinis = Vidurkis( ) * 0.4 +
        this-> egzas_ * 0.6;
  }
  setGalut(galutinis);
}

/**
 * Vidurkis funkcija skaiciuoja studento pazymiu vidurki 
 */
double Studentas::Vidurkis() {
  double vidurkis =
    accumulate(this->pazymiai_.begin(), this->pazymiai_.end(), 0.0) / this->pazymiai_.size();
  return vidurkis;
}

/**
 * Mediana funkcija skaiciuoja studento pazymiu mediana
 */
double Studentas::Mediana() {
  double mediana;
  sort(this->pazymiai_.begin(), this->pazymiai_.end());
  int vidurinisElementas = this->pazymiai_.size() / 2;
  if (this->pazymiai_.size() / 2 == 0) {
    mediana = (this->pazymiai_[vidurinisElementas - 1] + this->pazymiai_[vidurinisElementas]) / 2.;
  } else {
    mediana = this->pazymiai_[vidurinisElementas];
  }
  return mediana;
}


