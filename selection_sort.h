#pragma once
#include <vector>
#include <utility>

template<typename T>
void selection_sort(std::vector<T>& ary, int b, int e) {
    using std::swap;

    for (int i = b; i + 1 < e; i++) {
        int min_i = i;
        for (int j = i + 1; j < e; j++) // select min element in [i,e)
            if (ary[j] < ary[min_i])    // then put at i, then continue to check [i+1,e)            
                min_i = j;
        swap(ary[i], ary[min_i]);
    }
}