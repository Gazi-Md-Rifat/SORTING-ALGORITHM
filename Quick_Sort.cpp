#include <iostream>
using namespace std;

void swap(int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(int array[], int l, int r){
    int pvot = array[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (array[j] < pvot){
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, r);
    return i + 1;
}


void quick_sort(int array[], int l, int r){

    if (l < r){
        int pi = partition(array, l, r);
        quick_sort(array, l, pi - 1);
        quick_sort(array, pi + 1, r);
    }
}

int main (){

    int n;
    cout << "Put Your array size : ";
    cin >> n;
    int array[n];
    cout << "Put your value in array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << endl << endl;
    cout << "Your array is : " << endl;
     for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    int l = 0, r = n-1;
    quick_sort(array, l, r );

    cout << endl << endl << "Your Quick Sort Result : " << endl;
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;


    return 0;
}