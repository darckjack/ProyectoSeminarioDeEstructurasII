#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

#include <iostream>
#include "include/destiny.h"
#include "include/edge.h"

using namespace std;

int main() {
    Destiny des;
    Edge ed;
    int opc;
    int aux;
    string auxOr;
    char trueOrFalse;
    bool aux2;
    do {
        system(CLEAR);
        cout << "Destinos" << endl << endl;
        cout << "1.-Agregar un destino" << endl;
        cout << "2.-Mostrar destinos" << endl;
        cout << "3.-Modificar un destino" << endl;
        cout << "4.-Eliminar un destino" << endl;
        cout << "5.-Buscar un destino por codigo" << endl;
        cout << "6.-Buscar un destino por tipo" << endl;
        cout << "7.-Buscar un destino por disponibilidad" << endl;
        cout << "8.-Crear conexion" << endl;
        cout << "9.-Buscar una conexion" << endl;
        cout << "10.-Mostrar conexiones" << endl;
        cout << "11.-Modificar una conexion" << endl;
        cout << "12.-Eliminar una conexion" << endl;
        cout << "13.-Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        cin.ignore();
        system(CLEAR);

        switch(opc){
        case 1:
            des.createDestiny();
            cout << "Crear conexiones? s/n" << endl;
            cin >> trueOrFalse;
            
            if (trueOrFalse == 's' or trueOrFalse == 'S') {
                ed.createEdge(des.m_name);
            }
            
            break;

        case 2:
            des.readDestiny();
            cin.get();
            break;

        case 3:
            cout << "Ingrese el codigo del pais a modificar:" << endl;
            cin >> aux;
            des.updateDestiny(aux);
            break;

        case 4:
            cout << "Ingrese el codigo del pais a eliminar:" << endl;
            cin >> aux;
            des.searchDestinyById(aux);
            auxOr = des.m_name;
            des.deleteDestiny(aux);
            ed.deleteEdgesOr(auxOr);
            ed.deleteEdgesDes(auxOr);
            break;

        case 5:
            cout << "Ingrese el codigo del pais a mostrar:" << endl;
            cin >> aux;
            des.searchDestinyById(aux);
            cin.get();
            break;

        case 6:
            cout << "Mostrar los paises disponibles o no disponibles? s/n" << endl;
            cin >> trueOrFalse;
            if (trueOrFalse == 's' or trueOrFalse == 'S') {
                aux2 = true;
                des.searchDestinyByAviability(aux2);
            } else {
                aux2 = false;
                des.searchDestinyByAviability(aux2);
            }
            cin.get();
            break;

        case 7:
            cout << "Mostrar los paises de entrada o no de entrada? s/n" << endl;
            cin >> trueOrFalse;
            if (trueOrFalse == 's' or trueOrFalse == 'S') {
                aux2 = true;
                des.searchDestinyByType(aux2);
            } else {
                aux2 = false;
                des.searchDestinyByType(aux2);
            }
            cin.get();
            break;
        
        case 8:
            ed.createEdge();
            break;
            
        case 9:
            ed.searchEdge();
            cin.get();
            break;
            
        case 10:
            ed.showEdges();
            cin.get();
            break;
            
        case 11:
            ed.updateEdge();
            cin.get();
            break;
            
        case 12:
            ed.deleteEdge();
            cin.get();
            break;
        
        case 13:
            break;

        default:
            cout << "Opcion incorrecta..." << endl;
        }
    }while(opc != 13);

    return 0;
}
