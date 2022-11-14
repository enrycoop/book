/*
 * Copyright 2022 enrycoop92 <enrycoop92@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ESEMPIO1_H
#define ESEMPIO1_H

#include <iostream>
#include <cstring>

using namespace std;

int m(){
    int scores[] = {90, 70, 50, 80, 60, 85};
    int length = sizeof(scores) / sizeof(scores[0]);
    for (int i = 0; i < length; i++)
        cout << scores[i] << ", ";
    
    
    int tempArray[length +1]; // amplio tempArray
    
    for(int i = 0; i < length ; i++)
        tempArray[i] = scores[i]; // copia dell'tempArray
    
    tempArray[length] = 75;
    cout << endl;
    memcpy(scores,tempArray,sizeof(tempArray));
    for (int i = 0; i < length+1; i++)
        cout << scores[i] << ", ";
    
    return 0;
    
}




#endif // ESEMPIO1_H
