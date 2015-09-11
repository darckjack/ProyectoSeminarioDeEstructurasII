#include "../include/edge.h"

using namespace std;

Edge::Edge() {
    m_origin  = "";
    m_destiny = "";
    m_weight  = 0.0;
}

Edge::~Edge() {
    //dtor
}

void Edge::createEdge() {
    
    ofstream outFile;
    outFile.open("conexiones.dat",ios::out|ios::app);

    if(outFile.is_open()) {
        
        cout << "Pais de origen: ";
        cin >> m_origin;
        cout << endl;

        cin.ignore();
        cout << "Pais destino: ";
        cin >> m_destiny;
        cout << endl;

        cin.ignore();
        cout << "Costo de la conexion: ";
        cin >> m_weight;
        cout << endl;

        outFile << m_origin << " " << m_destiny << " " << m_weight << endl;
        
    } else {
        
        cout << "No se pudo abrir el archivo..." << endl;
    }

    outFile.close();
}

void Edge::createEdge(string origin) {
    ofstream outFile;
    outFile.open("conexiones.dat",ios::out|ios::app);

    if(outFile.is_open()) {
        
        m_origin = origin;
        
        cout << "Pais destino: ";
        cin >> m_destiny;
        cout << endl;

        cin.ignore();
        cout << "Costo de la conexion: ";
        cin >> m_weight;
        cout << endl;

        outFile << m_origin << " " << m_destiny << " " << m_weight << endl;
        
    } else {
        
        cout << "No se pudo abrir el archivo..." << endl;
    }

    outFile.close();
}

void Edge::showEdges() {
    
    ifstream inFile;
    inFile.open("conexiones.dat", ios::out | ios::in);

    if(inFile.is_open()) {
        
        inFile >> m_origin;

        while(!inFile.eof()) {
            inFile >> m_destiny >> m_weight;
            cout << "Origen: " << m_origin << endl;
            cout << "Destino: " << m_destiny << endl;
            cout << "Costo de la conexion: " << m_weight << endl;
            inFile >> m_origin;
        }
    } else {
        cout << endl << "Error..." << endl;
    }

    inFile.close();
    
}

void Edge::updateEdge() {
    
    string auxOrigin;
    string auxDestiny;
    float auxWeight;
    ofstream outFile;
    ifstream inFile;
    bool found = false;

    outFile.open("auxiliar.txt",ios::out);
    inFile.open("conexiones.dat",ios::in);

    if(outFile.is_open() and inFile.is_open()) {
        
        cout << "Introduzca el origen de la conexion a modificar: ";
        cin >> auxOrigin;

        inFile >> m_origin;

        while(!inFile.eof()) {
            inFile >> m_destiny >> m_weight;

            if(auxOrigin == m_origin) {
                found = true;

                cout << "Ingrese los nuevos datos de la conexion:" << endl;

                cout << "Destino: ";
                cin >> auxDestiny;

                cout << "Costo: ";
                cin >> auxWeight;

                outFile << m_origin << " " << auxDestiny << " " << auxWeight << endl;
                
            } else {
                outFile << m_origin << " " << m_destiny << " " << m_weight << endl;
            }
            
            inFile >> m_origin;
        }
    } else {
        
        cout << "No se pudo abrir el archivo..." << endl;
        cin.get();
    }

    if (found == false) {
        cout << endl << "Registro no existente..." << endl;
    }
    
    outFile.close();
    inFile.close();

    remove("conexiones.dat");
    rename("auxiliar.txt", "conexiones.dat");
}

void Edge::deleteEdge() {
    
    string auxOrigin;
    string auxDestiny;
    
    ifstream inFile;
    inFile.open("conexiones.dat", ios::in);

    ofstream outFile;
    outFile.open("auxiliar.txt", ios::out);

    if(inFile.fail()) {
        
        cout << "No se pudo abrir el archivo..." << endl;
        cin.get();
        
    } else {
        
        cout<< "Introduzca el origen de la conexion a eliminar: ";
        cin >> auxOrigin;
        
        cout << "Introduzca el destino de la conexion a eliminar";
        cin >> auxDestiny;

        inFile >> m_origin;

        while(!inFile.eof()) {
            
            inFile >> m_destiny >> m_weight;

            if(auxOrigin == m_origin and auxDestiny == m_destiny) {
                
                cout << endl << "El registro se ha eliminado...";
                cin.get();
            } else {
                outFile << m_origin << " " << m_destiny << " " << m_weight << endl;
            }
            
            inFile >> m_origin;
        }
    }

    outFile.close();
    inFile.close();

    remove("conexiones.dat");
    rename("auxiliar.txt", "conexiones.dat");
}

void Edge::deleteEdgesOr(string origin) {
    
    ifstream inFile;
    inFile.open("conexiones.dat", ios::in);

    ofstream outFile;
    outFile.open("auxiliar.txt", ios::out);

    if(inFile.fail()) {
        
        cout << "No se pudo abrir el archivo..." << endl;
        cin.get();
        
    } else {

        inFile >> m_origin;

        while(!inFile.eof()) {
            
            inFile >> m_destiny >> m_weight;

            if(origin != m_origin) {
                
                outFile << m_origin << " " << m_destiny << " " << m_weight << endl;
                
            }
            
            inFile >> m_origin;
        }
    }

    outFile.close();
    inFile.close();

    remove("conexiones.dat");
    rename("auxiliar.txt", "conexiones.dat");
}

void Edge::deleteEdgesDes(string destiny) {
    
    ifstream inFile;
    inFile.open("conexiones.dat", ios::in);

    ofstream outFile;
    outFile.open("auxiliar.txt", ios::out);

    if(inFile.fail()) {
        
        cout << "No se pudo abrir el archivo..." << endl;
        cin.get();
        
    } else {
        
        inFile >> m_origin;

        while(!inFile.eof()) {
            
            inFile >> m_destiny >> m_weight;

            if(destiny != m_destiny) {
                
                outFile << m_origin << " " << m_destiny << " " << m_weight << endl;
                
            }
            
            inFile >> m_origin;
        }
    }

    outFile.close();
    inFile.close();

    remove("conexiones.dat");
    rename("auxiliar.txt", "conexiones.dat");
}

void Edge::searchEdge() {
    
    string auxOrigin;
    string auxDestiny;
    
    ifstream inFile;
    inFile.open("conexiones.dat", ios::in);

    if(inFile.fail()) {
        
        cout << "No se pudo abrir el archivo..." << endl;
        cin.get();
        
    } else {
        
        cout<< "Introduzca el origen de la conexion a eliminar: ";
        cin >> auxOrigin;
        
        cout << "Introduzca el destino de la conexion a eliminar";
        cin >> auxDestiny;

        inFile >> m_origin;

        while(!inFile.eof()) {
            
            inFile >> m_destiny >> m_weight;

            if(auxOrigin == m_origin and auxDestiny == m_destiny) {
                
                cout << "Origen: " << m_origin << endl;
                cout << "Destino: " << m_destiny << endl;
                cout << "Costo de la conexion: " << m_weight << endl;
            }
            
            inFile >> m_origin;
        }
    }
    inFile.close();
}