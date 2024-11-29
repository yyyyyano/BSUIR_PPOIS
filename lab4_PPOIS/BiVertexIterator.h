#ifndef BI_VERTEX_ITERATOR_H
#define BI_VERTEX_ITERATOR_H


#include <utility>  
#include <vector>  
#include <iterator>
#include "NonorientedGraph.h"
using namespace std;

template<class T>
class BiVertexIterator {
public:
    using vertexIdx = int;
    using valueType = T;
    using vertexType = pair<vertexIdx, valueType>;
    using vertIt = typename vector<vertexType>::iterator;

    using constVertIt = typename vector<vertexType>::const_iterator;
    using reverseVertIt = typename vector<vertexType>::reverse_iterator;
    using constReverseVertIt = typename vector<vertexType>::const_reverse_iterator;

    template<class> friend class NonorientedGraph;
private:
    vertIt it;

public:
    BiVertexIterator(vertIt vectorIt) : it(vectorIt) {}

    vertexType& operator*() {
        return *it;
    }

    const vertexType& operator * () const {
        return *it;
    }

    vertexType* operator->() {
        return &(*it);
    }

    const vertexType* operator ->() const {
        return &(*it);
    }

    BiVertexIterator& operator++() {
        ++it;
        return *this;
    }

    BiVertexIterator& operator--() {
        --it;
        return *this;
    }

    bool operator==(const BiVertexIterator& otherIterator) const {
        return it == otherIterator.it;
    }

    bool operator!=(const BiVertexIterator& otherIterator) const {
        return it != otherIterator.it;
    }

    vertIt getIterator() {
        return it;
    }

    static constVertIt BeginConst(const vector<vertexType>& vertex) {
        return vertex.cbegin();
    }

    static constVertIt EndConst(const vector<vertexType>& vertex) {
        return vertex.cend();
    }

    static reverseVertIt BeginReverse(vector<vertexType>& vertex) {
        return vertex.rbegin();
    }

    static reverseVertIt EndReverse(vector<vertexType>& vertex) {
        return vertex.rend();
    }

    static constReverseVertIt BeginCR(const vector<vertexType>& vertex) {
        return vertex.crbegin();
    }

    static constReverseVertIt EndCR(const vector<vertexType>& vertex) {
        return vertex.crend();
    }
};

#endif