#ifndef EX_05_GRAPH_H
#define EX_05_GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <stdexcept>

using namespace std;

class Graph {

private:
    vector<vector<int> > adj_matrix;
    map<string, int> vertex_map;
    map<int, string> reverse_map;
    int num_vertices;

public:
    Graph() : num_vertices(0) {};                             // Constructor.

    Graph(const Graph &g);                                    // Copy Constructor.

    Graph &operator=(const Graph &g);                         // Copy assignment operator.

    virtual ~Graph();                                         // Destructor.

    /**
     * Adding Vertex to the graph.
     * @param vertex - vertex to be add.
     */
    void add_vertex(const string &vertex);

    /**
     * Delete Vertex from graph.
     * @param vertex - vertex to be deleted.
     */
    void delete_vertex(const string &vertex);

    /**
     * Adding a directed and weighted edge to the graph.
     * @param start - string of source.
     * @param end - string of destination.
     * @param weight - integer for edge weight
     */
    void add_edge(const string &start, const string &end, int weight);

    /**
     * deleting a directed and weighted arc to the graph.
     * @param start - string of source.
     * @param end - string of destination.
     */
    void delete_edge(const string &start, const string &end);

    /**
     * Updating the weight of a given edge in the graph.
     * @param start - string of source.
     * @param end - string of destination.
     * @param newWeight - integer for new edge weight
     */
    void update_edge_weight(const string &start, const string &end, int newWeight);

    /**
     * Query the weight of a given edge in the graph.
     * @param start - string of source.
     * @param end - string of destination.
     * @return = integer of edge weight.
     */
    int get_edge_weight(const string &start, const string &end);

    /**
     * Query the identity of the nearest neighbors of a given vertex in the graph,
     * the vertices that can be reached in a single arc transition.
     * @param vertex - vertex for get his neighbors.
     * @return = vector with all vertices that can be reached in a single edge transition.
     */
    vector<string> get_neighbors(const string &vertex);

    /**
     * Finding the set of vertices connected to a given vertex,
     * that is, the set of vertices that can be reached in any number of steps.
     * @param vertex - vertex for get his connected.
     * @return = vector with all vertices that can be reached in any number of steps.
     */
    vector<string> get_connected(const string &vertex);

    /**
     * Get the number of vertices.
     * @return = integer with current number of vertices in graph.
     */
    int getNumVertices() const;

    /**
     * Printing to standard output all connected vertices of given vertex.
     * @param vertex - string with vertex to print his connected.
     */
    void printGraph(const string &vertex);

    /**
     * printing all graph vertices to file.
     * @param file - file to be printing.
     */
    void printGraph(ofstream &file);

};


#endif //EX_05_GRAPH_H
