#include <fstream>
#include <iostream>
#include <iomanip>

// create a function to map numbers from [1,5] to [-1,2] 
double Map(double x)
{
	return (3.0 / 4.0) * x - (7.0 / 4.0);
}

int main()
{
	std::ifstream data("data.txt"); // reading the text file data.txt
	std::ofstream result("result.txt"); //create a text file called result.txt
	
	// printing error if file cannot be read
	if (data.fail())
	{
		std::cerr<<"file not found"<<std::endl;
		return 1;
	}
	
	// initialize variables val, N and sum to compute the partial means progressively
	double val;
	int N=0;
	double sum=0;
	
	result << "# N Mean" << std::endl;

	// appending the partial mean values in the result.txt file while be computed 
	while(data>>val)
	{	
		N += 1; 
		sum += Map(val);
		result << N << " " << std::scientific << std::setprecision(16) << (sum/N) << std::endl;
	}
	
	data.close();
	result.close();
	
    return 0;
}
