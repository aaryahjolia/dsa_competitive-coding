
```
#include <iostream>
using namespace std;
int main()
{

    int cmd = 0;
    for (int num = 0;; ++num)
    {
        cout << "Want to play CarRumming game" << endl
             << "Enter 1 for YES or 0 for NO";
        cin >> num;

        if (num == 0)
        {
            return 1;
        }
        else
        {

            cout << "Enter 1: start(to start a car)" << endl
                 << "Enter 2: Run (for run)" << endl
                 << "Enter 3: break (for temp. stop the car)" << endl
                 << "Enter 4: help(for guide)" << endl
                 << "Enter 5: exit(for exit from the game)";

            cin >> cmd;

            if (cmd == 1)
            {
                cout << "Car is started.." << endl;
            }

            else if (cmd == 2)
            {
                cout << "Car is Running.." << endl;
            }

            else if (cmd == 3)
            {
                cout << "Car is taking break.." << endl;
            }
            else if (cmd == 4)
            {
                cout << "Here is a guide..\n"
                     << endl;
            }
            else if (cmd == 5)
            {
                return 1;
            }
            else
            {
                cout << "Invalid number" << endl;
            }
        }
    }

    return 0;
}```