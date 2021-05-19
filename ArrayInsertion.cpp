#include<iostream>
#include<bits/stdc++.h>
#include<numeric>
using namespace std;

template<class arrType>
class List{
    private:
        int size;
        arrType *arr;
        void resize(){
            int tempSize = size*2;
            int *tempArr = new arrType[tempSize];
            for(int i = 0; i < size; i++){
                tempArr[i] = arr[i];
            }
            delete arr;
            arr = tempArr;
            size = tempSize;
        }
    protected:
        int num_of_elemns;
    public:
        List(){
            arr = new int[1];
            this->size = 1;
            num_of_elemns = 0;
        }
        List(arrType b,arrType e,int s){
            arr = new arrType[s];
            for(auto z = b,i=0; z<e;z++,i++){
                arr[i] = z;
            }
            size = s;
            num_of_elemns = s;
        }
        List (initializer_list<arrType> arr){
            size = arr.size();
            this->arr = new arrType[size];
            num_of_elemns=size;
            copy(arr.begin(),arr.end(),this->arr);
        }
        List operator + (arrType n){
            List res = *this;
            res.append(n);
            return res;
        }
        void operator += (arrType n){
            append(n);
        }
        List operator + (initializer_list<arrType> inarr){
            List res = *this;
            res.extend(inarr);
            return res;
        }
        void operator += (initializer_list<arrType> inarr){
            extend(inarr);
        }
        List operator + (List l){
            List res = *this;
            res.extend(l.arr,l.num_of_elemns);
            return res;
        }
        void operator += (List l){
            extend(l.arr,l.num_of_elemns);
        }
        List operator * (int m){
            List res = *this;
            auto *carr = res.arr;
            int size = res.num_of_elemns;
            for(int i = 1; i < m; i++)
                res.extend(carr,size);
            return res;
        }
        void operator *= (int m){
            auto *carr = arr;
            int size = num_of_elemns;
            for(int i = 1; i < m; i++)
                extend(carr,size);
        }
        friend ostream &operator << (ostream &out,List l){
            out<<"[";
            for(int i = 0; i < l.num_of_elemns; i++){
                out<<l.arr[i]<<", ";
            }
            if(l.num_of_elemns>0) out<<"\b\b";
            out<<"]";
            return out;
        }
        arrType &operator [] (int m){
            return arr[m];
        }
        bool operator == (List l){
            if(num_of_elemns!=l.num_of_elemns) return false;
            for(int i = 0; i < num_of_elemns; i++)
                if(arr[i] != l[i]) return false;
            return true;
        }
        bool operator != (List l){
            return !operator==(l);
        }
        bool operator < (List l){
            return sum()<l.sum();
        }
        bool operator > (List l){
            return sum()>l.sum();
        }
        bool operator <= (List l){
            return sum()<=l.sum();
        }
        bool operator >= (List l){
            return sum()>=l.sum();
        }
        int sum(){
            int sum=0;
            return accumulate(arr,arr+num_of_elemns,sum);
        }
        void append(arrType data){
            if(num_of_elemns==size)
                resize();
            arr[num_of_elemns]=data;
            num_of_elemns++;
        }
        void prepend(arrType data){
            if(num_of_elemns==size)
                resize();
            arrType temp,index=0;
            while(index<=num_of_elemns){
                temp = arr[index];
                arr[index] = data;
                data = temp;
                index++;
            }
            num_of_elemns++;
        }
        void insert(int index, arrType data){
            if(num_of_elemns==size)
                resize();
            if(index==num_of_elemns)
                append(data);
            else if(index==0)
                prepend(data);
            else if(index<size){
                arrType temp;
                while(index<=num_of_elemns){
                    temp = arr[index];
                    arr[index] = data;
                    data = temp;
                    index++;
                }
                num_of_elemns++;
            }
        }
        void remove(arrType data){
            int i = 0, j = 0;
            int len = length();
            while(i<len){
                if(arr[i]==data){
                    num_of_elemns--;
                }
                else{
                    arr[j]=arr[i];
                    j++;
                }
                i++;
            }
        }
        void removeAt(arrType index){
            int j = 0;
            for(int i = 0; i < num_of_elemns; i++){
                if(i == index)
                    continue;
                arr[j] = arr[i];
                j++;
            }
            num_of_elemns--;
        }
        void extend(int inarr[], int len){
            for(int i = 0; i < len; i++){
                append(inarr[i]);
            }
        }
        void extend(initializer_list<arrType> inarr){
            int s = inarr.size();
            auto *a = new arrType[size];
            copy(inarr.begin(),inarr.end(),a);
            extend(a,s);
        }
        void reverse(){
            std::reverse(arr,arr+num_of_elemns);
        }
        void sort(){
            std::sort(arr,arr+num_of_elemns);
        }
        int length(){
            return num_of_elemns;
        }
        arrType pop(){
            return(arr[--num_of_elemns]);
        }
        int find(arrType elem){
            for(int i = 0; i < num_of_elemns; i++)
                if(arr[i]==elem)
                    return i;
            return -1;
        }
        ~List(){
            delete[] arr;
        }
};

int main(){
    List<char> arr = {'a','b','c'};
    List<int> arr1 = {1,2,3};
    arr1[0]=10;
    cout<<arr1[0]<<endl;
    cout<<arr<<"\n"<<arr1<<endl;
}