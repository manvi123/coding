#include <iostream>

using namespace std;

int faccalculate(int number);
int main()
{
    int number;
    cout<< "enter the number" << endl;
    cin >> number;
    int result = faccalculate(number);
    cout << "result =" << result << endl;
}

int faccalculate(int number)
{
    if(number ==1)
    {
        return 1;
    }
    return (number*faccalculate(number-1));
}
