#include<iostream>
#include<ranges>

using namespace std;

bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	if (n < 4) // 2, 3
	{
		return true;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	// endless loop
	//for (int i : std::views::iota(100)) { cout << i; }

	// std::views::iota(100) - data generator
	// std::views::take(10) - data sink
	for (int i : std::views::iota(100) | std::views::filter(isPrime) | std::views::take(10)) 
	{
		cout << i << " ";
	}

	return 0;
}