#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

//If you don't want to set maxSum manully, you can calculate it by sum(max_side(dice_i))
void dp_dice(const std::vector<std::vector<int>> dice, const int maxSum)
{
	const int ndice = dice.size();
	if (!ndice)
		return;
	//row for dice, column for sum, which is easier to loop
	std::vector<std::vector<int>> dp(ndice + 1, std::vector<int>(maxSum + 1, 0));
	dp[0][0] = 1;
	std::vector<std::unordered_map<int, int>> dice_has_nSide_of_n(ndice);
	std::ofstream csv;
	csv.open("dp_dice.csv");

	csv << ',';
	for (int i = 0; i <= maxSum; i++)
	{
		csv << "sum = " << i << ',';
	}
	csv << std::endl;

	for (int i = 0; i != ndice; i++)
	{
		for (int j = 0; j != dice[0].size(); j++)
		{
			dice_has_nSide_of_n[i][dice[i][j]] += 1;
		}
		csv << "dice #" << i + 1 << ',';
		for (int j = 0; j <= maxSum; j++)
		{
			for (auto k = dice_has_nSide_of_n[i].begin(); k != dice_has_nSide_of_n[i].end(); k++)
			{
				if (k->first > j)
				{
					continue;
				}
				else
				{
					dp[i + 1][j] += k->second * dp[i][j - k->first];
				}
			}
			csv << dp[i + 1][j] << ',';
		}
		csv << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> v = { { 1,2,2,3,3,4 },{ 1,1,1,3,4,4 },{ 1,1,1,2,2,3 } };
	dp_dice(v, 10);
	return 0;
}