#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
void bubblesort(vector <int> &arr);

int main()
{
   int arrsize;
   cout <<"enter the size" << endl;
   cin >> arrsize;
   std:: vector <int> arr;
   for(int i =0;i<arrsize;i++)
   {
       arr.push_back(rand()%1000);
   }
   for(int i =0;i<arr.size();i++)
   {
       cout<< arr[i] <<endl;
   }
   bubblesort(arr);
   cout << "sorted array is = "<< endl;
   for(int i=0;i<arrsize;i++)
    {
        cout<< arr[i]<<endl;
    }
}

void bubblesort(vector<int> &arr)
{
    int temp =0;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<(arr.size()-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j] ^= arr[j+1] ^= arr[j] ^= arr[j+1];
            }
        }
    }
}

