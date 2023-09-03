
```
#include <string>
#include <iostream>
using namespace std;

string how_much_i_love_you(int nb_petals)
{
  if (nb_petals % 6 == 1)
    return "I love you";
  else if (nb_petals % 6 == 2)
    return "a little";
  else if (nb_petals % 6 == 3)
    return "a lot";
  else if (nb_petals % 6 == 4)
    return "passionately";
  else if (nb_petals % 6 == 5)
    return "madly";
  else if (nb_petals % 6 == 0)
    return "not at all";
}

int main()
{
  int nb_petals = 0;
  cout << "enter number of petals: ";
  cin >> nb_petals;

  if (nb_petals > 0)
    cout << how_much_i_love_you(nb_petals);
  else
    cout << "Invalid number";

  return 0;
}```