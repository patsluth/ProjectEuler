// 
//  Problem_79.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <boost/graph/adjacency_list.hpp>
#import <boost/graph/labeled_graph.hpp>
#import <boost/graph/topological_sort.hpp>

using namespace boost;





struct Vertex_79
{
	char name;
};

struct Edge_79
{
};

typedef labeled_graph<adjacency_list<listS, vecS, directedS, Vertex_79, Edge_79>, char> Graph_79;
typedef graph_traits<Graph_79>::vertex_descriptor Vertex_79_Descriptor;





@interface Problem_79 : ProblemBase
{
}

@end





@implementation Problem_79

- (id)solveProblem
{
	Graph_79 graph;
	
	stringstream file;
	file << "p079_keylog.txt";
	
	ifstream fileStream = readFile(file.str());
	
	if (fileStream) {
		
		string line;
		while (getline(fileStream, line, '\n')) { // iterate each line
			
			istringstream buffer(line);
			istream_iterator<string> passcode(buffer);
			
			auto itr = (*passcode).begin();
			
			while (itr + 1 != (*passcode).end()) {
				
				char from = *itr;
				char to = *(itr + 1);
				graph.add_vertex(from);
				graph.add_vertex(to);
				graph[from].name = from;
				graph[to].name = to;
				
				add_edge_by_label(from, to, graph);
				
				advance(itr, 1);
			}
			
		}
		
	}
	
	
	vector<Vertex_79_Descriptor> sortedVertices;
	topological_sort(graph.graph(), back_inserter(sortedVertices));
	
	auto itr = sortedVertices.rbegin();
	NSMutableString *solution = [NSMutableString new];
	
	while (itr != sortedVertices.rend()) {
		
		Vertex_79_Descriptor vertex = *itr;
		char vertexName = get(&Vertex_79::name, graph, vertex);
		[solution appendFormat:@"%c", vertexName];
		
		advance(itr, 1);
	}
	
	
	return solution;
}

@end





