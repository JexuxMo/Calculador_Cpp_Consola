/* 
 * File:   Menu.cpp
 * Author: sauron
 * 
 * Created on April 8, 2019, 10:48 PM
 */

#include "Menu.h"
#include "Datos.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;
#include <cstdlib>

Menu::Menu() {
   despliegaMenu();
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

void Menu::despliegaMenu()
{
   while(Menu::opcion!=7)
   {
      cout<<"\n\n\tPROGRAMA DE CALCULA TEOREMAS DEL CUATRIMESTRE VISTO"<<endl;
      cout<<"\n\n\nSelecciona el numero de acuerdo a la opcion que deseas calcular.\n";
      cout<<"\n\n1)  Error absoluto y relativo\n\n2)  Bisecciones\n\n3)  Newton-Raphson";
      cout<<"\n\n4)  Gauss-Jordan\n\n5)  Matris inversa\n\n6)  Metodo de Jacobi";
      cout<<"\n\n7)  Salir";
      cout<<"\n\n\n\nOpcion: "; 

      cin>>Menu::opcion;
      //Menu::opcion = 1*(cin.get());
      if(Menu::opcion<=7 and Menu::opcion>=1)
      {
         opcionSeleccionada(Menu::opcion);
      }
      else
      {
         system("clear");
         /*cout<<"\n\n\n\n\n\n\tLa opcion escrita no es correcta ingresela de nuevo!!!";
         cout<<"\n\n\n\npresione ENTER";
         cin.get();
         system("clear");*/
      }
      system("clear");
   }
}

void Menu::opcionSeleccionada(int opcion)
{
   Datos datos(opcion);
   switch(opcion)
   {
      case 1:
         datos.errorAyR();
         break;
      case 2:
         datos.biseccion();
         break;
      case 3:
         datos.newtonRaphson();
         break;
      case 4:
         datos.gaussJordan();
         break;
      case 5:
         datos.matrisInversa();
         break;
      case 6:
         datos.jacobi();
         break;
      default:
         break;
   }
   
}

