/* 
 * File:   Calculonewt.cpp
 * Author: sauron
 * 
 * Created on April 9, 2019, 6:30 PM
 */

#include "Calculonewt.h"
#include <cmath>
#include <iostream>
using namespace std;

Calculonewt::Calculonewt(int c1,int c2,int ind,int c1D,int indD,double x0,double mError) {
   newtonR(c1,c2,ind,c1D,indD,x0,mError);
}

Calculonewt::Calculonewt(const Calculonewt& orig) {
}

Calculonewt::~Calculonewt() {
}

double Calculonewt::funcion(double x,int c1,int c2,int ind){
   
    return c1*pow(x,2)+c2*x+ind;
}

double Calculonewt::derivada(double x,int c1D,int indD){
    
    return c1D*(x)+indD;
}

void Calculonewt::newtonR(int c1,int c2,int ind,int c1D,int indD,double x0,double mError)
{
   int i = 0;
   float e=1000,xn=x0,xn1=0;
   while(e>mError)
   {
      
      xn1 = xn-(funcion(xn,c1,c2,ind)/(derivada(xn,c1D,indD)));
      e = abs((xn1 - xn)/xn1);
      
      
      ++i;
      if(e>mError)
         xn = xn1;
      if(i == 10)
         e=0;
   }
   Calculonewt::xn = xn;
   Calculonewt::xn1 = xn1;
   Calculonewt::Er = e;
   Calculonewt::numIt = i;

}

float Calculonewt::getXn()
{
   return Calculonewt::xn;
}

float Calculonewt::getXn1()
{
   return Calculonewt::xn1;
}

float Calculonewt::getEr()
{
   return Calculonewt::Er;
}

int Calculonewt::getIteracion()
{
   return Calculonewt::numIt;
}
