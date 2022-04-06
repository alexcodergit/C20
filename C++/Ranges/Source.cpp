#include<iostream>
#include<vector>
#include<ranges>
#include <algorithm>
#include <list>

using namespace std;

struct ThreeEnd
{
	bool operator==(auto x) const
	{
		return *x == 3;
	}
};

int main()
{
	std::vector<int> nums{ 5,4,3,2,1 };

	std::ranges::subrange ran1(nums);
	std::ranges::for_each(ran1, [](int x) { cout << x << " "; });

	cout << endl;

	std::ranges::subrange firstTwo{ nums.data(), ThreeEnd{} };
	std::ranges::for_each(firstTwo, [](int x) { cout << x << " "; });

	cout << endl;

	std::ranges::sort(nums.begin(), nums.end());
	std::ranges::for_each(nums, [](int x) { cout << x << " "; });

	cout << endl;

	list<int> lnums{ 1,2,3,4,5 };
	std::ranges::subrange lran1(lnums);
	std::ranges::for_each(firstTwo, [](int x) { cout << x << " "; });

	cout << endl;

	std::ranges::transform(lran1.begin(), lran1.end(), lran1.begin(), [](int x) { return x * 2; });
	std::ranges::for_each(lran1, [](int x) { cout << x << " "; });

	cout << endl;

	__debugbreak();
}