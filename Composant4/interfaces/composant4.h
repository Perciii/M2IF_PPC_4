#pragma once
#ifndef COMPOSANT4_H
#define COMPOSANT4_H

#include <string>
#include "../interfaces/bloc.h"
#include "../interfaces/hash.h"

std::string hashBloc(Bloc bloc);
bool verifHash(Bloc bloc, std::string hashCode);
Bloc buildBloc(TX transaction);
Bloc buildBlocFull(char hash[], unsigned int nonce, int num, char prevHash[], TX transaction, TXM trasnsactionMineur);
std::string version();

#endif