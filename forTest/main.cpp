#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <random>

using namespace std;


int				main(int ac, char **av)
{
	random_device rd;
   	mt19937 gen(rd());
 	map<int, int> m;
	srand(time(NULL));
	if (ac != 2)
		return (0);
	int number = atol(av[1]);
	int idx = 0;
	int result;
	
	uniform_int_distribution<int> dis(-5000, 5000);
	while (idx < number)
	{
		result = dis(gen);
		m[result]++;
		if (m[result] == 1)
		{
			printf("%d",result);
			if (idx != number - 1)
				printf(" ");
			idx++;
		}		
	}
}