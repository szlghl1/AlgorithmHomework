#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <unordered_map>
#include <vector>

void fillRandomElement(int n, std::vector<int>& v);
void bubbleSort(std::vector<int>& v);
void countingSort(std::vector<int>& v);
void testSorting(int baseNum, decltype(countingSort) sortingFunc);

int main(int argc, char const *argv[])
{
	auto systemSort = [](std::vector<int>& v) {std::sort(v.begin(), v.end()); };
	std::cout << "Testing Bubble Sort..." << std::endl;
	testSorting(1000, bubbleSort);
	std::cout << std::endl << "Testing system nlgn sort..." << std::endl;
	testSorting(50000, systemSort);
	std::cout << std::endl << "Testing Counting sort..." << std::endl;
	testSorting(100000, countingSort);
	return 0;
}

void testSorting(int baseNum, decltype(countingSort) sortingFunc)
{
	for (int i = 1; i <= 10; i++)
	{
		int numEle = baseNum * i; 
		std::vector<int> v;
		fillRandomElement(numEle, v);
		auto start = std::chrono::system_clock::now();
		sortingFunc(v);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "Sorting " << numEle << " elements took " << diff.count() << " seconds." << std::endl;
	}
}

void fillRandomElement(int n, std::vector<int>& v)
{
	static std::default_random_engine dre(static_cast<int>(time(0)));
	std::uniform_int_distribution<int> uid(1, 2 * n);
	std::unordered_map<int,bool> m; //ensure it is a subset, which means no duplicate
	for(int i = 0; i != n; i++)
	{
		int temp;
		do
		{
			temp = uid(dre);
		}while(m.find(temp) != m.end());
		v.push_back(temp);
		m[temp] = true;
	}
}

void bubbleSort(std::vector<int>& v)
{
	for(int i = 1; i != v.size(); i++)
	{
		for(int j = 0; j != v.size() - i; j++)
		{
			if(v[j] > v[j+1])
			{
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}

void countingSort(std::vector<int>& v)
{
	int max = 0;
	int maxElement = *(std::max_element(v.begin(), v.end()));
	std::vector<int> counting (maxElement + 1, 0);
	for(auto i = v.begin(); i != v.end(); i++)counting[*i]++;
	int cur = 0;
	for(int i = 0; i != counting.size(); i++)
	{
		for(int j = 0; j != counting[i]; j++)
		{
			v[cur] = i;
			cur++;
		}
	}
}