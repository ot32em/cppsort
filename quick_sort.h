#pragma once
#include <vector>
#include <utility>
#include "insertion_sort.h"

template<typename T>
void quick_sort(std::vector<T>& ary, int b, int e) {
    if (e - b <= 4) {
        insertion_sort(ary, b, e);
    }
    else {
        int p = mm3(ary, b, e);
        p = partition(ary, b, e, p);
        quick_sort(ary, b, p);
        quick_sort(ary, p + 1, e);
    }
}

template<typename T>
int partition(std::vector<T>& ary, int b, int e, int p) {
    if (b >= e) { return b; }

    using std::swap;

    swap(ary[b], ary[p]);
    int s = b;    // stored index
    for (int i = b + 1; i < e; i++)
        if (ary[i] < ary[b])
            swap(ary[++s], ary[i]); // rightmost element < pivot is the pivot pos
    swap(ary[b], ary[s]);
    return s;
}

template<typename T>
int mm3(std::vector<T>& ary, int b, int e) {
    if (b >= e) { return b; }

    using std::swap;

    int mid = b + (e - b) / 2;
    if (ary[e - 1] < ary[b])
        swap(ary[e - 1], ary[b]);
    if (ary[mid] < ary[b])
        swap(ary[mid], ary[b]);
    if (ary[e - 1] < ary[mid])
        swap(ary[mid], ary[e - 1]);
    return mid;
}

template<typename T>
int quick_select(std::vector<T>& ary, int b, int e, int k) {
    if (b >= e) { return b; }

    int p = mm3(ary, b, e);
    p = partition(ary, b, e, p); // S1{Ab, Ab+1, ...} S2 {Ap} S3 {Ap+1, ...Ae}
    int s1 = (p - b);              // |s1| = p - b       
    if (k == s1)
        return p;
    else if (k < s1)
        return quick_select(ary, b, p, k);
    else
        return quick_select(ary, p + 1, e, k - s1 - 1);
}