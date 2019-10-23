/* 
 * File:   Datos.h
 * Author: sauron
 *
 * Created on April 9, 2019, 12:47 AM
 */

#ifndef DATOS_H
#define DATOS_H

class Datos {
public:
    Datos(int);
    Datos(const Datos& orig);
    virtual ~Datos();
    
    void errorAyR();
    void biseccion();
    void newtonRaphson();
    void gaussJordan();
    void matrisInversa();
    void jacobi();
    
    void obtenerDatos();
    void resultados(double,double);//AyR
    void resultados(double,double,double,double);//Bis
    void resultados(float,float,float,int);//Newton
    void resultados();//Gauss
    void resultadosI();//Inversa
    void resultadosJ();//Jacobi
    
    float suma_jacobi(float Matriz[], float vector[], int componente);
private:
    int opcion;
    //Datos del Error AyR
    double valorVerda;
    double valorAprox;
    //Datos de Biseccion
    int c1;
    int c2;
    int ind;
    double xi;
    double xm;
    int i;
    //Datos Newton-Rahpson
    double mError;
    double funcion;
    double derivada;
    int c1D;
    int indD;
    double x0;
    //Datos gauss-jordan
    int dimension;
    double m[20][21] = {0};
    //Datos Jacobi
    float error;
    float epsilon;
    int iteraciones=0;
    float A[20][20] = {0};
    float b[20];
    float x[20];
    float x_prev[20];
    float aux[20];
     
};

#endif /* DATOS_H */

