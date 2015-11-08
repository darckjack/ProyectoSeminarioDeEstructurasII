#include "../include/client.h"

using namespace std;

Client::Client() {
	m_id = 500;
}

Client::~Client() {
	
}

void Client::makeFile() {
	Client aux;
	ofstream outFile(CLIENT_FILE, ios::app);
	int cont = 0;
	
    for (int i = 0; i < 100; ++i)
    {
        outFile.write((char*)&cont, sizeof(int));
        for (int j = 0; j < 4; ++j)
        {
            outFile.write((char*)&aux, sizeof(aux));
        }
    }

    outFile.close();
}

long int Client::hashing(Client aux) {
    m_dirBase = 0;


    m_dirBase = m_dirBase + (100 + aux.m_name[0]) + 
        			(aux.m_name[1] % 84645);

    m_dirBase = m_dirBase % 100;
    
    return m_dirBase;
}

void Client::addClient() {
	Client aux;
	long int pos = 0;
	long int auxNum = 0;
	long int auxNum2 = 0;
	int cont = 0;
	fstream outFile(CLIENT_FILE, ios::in | ios::out);
	
	cout << "Ingresa el nombre del cliente:" << endl;
	cin.getline(aux.m_name, 40);
	
	cout << "Ingresa el correo electronico del cliente:" << endl;
	cin.getline(aux.m_email, 35);
	
	cout << "Ingresa el telefono del cliente" << endl;
	cin.getline(aux.m_phone, 15);
	
	m_id++;
	
	aux.m_id = this->m_id;
	
	cout << "El identificador es: " << aux.m_id << endl;
	
	aux.m_dirBase = hashing(aux);
	
	cout << "La direccion base es: " << aux.m_dirBase << endl;
	
	pos = aux.m_dirBase * ((sizeof(aux) * 4) + sizeof(int));
	
	cout << "La posicion es: " << pos << endl;
	
	outFile.seekg(pos, ios::beg);
    outFile.read((char*)&cont, sizeof(int));
    
    if (cont == 4) {
    	cout << "No hay espacio para guardar el dato" << endl;
    } else {
    	auxNum = pos + (cont * sizeof(aux)) + sizeof(int);
        auxNum2 = auxNum;
        outFile.seekp(auxNum, ios::beg);
        outFile.write((char*)&aux, sizeof(aux));
        cont++;
        outFile.seekp(pos, ios::beg);
        outFile.write((char*)&cont, sizeof(int));
        cin.get();
    }
    
    outFile.close();
}

void Client::showClients() {
	Client aux;
	long int pos = 0;
	int cont = 0;

    ifstream inFile(CLIENT_FILE);

    if (!inFile.good())
    {
        cout << "No existe el archivo" << endl;
    } else {
        while(!inFile.eof()) {
            inFile.seekg(pos, ios::beg);
            inFile.read((char*)&cont, sizeof(int));
            if (cont == 0)
            {
                pos = pos + (4 * sizeof(aux)) + sizeof(int);
            } else {
                for (int i = 0; i < cont; ++i)
                {   
                    inFile.read((char*)&aux, sizeof(aux));
                    cout << "Nombre: " << aux.m_name << endl;
                    cout << "Correo electronico: " << aux.m_email << endl;
                    cout << "Telefono: " << aux.m_phone << endl;
                    cout << "Codigo: " << aux.m_id << endl;
                    cout << "Direccion base: " << aux.m_dirBase << endl;
                    cout << endl;
                }

                pos = pos + (4 * sizeof(aux)) + sizeof(int);
            }
        }
    }

    inFile.close();
}

void Client::updateClient(int id) {
	Client aux;
	long int pos = 0;
	long int auxPos = 0;
	int cont = 0;

    fstream inFile(CLIENT_FILE, ios::in | ios::out);

    if (!inFile.good())
    {
        cout << "No existe el archivo" << endl;
    } else {
        while(!inFile.eof()) {
            inFile.seekg(pos, ios::beg);
            inFile.read((char*)&cont, sizeof(int));
            if (cont == 0)
            {
                pos = pos + (4 * sizeof(aux)) + sizeof(int);
            } else {
                for (int i = 0; i < cont; i++)
                {   
                    auxPos = inFile.tellg();
                    inFile.read((char*)&aux, sizeof(aux));
                    if (aux.m_id == id) {
                        cout << "Ingresa el nuevo nombre del cliente:" << endl;
                    	cin.getline(aux.m_name, 40);
                    	
                    	cout << "Ingresa el nuevo correo electronico del cliente:" << endl;
                    	cin.getline(aux.m_email, 35);
                    	
                    	cout << "Ingresa el nuevo telefono del cliente" << endl;
                    	cin.getline(aux.m_phone, 15);
                    	inFile.seekp(auxPos, ios::beg);
                    }
                }

                pos = pos + (4 * sizeof(aux)) + sizeof(int);
            }
        }
    }

    inFile.close();
}

void Client::deleteClient(int id) {
	
}