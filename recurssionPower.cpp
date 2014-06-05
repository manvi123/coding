#include <iostream>

using namespace std;

int powercalculate(int number, int power);
int main()
{
    int power, number;
    cout<<"enter the power" << endl;
    cin >> power;
    cout<< "enter the number" << endl;
    cin >> number;
    int result = powercalculate(number, power);
    cout << "result =" << result << endl;
}

int powercalculate(int number, int power)
{
    if(power ==1)
    {
        return number;
    }
    return (number*powercalculate(number, power-1));
}
