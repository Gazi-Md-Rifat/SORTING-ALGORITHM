#include <iostream>
#include <algorithm>
using namespace std;


void count_sort(int array[], int n){
    // find max number in array
    int k = array[0];
    for (int i = 0; i < n; i++){
        k = max(k, array[i]);
    }
    // create count array ..size will max size..
    int count_array[k + 1] = {0};
    for (int i = 0; i < n; i++){
        count_array[array[i]]++;
    }
    // modify count array..
    for (int i = 1; i <= k; i++){
        count_array[i] += count_array[i - 1]; 
    }
    // make a array similar size of main array..
    int output_array[n];
    for (int i = n - 1; i >= 0; i--){
        output_array[--count_array[array[i]]] = array[i];
    }
    // store value output array to main array..
    for (int i = 0; i < n; i++){
        array[i] = output_array[i];
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
    count_sort(array, n); 
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }


    return 0;
}