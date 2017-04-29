#pragma once

template<typename T>
void merge_sort(std::vector<T>& ary, int b, int e) {
	std::vector<T> spare(e - b);
	merge_sort_spare(ary, b, e, spare, 0);
}


template<typename T>
void merge_sort_spare(std::vector<T>& ary, int b, int e, std::vector<T>& spare, int spare_b) {
	int n = e - b;
	if (n <= 1) { return; }

	int mid = n >> 1;
	int b1 = b, e1 = b + mid;
	int b2 = b + mid, e2 = b + n;
	merge_sort_spare(ary, b1, e1, spare, spare_b);
	merge_sort_spare(ary, b2, e2, spare, spare_b + mid);

	for (int i = spare_b; i < spare_b + n; i++) {
		if (b1 == e1)
			spare[i] = std::move(ary[b2++]);
		else if (b2 == e2)
			spare[i] = std::move(ary[b1++]);
		else if (ary[b1] < ary[b2])
			spare[i] = std::move(ary[b1++]);
		else
			spare[i] = std::move(ary[b2++]);
	}
	while (b != e)
		ary[b++] = std::move(spare[spare_b++]);
}