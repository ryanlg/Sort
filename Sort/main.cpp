//
//  main.cpp
//  Insert Sort
//
//  Created by Ryan Liang on 3/19/16.
//  Copyright © 2016 Ryan Liang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "SortTools.cpp"
using namespace std;

const int number = 300;
static long long numberArray[number]={0};
static int locationArray[number]={0};
static ifstream openTheFuckingFile("numbers.txt", ios_base::in);;
static ofstream closeTheFuckingFile("numbers.txt", ios_base::app);
#define ARRAYTYPE long long




void writeToFile();
void readFromFile();
void putToFile(int n);
void createRandomNumbers();

template <typename T> void listArray(T *array);
template <typename T> void listArray(T *array, int capacity);
template <typename T> T* sort();




//------------------------------------------------------------------//
int main(int argc, const char * argv[]) {
    //createRandomNumbers();
    
    readFromFile();
    
    listArray<ARRAYTYPE>(SortTools<ARRAYTYPE>::bubbleSort(numberArray, number, ascending), number);
    
    listArray<int>(SortTools<ARRAYTYPE>::searchDiv(numberArray, (int)4, locationArray, number));
    
    return 0;
}
//------------------------------------------------------------------//


template <typename T>
void listArray(T *array) {
    cout<<"***********************************"<<endl;
    if (array == NULL) {
        cout << "NOT FOUND" << endl;
        cout<<"***********************************"<<endl;
        return;
    }
    
    int i = 0;
    while (array[i]) {
        cout << *(array+i)<<endl;
        i++;
    }
    cout<<"***********************************"<<endl;
}

template <typename T>
void listArray(T *array, int capacity) {
    cout<<"***********************************"<<endl;
    
    for (int i = 0; i < capacity; i++) {
        cout << *(array+i)<<endl;
    }
    
    cout<<"***********************************"<<endl;
}

//----------------FROM BOOK FOR COMPARISON--------------//
void insertSort(int a[], int n){
    int temp;
    for (int m = 1; m < n; m++) {
        if(a[m]<a[0]){
            temp=a[m];
            a[m]=a[0];
            a[0]=temp;
        }
        for (int i = 1; i < n; i++) {
            temp = a[i];
            for (int k = i - 1; k >=0; k--) {
                if (temp >= a[k]) {
                    for (int j = i ; j > k+1; j--) {
                        a[j]=a[j-1];
                    }
                    a[k+1]=temp;
                    break;
                }
            }
        }
    }
}
//----------------FROM BOOK FOR COMPARISON--------------//

void putToFile(int n){
    closeTheFuckingFile<<n;
    closeTheFuckingFile<<'\n';
}

void writeToFile(){
    closeTheFuckingFile.close();
}

void readFromFile(){
    ARRAYTYPE tempnumber = 0, count = 0;
    while(openTheFuckingFile >> tempnumber){
        numberArray[count] = tempnumber;
        count++;
    }
    
    //listArray<ARRAYTYPE>(numberArray, number);
    
    //cout << "*************** END OF ORIGINAL ARRAY **************" << endl <<endl;
}

void createRandomNumbers(){
    for (int i = 1; i <= number; i++) {
        putToFile(rand());
    }
    closeTheFuckingFile.close();
}