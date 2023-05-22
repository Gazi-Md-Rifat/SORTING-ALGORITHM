#include <iostream>
using namespace std;

void merge(int array[], int l, int r, int mid){
    int temp_1 = mid - l +1;
    int temp_2 = r - mid;

    // create temp array for store before mid point value and after mid point value
    int temp_arr_1[temp_1];
    int temp_arr_2[temp_2];
    // sotre value in temp array
    for (int i = 0; i < temp_1; i++){
        temp_arr_1[i] = array[l + i];
    }
    for (int i = 0; i < temp_2; i++){
        temp_arr_2[i] = array[mid + 1 + i];
    }
    int i = 0, j = 0, k = l; 
    // i represent the index of temp array 1 and j represent the index of temp array 2 and k represent the index of main array
    // assend value in main array through compair temp arry 1 with temp array 2;
    while (i < temp_1 && j < temp_2){
        if (temp_arr_1[i] > temp_arr_2[i]){
            array[k] = temp_arr_2[j];
            j++;
            k++;
        }
        else {
            array[k] = temp_arr_1[i];
            i++;
            k++;
        }
    }
    // if temp array 2 index is over for doing compare with temp array 1 then will store value in main array from next all value from temp aray 1
    while (i < temp_1){
        array[k] = temp_arr_1[i];
        i++;
        k++; 
    }
    // if temp array 1 index is over for doing compare with temp array 2 then will store value in main array  from next all value from temp array 2;
    while (j < temp_2){
        array[k] = temp_arr_2[j];
        j++;
        k++;
    }

    return;
}

void merge_sort(int array[], int l, int r){
    if (l < r){
       int mid = (l + r) / 2;
       merge_sort(array, l, mid);
       merge_sort(array,mid + 1,r);
       merge(array, l, r, mid);
    }
    return;
}

int main (){

    int n;
    cout << "put your array size : ";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << "your putted array is : " << endl;
    for (int i = 0 ; i < n; i++){
        cout << array[i] << " ";
    }
    int l = 0, r = n-1;
    merge_sort(array,l, r );
    cout << endl << "your merge sort array is : " << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }


    return 0;
}