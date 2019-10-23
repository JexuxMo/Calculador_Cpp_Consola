/* 
 * File:   CalculoErrorAyR.h
 * Author: sauron
 *
 * Created on April 9, 2019, 1:37 AM
 */

#ifndef CALCULOERRORAYR_H
#define CALCULOERRORAYR_H

class CalculoErrorAyR {
public:
    CalculoErrorAyR();
    CalculoErrorAyR(double,double);
    CalculoErrorAyR(const CalculoErrorAyR& orig);
    virtual ~CalculoErrorAyR();
    
    void calculaErrorRelativo(double,double);
    void calculaErrorAbsoluto(double,double);
    
    double getErrorRel();
    double getErrorAbs();

private:
    double errorAbsoluto;
    double errorRelativo;
};

#endif /* CALCULOERRORAYR_H */

