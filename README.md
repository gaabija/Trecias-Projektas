# Trecias-Projektas
Sukurtas programos studentų galutiniams balams skaičiuoti diegimo failas - setup.exe

### setup.exe naudojimas
- Atsiųskite setup.exe ar .msi failą
- Sekite Setup Wizard nurodymus, jums reikės nurodyti kur instaliuoti programą
<img width="386" alt="image" src="https://user-images.githubusercontent.com/113300842/208936259-71b35994-fdf0-4067-b410-871a3e490381.png">
- Sparčiasias programėlės nuorodas rasite ant darbalaukio ir programų meniu

### Naudojimas:
Paleidus programą bus prašoma:
- Pasirinkti ar norite generuoti failą
Jei pasirenkate generuoti failą prašoma:
- Įvesti kiek pažymių generuoti studentams
Jei pasirenkate negeneruoti failo prašoma:
- Įvesti studentų skaičių 
- Įvesti studento vardą bei pavardę
- Pasirinkti ar pažymiai bus įvedami naudotojo ar sugeneruota programos
    - Suvesti norimus pažymius baigus įvedant '0'bei įvesti egzamino rezutatą
    - Įvesti norimo sugeneruoti pažymių skaičių
- Pasirinkti ar galutinį balą skaičiuoti pagal vidurkį ar medianą

### Reikalavimai įvedimui:
- Įvedant studentų skaičių, pažymių skaičių, egzamino balą nepriimamos raidės ar simbolių reikšmės
- Nepriimami kiti atsakymai nei pateikia dviejų pasirinkimų klausimas 
    - Leidžiama tik 'g' ar 'n' renkantis duomenis imti iš failo/be failo
    - Leidžiama tik 'v' ar 'm' renkantis vidurkį/medianą
    - Leidžiama tik 'a' ar 'p' renkantis naudotojo/atsitiktinį pažymių suvedimą


## Versijos:
### v3.0 
- Sukurtas setup.exe
### v2.0
- Sukurta dokumentacija panaudojant Doxygen
### v1.5
- Sukurta Žmogus bazinė klasė iš kurios išvedama Studentas klasė
### v1.2
- Realizuota "Rule of three" turimai Studentas klasei
### v1.1
- Struktūros Irasas pagrindu sukurta Studentas klasė
- Išmatuota sparta naudojant vieną fiksuotą konteinerį vektorių, greičiausią dalijimo strategiją bei 100000 ir 1000000 dydžio failus
### v1.0
- paruošta cmake CMakeLists.txt įdiegimo instrukcija
- optimizuoti algoritmai vektoriaus studentų dalijimo procedūrai
- išmatuota programos veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijos
### v0.4
- Galimybė dirbti ne tik su vietoje generuojamu failu, bet ir su jau esančio failo nuskaitymu
- Naudojamas ne tik vector bet ir list tipo konteineris studentų duomenims saugoti
- Atliekama programos veikimo greičio (spartos) analizė vector ir list konteineriams:
    - duomenų nuskaitymui iš failų
    - studentų grupavimui į dvi grupes/kategorijas (Geresnio balo (>=5) ir žemesnio balo (<5) )
### v0.3
- Galimybė generuoti norimo dydžio studentų įrašų failus
- Studentų įrašai surūšiuojami pagal balą į dvi kategorijas ir išvedami į du skirtingus failus
- Atliekama programos veikimo greičio (spartos) analizė:
    - failų kūrimui
    - duomenų nuskaitymui iš failų
    - studentų rūšiavimui į dvi grupes/kategorijas
    - studentų išvedimui į du naujus failus
### v0.2
v.01 papildytas galimybe duomenis imti iš nuskaitomo failo, pridėtas klaidos jei failas neatsidarė sugavimas, failas išskaidytas į .h bei .cpp failus, lengvesniam skaitomumui.
### v0.1
Šioje versijoje yra 2 .cpp failai - masyvo bei vektoriaus realizacijos studento namų darbų pažymiams saugoti.
