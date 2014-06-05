#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>

using namespace std;
int mergesort(vector<int> &arr, vector<int> &arrout);
int merge(vector<int> &arr1,vector<int> &arr2, vector<int> &arrout);

int main()
{
   int arrsize;
   cout <<"enter the size" << endl;
   cin >> arrsize;
   std:: vector<int> arr;
   for(int i =0;i<arrsize;i++)
   {
       arr.push_back(rand()%1000);
   }
   for(int i =0;i<arr.size();i++)
   {
       cout<< arr[i] <<endl;
   }
   vector<int> arrsorted(arrsize);
   mergesort(arr,arrsorted);
   cout << "sorted array is = "<< endl;
   for(int i=0;i<arrsorted.size();i++)
    {
        cout<< arrsorted[i]<<endl;
    }
}

int mergesort(vector<int> &arr, vector<int> &arrout)
{
    if(arr.size() == 1)
    {
        arrout[0]= arr[0];
        return 0;
    }
    int half = arr.size()/2;
    vector<int> arr1(arr.begin(),arr.begin()+half);
    vector<int> arr2(arr.begin()+half, arr.end());
    vector<int> arr1out(arr1.size());
    vector<int> arr2out(arr2.size());
    
    //cout <<"middle" << middle << endl;
    mergesort(arr1,arr1out);
    mergesort(arr2,arr2out);
    merge(arr1out,arr2out,arrout);
    
    return 0;
}

int merge(vector<int> &arr1,vector<int> &arr2, vector<int> &arrout)
{
    int arrlen =0;
    int i =0,j=0,k=0;
    
    arrlen = arr1.size() + arr2.size();
    cout << "arrlen" << arrlen << endl;
    cout <<"srrout.size" <<arrout.size() << endl;
    while(k!= arrlen)
    {
        if((i!=arr1.size()) && (j!=arr2.size()))
        {
        if(arr1[i] < arr2[j])
        {
            arrout[k] = arr1[i];
            k++;
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            arrout[k]= arr2[j];
            k++;
            j++;
        }
        else if(arr1[i] == arr2[j])
        {
            arrout[k] = arr1[i];
            arrout[k+1] = arr2[j];
            k++;
            i++;
            j++;
        }
        }
        else
        {
            if( i == arr1.size())
            {
                arrout[k] = arr2[j];
                k++;
                j++;                
            }
            else
            {
                arrout[k] = arr1[i];
                k++;
                i++;
            }
        }
        
    }
    
}
