# How simple could it be to apply a function on each element in vector?

Suppose we have a function:

```cpp
int sqr(int x) { return x * x; }
```

How can we apply it to a vector?

STL provides a function `transform` to achieve this:

```cpp
vector<int> a = { 1, 3, 5, 7, 9 };
vector<int> b(a.size());
transform(a.begin(), a.end(), b.begin(), sqr);
```

In this repo, I constructed a function template, which could make this easier:

```cpp
template <typename container, typename function>
container operator % (function f, container i)
{
	container o(i.size());
	transform(i.begin(), i.end(), o.begin(), f);
	return o;
}
auto c = sqr%(a);
```

See more details in [demo.cpp](demo.cpp), and try following:

```sh
$ g++ -Wall -std=c++17 demo.cpp
$ ./a.out
vector   : 1 3 5 7 9
transform: 1 9 25 49 81
sqr%     : 1 9 25 49 81
list     : 1 3 5 7 9
transform: 1 9 25 49 81
sqr%     : 1 9 25 49 81
```
