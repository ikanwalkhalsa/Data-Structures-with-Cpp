#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *down;
        Node(int data){
            this->data=data;
            down = NULL;
        }
};

class Stack{
    private:
        Node *top;
    public:
        Stack():top(NULL){}
        
        bool isEmpty(){
            return top==NULL;
        }
        void push(int data){
            Node *n = new  Node(data);
            n->down=top;
            top=n;
        }
        int pop(){
            if(!isEmpty()){
                int tempData=top->data;
                top=top->down;
                return tempData;
            }
        }
        int peek(){
            if(!isEmpty())
                return top->data;
        }
        void toString(){
            Node *temp=top;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->down;
            }
        }
        ~Stack(){
            Node *next;
            while(top!=NULL){
                next=top->down;
                delete top;
                top = next;
            }
        }
};
int main(){
    Stack sc = Stack();
    sc.push(5);
    sc.push(4);
    sc.push(3);
    sc.pop();
    sc.toString();
}