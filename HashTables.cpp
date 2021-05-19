#include<iostream>
#include<sstream>
using namespace std;

template<typename keyType, typename valueType>
struct HashNode{
        keyType key;
        valueType value;
        HashNode<keyType,valueType> *next;
        HashNode():next(NULL){}
        HashNode(keyType key):key(key),next(NULL){
            valueType v{};
            value=v;
        }
        HashNode(keyType key, valueType value):key(key),value(value),next(NULL){}
        friend ostream &operator << (ostream &out,HashNode n){
            keyType k; valueType v;
            if(n.key!=k && n.value != v)out<<" "<<n.key<<" : "<<n.value<<",";
            return out;
        }
};

template<typename keyType, typename valueType>
class HashMap{
    private:
        HashNode<keyType,valueType> *map;
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
        HashMap(int size){
            map = new HashNode<keyType,valueType>[size]();
            this->size = size;
        }
        valueType &operator [] (keyType key){
            unsigned long address = hashKey(key);
            HashNode<keyType,valueType> *curr = &map[address];
            do{
                if(curr->key == key) return curr->value;
                curr=curr->next;
            }while(curr->next != NULL);
            stringstream ss;
            ss<<key<<" does not exists in map\n";
            cout<<ss.str();
            throw ss.str();
        }
        void add(keyType data, valueType val){
            keyType k{};
            unsigned long address = hashKey(data);
            if(map[address].key != k){
                HashNode<keyType,valueType> *curr = &map[address];
                do{
                    if(curr->key == data){ 
                        curr->value = val;
                        return;
                    }
                    curr=curr->next;
                }while(curr->next != NULL);
                HashNode<keyType,valueType> *n = new HashNode<keyType,valueType>{data,val};
                curr->next = n;
                curr= curr->next;
            }
            map[address] = {data,val};
        }
        friend ostream &operator << (ostream &out,HashMap &map){
            out<<"{";
            keyType k{};valueType v{};
            for(int i = 0; i < map.size; i++){
                HashNode<keyType,valueType> *curr = &(map.map[i]);
                while(curr!=NULL){
                    if(curr->key!=k&&curr->value!=v) out<<map.map[i];
                    curr=curr->next;
                }
            }
            out<<"}";
            return out;
        }
        bool has_key(keyType key){
            unsigned long address = hashKey(key);
            HashNode<keyType,valueType> *curr = &map[address];
            do{
                if(curr->key == key) return true;
                curr=curr->next;
            }while(curr->next != NULL);
            return false;
        }
        void remove(keyType key){
            keyType k; valueType v;
            unsigned long address = hashKey(key);
            HashNode<keyType,valueType> *curr = &map[address];
            if(curr->next!=NULL){
                HashNode<keyType,valueType> *prev = curr;
                do{
                    if(curr->key == key){
                        prev->next=curr->next;
                        curr->key=k;
                        curr->value=v;
                        curr->next=NULL;
                        delete curr;
                        return;
                    }
                    curr=curr->next;
                    prev=curr;
                }while(curr->next != NULL);
            }else{
                curr->key=k;
                curr->value=v;
                delete curr;
            }
        }
        ~HashMap(){
            for(int i = 0; i < size; i++){
                HashNode<keyType,valueType> *temp = &(map[i]);
                while(temp!=NULL){
                    HashNode<keyType,valueType> *prev = temp;
                    temp=temp->next;
                    delete prev;
                }
            }
            delete [] map;
        }  
};

int main(){
    HashMap<string,int> a(5);
    a.add("apples",500);
    cout<<a["apples"]<<endl;
    //cout<<a["grapes"]<<endl;
    cout<<a<<endl;
    //a.remove("apples");
    a.add("grapes",100);
    cout<<a<<endl;
}