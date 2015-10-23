#include <iostream>
#include <fstream>
#include <Windows.h>
#include <process.h>
#include <algorithm>
#include <vector>
#include <string>
#include <conio.h>
#include <new>

int main(void);
float cost(); //calculate cost
void read_matrix(); //read from file
void generate_permuatation_base(); //permutations base
void find_road(); // yeah, baby!
//globals
int* permutation_base;
float** matrix;
int node_num;
int* shoretest_road;
float lowest_cost = 1000;

int main()
{
	read_matrix();
	generate_permuatation_base();
	do
	{
		cost();
	} while (std::next_permutation(permutation_base, permutation_base + node_num - 1));
	std::cout << std::endl << lowest_cost << " <> ";
	for (int i = 0; i < node_num - 1; i++)
		std::cout << shoretest_road[i] << " - ";
	std::cout << "0";
	_getch();
	return 0;
}

void read_matrix()
{
	std::fstream file;
	file.open("w6.txt", std::ios::in);
	if (file.good() == true)
	{
		file >> node_num;
		matrix = new float*[node_num];
		for (int i = 0; i < node_num; i++)
			matrix[i] = new float[node_num];

		for (int i = 0; i < node_num; i++)
		{
			for (int j = 0; j < node_num; j++)
			{
				file >> matrix[i][j];
			}
		}
		file.close();
	}
}

void generate_permuatation_base()
{
	permutation_base = new int[node_num - 2];
	shoretest_road = new int[node_num - 2];
	for (int i = 0; i < (node_num - 1); i++)
	{
		permutation_base[i] = i + 1;
	}
}

float cost()
{
	float c = 0;
	c += matrix[0][permutation_base[0]];
	for (int i = 0; i < (node_num - 2); i++)
	{
		c += matrix[permutation_base[i]][permutation_base[i + 1]];
	}
	c += matrix[0][permutation_base[node_num - 2]];
	if (c < lowest_cost)
	{
		lowest_cost = c;
		for (int i = 0; i < node_num - 1; i++)
			shoretest_road[i] = permutation_base[i];
	}
	return c;
}