/* 
 * File:   Menu.h
 * Author: sauron
 *
 * Created on April 8, 2019, 10:48 PM
 */

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    
    void despliegaMenu();
    void opcionSeleccionada(int);
private:
    int opcion=0;
};

#endif /* MENU_H */

