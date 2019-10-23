/* 
 * File:   CalculoBis.cpp
 * Author: sauron
 * 
 * Created on April 9, 2019, 9:12 AM
 */

#include "CalculoBis.h"
#include <cmath>
using std::pow;

CalculoBis::CalculoBis(int c1,int c2,int ind,double xi,double xm,int i) {
   CalculoBis::c1 = c1;
   CalculoBis::c2 = c2;
   CalculoBis::ind = ind;
   
   biseccion(xi,xm,i);
}

CalculoBis::CalculoBis(const CalculoBis& orig) {
}

CalculoBis::~CalculoBis() {
}

double CalculoBis::funcion(int c1,int c2,int ind,double x){
    
    return c1*pow(x,2)+c2*x+ind;
}

void CalculoBis::biseccion(double xi,double xm,int MAXIT){
   int cont=0;
   double xr;
   double fxr,fxi;
   while(cont<MAXIT){
      
      
      xr=(xi+xm)/2;
      fxr=funcion(CalculoBis::c1,CalculoBis::c2,CalculoBis::ind,xr);
      fxi=funcion(CalculoBis::c1,CalculoBis::c2,CalculoBis::ind,xi);
      

      CalculoBis::xi = xi;
      CalculoBis::xm = xm;
      CalculoBis::fxifxr = fxi*fxr;
      
      if(fxi*fxr<0)
         xm=xr;
      if(fxr*fxi>0)
         xi=xr;
      
      cont=cont+1;
   }
   CalculoBis::xr = xr;
   //return xr;
} 

double CalculoBis::getXi()
{
   return CalculoBis::xi;
}

double CalculoBis::getXm()
{
   return CalculoBis::xm;
}

double CalculoBis::getFxiFxr()
{
   return CalculoBis::fxifxr;
}

double CalculoBis::getXr()
{
   return CalculoBis::xr;
}