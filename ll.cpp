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

Node* convertArr2LL(vector<int>&arr){
    Node*head= new Node(arr[0]);
    Node*mover=head;
    for (int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }return head;
}

int lengthofLL(Node*head){
    int count =0;
    Node *temp =head;
    while(temp){
        temp = temp->next;
        count++;
    }return count;
}

int printLL(Node*head){
    Node*temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }return 1;
}

int checkIfPresent(Node*head,int val){
    Node*temp = head;
    while(temp){
        if(temp->data==val)return 1;
        temp = temp->next;
    }return 0;
}

Node* deletehead(Node*head){
    if (head==NULL)return head;
    Node*temp = head;
    head= head->next;
    delete temp;
    return head;
}
int main() {
    vector<int> arr = {2, 45, 6, 7};
    Node* head = convertArr2LL(arr);
    
    head = deletehead(head);
    printLL(head);
    return 0;
}
