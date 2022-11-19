#include <iostream>
#include "singlelink.h"

using namespace std;

int main(int argc, char **argv) {
    
    SingleLink* list = new SingleLink();
    
    list->insert(5,"Z");
    list->output();
    list->remove(520);
    list->output();    
    delete list;
    
    
    return 0;
}
