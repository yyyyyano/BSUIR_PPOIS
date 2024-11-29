#ifndef BI_INCIDENT_EDGE_ITERATOR_H
#define BI_INCIDENT_EDGE_ITERATOR_H

#include <vector>
#include<tuple>
#include <iostream>
#include "NonorientedGraph.h"

using namespace std;

template<class T>
class BiIncidentEdgeIterator {
public:
    using vertexIdx = int;
    using edgeIdx = int;
    using edgeType = tuple<edgeIdx, vertexIdx, vertexIdx>;

private:
    NonorientedGraph<T>* graph;
    edgeIdx currentEdge;
    vertexIdx vertex;
    int edgeCount;

    bool IsIncident(edgeType edge) {
        return (get<1>(edge) == vertex || get<2>(edge) == vertex);
    }

public:

    BiIncidentEdgeIterator(NonorientedGraph<T>* inGraph, vertexIdx vertex)
        : graph(inGraph), currentEdge(0), vertex(vertex) {
        edgeCount = graph->GetEdgesCount();
        while (currentEdge < edgeCount && !IsIncident(graph->GetEdges()[currentEdge])) {
            ++currentEdge;
        }
    }

    edgeType& operator *() {
        if (currentEdge < edgeCount) {
            return graph->GetEdges()[currentEdge];
        }
        throw out_of_range("Out of range in BiIncidentEdgeIterator");
    }

    BiIncidentEdgeIterator& operator++() {
        ++currentEdge;
        while (currentEdge < edgeCount && !IsIncident(graph->GetEdges()[currentEdge])) {
            ++currentEdge;
        }
        return *this;
    }

    BiIncidentEdgeIterator& operator --() {
        --currentEdge;
        while (currentEdge >= 0 && !IsIncident(graph->GetEdges()[currentEdge])) {
            --currentEdge;
        }
        return *this;
    }

    bool operator ==(const BiIncidentEdgeIterator& other) const {
        return currentEdge == other.currentEdge;
    }

    bool operator !=(const BiIncidentEdgeIterator& other) const {
        return currentEdge != other.currentEdge;
    }
};

#endif