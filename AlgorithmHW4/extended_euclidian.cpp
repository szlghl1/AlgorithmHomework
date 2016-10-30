#include <iostream>
#include <fstream>

int find_multiple_inverse(const int in, const int modulo)
{
	std::ofstream csv;
	csv.open("find_multiple_inverse_i.csv");
	int a = modulo, b = in, q = 0, r = a % b;
	int pre_alpha = 0, pre_beta = 1, prpre_alpha = 1, prpre_beta = 0, pre_q = static_cast<int>(a / b);
	csv << "K,A,B,Q,R,Alpha,Beta" << std::endl;
	csv << "-1,N/A,N/A,N/A,N/A,1,0" << std::endl;
	csv << "0," << in << ',' << modulo << ',' << pre_q << ',' << r << ",0,1" << std::endl;
	if(modulo < in)
	{
		std::cout << "modulo is smaller than input" << std::endl;
		return -1;
	}
	if(r == 0)
	{
		std::cout << "check your input" << std::endl;
		return -1;
	}
	int i = 1;
	while(b != 1)
	{
		a = b;
		b = r;
		q = static_cast<int>(a / b);
		r = a % b;
		int alpha = prpre_alpha - pre_alpha * pre_q;
		int beta = prpre_beta - pre_beta * pre_q;
		prpre_alpha = pre_alpha;
		pre_alpha = alpha;
		prpre_beta = pre_beta;
		pre_beta = beta;
		pre_q = q;
		csv << i << ',' << a << ", " << b << ", " << q << ", " << r << ", " << alpha << ", "\
		<< beta << ", " << std::endl;
		i++;
	}

}
int main()
{
	find_multiple_inverse(9889, 12103);
}