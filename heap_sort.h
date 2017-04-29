#pragma once
#include <vector>

template<typename T>
void heap_sort(std::vector<T>& ary, int b, int e) {
	using std::swap;

	// build heap tree
	for (int n = parent(e - 1 - b) + b; n >= b; n--)
		heapify(ary, b, e, n);

	// pop top to n and maintain the remaining n-1 tree
	for (int n = e - 1; n > b; n--) {
		swap(ary[b], ary[n]);
		heapify(ary, b, n, b); // heapify [b, n) from root b
	}
}


inline int parent(int i) { return (i - 1) / 2; }
inline int left(int i) { return (i + 1) * 2 - 1; }
inline int right(int i) { return (i + 1) * 2; }

template<typename T>
void heapify(std::vector<T>& ary, int b, int e, int i) {
	using std::swap;

	while (i < e) {
		int r = right(i - b) + b;
		int l = left(i - b) + b;

		// k = node of max(ary[i], ary[l], ary[r]);
		int k = i;
		if (l < e && ary[k] < ary[l]) k = l;
		if (r < e && ary[k] < ary[r]) k = r;

		if (k == i) break;	// no change, then stop
		swap(ary[i], ary[k]);
		i = k; // continue heapify on the child node k
	}
}