#ifndef FUNKCIJOSCLASS_H
#define FUNKCIJOSCLASS_H

#include "irasasClass.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <vector>
#include <numeric>
#include <list>
#include <iterator>
#include <sstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::sort;
using std::vector;
using std::accumulate;
using std::ifstream;
using std::ofstream;
using std::setprecision;
using std::to_string;
using std::fixed;
using std::numeric_limits;
using std::streamsize;
using std::list;
using std::stringstream;

int SkIvedimasClass();
void PagalbineClass(char ar, char budasIsvesti,  int nStudentu);
void DuomenysClass(vector < Studentas > studentai);
void NaudotojoSuvedimasClass(Studentas & temp);
void SpausdinimasCl(Studentas &temp);
void RandomSuvedimasClass(Studentas & temp);
void NefailoDuomenuGavimasClass(Studentas & temp);
void SpausdinimasClass(Studentas temp);
bool LyginimasClass(Studentas & a, Studentas & b);
void DuomenuGeneravimasClass(int & nStudentu, int & nPazymiu);
void SkaiciavimasClass( vector<Studentas> &studentai, char budasIsvesti);
void FailoDuomenuGavimasClass(vector < Studentas > & studentai, int nStudentu);
void GrupavimasClass(int nStudentu, vector<Studentas> &studentai,
                      vector<Studentas> &geresnioBalo,
                      vector<Studentas> &zemesnioBalo);
void SpausdinimasClass(int nStudentu,
 vector < Studentas > & geresnioBalo,
     vector < Studentas > & zemesnioBalo);
#endif