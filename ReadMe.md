# Description

Some sorting implementation in cpp,

Demonstration use.

Use `int` as index type for simplification. 
But `int` has not guarantee to be big enough to map vector index.

Auto testing defined in `main.cpp`


# Interface 

Signature  
```
template<typename T>
void (std::vector<T>& ary, int b, int e)
```

- sorting range: [b, e)
- compare operator: `<`
- assignment: use std::move


# Current implementation

- bubble sort
- insertion sort
- selection sort
- merge sort
- heap sort
- quick sort