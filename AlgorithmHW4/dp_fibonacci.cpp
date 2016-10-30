#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>


int dp_fib(int n)
{
	std::vector<int> dp{-1,1,1};//index from zero, fib(n) from 1
	//it will be much quicker if the vector is static
	//static std::vector<int> dp{-1,1,1};//index from zero, fib(n) from 1
	if (n < dp.size())
	{
		return dp[n];
	}
	else
	{
		for(int i = dp.size(); i <= n; i++)
		{
			dp.push_back(dp[i-1] + dp[i-2]);
		}
		return dp[n];
	}
}

int main(int argc, char const *argv[])
{
	std::ofstream csv;
	csv.open("dp_fib.csv");
	csv << "n, seconds" << std::endl;
	std::vector<int> v = {1,4,8,16,20,22,24,26,28,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
	for(int i = 0; i != v.size(); i++)
	{
		int n = v[i];
		std::cout << "testing n = " << n << std::endl;
		auto start = std::chrono::system_clock::now();
		int res;
		for (int i = 0; i < 100000; ++i)//run 100000 times to let it slow enough to meter
		 {
		 	res = dp_fib(n);
		 }
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start;
		csv << n << ',' << diff.count() << std::endl;
		std::cout << "fib(" << n << ") = " << res << std::endl;
		std::cout << diff.count() << " seconds used." << std::endl;
	}
	return 0;
}