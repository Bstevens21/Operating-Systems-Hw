#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void do_stuff() {
	cout << "doing stuff" << endl;
}


void main() {
	clock_t begin1 = clock();
	for (int i = 0; i < 100; i++)
	{
		do_stuff();
	}
	clock_t end1 = clock();

	float time1 = float(end1 - begin1) / CLOCKS_PER_SEC;

	clock_t begin2 = clock();

	for (int i = 0; i < 100; )
	{
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
		do_stuff(); i++;
	}
	clock_t end2 = clock();

	float time2 = float(end2 - begin2) / CLOCKS_PER_SEC;

	cout << "rolled loop: " << time1 << " milliseconds vs " << "un-rolled loop: " << time2 << " milliseconds" << endl;

	system("pause");
}