#ifndef EDGE_H
#define EDGE_H

#define DELIMITER '|'

#include <iostream>
#include <string>
#include <fstream>

class Edge {
public:
	// Constructor and Destructor
	Edge();
	~Edge();

	// getters & setters
	std::string getOrigin()  { return m_origin; }
	std::string getDestiny() { return m_destiny; }
	float		getWeight()  { return m_weight; }
	
	void setOrigin(std::string val)  { m_origin = val; }
	void setDestiny(std::string val) { m_destiny = val; }
	void setWeight(float val) 		 { m_weight = val; }
	
	// CRUD Functions
	void createEdge();
	void createEdge(std::string);
	void showEdges();
	void updateEdge();
	void deleteEdge();
	void deleteEdgesOr(std::string);
	void deleteEdgesDes(std::string);
	void searchEdge();

private:
	std::string m_origin;
	std::string m_destiny;
	float		m_weight;

};

#endif // EDGE_H