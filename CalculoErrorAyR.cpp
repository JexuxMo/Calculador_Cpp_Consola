/* 
 * File:   CalculoErrorAyR.cpp
 * Author: sauron
 * 
 * Created on April 9, 2019, 1:37 AM
 */

#include "CalculoErrorAyR.h"
#include <string>

CalculoErrorAyR::CalculoErrorAyR()
{
   
}

CalculoErrorAyR::CalculoErrorAyR(double vV,double vA) {
   double d = 0;
   calculaErrorAbsoluto(vV,vA);
   d = getErrorAbs();
   calculaErrorRelativo(d,vV);
}

CalculoErrorAyR::CalculoErrorAyR(const CalculoErrorAyR& orig) {
}

CalculoErrorAyR::~CalculoErrorAyR() {
}

void CalculoErrorAyR::calculaErrorAbsoluto(double vV,double vA)
{
   CalculoErrorAyR::errorAbsoluto = vV-vA;

}

void CalculoErrorAyR::calculaErrorRelativo(double errorAbs,double vV)
{
   CalculoErrorAyR::errorRelativo = errorAbs/vV*100;
 
}

double CalculoErrorAyR::getErrorAbs()
{
   return CalculoErrorAyR::errorAbsoluto;
}

double CalculoErrorAyR::getErrorRel()
{
   return CalculoErrorAyR::errorRelativo;
}
