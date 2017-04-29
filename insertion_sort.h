#pragma once
#include <vector>

template<typename T>
void insertion_sort(std::vector<T>& ary, int b, int e) {
	for (int i = b + 1; i < e; i++) {		// pick up the item b+1, b+2, ..., e-1
		T v = std::move(ary[i]);			// insert the item i in its left sorted [b, i]
		int j = i;							
		while (j > b && v < ary[j - 1]) {
			ary[j] = std::move(ary[j - 1]);
			j--;
		}
		ary[j] = std::move(v);
	}
}