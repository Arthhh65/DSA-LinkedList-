#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node(int data1,Node* next1,Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
    
    public:
        Node(int data1){
            data =data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* convertArr2DLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }return head;
}

Node* deletehead(Node*head){
    if (head==NULL || head->next==NULL){
        return NULL;
    }

    Node* prev= head;
    head = head->next;
    head->back=nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

void printDLL(Node*head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* deletetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node*tail= head;
    Node*prev =nullptr;
    while(tail->next){
        tail = tail->next;
    }
    prev=tail->back;
    prev->next = nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}

Node* removekthelement(Node*head,int k){
    Node* temp= head;
    int count=0;
    if(head==NULL)return NULL;
    while(temp){
        count++;
        if(count==k){
            break;
        }
        temp=temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev==NULL && front==NULL){
        return NULL;
        }
    else if(prev==NULL){
        return deletehead(head);
    }
    else if(front==NULL){
        return deletetail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}

Node* deleteNode(Node* temp){
    Node* prev= temp->back;
    Node* front= temp->next;

    if(front==NULL){
        prev->next=nullptr;
        temp->back==nullptr;
        delete temp;
        
    }
    prev->next=front;
    front->back=prev;
    temp->next = temp->back = nullptr;
    delete temp;
    return 0;
}

Node* insertHead(Node*head , int val){
    Node* temp = new Node(val,head,nullptr);
    head->back = temp;
    return temp;
}

Node* insertTail(Node*head , int val){
    if(head==NULL)return NULL;
    Node*tail = head;
    while(tail->next){
        tail=tail->next;
    }
    Node* temp= new Node(val,nullptr,tail);
    tail->next=temp;
    return head;
}

Node* kthelelement(Node*head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
    else 
        return 0;
    }

    if(k==1){
        return(insertHead(head,val));
    }
    int count =0;
    Node*temp = head;
    
    while(temp){
        count++;
        if(count==k){
            Node* prev= temp->back;
            Node* newNode= new Node(val,temp,prev);
            temp->back= newNode;
            prev->next=newNode;
            break;
        }temp=temp->next;
    }return head;
}

void insertbeforeNode(Node*node , int val){
    Node*prev= node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next= newNode;
    node->back=newNode;
}
int main(){
    vector<int>arr={2,4,5,6,7,9};
    Node* head = convertArr2DLL(arr);
    head = kthelelement(head,8,7);
    printDLL(head);
}