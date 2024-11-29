#include "E:\PPOIS\labs\lab4_PPOIS\BiAdjacentVertexIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\BiEdgeIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\BiIncidentEdgeIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\BiVertexIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\NonorientedGraph.h"
#include "pch.h"

TEST(BiIncidentEdgeIteratorTests, IncidentEdgesExist) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    BiIncidentEdgeIterator<int> it(&graph, 1);
    EXPECT_EQ(*it, make_tuple(1, 1, 2)); 
    ++it;
    EXPECT_EQ(*it, make_tuple(2, 1, 3));
    ++it;
    BiIncidentEdgeIterator<int> endIt(&graph, 1);
    while (endIt != BiIncidentEdgeIterator<int>(&graph, 0)) {
        ++endIt;
    }
    EXPECT_TRUE(it == endIt);  
}

TEST(BiIncidentEdgeIteratorTests, Incident_Throw) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    BiIncidentEdgeIterator<int> it(&graph, 5);
    EXPECT_THROW(*it, out_of_range);
}

TEST(BiIncidentEdgeIteratorTests, DecrementTest) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    BiIncidentEdgeIterator<int> it(&graph, 1); 
    EXPECT_EQ(*it, make_tuple(1, 1, 2)); 
    ++it;
    EXPECT_EQ(*it, make_tuple(2, 1, 3));  
    --it; 
    EXPECT_EQ(*it, make_tuple(1, 1, 2));
    BiIncidentEdgeIterator<int> currIt(&graph, 1);
    EXPECT_TRUE(it == currIt);
    BiIncidentEdgeIterator<int> next_currIt(&graph, 3);
    EXPECT_TRUE(it != next_currIt);
}

TEST(BiIncidentEdgeIteratorTest, NoIncidentEdges) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddVertex(4);  
    BiIncidentEdgeIterator<int> it(&graph, 4);
    EXPECT_TRUE(it == BiIncidentEdgeIterator<int>(&graph, 4));  
    EXPECT_TRUE(it != BiIncidentEdgeIterator<int>(&graph, 3));
}

TEST(BiAdjacentVertexIteratorTest, AdjacentVertices) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddVertex(4);
    BiAdjacentVertexIterator<int> it(&graph, 1);
    EXPECT_EQ(*it, 3);  
    ++it;
    EXPECT_EQ(*it, 4);
}

TEST(BiAdjacentVertexIteratorTest, AdjacentVertices_Notadj) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddVertex(4);
    BiAdjacentVertexIterator<int> it(&graph, 4);
    EXPECT_TRUE(it == BiAdjacentVertexIterator<int>(&graph, 4));
    EXPECT_TRUE(it != BiAdjacentVertexIterator<int>(&graph, 2));
}

TEST(BiAdjacentVertexIteratorTest, DecrementAdjacentVertices) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    BiAdjacentVertexIterator<int> it(&graph, 1);
    ++it; 
    --it; 
    EXPECT_EQ(*it, 3); 
}

TEST(BiAdjacentVertexIteratorTest, DereferenceVertexOutOfRangeByTarget) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddEdge(1, 3); 
    BiAdjacentVertexIterator<int> it(&graph, 1);
    EXPECT_THROW(*it, out_of_range);
}

TEST(BiAdjacentVertexIteratorTest, DereferenceEdgeOutOfRange) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddEdge(1, 2);
    BiAdjacentVertexIterator<int> it(&graph, 1);
    it.SetCurrentEdge(100); 
    EXPECT_THROW(*it,out_of_range);
}

TEST(BiAdjacentVertexIteratorTest, DereferenceEdgeNegativeIndex) {
    NonorientedGraph<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddEdge(1, 2);
    BiAdjacentVertexIterator<int> it(&graph, 1);
    it.SetCurrentEdge(-1); 
    EXPECT_THROW(*it, out_of_range);
}
