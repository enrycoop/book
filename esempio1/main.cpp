#include <iostream>
#include "esempio3.h"

using namespace std;


int main(int argc, char **argv) {
    
    /*string array[] = {"Enrico", "Dario","Dora", "Ilaria","Antonio","Fcaldo","Giovanni","Patrizia","Ziovanni","Giacomo"};
    int length = 10;*/
    int array[] = {9,6,5,8,0,7,4,3,1,2};
    int length = sizeof(array)/sizeof(array[0]);
    
    printArray(array, length);
    
    shellSort(array,length, true);
    
    printArray(array, length);
    
    //reverse(array, length, false);
    
    //printArray(array, length);
    
    int item;
    cout << "Insert element to search: ";
    cin >> item;
    
    //int index = linearSearch(array, length, item, true);
    int index = dichotomyBinarySearch(array, length,item,false,true);
    
    if(index==-1)
        cout << "Item not found."<< endl;
    else
        cout <<"Item "<<item<<" found at position "<<index<<endl;
    
    cout << "*** End of program. ***" << endl;
    
    return 0;
}
