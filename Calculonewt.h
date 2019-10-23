/* 
 * File:   Calculonewt.h
 * Author: sauron
 *
 * Created on April 9, 2019, 6:30 PM
 */

#ifndef CALCULONEWT_H
#define CALCULONEWT_H

class Calculonewt {
public:
    Calculonewt(int,int,int,int,int,double,double);
    Calculonewt(const Calculonewt& orig);
    virtual ~Calculonewt();
    
    double funcion(double,int,int,int);
    double derivada(double,int,int);
    void newtonR(int,int,int,int,int,double,double);
    
    float getXn();
    float getXn1();
    float getEr();
    int getIteracion();
private:
    float xn;
    float xn1;
    float Er;
    int numIt;
};

#endif /* CALCULONEWT_H */

