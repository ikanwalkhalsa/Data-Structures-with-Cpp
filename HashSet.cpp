#include<iostream>
#include<sstream>
using namespace std;

template<typename keyType>
struct HashNode{
        keyType key;
        HashNode<keyType> *next;
        HashNode():next(NULL){}
        HashNode(keyType key):key(key),next(NULL){}
        friend ostream &operator << (ostream &out,HashNode n){
            keyType k;
            if(n.key!=k)out<<" "<<n.key<<",";
            return out;
        }
};

template<typename keyType>
class HashSet{
    private:
        HashNode<keyType> *set;
        int size;
        int hashKey(keyType key){
            stringstream ss;
            ss<<key;
            string s1 = ss.str();
            int hash = 0;
            for(auto a:s1){
                hash += int(char(a));
            }
            return hash%size;
        }
    public:
        HashSet(int size){
            set = new HashNode<keyType>[size]();
            this->size = size;
        }
        HashSet(initializer_list<keyType> initarr){
            keyType k{};
            set = new HashNode<keyType>[initarr.size()+5]{};
            this->size = initarr.size()+5;
            for(int i = 0; i < size; i++){
                set[i]=k;
            }
            for(auto a: initarr){
                add(a);
            }

        }
        keyType operator [] (keyType key){
            int address = hashKey(key);
            HashNode<keyType> *curr = &set[address];
            do{
                if(curr->key == key) return key;
                curr=curr->next;
            }while(curr->next != NULL);
        }
        void add(keyType data){
            keyType k{};
            int address = hashKey(data);
            if(set[address].key != k){
                HashNode<keyType> *curr = &set[address];
                do{
                    curr=curr->next;
                }while(curr->next != NULL);
                HashNode<keyType> *n = new HashNode<keyType>{data};
                curr->next = n;
                curr= curr->next;
            }
            set[address] = {data};
        }
        friend ostream &operator << (ostream &out,HashSet &set){
            out<<"{";
            keyType k{};
            for(int i = 0; i < set.size; i++){
                HashNode<keyType> *curr = &(set.set[i]);
                while(curr!=NULL){
                    if(curr->key!=k) out<<set.set[i];
                    curr=curr->next;
                }
            }
            out<<"}";
            return out;
        }
        void remove(keyType key){
            keyType k;
            int address = hashKey(key);
            HashNode<keyType> *curr = &set[address];
            if(curr->next!=NULL){
                HashNode<keyType> *prev = curr;
                do{
                    if(curr->key == key){
                        prev->next=curr->next;
                        curr->key=k;
                        curr->next=NULL;
                        delete curr;
                        return;
                    }
                    curr=curr->next;
                    prev=curr;
                }while(curr->next != NULL);
            }else{
                curr->key=k;
                delete curr;
            }
        }
        ~HashSet(){
            for(int i = 0; i < size; i++){
                HashNode<keyType> *temp = &(set[i]);
                while(temp!=NULL){
                    HashNode<keyType> *prev = temp;
                    temp=temp->next;
                    delete prev;
                }
            }
            delete [] set;
        }  
};
int main(){
    HashSet<int> set={1,2,3};
    set.add(4);
    cout<<set;
}