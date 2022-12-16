/**
 *  @file funkcijosClass.cpp
 * Pagrindines funkcijos reikalingos programos veikimui
 */
#include "funkcijosClass.h"


/**
 * DuomenysClass funkcija yra pagalbine funkcija nedirbant su failais
 * Joje atliekami klausimai naudotojui, informacija perduodama DuomenuGavimas ir Spausdinimas funkcijoms 
 */
void DuomenysClass(vector<Studentas> studentai) {
  int nStudentu;
  char budasIsvesti;
  cout << "Iveskite studentu skaiciu: ";
  nStudentu = SkIvedimasClass();
  for (int i = 0; i < nStudentu; i++) {
    Studentas st;
    NefailoDuomenuGavimasClass(st);
    studentai.push_back(st);
    
  }
  cout << "Ar norite kad galutinis balas butu isvedamas pagal viduki? 'v' Ar "
          "norite kad butu isvedamas pagal mediana? 'm' )  ";
  char arVidurkis;
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
  sort(studentai.begin(), studentai.end(), LyginimasClass);
  printf("%10s %10s %20s\n ", "Vardas\t", "Pavarde\t", "Galutinis balas\t");
  for (Studentas &studentas : studentai) {
    studentas.Galutinis(budasIsvesti);
    SpausdinimasCl(studentas);
  }
}

/**
 * SpausdinimasCL yra funkcija nedirbant su failais
 * Ji atlieka studento duomenu spausdinima i eilute
 */
/// @brief Studento duomenu spausdinimas i eilute
/// @param temp 
void SpausdinimasCl(Studentas &temp) {
  cout << endl;
  printf("%10s %10s %20.2f\n ", temp.vardas().c_str(), temp.pavarde().c_str(),
         temp.galut());
}

/**
 * NefailoDuomenuGavimasClass yra funkcija nedirbant su failais
 * Ji atsakinga uz vartotojo duomenu apie studentus surinkima
 */
void NefailoDuomenuGavimasClass(Studentas &temp) {
  cout << "Iveskite varda: ";
  string v;
  cin >> v;
  temp.setVardas(v);
  cout << "Iveskite pavarde: ";
  string p;
  cin >> p;
  temp.setPavarde(p);
  cout << "Iveskite 'p' jei norite ivesti namu darbu pazymius patys. Iveskite "
          "'a' kad pazymiai butu sugeneruojami atsitiktinai . )  ";
  char arPats;
  while (true) {
    cin >> arPats;
    arPats = tolower(arPats);
    if (arPats != 'p' && arPats != 'a') {
      cout << "Iveskite a arba p raidę: ";
    } else
      break;
  }
  if (arPats == 'p') {
    NaudotojoSuvedimasClass(temp);
  } else if (arPats == 'a') {
    RandomSuvedimasClass(temp);
  }
}

/**
 * NaudotojoSuvedimasClass yra funkcija nedirbant su failais
 * Ji atsakinga uz vartotojo pazymiu suvedima ranka
 */
void NaudotojoSuvedimasClass(Studentas &temp) {
  cout << "Iveskite namų darbų ivertinimus (desimtbaleje sistemoje) "
          "paspausdami Enter, kai baigsite iveskite 0 ir Enter "
       << endl;
  int pazymys;
  int i = 1;
  vector <int> pazymiai;
  while (true) {
    cout << i << " -as pazymys: ";
    while (true) {
      pazymys = SkIvedimasClass();
      if (pazymys < 0 || pazymys > 10) {
        cout << "Iveskite skaiciu desimtbaleje sistemoje: ";
      } else
        break;
    }

    if (pazymys >= 1 && pazymys <= 10) {
      pazymiai.push_back(pazymys);
    } else
      break;
    i++;
  }
  temp.setPazymiai(pazymiai);
  cout << "Iveskite egzamino ivertinima (desimtbaleje sistemoje): ";
  while (true) {
    int eg;
    eg=SkIvedimasClass();
    if (eg < 0 || eg > 10) {
      cout << "Iveskite skaiciu desimtbaleje sistemoje: ";
    } else
      temp.setEgzas(eg);
      break;
  }
}

/**
 * RandomSuvedimasClass yra funkcija nedirbant su failais
 * Ji atsakinga uz atsitiktini pazymiu generavima studentui
 */

void RandomSuvedimasClass(Studentas &temp) {
  cout << "Iveskite kiek namu darbu pazymiu sugeneruoti: ";
  int npaz;
  npaz = SkIvedimasClass();
  vector<int> pazymiai;
  cout << "Sugeneruoti namu darbu ivertinimai: ";
  for (int i = 0; i < npaz; i++) {
    pazymiai.push_back(1 + rand() % 10);
    cout << pazymiai.at(i) << " ";
  }
  temp.setPazymiai(pazymiai);
  cout << endl;
  int eg;
  eg = 1 + rand() % 10;
  temp.setEgzas(eg);
  cout << "Sugeneruotas egzamino ivertinimas: " << temp.egzas() << endl;
}

/**
 * LyginimasClass yra funkcija atsakinga uz studentu rusiavimui didejimo reikalinga palyginimo operacija 
 */
bool LyginimasClass(Studentas &a, Studentas &b) { return a.vardas() < b.vardas(); }

void PagalbineClass(char ar, char budasIsvesti,  int nStudentu) {

    vector<Studentas> studentai;
    vector<Studentas> geresnioBalo;
    vector<Studentas> zemesnioBalo;
    FailoDuomenuGavimasClass(studentai, nStudentu);
    SkaiciavimasClass(studentai, budasIsvesti);
    GrupavimasClass(nStudentu, studentai, geresnioBalo, zemesnioBalo);
    SpausdinimasClass(nStudentu, geresnioBalo, zemesnioBalo);
    studentai.clear();
    geresnioBalo.clear();
    zemesnioBalo.clear();
    cout << endl;
}

/**
 * DuomenuGeneravimasClass yra funkcija atsakinga uz duomenu failo sugeneravima
 * Jai veikti reikalingi studentu ir pazymiu skaiciai
 */
void DuomenuGeneravimasClass(int &nStudentu, int &nPazymiu) {
  string name = "Studentai" + to_string(nStudentu) + ".txt";
  ofstream studFile(name);
  for (int i = 0; i < nStudentu; i++) {
    studFile << "Vardas" + to_string(i + 1) << " "
             << "Pavarde" + to_string(i + 1) << " ";
    for (int j = 0; j < nPazymiu + 1; j++) {
      studFile << rand() % 10 + 1 << " ";
    }
    studFile << endl;
  }
}

/**
 * FailoDuomenuGavimasClass yra funkcija atsakinga uz duomenu is studentu failo pasiemima
 */
void FailoDuomenuGavimasClass(vector<Studentas> &studentai, int nStudentu) {
  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
      studentai.reserve(nStudentu);
    ifstream fd;
    string name = "Studentai" + to_string(nStudentu) + ".txt";
  stringstream buffer;
  fd.open(name);
  buffer << fd.rdbuf();
  fd.close();
  string eil;

  while (getline(buffer, eil)) {
    Studentas studentas;
    stringstream fd(eil);
    string vardas, pavarde;
    fd >> vardas>>pavarde;
    studentas.setVardas(vardas);
    studentas.setPavarde(pavarde);
    int pazymys;
    vector <int> nd;
    while (fd >> pazymys) {
      nd.push_back(pazymys);
    }
    int egzas;
    egzas = nd.back();
    nd.pop_back();
    studentas.setPazymiai(nd);
    
    studentas.setEgzas(egzas);
    studentai.push_back(studentas);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  cout << to_string(nStudentu)
       << " irasu nuskaitymo laikas su Class: " << diff.count() << " s\n";
}

/**
 * SkaiciavimasClass yra funkcija atsakinga uz galutinio balo suskaiciavima studentui
 * Jai veikti reiklingas budo isvesti parametras
 */
void SkaiciavimasClass( vector<Studentas> &studentai, char budasIsvesti){
  for (auto &i : studentai){
    i.Galutinis(budasIsvesti);
  }
}

/**
 * GrupavimasClass funkcija sugrupuoja is failo gautus studentu duomenis pagal pazymius
 * Studentai <5 priskiriami zemesnioBalo, >5 geresnio balo vektoriui
 */
void GrupavimasClass(int nStudentu, vector<Studentas> &studentai,
                      vector<Studentas> &geresnioBalo,
                      vector<Studentas> &zemesnioBalo) {

  auto start = std::chrono::high_resolution_clock::now();
  auto startas = start;
  for (auto &i : studentai) {
        if (i.galut() < 5.00) {
           zemesnioBalo.push_back(i);
        } else {
            geresnioBalo.push_back(i);
        }
    }
  sort(zemesnioBalo.begin(), zemesnioBalo.end(), LyginimasClass);
  sort(geresnioBalo.begin(), geresnioBalo.end(), LyginimasClass);

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  cout << to_string(nStudentu)
       << " irasu grupavimo laikas su Class: " << diff.count() << " s\n";
}

/**
 * GrupavimasClass funkcija isspausdina i failus duomenis is sugrupuotu ir surusiuotu vektoriu
 * Kur studentai <5 zemesnioBalo spausdinami i ZemesnioBaloClass, o >5 GeresnioBaloClass failus
 */
void SpausdinimasClass(int nStudentu, vector<Studentas> &geresnioBalo,
                        vector<Studentas> &zemesnioBalo) {
  string zemesniuName = "ZemesnioBaloClass" + to_string(nStudentu) + ".txt";
  ofstream zemesn(zemesniuName);
  string geresniuName = "GeresnioBaloClass" + to_string(nStudentu) + ".txt";
  ofstream geresn(geresniuName);
  for (Studentas temp : zemesnioBalo) {
    zemesn << temp.vardas() << " " << temp.pavarde() << " " << fixed
           << setprecision(2) << temp.galut() << endl;
  }
  for (Studentas temp : geresnioBalo) {
    geresn << temp.vardas() << " " << temp.pavarde() << " " << fixed
           << setprecision(2) << temp.galut() << endl;
  }
  zemesnioBalo.clear();
  geresnioBalo.clear();
}

/**
 * SkIvedimasClass funkcija atsakinga uz skaiciaus teisingu formatu ivedima
 * Reikalinga tam kad vietose kur reikalingas skaicius nebutu priimama raide ar simbolis ir nekiltu error
 */
int SkIvedimasClass() {
  int sk;
  cin >> sk;
  while (1) {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Iveskite sveikaji skaiciu: " << endl;
      cin >> sk;
    }
    if (!cin.fail())
      break;
  }
  return sk;
}