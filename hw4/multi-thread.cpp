#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;
int i = 1;

void buyRedBoxMovie()
{
	m.lock();
	
	cout << " Customer " << i << " is Looking at movie options" << endl;
	i++;
	m.unlock();
	cout << " --Customer " << i - 1 << " bought a movie and left the kiosk \n" << endl;
}

int main()
{
	thread cust1(buyRedBoxMovie);
	thread cust2(buyRedBoxMovie);
	thread cust3(buyRedBoxMovie);
	cust1.join();
	cust2.join();
	cust3.join();

	system("pause");
	return 0;
}