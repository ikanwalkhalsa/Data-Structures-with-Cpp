#include<iostream>
using namespace std;

class Stack{
    private:
        char *stack;
        int size,top;
    public:
        Stack(int size = 0){
            this->size = size!=0?size:10;
            stack = new char[this->size];
            top = -1;
        }
        void push(int data){
            if(!isFull())
                stack[++top]=data;
        }
        char pop(){
            if(!isEmpty())
                return stack[top--];
        }
        char peek(){
            if(!isEmpty())
                return stack[top];
        }
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top+1==size;
        }
        void toString(){
            for(int i = top; i>=0; i--)
                cout<<stack[i]<<endl;
        }
        ~Stack(){
            delete[] stack;
        }

};
int main(){
    Stack sc=Stack();
    string inpStr = "[{()()}{}()[]][";
    for(int i = 0; i < inpStr.length(); i++){
        if(inpStr[i]=='{' or inpStr[i]=='(' or inpStr[i]=='[')
            sc.push(inpStr[i]);
        else if(inpStr[i]=='}' && sc.peek()=='{')
            sc.pop();
        else if(inpStr[i]==')' && sc.peek()=='(')
            sc.pop();
        else if(inpStr[i]==']' && sc.peek()=='[')
            sc.pop();
        else{
            sc.push(' ');
            break;
        }
    }
    if(sc.isEmpty())
        cout<<"Brackets are valid"<<endl;
    else
        cout<<"Given string in not Valid"<<endl;
}