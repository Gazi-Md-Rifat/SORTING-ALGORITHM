#include <iostream>
using namespace std;

// Each value should be 0,1 or 2...Because this DNF algorithm work just for three similar value...
// Example : 0,1,0,0,2,2,1,0,1,1,2,2,0,1,0,2...........................


void swap_func(int array[], int mid, int low){
    int temp = array[mid];
    array[mid] = array[low];
    array[low] = temp;

}

void DNF_sort(int array[], int n){

    int low = 0 , mid = 0;
    int  high = n - 1;

    while (mid <= high){
        if (array[mid] == 0){
            swap_func(array, mid, low);
            low++;
            mid++;
        }
        else if (array[mid] == 1){
            mid++;
        }
        else if (array[mid] == 2){
           swap_func(array, mid, high);
            mid++;
            high--;
        }
    }

}

int main (){

    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    DNF_sort(array, n);
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    return 0;
}