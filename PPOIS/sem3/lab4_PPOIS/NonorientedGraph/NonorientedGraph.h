#ifndef NONORIENTED_GRAPH_H
#define NONORIENTED_GRAPH_H

#include <tuple>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include "BiVertexIterator.h"
#include "BiEdgeIterator.h"

using namespace std;

template<class T>
class NonorientedGraph {
public:
    using valueType = T;
    using vertexIdx = int;
    using edgeIdx = int;
    using edgeType = tuple<edgeIdx, vertexIdx, vertexIdx>;

private:
    vector<pair<vertexIdx, valueType>> vertices;
    vector<tuple<edgeIdx, vertexIdx, vertexIdx>> edges;
    vector<vector<int>> incidenceMatrix;
    int vertexCounter;
    int edgesCounter;

public:
    NonorientedGraph() : vertexCounter(0), edgesCounter(0) {}

    NonorientedGraph(const NonorientedGraph& other) {
        this->vertices = other.vertices;
        this->edges = other.edges;
        this->incidenceMatrix = other.incidenceMatrix;
        this->vertexCounter = other.vertexCounter;
        this->edgesCounter = other.edgesCounter;
    }

    vector<tuple<edgeIdx, vertexIdx, vertexIdx>>& GetEdges() {
        return edges;
    }

    vector<pair<vertexIdx, valueType>>& GetVertices() {
        return vertices;
    }

    bool IsEmpty() {
        return ((vertices.size() == 0) && (edges.size() == 0));
    }

    void ClearGraph() {
        vertices.clear();
        edges.clear();
        incidenceMatrix.clear();
        vertexCounter = 0;
        edgesCounter = 0;
    }

    bool HasVertex(valueType value) {
        for (BiVertexIterator<valueType> it(vertices.begin()); it != BiVertexIterator<valueType>(vertices.end()); ++it) {
            if (it->second == value) {
                return true;
            }
        }
        return false;
    }

    bool HasVertexByIdx(vertexIdx findIdx) {
        for (BiVertexIterator<valueType> it(vertices.begin()); it != BiVertexIterator<valueType>(vertices.end()); ++it) {
            if (it->first == findIdx) {
                return true;
            }
        }
        return false;
    }

    bool HasEdge(vertexIdx firstVertex, vertexIdx secondVertex) {
        for (BiEdgeIterator<valueType> it(edges.begin()); it != BiEdgeIterator<valueType>(edges.end()); ++it) {
            auto edgeTuple = *it;
            if ((get<1>(edgeTuple) == firstVertex && get<2>(edgeTuple) == secondVertex) ||
                (get<1>(edgeTuple) == secondVertex && get<2>(edgeTuple) == firstVertex)) {
                return true;
            }
        }
        return false;
    }

    bool HasEdgeByIdx(edgeIdx findEdge) {
        for (BiEdgeIterator<valueType> it(edges.begin()); it != BiEdgeIterator<valueType>(edges.end()); ++it) {
            auto edgeTuple = *it;
            if (get<0>(edgeTuple) == findEdge) {
                return true;
            }
        }
        return false;
    }

    void AddVertex(valueType value) {
        try {
            if (HasVertex(value)) {
                throw runtime_error("Graph already contains vertex with value <" + to_string(value) + ">");
                return;
            }
            vertexCounter++;
            vertices.push_back(make_pair(vertexCounter, value));
            for (auto& row : incidenceMatrix) {
                row.push_back(0);
            }
            incidenceMatrix.push_back(vector<int>(vertices.size(), 0));
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
        }
    }


    void DeleteVertex(vertexIdx deleteIdx) {
        try {
            if (!HasVertexByIdx(deleteIdx)) {
                throw runtime_error("Graph has no vertex with idx <" + to_string(deleteIdx) + ">");
                return;
            }
            for (auto it = edges.begin(); it != edges.end(); ) {
                if (get<1>(*it) == deleteIdx || get<2>(*it) == deleteIdx) {
                    vertexIdx firstVertex = get<1>(*it);
                    vertexIdx secondVertex = get<2>(*it);
                    DeleteEdge(firstVertex, secondVertex);
                    it = edges.begin();

                }
                else {
                    ++it;
                }
            }
            incidenceMatrix.erase(incidenceMatrix.begin() + deleteIdx - 1);

            vertices.erase(vertices.begin() + deleteIdx - 1);
            vertexCounter--;
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
        }
    }


    void AddEdge(vertexIdx firstVertex, vertexIdx secondVertex) {
        try {
            if (HasEdge(firstVertex, secondVertex)) {
                throw runtime_error("Graph already contains edge between vertices " + to_string(firstVertex) + " & " + to_string(secondVertex));
            }
            edgesCounter++;
            edges.push_back(make_tuple(edgesCounter, firstVertex, secondVertex));

            for (auto& row : incidenceMatrix) {
                row.push_back(0);
            }

            incidenceMatrix.push_back(vector<int>(edgesCounter, 0));

            if (firstVertex == secondVertex) {
                incidenceMatrix[firstVertex - 1][edgesCounter - 1] = 2;
            }
            else {
                incidenceMatrix[firstVertex - 1][edgesCounter - 1] = 1;
                incidenceMatrix[secondVertex - 1][edgesCounter - 1] = 1;
            }
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
        }
    }

    void DeleteEdge(vertexIdx firstVertex, vertexIdx secondVertex) {
        try {
            if (!HasEdge(firstVertex, secondVertex)) {
                throw runtime_error("Graph has no edge between vertices " + to_string(firstVertex) + " & " + to_string(secondVertex));
            }
            for (auto it = edges.begin(); it != edges.end(); ) {
                auto edgeTuple = *it;

                if ((get<1>(edgeTuple) == firstVertex  && get<2>(edgeTuple) == secondVertex ) ||
                    (get<1>(edgeTuple) == secondVertex  && get<2>(edgeTuple) == firstVertex )) {

                    it = edges.erase(it);
                    edgesCounter--;

                    for (auto& row : incidenceMatrix) {
                        row.erase(row.begin() + (it - edges.begin()));
                    }
                }
                else {
                    ++it;
                }
            }
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
        }
    }

    void DeleteEdgeByIdx(edgeIdx deleteIdx) {
        try {
            if (!HasEdgeByIdx(deleteIdx)) {
                throw runtime_error("Graph has no edge with idx " + to_string(deleteIdx));
            }
            for (auto it = edges.begin(); it != edges.end(); ) {
                auto edgeTuple = *it;

                if (get<0>(edgeTuple) == deleteIdx ) {

                    it = edges.erase(it);
                    edgesCounter--;

                    for (auto& row : incidenceMatrix) {
                        row.erase(row.begin() + (it - edges.begin()));
                    }
                }
                else {
                    ++it;
                }
            }
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
        }
    }

    int GetVertexCount() {
        return vertexCounter;
    }

    int GetEdgesCount() {
        return edgesCounter;
    }

    int CalculateVertexDegree(vertexIdx calcVertex) {
        try {
            if (!HasVertexByIdx(calcVertex)) {
                throw runtime_error("Graph has no vertex with idx <" + to_string(calcVertex) + ">");
            }

            int degree = 0;
            for (auto it = edges.begin(); it != edges.end(); ++it) {
                auto edgeTuple = *it;
                if (get<1>(edgeTuple) == calcVertex || get<2>(edgeTuple) == calcVertex) {
                    degree++;
                }
            }
            return degree;
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
            return -1;
        }
    }

    int CalculateEdgeDegree(edgeIdx calcEdge) {
        try {
            calcEdge -= 1;
            if (!HasEdgeByIdx(calcEdge)) {
                throw runtime_error("Graph has no edge with idx " + to_string(calcEdge));
            }
            for (BiEdgeIterator<valueType> it(edges.begin()); it != BiEdgeIterator<valueType>(edges.end()); ++it) {
                auto edgeTuple = *it;
                if (get<0>(edgeTuple) == calcEdge) {
                    if (get<1>(edgeTuple) == get<2>(edgeTuple))
                        return 1;
                    else
                        return 2;
                }
            }
        }
        catch (const runtime_error& exception) {
            cerr << "Error: " << exception.what() << '\n';
            return -1;
        }
    }

    void PrintIncidenceMatrix() {
        cout << "   ";
        for (int i = 0; i < edgesCounter; ++i) {
            cout << "e" << get<0>(edges[i])  << "   ";
        }
        cout << endl;

        for (int i = 0; i < vertices.size(); ++i) {
            cout << "v" << vertices[i].first << "  ";
            for (int j = 0; j < edgesCounter; ++j) {
                cout << incidenceMatrix[i][j] << "    ";
            }
            cout << endl;
        }
    }

    NonorientedGraph& operator = (NonorientedGraph& other) {
        if (this != &other) {
            this->vertices = other.vertices;
            this->edges = other.edges;
            this->incidenceMatrix = other.incidenceMatrix;
            this->vertexCounter = other.vertexCounter;
            this->edgesCounter = other.vertexCounter;
        }
        return *this;
    }

    bool operator == (NonorientedGraph& other) {
        return vertices == other.vertices && edges == other.edges && incidenceMatrix == other.incidenceMatrix;
    }

    bool operator != (NonorientedGraph& other)  {
        return !(*this == other);
    }

    bool operator < (NonorientedGraph& other)  {
        if (vertexCounter != other.vertexCounter)
            return vertexCounter < other.vertexCounter;
        if (edgesCounter != other.edgesCounter)
            return edgesCounter < other.edgesCounter;
        return vertices < other.vertices || (vertices == other.vertices && edges < other.edges);
    }

    bool operator > (NonorientedGraph& other) {
        return other < *this;
    }

    bool operator <= (NonorientedGraph& other) {
        return !(other < *this);
    }

    bool operator >= (NonorientedGraph& other) {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const NonorientedGraph& graph) {
        os << "Vertices:\n";
        for_each(graph.vertices.begin(), graph.vertices.end(), [&](const pair<vertexIdx, valueType>& vertex) {
            os << "v" << vertex.first << " (" << vertex.second << ")\n";
            });

        os << "\nEdges:\n";
        for_each(graph.edges.begin(), graph.edges.end(), [&](const edgeType& edge) {
            os << "e" << get<0>(edge) << ": v" << get<1>(edge) << " - v" << get<2>(edge) << "\n";
            });

        return os;
    }

    ~NonorientedGraph() = default;
};

#endif
