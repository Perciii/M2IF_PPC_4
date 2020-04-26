#pragma once
#ifndef COMPOSANT4_H
#define COMPOSANT4_H

#include <string>
#include "../interfaces/bloc.h"

std::string hash(Bloc bloc);
bool verifHash(Bloc bloc, std::string hashCode);
Bloc buildBloc(TX transaction);
std::string version();

#endif