#include "NodoS.h"


NodoS::NodoS() : NodoS(0){}
NodoS::NodoS(int pdato) :NodoS(pdato, nullptr){}
NodoS::NodoS(int pdato, NodoS*pnext):dato(pdato), next(pnext){}
