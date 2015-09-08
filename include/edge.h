#ifndef EDGE_H
#define EDGE_H

#include <string>

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
	void showEdges();
	void updateEdge();
	void deleteEdge();

private:
	std::string m_origin;
	std::string m_destiny;
	float		m_weight;

}

#endif // EDGE_H