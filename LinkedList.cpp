#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList{
    private:
        Node *head;
        Node *tail;
        int num_of_elems;
    public:
        LinkedList():head(NULL),tail(NULL),num_of_elems(0){}
        bool isEmpty(){
            return head==NULL;
        }
        void append(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                head = n;
                tail = n;
            }else{
                tail->next=n;
                tail=n;
            }
            num_of_elems++;
        }
        void prepend(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                head = n;
                tail = n;
            }else{
                n->next=head;
                head=n;
            }
            num_of_elems++;
        }
        void insertBefore(int key,int data){
            if(key==head->data)
                prepend(data);
            else{
                Node *temp = head;
                Node *prev = NULL;
                while(temp!=NULL){
                    if(key==temp->data){
                        Node *n = new Node(data);
                        prev->next=n;
                        n->next=temp;
                        num_of_elems++;
                        break;
                    }
                    prev = temp;
                    temp=temp->next;
                }
            }
        }
        void insertAfter(int key,int data){
            if(key==tail->data)
                append(data);
            else{
                Node *temp = head;
                while(temp!=NULL){
                    if(key==temp->data){
                        Node *n = new Node(data);
                        n->next=temp->next;
                        temp->next=n;
                        num_of_elems++;
                        break;
                    }
                    temp=temp->next;
                }
            }
        }
        void insertAt(int index, int data){
            if(index==0)
                prepend(data);
            else if(index==num_of_elems)
                append(data);
            else if(index>0 && index<num_of_elems){
                Node *n = new Node(data);
                Node *temp = head;
                for(int i = 0; i < index-1; i++)
                    temp=temp->next;
                n->next=temp->next;
                temp->next=n;                
                num_of_elems++;
            }
        }
        void removeBefore(int data){
            if(head->next!=NULL && head->next->data==data){
                head=head->next;
                num_of_elems--;
            }else{
                Node *temp = head;
                while(temp!=NULL){
                    if(temp->next!=NULL && temp->next->data==data){
                        temp->next=temp->next->next;
                        num_of_elems--;
                        break;
                    }
                    temp=temp->next;
                }
            }
        }
        void removeAfter(int data){
            if(tail->data!=data){
                Node *temp = head;
                while(temp->next!=NULL){
                    if(temp->data==data){
                        temp->next=temp->next->next;
                        num_of_elems--;
                        break;
                    }
                    temp = temp->next;
                }
            }    
        }
        void remove(int data){
            if(head->data==data){
                head=head->next;
                num_of_elems--;
            }
            else{
                Node *prev=NULL;
                Node *temp=head;
                while(temp!=NULL){
                    if(temp->data==data){
                        prev->next=temp->next;
                        delete temp;
                        num_of_elems--;
                        break;
                    }
                    prev=temp;
                    temp=temp->next;
                }
            }
        }
        void removeAt(int index){
            if(index==0){
                head=head->next;
                num_of_elems--;
            }
            else{
                Node *temp=head;
                for(int i = 0; i < index-1; i++)
                    temp=temp->next;
                temp->next=temp->next->next;
                num_of_elems--;
            }
        }
        void toString(){
            cout<<"["<<flush;
            Node *temp = head;
            while(temp!=NULL){
                cout<<temp->data<<", "<<flush;
                temp=temp->next;
            }
            cout<<"\b\b]"<<endl;
        }
        ~LinkedList(){
            Node *temp = head;
            while(head!=NULL){
                temp=head->next;
                delete head;
                head=temp;
            }
        }
};
int main(){
    LinkedList ll = LinkedList();
    ll.append(5);
    ll.prepend(3);
    ll.insertAfter(5,6);
    ll.insertBefore(5,4);
    ll.toString();
    ll.removeAt(0);
    ll.removeAfter(5);
    ll.toString();
}