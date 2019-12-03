/*
 * graph_traversals.hpp
 *
 *  Created on: Dec 3, 2019
 *      Author: Kristiyan
 */

#ifndef GRAPH_TRAVERSALS_HPP_
#define GRAPH_TRAVERSALS_HPP_

#include <vector>
#include <queue>

const int N = 10;
std::vector<std::vector<int>> graph;
std::vector<bool> visited = std::vector<bool>(N, false);

/*
 *          7
 *         / ^
 *        v   \
 *       1 --> 2 --> 5
 *      / \     \
 *     v   v     v
 *    0     3     6
 *           \
 *            v
 *             4 --> 8
 *              \
 *               v
 *                9
 */

void generate_graph() {
	for ( int i = 0; i < N; i++ ) {
		graph.push_back(std::vector<int>());
	}

	graph[1].push_back(0); // Create a connection from 1 to 0
	graph[1].push_back(2); // Create a connection from 1 to 2
	graph[1].push_back(3); // Create a connection from 1 to 3

	graph[2].push_back(5); // Create a connection from 2 to 5
	graph[2].push_back(6); // ...
	graph[2].push_back(7);

	graph[3].push_back(4);

	graph[4].push_back(8);
	graph[4].push_back(9);

	graph[7].push_back(1);
}


void bfs(int start) {
	std::vector<bool> visited_vertices(N, false); // Reset the visited state for all vertices
	std::queue<int> q;
	q.push(start);

	while ( ! q.empty() ) {
		int vertex = q.front();
		visited_vertices[vertex] = true; // Mark the vertex as visited to avoid endless loop
		std::cout << vertex << " ";
		q.pop();

		// Add all of the unvisited neighboring vertices to the queue
		for ( size_t i = 0; i < graph[vertex].size(); i++ ) {
			if ( ! visited_vertices[graph[vertex][i]])
				q.push(graph[vertex][i]);
		}
	}

	std::cout << std::endl;

	fflush(NULL);
}

void dfs(int start) {
	visited[start] = true; // Mark the vertex as visited to avoid endless loop
	std::cout << start << " ";

	for ( size_t i = 0; i < graph[start].size(); i++ ) {
		if ( ! visited[graph[start][i]] ) {
			dfs(graph[start][i]);
		}
	}
}



#endif /* GRAPH_TRAVERSALS_HPP_ */
