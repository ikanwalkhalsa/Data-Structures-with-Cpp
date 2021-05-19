#include<iostream>
#include <queue>
using namespace std;

template<typename valType>
struct Node{
    valType value{};
    Node<valType> *left, *right;
    Node(valType value):value(value),left(NULL),right(NULL){}
};

template<typename valType>
class BST{
    private:
        Node<valType> *root;
        void travarseInorder(Node<valType> *current){
            if(current->left) travarseInorder(current->left);
            cout<<current->value<<", ";
            if(current->right) travarseInorder(current->right);
        }
        void travarsePreorder(Node<valType> *current){
            cout<<current->value<<", ";
            if(current->left) travarsePreorder(current->left);
            if(current->right) travarsePreorder(current->right);
        }
        void travarsePostorder(Node<valType> *current){
            if(current->left) travarsePostorder(current->left);
            if(current->right) travarsePostorder(current->right);
            cout<<current->value<<", ";
        }
    public:
        BST():root(NULL){};
        void insert(valType value){
            if(root == NULL){
                root = new Node<valType>(value);
                return;
            }else{
                Node<valType> *current = root;
                while(true){
                    if(value < current->value){
                        if(current->left == NULL){
                            current->left = new Node<valType>(value);
                            return;
                        }
                        current = current->left;
                    }else{
                        if(current->right == NULL){
                            current->right = new Node<valType>(value);
                            return;
                        }
                        current = current->right;
                    }
                }
            }
        }
        bool lookup(valType value){
            Node<valType> *current = root;
            while(current){
                if(value == current->value){
                    return true;
                }else if(value < current->value){
                    current = current->left;
                }else if(value > current->value){
                    current = current->right;
                }
            }
            return false;
        }
        void remove(valType value){
            Node<valType> *current = root;
            Node<valType> *toberemoved=NULL;
            Node<valType> *parent=NULL;
            while(current){
                if(current->value == value){
                    toberemoved  = current;
                    if(current->right){
                        current = current->right;
                        while(current->left){
                            parent = current;
                            current = current->left;
                        }
                        parent->left = current->right;
                        toberemoved->value = current->value;
                        current = NULL;
                        return;
                    }else if(current->left){
                        current = current->left;
                        while(current->right){
                            parent = current;
                            current = current->right;
                        }
                        parent->right = current->left;
                        toberemoved->value = current->value;
                        current = NULL;
                        return;
                    }else{
                        current=NULL;
                        return;
                    }
                }else if(value<current->value){
                    current = current->left;
                }else if(value>current->value){
                    current = current->right;
                }
            }
        }
        void bfs(){
            queue<Node<valType>*> q;
            q.push(root);
            while(!q.empty()){
                Node<valType> *current = q.front();
                cout<<current->value<<", ";
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            cout<<endl;
        }
        void dfsInorder(){
            travarseInorder(root);
            cout<<endl;
        }
        void dfsPreorder(){
            travarsePreorder(root);
            cout<<endl;
        }
        void dfsPostorder(){
            travarsePostorder(root);
            cout<<endl;
        }
};
int main(){
    BST<int> tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);
    if(tree.lookup(1)){
        cout<<"Element Found"<<endl;
    }else{
        cout<<"Element Not Found"<<endl;
    }
    tree.bfs();
    tree.dfsInorder();
    tree.dfsPreorder();
    tree.dfsPostorder();
}