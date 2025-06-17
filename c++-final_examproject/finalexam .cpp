#include <iostream>
using namespace std;

// Edge between vertices
struct Edge {
    int to;
    float weight;
};

// Vertex with dynamic edge array
struct Vertex {
    int id, edgeCount, edgeCapacity;
    Edge* edges;

    Vertex(int id_) : id(id_), edgeCount(0), edgeCapacity(0), edges(nullptr) {}
    ~Vertex() { delete[] edges; }

    void addEdge(int to, float weight) {
        if (edgeCount == edgeCapacity) {
            int cap = edgeCapacity == 0 ? 2 : edgeCapacity * 2;
            Edge* newEdges = new Edge[cap];
            for (int i = 0; i < edgeCount; ++i) newEdges[i] = edges[i];
            delete[] edges;
            edges = newEdges;
            edgeCapacity = cap;
        }
        edges[edgeCount++] = {to, weight};
    }

    void removeEdge(int to) {
        for (int i = 0; i < edgeCount; ++i)
            if (edges[i].to == to) {
                for (int j = i; j < edgeCount - 1; ++j)
                    edges[j] = edges[j + 1];
                --edgeCount;
                break;
            }
    }
};

// Base class for graphs
class GraphBase {
protected:
    Vertex** vertices;
    int vertexCount, vertexCapacity;

public:
    GraphBase() : vertices(nullptr), vertexCount(0), vertexCapacity(0) {}
    virtual ~GraphBase() {
        for (int i = 0; i < vertexCount; ++i) delete vertices[i];
        delete[] vertices;
    }

    virtual void addEdge(int from, int to, float weight) = 0;

    void addVertex(int id) {
        if (findVertex(id)) return;
        if (vertexCount == vertexCapacity) {
            int cap = vertexCapacity == 0 ? 2 : vertexCapacity * 2;
            Vertex** newVerts = new Vertex*[cap];
            for (int i = 0; i < vertexCount; ++i) newVerts[i] = vertices[i];
            delete[] vertices;
            vertices = newVerts;
            vertexCapacity = cap;
        }
        vertices[vertexCount++] = new Vertex(id);
    }

    void removeVertex(int id) {
        int idx = -1;
        for (int i = 0; i < vertexCount; ++i)
            if (vertices[i]->id == id) { idx = i; break; }
        if (idx == -1) return;
        delete vertices[idx];
        for (int i = idx; i < vertexCount - 1; ++i)
            vertices[i] = vertices[i + 1];
        --vertexCount;
        for (int i = 0; i < vertexCount; ++i)
            vertices[i]->removeEdge(id);
    }

    Vertex* findVertex(int id) {
        for (int i = 0; i < vertexCount; ++i)
            if (vertices[i]->id == id) return vertices[i];
        return nullptr;
    }

    void print() {
        for (int i = 0; i < vertexCount; ++i) {
            cout << "Vertex " << vertices[i]->id << ": ";
            for (int j = 0; j < vertices[i]->edgeCount; ++j)
                cout << "(" << vertices[i]->edges[j].to << ", " << vertices[i]->edges[j].weight << ") ";
            cout << "\n";
        }
    }
};

// Directed graph: edges go one way
class DirectedGraph : public GraphBase {
public:
    void addEdge(int from, int to, float weight) override {
        addVertex(from);
        addVertex(to);
        findVertex(from)->addEdge(to, weight);
    }
};

// Undirected, unweighted graph: edges go both ways, weight always 1
class UnweightedGraph : public GraphBase {
public:
    void addEdge(int from, int to, float) override {
        addVertex(from);
        addVertex(to);
        findVertex(from)->addEdge(to, 1.0f);
        findVertex(to)->addEdge(from, 1.0f);
    }
};

int main() {
    GraphBase* graphs[2];
    graphs[0] = new DirectedGraph();
    graphs[1] = new UnweightedGraph();

    // Directed graph
    graphs[0]->addEdge(1, 2, 3.5f);
    graphs[0]->addEdge(2, 3, 2.0f);
    graphs[0]->addEdge(1, 3, 1.5f);

    // Unweighted graph
    graphs[1]->addEdge(4, 5, 0.0f);
    graphs[1]->addEdge(5, 6, 0.0f);

    cout << "Directed Graph:\n";
    graphs[0]->print();

    cout << "\nUnweighted Graph:\n";
    graphs[1]->print();

    // Remove a vertex from directed graph
    graphs[0]->removeVertex(2);
    cout << "\nDirected Graph after removing vertex 2:\n";
    graphs[0]->print();

    delete graphs[0];
    delete graphs[1];
    return 0;
}
