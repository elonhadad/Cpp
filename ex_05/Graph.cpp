//
// Created by ELON HADAD on 19/01/2023.
//

#include "Graph.h"

Graph::Graph(const Graph &g) {
    this->num_vertices = g.num_vertices;
}

Graph &Graph::operator=(const Graph &g) {
    if (this != &g) {
        this->num_vertices = g.num_vertices;
    }
    return *this;
}

void Graph::add_vertex(const string &vertex) {
    if (vertex_map.count(vertex) > 0) {
        return;
    }

    num_vertices++;
    vertex_map[vertex] = num_vertices - 1;
    reverse_map[num_vertices - 1] = vertex;
    adj_matrix.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i].resize(num_vertices);
    }
}

void Graph::delete_vertex(const string &vertex) {
    if (vertex_map.count(vertex) == 0) {
        throw invalid_argument("Vertex does not exist");
    }

    int index = vertex_map[vertex];
    vertex_map.erase(vertex);
    reverse_map.erase(index);
    num_vertices--;
    adj_matrix.erase(adj_matrix.begin() + index);
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i].erase(adj_matrix[i].begin() + index);
    }
}

void Graph::add_edge(const string &start, const string &end, int weight) {
    if (vertex_map.count(start) == 0 || vertex_map.count(end) == 0) {
        throw invalid_argument("One or both of the vertices do not exist");
    }

    int start_index = vertex_map[start];
    int end_index = vertex_map[end];
    adj_matrix[start_index][end_index] = weight;
}

void Graph::delete_edge(const string &start, const string &end) {
    if (vertex_map.count(start) == 0 || vertex_map.count(end) == 0) {
        throw invalid_argument("One or both of the vertices do not exist");
    }

    int start_index = vertex_map[start];
    int end_index = vertex_map[end];
    adj_matrix[start_index][end_index] = 0;
}

void Graph::update_edge_weight(const string &start, const string &end, int newWeight) {
    if (vertex_map.count(start) == 0 || vertex_map.count(end) == 0) {
        throw invalid_argument("One or both of the vertices do not exist");
    }

    int start_index = vertex_map[start];
    int end_index = vertex_map[end];
    adj_matrix[start_index][end_index] = newWeight;
}

int Graph::get_edge_weight(const string &start, const string &end) {
    if (vertex_map.count(start) == 0 || vertex_map.count(end) == 0) {
        throw invalid_argument("One or both of the vertices do not exist");
    }

    int start_index = vertex_map[start];
    int end_index = vertex_map[end];
    return adj_matrix[start_index][end_index];
}

vector<string> Graph::get_neighbors(const string &vertex) {
    if (vertex_map.count(vertex) == 0) {
        throw invalid_argument("Vertex does not exist");
    }

    int index = vertex_map[vertex];
    vector<string> neighbors;
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[index][i] != 0) {
            neighbors.push_back(reverse_map[i]);
        }
    }
    return neighbors;
}

vector<string> Graph::get_connected(const string &vertex) {
    vector<string> connected_vertices;
    if (vertex_map.count(vertex) == 0) {
        cout << vertex + " does not exist in the current network" << endl;
        cout << "USAGE: <node> or ‘exit’ to terminate";
        return connected_vertices;
    }
    vector<bool> visited(num_vertices, false);
    int index = vertex_map[vertex];
    queue<int> q;
    q.push(index);
    visited[index] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        connected_vertices.push_back(reverse_map[current]);
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return connected_vertices;
}

void Graph::printGraph(ofstream &file) {
    for (int i = 0; i < num_vertices; i++) {
        file << reverse_map[i] << " : ";
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j] != 0) {
                file << reverse_map[j] << " ";
            }
        }
        file << "\n";
    }
}

void Graph::printGraph(const string &vertex) {
    int count = 0;
    vector<string> connected = get_connected(vertex);
    if (connected.empty())
        return;
    cout << connected[0];
    for (int i = 1; i < num_vertices; i++) {
        if (connected.size() > 1)
            cout << "\t" << connected[i];
        else
            count++;

        if (count == num_vertices - 1)
            cout << " : no outbound travel";
    }
}

int Graph::getNumVertices() const {
    return num_vertices;
}

Graph::~Graph() = default;
