#include<iostream>
#include<vector>

using namespace std;

class clsA
{
public:
	//Parametarized Constructor
	clsA(int value)
	{
		x = value;
	}

	int x;

	void Print()
	{
		cout << "The value of x=" << x <<endl;
	}
};

int main() 
{
	vector <clsA> v1;
	short NumberOfObjects=5;

	// inserting object at the end of vector
	for (int i = 0; i < NumberOfObjects; i++)
	{
		v1.emplace_back(i);
	}

	// printing object content
	for (int i = 0; i < NumberOfObjects; i++)
	{
		v1[i].Print();
	}

	return 0;
}

