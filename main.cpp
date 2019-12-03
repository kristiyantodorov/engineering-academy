/*
 * main.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: Kristiyan
 */

#include <iostream>
#include "graph_traversals.hpp"
#include "binary_search.hpp"

int main() {
	generate_graph();
	std::cout << "BFS traversal:" << std::endl;
	bfs(1);
	std::cout << "DFS traversal:" << std::endl;
	dfs(1);
	std::cout << std::endl;

	std::cout << "Binary search result: " << binary_search(64) << std::endl;

	return 0;
}
