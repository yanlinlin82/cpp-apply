#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename container, typename function>
container operator % (function f, container i)
{
	container o(i.size());
	transform(i.begin(), i.end(), o.begin(), f);
	return o;
}

template <typename t, template <typename> class container>
ostream& operator << (ostream& os, const container<t>& i)
{
	for (auto e : i) os << " " << e;
	return os;
}

int sqr(int x) { return x * x; }

int main()
{
	// vector
	vector<int> a = { 1, 3, 5, 7, 9 };
	cout << "vector   :" << a << endl;

	vector<int> b(a.size());
	transform(a.begin(), a.end(), b.begin(), sqr);
	cout << "transform:" << b << endl;

	auto c = sqr%(a);
	cout << "sqr%     :" << c << endl;

	// list
	list<int> d = { 1, 3, 5, 7, 9 };
	cout << "list     :" << d << endl;

	list<int> e(d.size());
	transform(d.begin(), d.end(), e.begin(), sqr);
	cout << "transform:" << e << endl;

	auto f = sqr%(d);
	cout << "sqr%     :" << f << endl;

	return 0;
}
