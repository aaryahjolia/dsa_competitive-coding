Printing the inverted triangle pattern using for loop.

#include <iostream>
using namespace std;

void printInvTriangle(int n)
{

	for (int i = 0; i < n; i++) {

		int space = i;

		
		for (int j = 0; j < 2 * n - i - 1; j++) {

			if (space) {
				cout << " ";
				space--;
			}
			else {
				cout << "* ";
			}
		}
		cout << endl;
	}
}

int main()
{
	printInvTriangle(5);

	return 0;
}

Output

* * * * * * * * * 
  * * * * * * * 
    * * * * * 
      * * * 
        * 