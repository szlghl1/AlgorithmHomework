#include <iostream>
#include <vector>

int swapTimes = 0;
void maxHeapifyVector(std::vector<int>& v);

int main(int argc, char const *argv[])
{
	std::vector<int> v = {23, 56, 87, 46, 57, 12, 78, 23, 12, 43, 99, 89, 54, 32, 25, 19, 17, 14, 11, 10};
	maxHeapifyVector(v);
	std::cout << "The heapified vector: " << std::endl;
	for(auto i = v.begin(); i != v.end(); i++)
		std::cout << *i << ' ';
	return 0;
}

void maxHeapify(std::vector<int>& v, int index)
{
	int leftIndex = index * 2;
	int rightIndex = index * 2 + 1;
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
