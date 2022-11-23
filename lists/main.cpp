#include <iostream>
#include "singlelink.h"
#include <string>

using namespace std;

//chiamata ricorsiva
long factorial(int n){
    if(n==1)
        return 1;
    else
        return factorial(n-1)*n;
}

int main(int argc, char **argv) {
    
    SingleLink* list = new SingleLink();
    for(int i : {1,2,3,4,5,6}){
        list->insert(0, to_string(factorial(i)));
    }
    list->output();
    delete list;
    
    
    return 0;
}
