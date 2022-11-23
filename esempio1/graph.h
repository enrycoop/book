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

#ifndef GRAPH_H
#define GRAPH_H
#define STACKSIZE 10000
#define MAX_VERTEX_SIZE 5
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>

template<typename T>
class Vertex
{
public:
    T data;
    int visited;
};

//stack of positive integer elements
class Stack{
private:
    int top;
    int elements[STACKSIZE];
public:
    Stack(){top =-1;}
    
    void push(int element){
        top++;
        elements[top] = element;
    }
    
    int pop(){
        if(top == -1)
            return -1;
        int data = elements[top];
        top--;
        return data;
    }
    
    int peek(){
        if(top == -1)
            return -1;
        int data = elements[top];
        return data;
    }
    
    bool isEmpty(){return top<=-1;}
};

template <typename T>
class Graph
{
private:
    int size;
    Vertex<T> vertexs[MAX_VERTEX_SIZE];
    int adjacencyMatrix[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
    Stack stack;
public:
    Graph(){
        size = 0;
        memset(adjacencyMatrix,0,sizeof(adjacencyMatrix));
    }
    
    void addVertex(T data){
        Vertex<T> vertex;
        vertex.data = data;
        vertex.visited = false;
        
        vertexs[size] = vertex;
        size++;
    }
    
    void addEdge(int from,int to){
        adjacencyMatrix[from][to] = 1;
    }
    
    void addEdge(T from,T to){
        int from_index=-1,to_index=-1;
        int i = 0;
        for(Vertex<T> item : vertexs){
            if(item.data == from)
                from_index = i;
            if(item.data == to)
                to_index = i;
            i++;
        }
        if(from_index!=-1 && to_index!=-1)
            adjacencyMatrix[from][to] = 1;
    }
    
    //scorrimento di tutte le colonne per riga in input
    int findAdjacencyUnVisitedVertex(int row){
        for (int col = 0; col < size; col++)
            if (adjacencyMatrix[row][col] == 1 && !vertexs[col].visited)
                return col;
        return -1;
    }
    
    void depthFirstSearch(){
        using namespace std;
        vertexs[0].visited = true;
        cout << vertexs[0].data;
        stack.push(0);
        
        while(!stack.isEmpty()){
            int row = stack.peek();
            int col = findAdjacencyUnVisitedVertex(row);
            if(col == -1)
                stack.pop();
            else{
            
                vertexs[col].visited = true;
                cout << " -> " << vertexs[col].data;
                stack.push(col);
            }
        }
        clear();
    }
    
    void printGraph(){
        using namespace std;
        for(int i = 0; i < MAX_VERTEX_SIZE; i++){
            cout << vertexs[i].data << " ";
        }
        cout << endl;
        
        for(int i = 0; i < MAX_VERTEX_SIZE; i++){
            cout << vertexs[i].data << " ";
            for(int j = 0; j < MAX_VERTEX_SIZE; j++){
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void clear(){
        for(Vertex<T> v : vertexs)
            v.visited = false;
    }
    
};

#endif // GRAPH_H
