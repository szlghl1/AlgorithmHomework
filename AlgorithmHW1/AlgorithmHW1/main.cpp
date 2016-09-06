#include <iostream>
#include <list>
#include <vector>
#include <chrono>

int main()
{
	auto pushNNodeFront = [](int n, std::list<int>& l)
	{
		for (int i = 0; i != n; i++)
		{
			l.push_front(0);
		}
	};
	//pretending there is no pointer pointing to the tail
	auto pushNNodeBack = [](int n, std::list<int>& l)
	{
		//std::cout << n << " nodes inserting." << std::endl;
		for (int i = 0; i != n; i++)
		{
			auto j = l.begin();
			while (j != l.end()) j++;
			l.insert(j, 1);
			//std::cout << "n = " << n << " i = " << i << '\r';
		}
		//std::cout << n << " nodes inserted." << std::endl;
	};

	for (auto i = 0; i != 10; i++)
	{
		std::list<int> l;
		int numNode = 50 << i;
		auto start = std::chrono::system_clock::now();
		//pushNNodeFront(numNode, l);
		pushNNodeBack(numNode, l);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start;
		//std::cout << "Time to push " << numNode << " nodes " 
		//<< "to the head of a linked list equals " << diff.count() << " seconds." << std::endl;
		std::cout << "Time to push " << numNode << " nodes " 
		<< "to the back of a linked list equals " << diff.count() << " seconds." << std::endl;
	}
}