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





@interface Problem_79 : ProblemBase
{
}

struct Vertex_79
{
	char name;
};

struct Edge_79
{
};

typedef labeled_graph<adjacency_list<listS, vecS, directedS, Vertex_79, Edge_79>, char> Graph_79;
typedef graph_traits<Graph_79>::vertex_descriptor Vertex_79_Descriptor;

@end





@implementation Problem_79

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	Graph_79 graph;
	
	stringstream file;
	file << "p079_keylog.txt";
	
	ifstream fileStream = readFile(file.str());
	
	if (fileStream) {
		
		string line;
		while (getline(fileStream, line, '\n')) { // iterate each line
			
			istringstream buffer(line);
			istream_iterator<string> passcode(buffer);
			
			for (auto itr = (*passcode).begin(); itr + 1 != (*passcode).end(); advance(itr, 1)) {
				
				char from = *itr;
				char to = *(itr + 1);
				graph.add_vertex(from);
				graph.add_vertex(to);
				graph[from].name = from;
				graph[to].name = to;
				
				add_edge_by_label(from, to, graph);
				
			}
			
		}
		
	}
	
	
	vector<Vertex_79_Descriptor> sortedVertices;
	topological_sort(graph.graph(), back_inserter(sortedVertices));
	
	NSMutableString *solution = [NSMutableString new];
	
	for (auto itr = sortedVertices.rbegin(); itr != sortedVertices.rend(); advance(itr, 1)) {
		
		Vertex_79_Descriptor vertex = *itr;
		char vertexName = get(&Vertex_79::name, graph, vertex);
		[solution appendFormat:@"%c", vertexName];
		
	}
	
	completion(solution, self.endTime);	// 73162890
}

@end





