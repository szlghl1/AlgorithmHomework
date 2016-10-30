#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

int naive_fib(int n)
{
	if (n == 0) return 1;
    if (n == 1) return 1;
    return (naive_fib(n-1) + naive_fib(n-2));
}

int main(int argc, char const *argv[])
{
	std::ofstream csv;
	csv.open("naive_fib.csv");
	csv << "n, seconds" << std::endl;
	std::vector<int> v = {1,4,8,16,20,22,24,26,28,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
	for(int i = 0; i != v.size(); i++)
	{
		int n = v[i];
		std::cout << "testing n = " << n << std::endl;
		auto start = std::chrono::system_clock::now();
		naive_fib(n);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start;
		csv << n << ',' << diff.count() << std::endl;
		std::cout << n << ',' << diff.count() << std::endl;
	}
	return 0;
}