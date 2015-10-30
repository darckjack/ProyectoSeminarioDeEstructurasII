#ifndef CLIENT_H
#define CLIENT_H

#define CLIENT_FILE "clients.dat"

#include <iostream>
#include <fstream>
#include <cstring>


class Client {
public:
	Client();
	~Client();
	void addClient();
	void showClients();
	void updateClient(int);
	void deleteClient(int);
	
	void makeFile();

	char m_name[40];
	char m_email[35];
	char m_phone[15];
	
	int m_id;
	long int m_dirBase;
	
	long int hashing(Client);
};

#endif