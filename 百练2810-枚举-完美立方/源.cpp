#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N <= 100)
	{

	
	for (int a = 2; a <= N; a++)
	{
		for (int b = 2; b < a; b++)
		{
			for (int c = 2; c <= b; c++)
			{
				for (int d = 2; d <= c; d++)
				{
					if (a * a * a == b * b * b + c * c * c + d * d * d)
						printf("Cube = %d, Triple = (% d,% d,%d)\n", a, b, c, d);
				}
			}
		}
	}
	}

}