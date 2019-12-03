/*
 * binary_search.hpp
 *
 *  Created on: Dec 3, 2019
 *      Author: Kristiyan
 */

#ifndef BINARY_SEARCH_HPP_
#define BINARY_SEARCH_HPP_


#include <vector>

std::vector<int> haystack = {-4, 3, 7, 12, 18, 23, 64};

// O(log N) time complexity
int binary_search(int needle) {
	int left = 0, right = haystack.size(); // Indices for the pivots
	int mid_index = (left + right) / 2;

	while ( left < right ) {
		if ( needle == haystack[mid_index] ) return mid_index;

		if ( needle < haystack[mid_index] ) {
			right = mid_index;
			mid_index = (left + right) / 2;
		} else {
			left = mid_index;
			mid_index = (left + right) / 2;
		}
	}
	return -1;
}

// O(N) time complexity
int linear_search(int needle) {
	for ( size_t i = 0; i < haystack.size(); i++ ) {
		if ( needle == haystack[i] ) return i;
	}
	return -1;
}


#endif /* BINARY_SEARCH_HPP_ */
