#include<iostream>
using namespace std;

class Queue{
    private:        
        int front,rear,size,num_of_elem;
        int *queue;
        void resize(){
            int tempSize = size*2;
            int *tempArr=new int[tempSize];
            int i=front,j=0;
            while(i != rear){
                tempArr[j++]=queue[i];
                i=(i+1)%size;
            }
            tempArr[j]=queue[i];
            front = 0;
            rear = j;
            delete queue;
            queue = tempArr;
            size = tempSize;
        }
    public:
        Queue(int size=0){
            this->size=size!=0?size:3;
            queue = new int[this->size];
            front=-1;
            rear=-1;
            num_of_elem=0;
        }
        void enqueue(int data){
            if(isFull())
                resize();
            front = front==-1?0:front;
            rear = (rear+1)%size;
            queue[rear] = data;
            num_of_elem++;
        }
        int dequeue(){
            if(!isEmpty()){
                int temp = front;
                front = (front + 1)%size;
                num_of_elem--;
                return queue[temp];
            }
        }
        int peek(){
            if(!isEmpty())
                return queue[front];
        }
        bool isEmpty(){
            return num_of_elem==0;
        }
        bool isFull(){
            return num_of_elem==size;
        }
        void toString(){
            cout<<"[";
            int temp = front;
            while(temp!=rear){
                cout<<queue[temp]<<", ";
                temp=(temp+1)%size;
            }
            cout<<queue[temp]<<"]"<<endl;
        }
        ~Queue(){
            delete[] queue;
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