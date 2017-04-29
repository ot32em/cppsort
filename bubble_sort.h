#pragma once
#include <vector>

template<typename T>
void bubble_sort(std::vector<T>& ary, int b, int e) {
    using std::swap;

    for (int i = b; i + 1 < e; i++)
        for (int j = e - 1; j > i; j--)
            if (ary[j] < ary[j - 1])
                swap(ary[j], ary[j - 1]);
}