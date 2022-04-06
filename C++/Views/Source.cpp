#include<iostream>
#include<vector>
#include<ranges>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	// views can be applied on range and perform operations
	std::vector<int> nums{ 1,2,3,4,5 };

	// using pipe operator
	auto res = nums | std::views::filter([](int x) {return x % 2 == 1; })
		| std::views::transform([](int x) { return x * x; });

	std::ranges::for_each(res, [](int x) { cout << x << " "; });

	cout << endl;

	auto firstFour = nums | std::views::take(4);
	std::ranges::for_each(firstFour, [](int x) { cout << x << " "; });

	cout << endl;

	auto lastOne = nums | std::views::drop(4);
	std::ranges::for_each(lastOne, [](int x) { cout << x << " "; });

	cout << endl;

	// changind data over view changes original
	cout << lastOne[0] << endl;
	lastOne[0] *= 2;
	cout << lastOne[0] << endl;
	cout << nums[4] << endl;

	// views do not own data, they can be applied only on lvalues
	//auto res2 = { 1,2,3,4,5 } | std::views::drop(4);

	__debugbreak();
}