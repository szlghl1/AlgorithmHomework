#include <iostream>
#include <vector>

int swapTimes = 0;
void maxHeapifyVector(std::vector<int>& v);

int main(int argc, char const *argv[])
{
	std::vector<int> v = {23, 99, 56, 89, 87, 54, 46, 32, 57, 25, 12, 19, 78, 17, 23, 14, 12, 11, 43, 10};
	maxHeapifyVector(v);
	std::cout << "The heapified vector: " << std::endl;
	for(auto i = v.begin(); i != v.end(); i++)
		std::cout << *i << ' ';
	return 0;
}

void maxHeapify(std::vector<int>& v, int index)
{
	//because index is begin from 0, it is different from textbook
	int leftIndex = index * 2 + 1;
	int rightIndex = index * 2 + 2;
	int largestIndex = index;
	if(leftIndex < v.size() && v[index] < v[leftIndex])
		largestIndex = leftIndex;
	if(rightIndex < v.size() && v[largestIndex] < v[rightIndex])
		largestIndex = rightIndex;
	if(largestIndex != index)
	{
		swapTimes++;
		int temp = v[index];
		v[index] = v[largestIndex];
		v[largestIndex] = temp;
		maxHeapify(v, largestIndex);
	}
	return;
}

void maxHeapifyVector(std::vector<int>& v)
{
	//heapify it bottom up
	for(int i = (v.size() - 1)/2; i >= 0; i--)
	{
		maxHeapify(v, i);
	}
	std::cout << swapTimes << " swaps happened." << std::endl;
}
