#include <iostream>
#include <vector>
#include <string>

enum class Direct { Up, Left, Diagonal };

std::string dp_LCS(const std::string s1, const std::string s2)
{
	if (s1.empty() || s2.empty())
		return std::string();
	std::vector<std::vector<int>> dp_length(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));
	std::vector<std::vector<Direct>> dp_direct(s1.size() + 1, std::vector<Direct>(s2.size() + 1));
	std::string subsequence;
	for (int i = 0; i != s1.size(); i++)
	{
		for (int j = 0; j != s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				dp_length[i + 1][j + 1] = dp_length[i][j] + 1;
				dp_direct[i + 1][j + 1] = Direct::Diagonal;
			}
			else if (dp_length[i][j + 1] >= dp_length[i + 1][j])
			{
				dp_length[i + 1][j + 1] = dp_length[i][j + 1];
				dp_direct[i + 1][j + 1] = Direct::Up;
			}
			else
			{
				dp_length[i + 1][j + 1] = dp_length[i + 1][j];
				dp_direct[i + 1][j + 1] = Direct::Left;
			}
		}
	}
	int i = dp_direct.size() - 1, j = dp_direct[0].size() - 1;
	while(i != 0 && j != 0)
	{
		switch (dp_direct[i][j])
		{
		case Direct::Left: j--; break;
		case Direct::Up: i--; break;
		case Direct::Diagonal: subsequence = (s1[i - 1]) + subsequence; i--; j--; break;
		}
	}

	return subsequence;
}

int main(int argc, char const *argv[])
{
	std::string input1("ACTGAACTCTGTGCACT"), input2("TGACTCAGCACAAAAAC");
	std::string s = dp_LCS(input1, input2);
	std::cout << "The longest common subsequence is:\n" << s << std::endl;
	std::cout << "Its length equals " << s.length() << std::endl;
	return 0;
}