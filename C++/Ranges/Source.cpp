#include<iostream>
#include<vector>
#include<ranges>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

struct ThreeEnd
{
	bool operator==(auto x) const
	{
		return *x == 3;
	}
};

struct Person
{
	string name;
	int age;
	int wage;

	Person(string n, int a, int w) : name(n), age(a), wage(w) {}

	string toString() const
	{
		return "Name: " + name + ", age: " + to_string(age) + ", wage: " + to_string(wage);
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

	std::reverse(nums.begin(), nums.end());
	std::ranges::sort(nums);
	std::ranges::for_each(nums, [](int x) { cout << x << " "; });

	cout << endl;

	list<int> lnums{ 1,2,3,4,5 };
	std::ranges::subrange lran1(lnums);
	std::ranges::for_each(firstTwo, [](int x) { cout << x << " "; });

	cout << endl;

	std::ranges::transform(lran1.begin(), lran1.end(), lran1.begin(), [](int x) { return x * 2; });
	std::ranges::for_each(lran1, [](int x) { cout << x << " "; });

	cout << endl;

	vector<Person> persons({ {"Alex", 29, 5000}, {"Bob", 25, 6000, }, {"Lena", 50, 4000} });
	std::ranges::sort(persons, {}, &Person::name);
	std::ranges::for_each(persons, [](Person & p) { cout << p.toString() << "; "; });

	cout << endl;

	std::ranges::sort(persons, {}, &Person::age);
	std::ranges::for_each(persons, [](Person& p) { cout << p.toString() << "; "; });

	cout << endl;

	std::ranges::sort(persons, {}, &Person::wage);
	std::ranges::for_each(persons, [](Person& p) { cout << p.toString() << "; "; });

	cout << endl;
	__debugbreak();
}