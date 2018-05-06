#include <iostream>
//Jonathan Branson

using namespace std;

int main()
{
    cout << "\nData Type            Bytes"
         << "\n---------            -----"
         << "\nint                    " << sizeof(int)
         << "\nunsigned int           " << sizeof(unsigned int)
         << "\nshort int              " << sizeof(short int)
         << "\nunsigned short int     " << sizeof(unsigned short int)
         << "\nlong int               " << sizeof(long int)
         << "\nunsigned long int      " << sizeof(unsigned long int)
         << '\n';

    return 0;
}
