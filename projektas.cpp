
#include "funkcijosClass.h"
#include "irasasClass.h"
#include "funkcijosClass.cpp"
#include "irasasClass.cpp"
/**
 * Main funkcija atliekanti pagrindinius klausimus vartotojui 
 */
int main() {
  
  cout << "Iveskite f jeigu norite dirbti su failu arba n jei norite studentus ivesti patys: " << endl;;
  char arGeneruoti;
  while (true) {
    cin >> arGeneruoti;
    arGeneruoti = tolower(arGeneruoti);
    if (arGeneruoti != 'f' && arGeneruoti != 'n') {
      cout << "Iveskite f arba n raidę: ";
    } else break;
  }
  if (arGeneruoti == 'f') {
      cout << "Ar norite kad galutinis balas butu isvedamas pagal vidurki? 'v' Ar "
          "norite kad butu isvedamas pagal mediana? 'm' )  ";
  char arVidurkis;
  char budasIsvesti;
  string name;
  while (true) {
    cin >> arVidurkis;
    arVidurkis = tolower(arVidurkis);
    if (arVidurkis != 'v' && arVidurkis != 'm') {
      cout << "Iveskite v arba m raidę: ";
    } else
      break;
  }
  if (arVidurkis == 'v') {
    budasIsvesti = 'v';
  } else if (arVidurkis == 'm') {
    budasIsvesti = 'm';
  }
  cout << "Iveskite failo studentu skaičių: " << endl;
  int nStudentu;
  nStudentu = SkIvedimasClass();

  cout << "Ar norite nuskaityti faila? 'n' Ar norite ji sugeneruoti? 'g' )  ";
  char ar;
  while (true) {
    cin >> ar;
    ar = tolower(ar);
    if (ar != 'n' && ar != 'g') {
      cout << "Iveskite n arba g raidę: ";
    } else
      break;
  }
    if (ar == 'g') {
    cout << "Iveskite studento pazymiu skaičių: " << endl;
    int nPazymiu;
    nPazymiu = SkIvedimasClass();
    DuomenuGeneravimasClass(nStudentu, nPazymiu);
  }
    PagalbineClass(ar, budasIsvesti, nStudentu);
    
  } else if (arGeneruoti == 'n') {
    
    vector < Studentas > studentai;
    studentai.reserve(1000);
    DuomenysClass(studentai);
    studentai.clear();
  }

  return 0;
}