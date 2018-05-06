//Jonathan Branson
//Chapter 3.2
/*
This program illusttates the use of the prefix and postfix increment
It also shows how to write several shortcut assignment statements
*/

#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

int main()
{
    int i = 3;
    int sum = 14;

    cout << "Original value of i is " << i << '\n';

    i = i + 1;
    cout << "Value of i increased by 1 " << i << '\n';

    i++;
    cout << "Value of i increased by 1 a second time. " << i << '\n';

    ++i;
    cout << "Value of i increased by 1 a third time. " << i << '\n';

    cout << "Value of i increased by 1 a fourth time using prefix. " << i++ << '\n';

    cout << "Value of i increased by 1 a fifth time using postfix. " << ++i << '\n';

    cout << "Value changed in i shows up the next time the variable is accessed. " << i << '\n';

    cout << "\n\n\nOther Shortcuts\n\n";

    sum = sum +3;
    cout << "The sum is increase by 3 " << sum << '\n';

    sum += 3;
    cout << "The sum is increased by 3 a second time " << sum << '\n';

    sum += i;
    cout << "The sum is increase by the value of i where i = 8 " << sum << '\n';

    sum *= sum;
    cout << "The sum is multiplied by itself and stored in sum " << sum << '\n';


    return 0;
}
