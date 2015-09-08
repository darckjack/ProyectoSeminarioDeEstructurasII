#ifndef DESTINY_H
#define DESTINY_H

#include <iostream>
#include <cstring>
#include <fstream>

class Destiny
{
    public:
        Destiny();
        //Destiny(std::string, bool, bool, bool);
        ~Destiny();
        /*
        unsigned int getId() { return m_id; }
        std::string getName() { return m_name; }
        bool getAviability() { return m_aviability; }
        bool getType() { return m_type; }
        bool getTax() { return m_tax; }

        void setName(std::string val) { m_name = val; }
        void setAviability(bool val) { m_aviability = val; }
        void setType(bool val) { m_type = val; }
        void setTax(bool val) { m_tax = val; }
        */

        void createDestiny(); // capturar
        void readDestiny(); // mostrar o imprimir
        void updateDestiny(unsigned int); // modificar
        void deleteDestiny(unsigned int); // eliminar
        void searchDestinyById(unsigned int); // buscar por codigo
        void searchDestinyByType(bool); // buscar por nombre
        void searchDestinyByAviability(bool); // buscar por disponibilidad


    protected:
    private:
        unsigned int m_id;
        char m_name[30];
        bool m_aviability;
        bool m_type;
        bool m_tax;
        int sizeName;

};

#endif // DESTINY_H