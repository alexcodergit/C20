#include<iostream>
#include<ranges>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<string, int> wordsMap{ {"a", 1}, {"bc", 2}, {"abc", 3}, {"xyz", 4}};
	auto keys = std::views::keys(wordsMap);
	for (auto key : keys) { cout << key << " "; };

	cout << endl;

	auto values = std::views::values(wordsMap);
	for (auto value : values) { cout << value << " "; };

	cout << endl;

	auto size_three_filter = [](const string& str) { return str.size() == 3; };
	for (const auto& word : std::views::keys(wordsMap) | std::views::filter(size_three_filter))
	{
		cout << word << " ";
	}

	return 0;
}