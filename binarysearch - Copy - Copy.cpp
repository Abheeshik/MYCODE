#include<iostream>
using namespace std;

int binaryseach(int arr[],int size,int key)
{
     int mid,start,end;

     start = 0;
     end = size - 1;

     mid = start + (end-start)/2;

     while(start <= end)
     {
         if(arr[mid] == key){
             return mid;
         }

         if(key > arr[mid]){
             start = mid +1;
         }
         if(key <arr[mid]){
             end = mid -1;
         }

         mid = start + (end - start)/2;

     }
     return -1;
}

int main()
{
    int even[8] = {12,34,56,77,88,90,91,94};
    int odd[7] = {2,4,6,12,16,19,23};

    int evenIndex = binaryseach(even,8,94);

    cout << "index of 94 is " << evenIndex << endl;

    int oddIndex = binaryseach(odd,7,12);

    cout << "index of 12 is " << oddIndex << endl;



}