#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include<string>
#include<sstream>

class Graph
{
public:
	// constructor - create a graph from a file with the given name
	Graph(char* fname);
	// destructor
	~Graph();
	// return the number of vertices
	int get_num_v() const { return num_v; }
	// return the weight between the given source & dest vertices
	// weight = 0.0 means no edge
	double get_edge(int source, int dest) const;
private:
	// the graph
	int num_v; // number of vertices
	bool directed; // direction
	double** edges; // 2-D adjacency matrix holding weighets for edges
	// from num_v vertices to num_v vertices
};

Graph::Graph(char* fname) {
	std::ifstream fin(fname);
	if (!fin) {
		std::cout << "File Handling Error: " << fname << std::endl;
		return;
	}
	std::string number;
	getline(fin, number);
	std::stringstream geek(number);
	geek >> num_v;
	std::string dir;
	getline(fin, dir);
	if (dir == "u") directed = false;
	else directed = true;
	edges = new double* [num_v];
	for (int i = 0; i < num_v; i++) {
		if (directed)
			edges[i] = new double[num_v];
		else
			edges[i] = new double[i];
		for (int j = 0; j < num_v; j++)
			edges[i][j] = 0.0;
	}
	std::string information;
	std::string source, destination, weight;
	int sourceInt, destinationInt;
	double weightFloat;
	while (getline(fin, information)) {
		std::istringstream sin(information);
		sin >> source;
		sin >> destination;
		sin >> weight;
		std::stringstream check(source);
		check >> sourceInt;
		std::stringstream check2(destination);
		check2 >> destinationInt;
		std::stringstream check3(weight);
		check3 >> weightFloat;
		edges[sourceInt][destinationInt] = weightFloat;
		if (directed == false) {
			if (destinationInt > sourceInt) edges[destinationInt][sourceInt] = weightFloat;
			else edges[sourceInt][destinationInt] = weightFloat;
		}
		else edges[sourceInt][destinationInt] = weightFloat;
	}
	fin.close();
}

Graph::~Graph() {
	for (int i = 0; i < num_v; i++)
		delete[] edges[i];
	delete[] edges;
}

double Graph::get_edge(int source, int dest)const {
	if (source < 0 || dest < 0 || source >= num_v || dest >= num_v) {
		std::cout << "Unable to return edge" << std::endl;
		return -1.0;
	}
	if (directed)
		return edges[source][dest];
	if (dest > source)
		return edges[dest][source];
	return edges[source][dest];
}

#endif //GRAPH_H