#include <iostream>
using namespace std;

void swap(int array[], int i, int l){
    int temp = array[i];
    array[i] = array[l];
    array[l] = temp;
}

void Wave_sort(int array[], int n){

    for (int i = 1; i < n; i +=2){
        if (array[i] > array[i - 1]){
            swap(array,i, i-1);
        }
        if (array[i] > array[i + 1] && i <= n-2){
            swap(array, i, i+1);
        }
    }

    return;
}


int main (){

    int n;
    cin >> n;
    int array[n]; 
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    Wave_sort(array, n);
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    return 0;
}