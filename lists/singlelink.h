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

#ifndef SINGLELINK_H
#define SINGLELINK_H
#include "node.h"

using namespace std;
/**
 * @todo write docs
 */
class SingleLink
{
private:
    Node* tail;
    Node* head;
public:
    SingleLink(){
        head = new Node();
        head->data = "A";
        head->next = nullptr;
        
        Node* nodeB = new Node();
        nodeB->data = "B";
        nodeB->next = nullptr;
        head->next = nodeB;
        
        Node* nodeC = new Node();
        nodeC->data = "C";
        nodeC->next = nullptr;
        nodeB->next = nodeC;
        
        tail = new Node();
        tail->data = "D";
        tail->next=nullptr;
        nodeC->next = tail;
    }
    
    void output(){
        Node* p = head;
        
        while(p!=nullptr){
        
            cout << p->data << " -> ";
            p = p->next;
        }
        cout<<"End\n\n";
    }
    
    void add(string data){
    
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    
    void insert(int pos, string data){
    
        Node* newNode = new Node();
        newNode->data = data;
        Node* p = head;
        for(int i=0; i<pos-1 && p!=tail; i++){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    
    void remove(int pos){
        if(pos<=0){
            Node* temp = head;
            head = head->next;
            temp->next = nullptr; //serve?
            delete temp;
            return;
        }
        
        Node* p = head;
        for(int i=0; i<pos-1 && p!=tail; i++)
            p=p->next;
        
        Node* temp = p->next;
        p->next = p->next->next;
        temp->next = nullptr; //serve?
        delete temp;
    }
    
    ~SingleLink(){
    
        Node* p = head;
        Node* temp = p;
        
        while(p!=nullptr) {
            temp = p;
            p = p->next;
            delete temp;
        }
    }
};

#endif // SINGLELINK_H
