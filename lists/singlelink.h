#ifndef SINGLELINK_H
#define SINGLELINK_H
#include "node.h"

using namespace std;/**
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
        head->data = "HEAD";
        head->next = nullptr;
        
        tail = head;
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
