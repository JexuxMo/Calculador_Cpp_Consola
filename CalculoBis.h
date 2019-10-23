/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CalculoBis.h
 * Author: sauron
 *
 * Created on April 9, 2019, 9:12 AM
 */

#ifndef CALCULOBIS_H
#define CALCULOBIS_H

class CalculoBis {
public:
    CalculoBis(int ,int ,int ,double ,double ,int);
    CalculoBis(const CalculoBis& orig);
    virtual ~CalculoBis();
    
    void biseccion(double ,double ,int );
    double funcion(int ,int ,int ,double );
    
    double getXi();
    double getXm();
    double getXr();
    double getFxiFxr();
    
private:
    int c1;
    int c2;
    int ind;
    
    double xi;
    double xm;
    double xr;
    double fxifxr;

};

#endif /* CALCULOBIS_H */

