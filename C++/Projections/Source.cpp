#include<iostream>
#include<vector>
#include<ranges>
#include <functional>
#include <algorithm>

using namespace std;

/*
template <std::random_access_iterator It, std::sentinel_for<It> Sent,
	class Comp = ranges::less, class Proj = std::identity>
	requires std::sortable<It, Comp, Proj>
constexpr It sort(It first, Sent last, Comp comp = {}, Proj proj = {});


template <ranges::random_access_range Range, class Comp = ranges::less,
	class Proj = std::identity>
	requires std::sortable<ranges::iterator_t<Range>, Comp, Proj>
constexpr ranges::borrowed_iterator_t<Range> sort(Range&& r, Comp comp = {}, Proj proj = {});
*/


struct Person
{
	string name;
	int age;
	Person(string n, int a) : name(n), age(a) {}
};

struct PersonSentinel
{
	bool operator==(auto pers) const
	{
		return (*pers).name == "Alex";
	}
};

void printPersons(const vector<Person>& persons)
{
	cout << "( ";
	for (const auto& person : persons)
	{
		cout << person.name << ", " << person.age << " ";
	}
	cout << ")\n";
}

int main()
{
	vector<Person> persons({ {"Felix", 42}, {"Lena", 48 }, {"Alex", 50} });

	std::ranges::sort(persons.begin(), PersonSentinel{}, std::ranges::less(), &Person::name);
	printPersons(persons);

	std::ranges::sort(persons, {}, &Person::name);
	printPersons(persons);

	std::ranges::sort(persons, {}, &Person::age);
	printPersons(persons);

	std::ranges::sort(persons, std::ranges::greater(), &Person::age);
	printPersons(persons);

	__debugbreak();
}

