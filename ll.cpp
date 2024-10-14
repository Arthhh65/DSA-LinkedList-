#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node{
    int data ;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};

Node* change2LL(vector<int>&arr){
    Node* head= new Node(arr[0]);
    Node*mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp = new Node(arr[i]);
        mover->next=temp;
        mover= temp;
    }return head;
}

int checkIfPresent(Node*head,int val){
    Node* temp = head;
    while(temp){
        if(temp->data==val){
            return 1;
        }
        temp= temp->next;
    }return 0;
}

Node* insertNode(Node* head, int val,int k){
    if (head==NULL){
        if (k==1)return new Node(val);
        else return NULL;
    }
    if (k==1){
        return new Node(val,head);
    }
    int count=0;
    Node* temp=head;
    while(temp !=NULL){
        count++;
        if (count ==k-1){
            Node *x=new Node(val ,temp->next);
            temp->next=x;
        }temp = temp->next;
    }return head;
}

Node* deleteNode(Node*head,int k){
    if (head==NULL){
        return NULL;
    }
    if (k==1){
        Node*temp = head;
        head = head->next;
        delete temp;
    }
    int count=0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        count++;
        if (count==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }prev=temp;
        temp=temp->next;
    }return head;
}

int printLL(Node*head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }return 1;
}

int main() {
    vector<int> arr = {2,3,4,5,6,7};
    Node* head = change2LL(arr);
    head= deleteNode(head,5);
    printLL(head);
    
    return 0;
}