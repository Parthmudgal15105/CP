#include <iostream>
using namespace std;

void print(int arr[], int size){
    cout<<"size of array is" << size<< endl;

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int SumOfAll(int arr[], int size){
    print(arr,size);
    //base case
    if(size == 0){
    return 0;
    }
    else{
        return arr[size - 1] + SumOfAll(arr, size - 1);
      
    }

}

int main() {
   int arr[5] = {3,2,5,1,6};
   int size = 5;
   int sum = SumOfAll(arr, size);

   cout << sum << endl;
      cout<<"DONE SUm"<<endl;
    return 0;
}