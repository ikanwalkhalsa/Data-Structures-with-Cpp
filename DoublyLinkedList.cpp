#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;
        int num_of_elems;
    public:
        DoublyLinkedList():head(NULL),tail(NULL),num_of_elems(0){}
        
        bool isEmpty(){
            return head==NULL;
        }
        void append(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                head = n;
                tail = n;
            }else{
                n->prev=tail;
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
                head->prev=n;
                n->next=head;
                head=n;
            }
            num_of_elems++;
        }
        void insertBefore(int key,int data){
            if(key==head->data)
                prepend(data);
            else if(key==tail->data){
                Node *n = new Node(data);
                n->prev=tail->prev;
                tail->prev->next=n;
                n->next=tail;
            }
            else{
                Node *temp = head;
                while(temp!=NULL){
                    if(key==temp->data){
                        Node *n = new Node(data);
                        n->prev=temp->prev;
                        temp->prev->next=n;
                        n->next=temp;
                        num_of_elems++;
                        break;
                    }
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
                        n->prev=temp;
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
                n->prev=temp;
                n->next=temp->next;
                temp->next=n;                
                num_of_elems++;
            }
        }
        void removeBefore(int data){
            if(head->next!=NULL && head->next->data==data){
                head=head->next;
                delete head->prev;
                head->prev=NULL;
                num_of_elems--;
            }else{
                Node *temp = head;
                while(temp!=NULL){
                    if(temp->data==data){
                        temp->prev=temp->prev->prev;
                        temp->prev->next=temp;
                        num_of_elems--;
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
                        if(temp->next!=NULL) temp->next->prev=temp;
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
                delete head->prev;
                head->prev=NULL;
                num_of_elems--;
            }
            else if(tail->data==data){
                tail=tail->prev;
                delete tail->next;
                tail->next=NULL;
                num_of_elems--;
            }
            else{
                Node *temp=head;
                while(temp!=NULL){
                    if(temp->data==data){
                        temp->prev->next=temp->next;
                        temp->next->prev=temp->prev;
                        delete temp;
                        num_of_elems--;
                        break;
                    }
                    temp=temp->next;
                }
            }
        }
        void removeAt(int index){
            if(index==0){
                head=head->next;
                delete head->prev;
                head->prev=NULL;
                num_of_elems--;
            }
            else if(index==num_of_elems-1){
                tail=tail->prev;
                delete tail->next;
                tail->next=NULL;
                num_of_elems--;
            }
            else{
                Node *temp=head;
                for(int i = 0; i < index-1; i++)
                    temp=temp->next;
                temp->next=temp->next->next;
                temp->next->prev=temp;
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
        ~DoublyLinkedList(){
            Node *temp = head;
            while(head!=NULL){
                temp=head->next;
                delete head;
                head=temp;
            }
        }
};
int main(){
    DoublyLinkedList ll = DoublyLinkedList();
    ll.append(4);
    ll.append(5);
    ll.append(6);
    ll.toString();
    ll.insertAt(3,3);
    ll.toString();
}