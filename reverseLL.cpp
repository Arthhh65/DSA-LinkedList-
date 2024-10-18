#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }
    
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* reverseLL(Node*head){
    Node*temp= head;
    Node*prev= nullptr;
    while(temp){
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }return prev;
}