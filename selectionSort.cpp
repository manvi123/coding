#include <iostream>

using namespace std;
void selectionsort(int *arr, int num);

int main()
{
   int arrsize;
   cout <<"enter the size" << endl;
   cin >> arrsize;
   int arr[arrsize];
   
   for(int i =0;i<arrsize;i++)
   {
       arr[i]= (rand()%1000)+1;
   }
   /*for(int i =0;i<arrsize;i++)
   {
       cout<< arr[i] <<endl;
   }*/
   selectionsort(arr,arrsize);
   cout << "sorted array is = "<< endl;
   for(int i=0;i<arrsize;i++)
    {
        cout<< arr[i]<<endl;
    }
}

void selectionsort(int *arr, int num)
{
    int temp =0;
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    }
}

SWAP without temp
using + and -
a= a+b
b = a-b;
a = a-b;

using * and /

a = a*b
b = a/b
a = a/b

using XOR ( works only for integers)
a ^= b ^= a ^= b
