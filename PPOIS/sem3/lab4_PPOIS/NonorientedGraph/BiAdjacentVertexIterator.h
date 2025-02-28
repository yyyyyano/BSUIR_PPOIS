#ifndef BI_ADJACENT_VERTEX_ITERATOR_H
#define BI_ADJACENT_VERTEX_ITERATOR_H

#include <iostream>
#include <vector>
#include <tuple>
#include "NonorientedGraph.h"

using namespace std;

template<class T>
class BiAdjacentVertexIterator {
public:
    using vertexIdx = int;
    using edgeIdx = int;
    using valueType = T;
    using edgeType = tuple<edgeIdx, vertexIdx, vertexIdx>;

private:
    NonorientedGraph<T>* graph;
    vertexIdx vertex;
    edgeIdx currentEdge;
    int edgeCount;

    bool IsEdgeIncidentOtherVertex(edgeType& edge) {
        return (get<1>(edge) == vertex && get<2>(edge) != vertex) ||
            (get<1>(edge) != vertex && get<2>(edge) == vertex);
    }

public:
    BiAdjacentVertexIterator(NonorientedGraph<T>* inGraph, vertexIdx adjVertex)
        : graph(inGraph), vertex(adjVertex), currentEdge(0), edgeCount(inGraph->GetEdgesCount()) {
        if (graph->GetEdgesCount() > 0) {
            while (currentEdge < edgeCount && !IsEdgeIncidentOtherVertex(graph->GetEdges()[currentEdge])) {
                ++currentEdge;
            }
        }
    }

    void SetCurrentEdge(edgeIdx setIdx) {
        this->currentEdge = setIdx;
    }

    valueType& operator*() {
        if (currentEdge >= 0 && currentEdge < edgeCount) {
            auto edge = graph->GetEdges()[currentEdge];
            if (get<1>(edge) == vertex) {
                if (get<2>(edge) < graph->GetVertices().size()) {
                    return graph->GetVertices()[get<2>(edge)].second;
                }
                else {
                    throw out_of_range("Index for vertex out of range");
                }
            }
            else {
                if (get<1>(edge) < graph->GetVertices().size()) {
                    return graph->GetVertices()[get<1>(edge)].second;
                }
                else {
                    throw out_of_range("Index for vertex out of range");
                }
            }
        }
        else {
            throw out_of_range("Current edge index out of range");
        }
    }

    BiAdjacentVertexIterator& operator++() {
        ++currentEdge;
        while (currentEdge < edgeCount && !IsEdgeIncidentOtherVertex(graph->GetEdges()[currentEdge])) {
            ++currentEdge;
        }
        return *this;
    }

    BiAdjacentVertexIterator& operator--() {
        --currentEdge;
        while (currentEdge >= 0 && !IsEdgeIncidentOtherVertex(graph->GetEdges()[currentEdge])) {
            --currentEdge;
        }
        return *this;
    }

    bool operator ==(BiAdjacentVertexIterator& other) {
        return currentEdge == other.currentEdge;
    }

    bool operator !=(BiAdjacentVertexIterator& other) {
        return currentEdge != other.currentEdge;
    }
};

#endif


