/* 
 * File:   Datos.cpp
 * Author: sauron
 * 
 * Created on April 9, 2019, 12:47 AM
 */

#include "Datos.h"
#include "CalculoErrorAyR.h"
#include "CalculoBis.h"
#include "Calculonewt.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Datos::Datos(int opcion) {
   Datos::opcion = opcion;
}

Datos::Datos(const Datos& orig) {
}

Datos::~Datos() {
}

void Datos::errorAyR()
{
   //funsion que pide los datos al usuario
   obtenerDatos();
   //calcula los datos obtenidos por el usuario y regresa los resultados
   CalculoErrorAyR calculoErrorAyR(Datos::valorVerda,Datos::valorAprox);
   resultados(calculoErrorAyR.getErrorAbs(),calculoErrorAyR.getErrorRel());
}

void Datos::biseccion()
{
   //pide datos al usuario
   obtenerDatos();
   //calcula los datos obtenidos por el usuario y regresa los resultados
   CalculoBis bis(Datos::c1,Datos::c2,Datos::ind,Datos::xi,Datos::xm,Datos::i);
   resultados(bis.getXr(),bis.getFxiFxr(),bis.getXi(),bis.getXm());
}

void Datos::newtonRaphson()
{
   //pide datos al usuario
   obtenerDatos();
   //calcula los datos obtenidos por el usuario y regresa los resultados
   Calculonewt newton(Datos::c1,Datos::c2,Datos::ind,Datos::c1D,Datos::indD,Datos::x0,Datos::mError);
   resultados(newton.getXn(),newton.getXn1(),newton.getEr(),newton.getIteracion());
}

void Datos::gaussJordan()
{
   //pide datos al usuario
   obtenerDatos();
   //calcula los datos obtenidos por el usuario y regresa los resultados
   int i,j,k,n=dimension;
   
   for(i=0;i<=n-1;i++) 
   { 
      for(j=n;j>=0;j--) 
      { 
         m[i][j]=m[i][j]/m[i][i]; 
      } 
      for(k=i+1;k<=n-1;k++) 
      { 
         for(j=n;j>=0;j--) 
         { 
            m[k][j]=m[k][j]-m[k][i]*m[i][j]; 
         } 
      } 
      for(k=0;k<=i-1;k++) 
      { 
         for(j=n;j>=0;j--) 
         { 
            m[k][j]=m[k][j]-m[k][i]*m[i][j]; 
         } 
      } 
   } 
   resultados();
}

void Datos::matrisInversa()
{
   //pide datos al usuario
   obtenerDatos();
   //calcula los datos obtenidos por el usuario y regresa los resultados
   
   int i,j,k;
   double d;
   for (i = dimension; i > 1; i--)
   {
      if (m[i - 1][1] < m[i][1])
            for (j = 1; j <= dimension * 2; j++)
            {   
               d = m[i-1][j-1];

               m[i-1][j-1] = m[i - 2][j-1];

               m[i - 2][j-1] = d;
            }

   }

   /********** matris diagonal reducida ***********/



   for (i = 1; i <= dimension; i++)

   {

       for (j = 1; j <= dimension * 2; j++)

           if (j != i)

           {

               d = m[j-1][i-1] / m[i-1][i-1];

               for (k = 1; k <= dimension * 2; k++)

                   m[j-1][k-1] -= m[i-1][k-1] * d;

           }

   }

   /************** matris identidad reducida *************/

   for (i = 1; i <= dimension; i++)

   {

       d = m[i-1][i-1];

       for (j = 1; j <= dimension * 2; j++)

           m[i-1][j-1] = m[i-1][j-1] / d;

   }
  
   resultadosI();
}

void Datos::jacobi()
{
   int i,j;
   //pide datos al usuario
   obtenerDatos();
   //calcula los datos obtenidos por el usuario y regresa los resultados

   while (iteraciones<4){

      for(i=0;i<dimension;i++){
         for(j=0;j<dimension;j++) 
         {
            aux[j]=A[i][j];
         }
         x[i]=(1/(A[i][i]))*((b[i])-suma_jacobi(aux,x_prev,i));
         
      }

      printf("\n\n Iteracion %d: \n",iteraciones+1);
      for(i=0;i<dimension;i++){
         x_prev[i]=x[i];
         printf("X(%d)=%f \n",i,x[i]);
      }

      iteraciones++;
   }
    
   resultadosJ();
}

void Datos::obtenerDatos()
{
   system("clear");
   int i=0,j=0;
   switch(Datos::opcion)
   {  
      case 1:
         cout<<"Valor Verdadero[ X ] = ";
         cin>>Datos::valorVerda;
         cout<<"\nValor aproximado[ Xi ] = ";
         cin>>Datos::valorAprox;
         break;
      case 2:
         cout<<"Escribe los coeficientes de la funcion:\n";
         cout<<"Coeficiente de X² = ";
         cin>>Datos::c1;
         cout<<"\nCoeficiente de X = ";
         cin>>Datos::c2;
         cout<<"\ntermino indendiente = ";
         cin>>Datos::ind;
         
         cout<<"\n\nlimite inferior[ Xi ] = ";
         cin>>Datos::xi;
         cout<<"\nlimite superior[ Xm ] = ";
         cin>>Datos::xm;
         cout<<"\n\ncantidad de interaciones= ";
         cin>>Datos::i;
         break;
      case 3:
         cout<<"Escribe los coeficientes de la funcion:\n";
         cout<<"Coeficiente de X² = ";
         cin>>Datos::c1;
         cout<<"\nCoeficiente de X = ";
         cin>>Datos::c2;
         cout<<"\ntermino indendiente = ";
         cin>>Datos::ind;
         
         cout<<"Escribe los coeficientes de la funsion derivada:\n";
         cout<<"Coeficiente de X = ";
         cin>>Datos::c1D;
         cout<<"\ntermino indendiente = ";
         cin>>Datos::indD;
         cout<<"\n\npunto de inicio[ X0 ] = ";
         cin>>Datos::x0;
         /*
         cout<<"\n\nlimite inferior[ Xi ] = ";
         cin>>Datos::xi;
         cout<<"\nlimite superior[ Xm ] = ";
         cin>>Datos::xm;
         */
         cout<<"\n\nMargen de error[ % ]= ";
         cin>>Datos::mError;
         break;
      case 4:  
         cout<<"Escribe la dimension de la matris:\n";
         cin>>dimension;
         
         //damos los valores de la matris
         for(i=1;i<=dimension;i++)
         {
            for(j=1;j<=dimension;j++)
            {
               cout<<"\n M=["<<i<<","<<j<<"]= ";
               cin>>m[i-1][j-1];
            }
            cout<<"\n Termino independiente de X"<<i<<" ";
            cin>>m[i-1][dimension];
         }
         system("clear");
         //imprime la matris acomodandola de forma cuadrada
         cout<<"\nLa matris es:\n\n";
         for(i=1;i<=dimension;i++)
         {
            for(j=1;j<=dimension+1;j++)
            {
               cout<<m[i-1][j-1]<<" ";
            }
            cout<<"\n";
         }
         break;
      case 5:
         cout<<"Escribe la dimension de la matriz:\n";
         cin>>dimension;
         
         //damos los valores de la matris
         for(i=1;i<=dimension;i++)
         {
            for(j=1;j<=dimension;j++)
            {
               cout<<"\n M=["<<i<<","<<j<<"]= ";
               cin>>m[i-1][j-1];
            }
         }
         //crea la matris identidad
         for (i = 1; i <= dimension; i++)
            for (j = dimension+1; j <= 2 * dimension; j++)
               if (j == (i + dimension))
                  m[i-1][j-1] = 1;
               else 
                  m[i-1][j-1]=0;
            
         system("clear");
         //imprime la matris acomodandola de forma cuadrada
         cout<<"\nLa matriz es:\n\n";
         for(i=1;i<=dimension;i++)
         {
            for(j=1;j<=dimension*2;j++)
            {
               cout<<"\t"<<m[i-1][j-1]<<" ";
            }
            cout<<"\n";
         }
         
         break;
      case 6:
         cout<<"Dimension de la matriz A:\n";
         cin>>dimension;
         
         //damos los valores de la matris
         for(i=1;i<=dimension;i++)
         {
            for(j=1;j<=dimension;j++)
            {
               cout<<"\n M=["<<i<<","<<j<<"]= ";
               cin>>A[i-1][j-1];
            }
         }

         printf("\n Elementos del vector b: \n");
         for(i=0;i<dimension;i++){
            printf("b[%d]=",i+1); 
            //scanf("%f",&b[i]);
            cin>>b[i];
         }
         
         printf("\n Valor inicial de la iteracion: \n");
         for(i=0;i<dimension;i++){
            printf("x0[%d]=",i+1); //scanf("%f",&x_prev[i]);
            cin>>x_prev[i];
         }
         
         break;
   }
}

//ErrorAyR
void Datos::resultados(double a,double b)
{
   int e;
   ////////////////////resultado del calculo////////////////////////////////////
   cout<<"\n\n\nErrorAbsoluto = "<<a<<"\nErrorRelativo = "<<b<<"%";
   /////////////////////////////////////////////////////////////////////////////
   
   cout<<"\n\n\n\nPresiona [1]+[Enter] para regresar: "; 

      cin>>e; 
}

//Biseccion
void Datos::resultados(double a,double b,double c,double d)
{
   int e;

   cout<<"\n\n\nResultados de la ultima iteracion:\nXi = "<<c<<"\n";
   cout<<"Xm = "<<d<<"\nXr = "<<a<<"\nf(xi)f(xr) = "<<b;
   cout<<"\n\n\n\nPresiona [1]+[Enter] para regresar: "; 

   cin>>e;
   
}

//NewtonR
void Datos::resultados(float a,float b,float c,int d)
{
   int e;

   cout<<"\n\n\nResultados de la ultima iteracion:\nXn = "<<a<<"\n";
   cout<<"Xn+1 = "<<b<<"\nEr = "<<c<<" %\n#iteraciones = "<<d;
   cout<<"\n\n\n\nPresiona [1]+[Enter] para regresar: "; 

   cin>>e;
   
}

//Gauss
void Datos::resultados()
{
   int i,e,n=dimension;

   cout<<"Sus resultados son:"; 
   for(i=0;i<=n-1;i++) 
   { 
      cout<<"\nX["<<i<<"] = "<<m[i][n]; 
   }
   
   cout<<"\n\n\n\nPresiona [1]+[Enter] para regresar: "; 

   cin>>e;
   
}

//Inversa
void Datos::resultadosI()
{
   int i,j,e,n=dimension;

   cout << "la matriz inversa es: " << endl;

   for (i = 1; i <= n; i++)

   {

      for (j = n + 1; j <= n * 2; j++)

         cout <<"\t"<< m[i-1][j-1] << " ";

      cout << endl;

   }
   
   cout<<"\n\n\n\nPresiona [1]+[Enter] para regresar: "; 

   cin>>e;
}

//Jacobi
void Datos::resultadosJ()
{
   int i,e;
   printf("\nSolucion del sistema\n");
   printf("Numero de iteraciones: %d \n", iteraciones);
   for(i=0;i<dimension;i++){
      printf("x(%d)=%f\n",i,x[i]);
   }
   cout<<"\n\n\n\nPresiona [1]+[Enter] para regresar: "; 

   cin>>e;
}

float Datos::suma_jacobi(float Matriz[], float vector[], int componente)
{
   float aux=0;
   int i;
   for(i=0;i<dimension;i++){
      if (componente!=i){
         aux=aux+Matriz[i]*vector[i];
      }
   }
   return aux;
}