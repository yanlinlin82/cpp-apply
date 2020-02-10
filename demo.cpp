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

int square(int x) { return x * x; }

int main()
{
	// vector
	{
		vector<int> src = { 1, 3, 5, 7, 9 };
		cout << "vector   :" << src << endl;

		vector<int> dst(src.size());
		transform(src.begin(), src.end(), dst.begin(), square);
		cout << "transform:" << dst << endl;

		auto dst2 = square%(src);
		cout << "square%  :" << dst2 << endl;
	}

	// list
	{
		list<int> src = { 1, 3, 5, 7, 9 };
		cout << "list     :" << src << endl;

		list<int> dst(src.size());
		transform(src.begin(), src.end(), dst.begin(), square);
		cout << "transform:" << dst << endl;

		auto dst2 = square%(src);
		cout << "square%  :" << dst2 << endl;
	}
	return 0;
}
