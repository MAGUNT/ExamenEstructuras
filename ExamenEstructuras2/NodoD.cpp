#include "NodoD.h"

NodoD::NodoD() : NodoD(0){}
NodoD::NodoD(int pdato) : NodoD(pdato, nullptr,nullptr){}
NodoD::NodoD(int pdato, NodoD *pprev, NodoD *pnext) : dato(pdato), next(pnext){}