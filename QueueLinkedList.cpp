#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            next=NULL;
        }
};

class Queue{
    private:
        Node *front,*rear;
    public:
        Queue():front(NULL),rear(NULL){}
        void enqueue(int data){
            Node *n = new Node(data);
            if(isEmpty()){
                front = n;
                rear=n;
            }
            else{
                rear->next=n;
                rear=n;
            }
        }
        int dequeue(){
            if(!isEmpty()){
                int temp=front->data;
                front=front->next;
                return temp;
            }
        }
        int peek(){
            if(!isEmpty())
                return front->data;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void toString(){
            cout<<"[";
            Node *temp = front;
            while(temp != NULL){
                cout<<temp->data<<", ";
                temp=temp->next;
            }
            cout<<"\b\b]";
        }
        ~Queue(){
            Node *next;
            while(front!=NULL){
                next=front->next;
                delete front;
                front = next;
            }
        }
};
int main(){
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<" "<<q.peek()<<endl;
    q.enqueue(4);
    q.toString();
}