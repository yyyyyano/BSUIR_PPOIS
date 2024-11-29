#ifndef BI_EDGE_ITERATOR_H
#define BI_EDGE_ITERATOR_H

#include <tuple>
#include <vector>
#include "NonorientedGraph.h"

using namespace std;

template<class T>
class BiEdgeIterator {
public:
    using vertexIdx = int;
    using edgeIdx = int;
    using edgeType = tuple<edgeIdx, vertexIdx, vertexIdx>;
    using edgeIterator = typename vector<edgeType>::iterator;

    using constEdgeIterator = typename vector<edgeType>::const_iterator;
    using reverseEdgeIterator = typename vector<edgeType>::reverse_iterator;
    using constReverseEdgeIterator = typename vector<edgeType>::const_reverse_iterator;

    template<class> friend class NonorientedGraph;
private:
    edgeIterator it;

public:
    BiEdgeIterator(edgeIterator vectIt) :it(vectIt) {};

    edgeType& operator*() {
        return *it;
    }

    const edgeType& operator*() const {
        return *it; 
    }

    edgeType* operator->() {
        return &(*it);
    }

    const edgeType* operator->() const {
        return &(*it);
    }

    BiEdgeIterator& operator++() {
        ++it;
        return *this;
    }

    BiEdgeIterator& operator--() {
        --it;
        return *this;
    }

    bool operator==(const BiEdgeIterator& otherIterator) const {
        return it == otherIterator.it;
    }

    bool operator!=(const BiEdgeIterator& otherIterator) const {
        return it != otherIterator.it;
    }

    static constEdgeIterator BeginConst(const vector<edgeType>& vertex) { 
        return vertex.cbegin(); 
    }

    static constEdgeIterator EndConst(const vector<edgeType>& vertex) {
        return vertex.cend();
    }

    static reverseEdgeIterator BeginReverse(vector<edgeType>& vertex) { 
        return vertex.rbegin();
    }

    static reverseEdgeIterator EndReverse(vector<edgeType>& vertex) { 
        return vertex.rend(); 
    }

    static constReverseEdgeIterator BeginCR(const vector<edgeType>& vertex) { 
        return vertex.crbegin();
    }

    static constReverseEdgeIterator EndCR(const vector<edgeType>& vertex) {
        return vertex.crend();
    }
};


#endif
