//
//  SortTools.cpp
//  Sort
//
//  Created by Ryan Liang on 3/20/16.
//  Copyright © 2016 Ryan Liang. All rights reserved.
//

#include "SortTools.hpp"

template <typename T>
T* SortTools<T>::insertSort(T *array, int total, SORT_ORDER order) {
    int iout = 0, templ = 0;
    T *tempArray = new T[total];
    //T tempArray[number] = {0}; //UNCOMMENT THIS TO DEBUG ON XCODE
    T tNumber;
    
    if (order == ascending) {
        for (; iout < total; iout ++) {
            tNumber = array[iout];
            
            if (tNumber >= tempArray[iout - 1]) {
                tempArray[iout] = tNumber;
                continue;
            }
            
            for (int iin = 0; iin <= iout; iin++) {
                if (tNumber <= tempArray[iin]) {
                    
                    //---------------- ALTERNATIVE--------------//
                    /*while (!(iin == templ)) {
                     tempArray[templ] = tempArray[templ-1];
                     tempArray[templ-1] = tempArray[templ-2];
                     templ--;
                     }*/
                    //---------------- ALTERNATIVE--------------//
                    
                    for (templ = iout; templ > iin; templ--) {
                        tempArray[templ] = tempArray[templ-1];
                        tempArray[templ-1] = tempArray[templ-2];
                    }
                    tempArray[iin] = tNumber;
                    break;
                }
            }
        }
    }else{
        
        for (; iout < total; iout ++) {
                tNumber = array[iout];
                
                if (tNumber <= tempArray[iout - 1]) {
                    tempArray[iout] = tNumber;
                    continue;
                }
                
                for (int iin = 0; iin <= iout; iin++) {
                    if (tNumber >= tempArray[iin]) {
                        
                        for (templ = iout; templ > iin; templ--) {
                            tempArray[templ] = tempArray[templ-1];
                            tempArray[templ-1] = tempArray[templ-2];
                        }
                        tempArray[iin] = tNumber;
                        break;
                    }
                }
        }
    }
    return tempArray;
}

template <typename T>
T* SortTools<T>::selectSort(T *array, int total, SORT_ORDER order){
    for (int iout = 0; iout < total; iout++) {
        for (int iin = iout; iin < total; iin++) {
            if (order == ascending) {
                
                if ( array[iin] <= array[iout] ) {
                    T temp = array[iin];
                    array[iin] = array[iout];
                    array[iout] = temp;
                }
                
            }else{
                
                if ( array[iin] >= array[iout] ) {
                    T temp = array[iin];
                    array[iin] = array[iout];
                    array[iout] = temp;
                }
                
            }
        }
    }
    return array;
}

template <typename T>
T* SortTools<T>::bubbleSort(T *array, int total, SORT_ORDER order){
    int currentLocation = total;
    while (currentLocation > 0) {
        for (int iout=0;iout < total; iout++) {
            if (order == ascending) {
                if (array[iout] > array[iout + 1]) {
                    T temp = array[iout];
                    array[iout] = array[iout+1];
                    array[iout+1] = temp;
                }
            }else{
                if (array[iout] < array[iout + 1]) {
                    T temp = array[iout];
                    array[iout] = array[iout+1];
                    array[iout+1] = temp;
                }
            }
        }
        currentLocation--;
    }
    
    return array;
}

template <typename T>
int* SortTools<T>:: searchInOrder(T *array, T searchFor, int *resultArray, int total){
    int count = 0;
    for (int i = 0; i < total; i++) {
        if (array[i] == searchFor) {
            resultArray[count] = i+1;
            count ++;
        }
    }
    
    if (count == 0)  {return nullptr;}
    
    return resultArray;
}

template <typename T>
int* SortTools<T>:: searchDiv(T *array, T searchFor, int *resultArray, int total){
    int count = 0;
    int offest = total/2;
    int currentLocation = offest;
    
    while (offest != 0){
        
        offest = (offest+1)/2; //+1 IS ESSENTIAL TO GET NUMBERS RIGHT;
        
        //NEXT PART
        //offest = (offest+1)/2 -> GET TO THE NEXT HALF PART OF ARRAY -> IF IT'S EQUAL TO searchFor, SEARCH AROUND FOR MORE ('CAUSE NUMBERS ARE ORDER);
        
        if (array[currentLocation] == searchFor) {
            int c = currentLocation + 1;  //+1 TO AVOID DUPLICATION IN resultArray;
            
            
            //SEARCH AROUND FOR MORE;
            while (array[currentLocation] == searchFor) {
                resultArray[count]=currentLocation + 1; //+1 TO START COUNTING FROM 1;
                count++;
                currentLocation--;
            }
            
            while (array[c] == searchFor) {
                resultArray[count]=c + 1;  //+1 TO START COUNTING FROM 1;
                count++;
                c++;
            }
            break; //AVOID TOO MANY CYCLE;
            
            
        }else if (array[currentLocation] < searchFor){
            currentLocation += offest;
        }else{
            currentLocation -= offest;
        }
    }
    
    if (count == 0) {
        return nullptr;
    }
    
    return resultArray;
}

















