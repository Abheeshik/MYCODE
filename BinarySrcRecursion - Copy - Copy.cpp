#include<iostream>
using namespace std;

bool BinarySearch(int arr[] , int start , int end , int key )
{
    if (start > end )
    {
        return false;
    }
    int  mid = start + (end - start)/2;

    if (arr[mid] == key)
    {
        return true;
    }
    
    if(arr[mid] <  key)
    {
            
        return BinarySearch(arr, mid +1, end ,key );
    }

    else
    {
        return BinarySearch(arr, start , mid -1 ,key );
             
    }
}


int main()
{
    int arr[] = {4,6,7,11,15,22,33};

    int size = 7;
    
    int key = 111;

    int ans = BinarySearch(arr , 0 , 6 , key);
    
    if (ans)
    {
       cout << "element found" << endl;
    }
    else{
        cout << "element not found" << endl;
        
    }
}