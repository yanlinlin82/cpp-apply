# How simple could it be to apply a function on each element in vector?

## Question

Suppose we have a function:

```cpp
int square(int x) { return x * x; }
```

How can we apply it to a vector (or list)?

## STL answer

STL provides a function `transform` to achieve this:

```cpp
vector<int> dst(src.size());
transform(src.begin(), src.end(), dst.begin(), square);
```

## My answer

In this repo, I constructed a function template, which could make this easier:

```cpp
auto dst = square%(src);
```

## See also

See more details in [demo.cpp](demo.cpp), and try following:

```sh
$ g++ -Wall -std=c++17 demo.cpp
$ ./a.out
vector   : 1 3 5 7 9
transform: 1 9 25 49 81
square%  : 1 9 25 49 81
list     : 1 3 5 7 9
transform: 1 9 25 49 81
square%  : 1 9 25 49 81
```
