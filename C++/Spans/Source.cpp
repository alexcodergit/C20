#include<ranges>
#include<vector>
#include<iostream>
#include<list>
#include<algorithm>
#include<span>

using namespace std;

int main()
{
	// spans refer to object located in memory contiguously
	// spans do not own objects
	vector<int> nums({1,2,3,4,5});
	std::span<int> dyn_span(nums.begin(), nums.end());
	// undefined behavior
	//std::span<int, 4> stat_span(nums.begin(), nums.end()); 
	std::span<int, 4> stat_span(nums.begin(), nums.begin() + 4);

	for (auto n : dyn_span) { cout << n << " "; };
	cout << endl;
	for (auto n : stat_span) { cout << n << " "; }; 
	cout << endl;

	dyn_span = stat_span;
	for (auto n : dyn_span) { cout << n << " "; };
	cout << endl;

	// does not compile
	//stat_span = dyn_span;

	list<int> lst({1,2,3});
	// does not compile
	//dyn_span = std::span<int>(lst.begin(), lst.end());
	
	int arr[4]{ 4,5,6,7 };
	dyn_span = std::span<int>(arr);
	for (auto n : dyn_span) { cout << n << " "; };
	cout << endl;

	// does not compile
	//dyn_span = std::span<int>(vector<int>({1, 2, 3 }));

	dyn_span = std::span<int>(std::begin(arr), std::begin(arr) + 2);
	std::transform(dyn_span.begin(), dyn_span.end(), dyn_span.begin(), [](int x) { return x / 2; });
	for (auto n : arr) { cout << n << " "; };
	cout << endl;

	dyn_span[1] = 10;
	for (auto n : arr) { cout << n << " "; };
	cout << endl;

	dyn_span = std::span<int>(nums.begin(), nums.end());
	auto dyn_subspan = dyn_span.subspan(1, 3);
	for (auto n : dyn_subspan) { cout << n << " "; };
	cout << endl;
	return 0;
}