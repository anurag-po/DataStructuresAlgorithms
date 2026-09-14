#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

class List{
    Node* head=NULL;
public:
    void insert(int x){
        Node* n=new Node(x);
        if(!head) head=n;
        else{
            Node* t=head;
            while(t->next) t=t->next;
            t->next=n;
        }
    }

    void del(int x){
        Node *t=head,*p=NULL;
        while(t && t->data!=x) p=t,t=t->next;
        if(!t) return;
        if(p) p->next=t->next;
        else head=t->next;
        delete t;
    }

    void display(){
        for(Node* t=head;t;t=t->next) cout<<t->data<<" ";
    }
};

int main(){
    List l;
    l.insert(10); l.insert(20); l.insert(30);
    l.display();
    l.del(20);
    cout<<"\n";
    l.display();
}
