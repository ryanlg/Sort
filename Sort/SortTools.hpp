//
//  SortTools.hpp
//  Sort
//
//  Created by Ryan Liang on 3/20/16.
//  Copyright © 2016 Ryan Liang. All rights reserved.
//

typedef int SORT_ORDER;
const static SORT_ORDER ascending = 0;
const static SORT_ORDER decending = 1;

template <typename T>
class SortTools {
public:
    static T* insertSort(T *array, int total, SORT_ORDER order = ascending);
    static T* selectSort(T *array, int total, SORT_ORDER order = ascending);
    static T* bubbleSort(T *array, int total, SORT_ORDER order = ascending);
    
    static int* searchInOrder(T *array, T searchFor,int *resultArray, int total);
    static int* searchDiv(T *array, T searchFor,int *resultArray, int total);

};

