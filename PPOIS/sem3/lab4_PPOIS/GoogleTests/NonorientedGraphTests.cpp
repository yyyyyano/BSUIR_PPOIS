#include "E:\PPOIS\labs\lab4_PPOIS\BiAdjacentVertexIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\BiEdgeIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\BiIncidentEdgeIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\BiVertexIterator.h"
#include "E:\PPOIS\labs\lab4_PPOIS\NonorientedGraph.h"
#include "pch.h"

TEST(NonorientedGraphTests, IsEmpty_True) {
	NonorientedGraph<int> graph1;
	EXPECT_TRUE(graph1.IsEmpty());
}

TEST(NonorientedGraphTests, IsEmpty_False) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	EXPECT_FALSE(graph1.IsEmpty());
}

TEST(NonorientedGraphTests, ClearTest) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	EXPECT_FALSE(graph1.IsEmpty());
	graph1.ClearGraph();
	EXPECT_TRUE(graph1.IsEmpty());
	EXPECT_EQ(graph1.GetEdgesCount(), 0);
	EXPECT_EQ(graph1.GetVertexCount(), 0);
}

TEST(NonorientedGraphTests, HasVertex_True) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	EXPECT_TRUE(graph1.HasVertex(11));
}

TEST(NonorientedGraphTests, HasVertex_ExpectFalse) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	EXPECT_FALSE(graph1.HasVertex(321));
}

TEST(NonorientedGraphTests, HasVertexByIdx_True) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	EXPECT_TRUE(graph1.HasVertexByIdx(1));
}

TEST(NonorientedGraphTests, HasVertexByIdx_False) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	EXPECT_FALSE(graph1.HasVertexByIdx(11));
}

TEST(NonorientedGraphTests, HasEdge_True_TwoCombinations) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	graph1.AddEdge(1, 3);
	EXPECT_TRUE(graph1.HasEdge(1,2));
	EXPECT_TRUE(graph1.HasEdge(2, 1));
	EXPECT_TRUE(graph1.HasEdge(3, 1));
}

TEST(NonorientedGraphTests, HasEdge_False) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	graph1.AddEdge(1, 3);
	EXPECT_FALSE(graph1.HasEdge(3, 2));
}

TEST(NonorientedGraphTests, HasEdgeByIdx_True) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	graph1.AddEdge(1, 3);
	EXPECT_TRUE(graph1.HasEdgeByIdx(1));
}

TEST(NonorientedGraphTests, HasEdgeByidx_False) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(110);
	EXPECT_NO_THROW(graph1.AddVertex(1), runtime_error);
	graph1.AddVertex(11);
	graph1.AddVertex(10);
	graph1.AddEdge(1, 2);
	graph1.AddEdge(1, 3);
	EXPECT_FALSE(graph1.HasEdgeByIdx(3));
}

TEST(NonorientedGraphTests, AddVertex_CatchException) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(13);
	ASSERT_THROW(graph1.AddVertex(13), runtime_error);
}

TEST(NonorientedGraphTests, DeleteVertex_CatchException) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(13);
	EXPECT_THROW(graph1.DeleteVertex(2), runtime_error);
}

TEST(NonorientedGraphTests, DeleteVertex_NoException) {
	NonorientedGraph<int> graph1;
	graph1.AddVertex(13);
	graph1.AddVertex(8);
	graph1.AddEdge(1, 2);
	graph1.AddEdge(2, 2);
	EXPECT_EQ(graph1.GetVertexCount(), 2);
	EXPECT_NO_THROW(graph1.DeleteVertex(2), runtime_error);
        EXPECT_EQ(graph1.GetVertexCount(), 1);
}

TEST(NonorientedGraphTests, AddEdge_CatchException) {
	NonorientedGraph<int> graph;
	graph.AddVertex(10);
	graph.AddVertex(2);
	graph.AddVertex(32);
	graph.AddEdge(1, 2);
	ASSERT_THROW(graph.AddEdge(1, 2), runtime_error);
}

TEST(NonorientedGraphTests, AddEdge_CatchNoException) {
	NonorientedGraph<int> graph;
	graph.AddVertex(10);
	graph.AddVertex(2);
	graph.AddVertex(32);
	graph.AddEdge(1, 2);
	EXPECT_NO_THROW(graph.AddEdge(1, 3), runtime_error);
}

TEST(NonorientedGraphTests, DeleteEdge_CatchException) {
	NonorientedGraph<int> graph;
	graph.AddVertex(10);
	graph.AddVertex(2);
	graph.AddVertex(32);
	graph.AddEdge(1, 2);
	ASSERT_THROW(graph.DeleteEdge(1, 3), runtime_error);
}

TEST(NonorientedGraphTests, DeleteEdge_CatchNoException) {
	NonorientedGraph<int> graph;
	graph.AddVertex(10);
	graph.AddVertex(2);
	graph.AddVertex(32);
	graph.AddEdge(1, 2);
	graph.AddEdge(3, 2);
	EXPECT_NO_THROW(graph.DeleteEdgeByIdx(2), runtime_error);
	EXPECT_EQ(graph.GetEdgesCount(), 1);
}

TEST(NonorientedGraphTests, DeleteEdgeByidx_CatchException) {
	NonorientedGraph<int> graph2;
	graph2.AddVertex(10);
	graph2.AddVertex(2);
	graph2.AddVertex(32);
	graph2.AddEdge(1, 2);
	graph2.AddEdge(3, 2);
	ASSERT_THROW(graph2.DeleteEdgeByIdx(3), runtime_error);
}

TEST(NonorientedGraphTests, GetVertexCount_Correct) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	EXPECT_EQ(gr.GetVertexCount(), 2);
}

TEST(NonorientedGraphTests, GetEdgesCount_Correct) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	gr.AddEdge(1, 1);
	gr.AddEdge(1, 2);
	EXPECT_EQ(gr.GetEdgesCount(), 2);
}

TEST(NonorientedGraphTests, CalculateVertexDegree_CatchException) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	gr.AddEdge(1, 1);
	gr.AddEdge(1, 2);
	EXPECT_THROW(gr.CalculateVertexDegree(3), runtime_error);
}


TEST(NonorientedGraphTests, CalculateVertexDegree_Correct) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	gr.AddEdge(1, 1);
	gr.AddEdge(1, 2);
	EXPECT_EQ(gr.CalculateVertexDegree(2), 1);
}

TEST(NonorientedGraphTests, CalculateEdgeDegree_CatchException) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	gr.AddEdge(1, 1);
	EXPECT_THROW(gr.CalculateEdgeDegree(2), runtime_error);
}


TEST(NonorientedGraphTests, CalculateEdgeDegree_Correct) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	gr.AddEdge(1, 1);
	EXPECT_EQ(gr.CalculateEdgeDegree(1), 1);
}

TEST(NonorientedGraphTests, CalculateEdgeDegree_CorrectNotPetlya) {
	NonorientedGraph<int> gr;
	gr.AddVertex(10);
	gr.AddVertex(3);
	gr.AddEdge(1, 2);
	EXPECT_EQ(gr.CalculateEdgeDegree(1), 2);
}

TEST(NonorientedGraphTests, OperatorRavno) {
	NonorientedGraph<int> a1;
	a1.AddVertex(1);
	a1.AddVertex(2);
	a1.AddEdge(1, 2);
	NonorientedGraph<int> b1;
	b1 = a1;
	EXPECT_EQ(b1.GetEdgesCount(), 2);
	EXPECT_EQ(b1.GetVertexCount(), 2);
}

TEST(NonorientedGraphTests, CopyConstructor) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 2);
	NonorientedGraph<int> b=a;
	EXPECT_EQ(b.GetEdgesCount(), 1);
	EXPECT_EQ(b.GetVertexCount(), 2);
}

TEST(NonorientedGraphTests, OperatorRavnoRavno_True) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	EXPECT_TRUE(a == b);
}

TEST(NonorientedGraphTests, OperatorRavnoRavno_False) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddVertex(3);
	EXPECT_FALSE(a == b);
}

TEST(NonorientedGraphTests, OperatorNotRavno_True) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	a.AddEdge(2, 2);
	EXPECT_TRUE(a != b);
}

TEST(NonorientedGraphTests, OperatorNotRavno_False) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	EXPECT_FALSE(a != b);
}

TEST(NonorientedGraphTests, OperatorLessTrue) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddEdge(2, 2);
	EXPECT_TRUE(a < b);
}

TEST(NonorientedGraphTests, OperatorLessFalse) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddVertex(23);
	b.AddVertex(33);
	b.AddVertex(43);
	EXPECT_FALSE(b < a);
}

TEST(NonorientedGraphTests, OperatorMoreTrue) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddEdge(2, 2);
	EXPECT_TRUE(b>a);
}

TEST(NonorientedGraphTests, OperatorMoreFalse) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	a.AddEdge(1, 2);
	EXPECT_FALSE(b > a);
}

TEST(NonorientedGraphTests, OperatorLessRavnoTrue) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddEdge(2, 2);
	EXPECT_TRUE(a <= b);
	a.AddEdge(1, 2);
	EXPECT_TRUE(a <= b);
}

TEST(NonorientedGraphTests, OperatorLessRavnoFalse) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddEdge(2, 2);
	EXPECT_FALSE(b <= a);
	a.AddEdge(1, 2);
	EXPECT_FALSE(b <= a);
}

TEST(NonorientedGraphTests, OperatorMoreRavnoTrue) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddEdge(2, 2);
	EXPECT_TRUE(b >= a);
	a.AddEdge(1, 2);
	EXPECT_TRUE(b >= a);
}

TEST(NonorientedGraphTests, OperatorMoreRavnoFalse) {
	NonorientedGraph<int> a;
	a.AddVertex(1);
	a.AddVertex(2);
	a.AddEdge(1, 1);
	NonorientedGraph<int> b;
	b = a;
	b.AddEdge(2, 2);
	EXPECT_FALSE(a >= b);
	a.AddEdge(1, 2);
	EXPECT_FALSE(a >= b);
}

TEST(NonorientedGraphTests, Output_Correct) {
	NonorientedGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 1);
	g.AddVertex(12);
	testing::internal::CaptureStdout();
	cout << g;
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "Vertices:\nv1 (1)\nv2 (2)\nv3 (3)\nv4 (12)\n\nEdges:\ne1: v1 - v1\n";
	EXPECT_EQ(output, expected_output);
}

TEST(NonorientedGraphTests, PrintMatrix_Correct) {
	NonorientedGraph<int> g;
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddEdge(1, 1);
	g.AddVertex(12);
	testing::internal::CaptureStdout();
	g.PrintIncidenceMatrix();
	string output = testing::internal::GetCapturedStdout();
	string expected_output = "   e1   \nv1  2    \nv2  0    \nv3  0    \nv4  0    \n";
	EXPECT_EQ(output, expected_output);
}
