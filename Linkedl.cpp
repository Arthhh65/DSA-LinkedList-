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
Node* deletetail(Node * head){
    if (head==NULL || head->next==NULL){
        return NULL;
    }
    Node*temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removek(Node*head , int k){
    if (head == NULL)return head;
    if (k==1){
        Node*temp = head ;
        head = head->next;
        delete temp;
        return head;
    }
    int count =0;
    Node* temp = head;
    Node*prev= NULL;
    while (temp){
        count ++;
        if (count==k){
            prev->next = prev->next->next;
            delete temp ;
            break;
        }
        prev = temp ;
        temp = temp->next;
    }   return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node*head, int val){
    if(head==NULL) {return new Node(val);}
    Node*temp = head;
    while(temp->next!= NULL){
        temp =temp->next;
    }
    Node* Tail= new Node(val);
    temp->next= Tail;
    return head;
}

Node* insertPosition(Node* head, int el,int k){
    if (head== NULL){
        if(k==1)
            {return new Node(el);}
        else {
            return NULL;
        }}
    if (k==1){
        return new Node(el);
    }
    int count =0;
    Node* temp= head;
    while (temp!=NULL){
        count++;
        if (count == k-1){
            Node* x = new Node(el,temp->next);
            temp->next=x;
            break;
        }temp = temp->next;
    }return head;

}
int main() {
    vector<int> arr = {2, 45, 6, 7};
    Node* head = convertArr2LL(arr);
    head= insertPosition(head,100,5);
    printLL(head);
    
    return 0;
}
