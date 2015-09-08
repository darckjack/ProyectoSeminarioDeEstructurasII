#include "../include/destiny.h"

using namespace std;

Destiny::Destiny() {
    m_id            = 0;
    m_aviability    = true;
    m_type          = true;
    m_tax           = false;
}

/*
Destiny::Destiny(string name, bool aviability, bool type, bool tax) {
    m_id            = 0;
    m_name          = name;
    m_aviability    = aviability;
    m_type          = type;
    m_tax           = tax;
}
*/

Destiny::~Destiny() {
    //dtor
}

void Destiny::createDestiny() {
    char trueOrFalse;

    ofstream outFile("destinos.dat", ios::app);

    cout << "Ingrese el nombre del destino:" << endl;
    cin.getline(m_name, 30);

    cout << "El destino esta disponible? (s/n)" << endl;
    cin >> trueOrFalse;
    if (trueOrFalse == 's') {
        m_aviability = true;
    } else {
        m_aviability = false;
    }

    cout << "El destino es un pais de entrada? (s/n)" << endl;
    cin >> trueOrFalse;
    if (trueOrFalse == 's') {
        m_type = true;
    } else {
        m_type = false;
    }

    cout << "El destino requiere impuesto? (s/n)" << endl;
    cin >> trueOrFalse;
    if (trueOrFalse == 's') {
        m_tax = true;
    } else {
        m_tax = false;
    }
    cin.ignore();

    m_id = m_id + 1;

    sizeName = strlen(m_name);

    outFile.write((char*)&m_id, sizeof(int));
    outFile.write((char*)&sizeName, sizeof(int));
    outFile.write((char*)&m_name, sizeName);
    outFile.write((char*)&m_aviability,sizeof(bool));
    outFile.write((char*)&m_type, sizeof(bool));
    outFile.write((char*)&m_tax, sizeof(bool));
    outFile.close();
}

void Destiny::readDestiny() {
    ifstream infile("destinos.dat");
    if(!infile.good())
        cout<<"No existe el archivo"<<endl<<endl;
    else {
        while(!infile.eof()) {
            infile.read((char*)&m_id, sizeof(int));

            infile.read((char*)&sizeName, sizeof(int));
            infile.read((char*)&m_name, sizeName);
            m_name[sizeName]='\0';

            infile.read((char*)&m_aviability, sizeof(bool));

            infile.read((char*)&m_type, sizeof(bool));

            infile.read((char*)&m_tax, sizeof(bool));

            if(infile.eof()) {
                break;
            }

            cout << "Codigo: " << m_id << endl;
            cout << "Nombre: " << m_name << endl;

            if (m_aviability == true) {

                cout << "El destino esta disponible" << endl;

            } else {

                cout << "El destino no esta disponible" << endl;

            }

            if (m_type == true) {

                cout << "El pais es un pais de entrada" << endl;

            } else {

                cout << "El destino no es un pais de entrada" << endl;

            }

            if (m_tax == true) {

                cout << "El destino requiere un impuesto extra" << endl;

            } else {

                cout << "el destino no requiere un impuesto extra" << endl;

            }

        }
    }
    infile.close();
}

void Destiny::updateDestiny(unsigned int id) {

    char trueOrFalse;
    ofstream outFile("temporal.txt",ios::app);
    ifstream infile("destinos.dat");

    if(!infile.good())
        cout<<"No existe el archivo"<<endl<<endl;
    else {
        while(!infile.eof()) {
            infile.read((char*)&m_id, sizeof(int));

            infile.read((char*)&sizeName, sizeof(int));
            infile.read((char*)&m_name, sizeName);
            m_name[sizeName]='\0';

            infile.read((char*)&m_aviability, sizeof(bool));


            infile.read((char*)&m_type, sizeof(bool));

            infile.read((char*)&m_tax, sizeof(bool));
            if(infile.eof())
                break;

            if(m_id != id) {
                sizeName = strlen(m_name);

                outFile.write((char*)&m_id, sizeof(int));
                outFile.write((char*)&sizeName, sizeof(int));
                outFile.write((char*)&m_name, sizeName);
                outFile.write((char*)&m_aviability, sizeof(bool));
                outFile.write((char*)&m_type, sizeof(bool));
                outFile.write((char*)&m_tax, sizeof(bool));
                if(infile.eof())
                    break;
            } else {
                cout << "Ingrese el nombre del destino:" << endl;
                cin.ignore();
                cin >> m_name;

                cout << "El destino esta disponible? (s/n)" << endl;
                cin >> trueOrFalse;
                if (trueOrFalse == 's') {
                    m_aviability = true;
                } else {
                    m_aviability = false;
                }

                cout << "El destino es un pais de entrada? (s/n)" << endl;
                cin >> trueOrFalse;
                if (trueOrFalse == 's') {
                    m_type = true;
                } else {
                    m_type = false;
                }

                cout << "El destino requiere impuesto? (s/n)" << endl;
                cin >> trueOrFalse;
                if (trueOrFalse == 's') {
                    m_tax = true;
                } else {
                    m_tax = false;
                }

                sizeName = strlen(m_name);

                outFile.write((char*)&m_id, sizeof(int));
                outFile.write((char*)&sizeName, sizeof(int));
                outFile.write((char*)&m_name, sizeName);
                outFile.write((char*)&m_aviability, sizeof(bool));
                outFile.write((char*)&m_type, sizeof(bool));
                outFile.write((char*)&m_tax, sizeof(bool));

                if(infile.eof())
                    break;
            }
            if(infile.eof()) {
                break;
            }
        }
        outFile.close();
        infile.close();
        remove("destinos.dat");
        rename( "temporal.txt" , "destinos.dat" );
        cout << "Los cambios se han aplicado" << endl << endl;
    }
}


void Destiny::deleteDestiny(unsigned int id) {
    ofstream outFile("temporal.txt",ios::app);
    ifstream infile("destinos.dat");

    if(!infile.good())
        cout<<"No existe el archivo"<<endl<<endl;
    else {
        while(!infile.eof()) {
            infile.read((char*)&m_id, sizeof(int));

            infile.read((char*)&sizeName, sizeof(int));
            infile.read((char*)&m_name, sizeName);
            m_name[sizeName]='\0';

            infile.read((char*)&m_aviability, sizeof(bool));


            infile.read((char*)&m_type, sizeof(bool));

            infile.read((char*)&m_tax, sizeof(bool));
            if(infile.eof())
                break;

            if(m_id != id) {
                sizeName = strlen(m_name);

                outFile.write((char*)&m_id, sizeof(int));
                outFile.write((char*)&sizeName, sizeof(int));
                outFile.write((char*)&m_name, sizeName);
                outFile.write((char*)&m_aviability, sizeof(bool));
                outFile.write((char*)&m_type, sizeof(bool));
                outFile.write((char*)&m_tax, sizeof(bool));
                if(infile.eof())
                    break;
            }

            outFile.close();
            infile.close();
            remove("destinos.dat");
            rename( "temporal.txt" , "destinos.dat" );
            cout << "Los cambios se han aplicado" << endl << endl;
        }
    }
}

void Destiny::searchDestinyById(unsigned int id) {
    ifstream infile("destinos.dat");
    if(!infile.good())
        cout<<"No existe el archivo"<<endl<<endl;
    else {
        while(!infile.eof()) {
            infile.read((char*)&m_id, sizeof(int));

            infile.read((char*)&sizeName, sizeof(int));
            infile.read((char*)&m_name, sizeName);
            m_name[sizeName]='\0';

            infile.read((char*)&m_aviability, sizeof(bool));


            infile.read((char*)&m_type, sizeof(bool));

            infile.read((char*)&m_tax, sizeof(bool));

            if(infile.eof()) {
                break;
            }

            if (m_id == id) {
                cout << "Codigo: " << m_id << endl;
                cout << "Nombre: " << m_name << endl;

                if (m_aviability == true) {

                    cout << "El destino esta disponible" << endl;

                } else {

                    cout << "El destino no esta disponible" << endl;

                }

                if (m_type == true) {

                    cout << "El pais es un pais de entrada" << endl;

                } else {

                    cout << "El destino no es un pais de entrada" << endl;

                }

                if (m_tax == true) {

                    cout << "El destino requiere un impuesto extra" << endl;

                } else {

                    cout << "el destino no requiere un impuesto extra" << endl;

                }
            }

        }
    }
    infile.close();
}


void Destiny::searchDestinyByType(bool type) {
    ifstream infile("destinos.dat");
    if(!infile.good())
        cout<<"No existe el archivo"<<endl<<endl;
    else {
        while(!infile.eof()) {
            infile.read((char*)&m_id, sizeof(int));

            infile.read((char*)&sizeName, sizeof(int));
            infile.read((char*)&m_name, sizeName);
            m_name[sizeName]='\0';

            infile.read((char*)&m_aviability, sizeof(bool));


            infile.read((char*)&m_type, sizeof(bool));

            infile.read((char*)&m_tax, sizeof(bool));

            if(infile.eof()) {
                break;
            }

            if (m_type == type) {
                cout << "Codigo: " << m_id << endl;
                cout << "Nombre: " << m_name << endl;

                if (m_aviability == true) {

                    cout << "El destino esta disponible" << endl;

                } else {

                    cout << "El destino no esta disponible" << endl;

                }

                if (m_type == true) {

                    cout << "El pais es un pais de entrada" << endl;

                } else {

                    cout << "El destino no es un pais de entrada" << endl;

                }

                if (m_tax == true) {

                    cout << "El destino requiere un impuesto extra" << endl;

                } else {

                    cout << "el destino no requiere un impuesto extra" << endl;

                }
            }

        }
    }
    infile.close();
}


void Destiny::searchDestinyByAviability(bool aviability) {
    ifstream infile("destinos.dat");
    if(!infile.good())
        cout<<"No existe el archivo"<<endl<<endl;
    else {
        while(!infile.eof()) {
            infile.read((char*)&m_id, sizeof(int));

            infile.read((char*)&sizeName, sizeof(int));
            infile.read((char*)&m_name, sizeName);
            m_name[sizeName]='\0';

            infile.read((char*)&m_aviability, sizeof(bool));


            infile.read((char*)&m_type, sizeof(bool));

            infile.read((char*)&m_tax, sizeof(bool));

            if(infile.eof()) {
                break;
            }

            if (m_aviability == aviability) {
                cout << "Codigo: " << m_id << endl;
                cout << "Nombre: " << m_name << endl;

                if (m_aviability == true) {

                    cout << "El destino esta disponible" << endl;

                } else {

                    cout << "El destino no esta disponible" << endl;

                }

                if (m_type == true) {

                    cout << "El pais es un pais de entrada" << endl;

                } else {

                    cout << "El destino no es un pais de entrada" << endl;

                }

                if (m_tax == true) {

                    cout << "El destino requiere un impuesto extra" << endl;

                } else {

                    cout << "el destino no requiere un impuesto extra" << endl;

                }
            }

        }
    }
    infile.close();
}