

#ifndef ESEMPIO3_H
#define ESEMPIO3_H
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swap(T array[], int i, int j){
    T flag = array[i];
    array[i] = array[j];
    array[j] = flag;
}

template <typename T>
void printArray(T array[], int dim){
    cout << "[ ";
    for (int i =0;i<dim;i++)
        cout << array[i] << " ";
    cout << "]" << endl;
}

template <typename T>
void printArray(T array[], int start, int dim){
    cout << "[ ";
    for (int i =start;i<dim;i++)
        cout << array[i] << " ";
    cout << "]" << endl;
}

template <typename T>
void bblSrt(T array[], int length, bool verbose){
    if(verbose)
        cout << "Start bubble sort function..." << endl;
    for(int i=0; i<length-1; i++){
        bool isSwap = false;
        for(int j=0; j<length-i-1; j++)
            if(array[j] > array[j+1]){
                swap(array, j, j+1);
                isSwap = true;
            }
        if(!isSwap)
            break;
        if(verbose)
            printArray(array,length);
    }
    if(verbose)
        cout<<"End bubble sort function"<<endl;
}

template <typename T>
void selSrt(T array[], int length, bool verbose){
    if(verbose)
        cout << "Start selection sort function..." << endl;
    int minIndex;
    for(int i=0; i<length-1; i++){
        minIndex = i;
        T minValue = array[minIndex];
        for(int j=i; j<length-1; j++)
            if(minValue > array[j + 1]){
                minValue = array[j+1];
                minIndex = j+1;
            }
        if(i!=minIndex){
            swap(array,i,minIndex);
        }
        if(verbose)
            printArray(array,length);
    }
    if(verbose)
        cout<<"End reverse function"<<endl;
}

void shellSort(int array[], int length, bool verbose){
    if(verbose)
        cout << "Start shellSort function..." << endl;
    for(int gap=length/2; gap>0; gap/=2){
        if(verbose){
                printArray(array,length);
                cout << "Gap >> " << gap << endl;
            }
        for(int i=gap; i<length; i++){
            int j=i;
            while(j-gap>=0 && array[j]<array[j - gap]){
                if(verbose)
                    cout << "swapping -> [" << array[j] << "] <-> [" << array[j-gap] << "]" << endl;
                swap(array,j,j-gap);
                j-=gap;
            }
        }
    }
    if(verbose)
        cout << "End shellSort function..." << endl;
}

template <typename T>
void reverse(T array[], int length, bool verbose){
    if(verbose)
        cout << "Start reverse function..." << endl;
    int middle = length/2;
    for(int i=0; i<middle; i++){
        swap(array, i, length-i-1);
        if (verbose)
            printArray(array, length);
    }
    if(verbose)
        cout<<"End selection sort function"<<endl;
}

template < typename T>
int linearSearch(T array[], int length, T item, bool verbose){
    if(verbose)
        cout << "Start linear search function..." << endl;
    for(int i=0; i<length; i++){
        if(verbose)
            cout << "array[" << i << "] = " << array[i];
        if(array[i]==item){
            if(verbose){
                cout << " == " << item << " item found!" << endl;
                cout << "end of linear search, saved circles: " << length-i-1 << endl;
            }
            return i;
        }
        if(verbose)
            cout << " != " << item << endl;
        
    }
    if(verbose)
        cout << "end linear search function..." << endl;
    return -1;
}




template <typename T>
int dichotomyBinarySearch(T array[], int length, T item, bool toOrder, bool verbose){
    if(verbose)
        cout << "Start DichotomyBinarySearch function..." << endl;
    if(toOrder && verbose){
        cout << "WARNING! toOrder flag is set to True, this will change order of the elements." << endl << "Are you shure?[y/n] ";
        string shure;
        cin >> shure;
        if (shure=="n"){
            cout << "User abort" << endl;
            return -1;
        }
        cout << "Ordering asset." << endl;
        bblSrt(array, length,verbose);
    }
   
    
    int low = 0;
    int high = length;
    int mid = 0;
    
    while(low<=high){
        mid =(low+high)/2;
        if(verbose){
            cout << "considering subarray:" << endl;
            printArray(array,low,high);
            cout << "array[mid] = " << array[mid] << endl;
        }
        if(array[mid]==item){
            cout << "Good news from DichotomyBinarySearch - item found!" << endl;
            return mid;
        }
        else if(array[mid]<item)
            low = mid+1;
        else if(array[mid]>item)
            high = mid-1;
        if (low==high)
            break;
            
    }
    if(verbose)
        cout << "end DichotomyBinarySearch function..." << endl;
    return -1;
}



#endif // ESEMPIO3_H
