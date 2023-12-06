#include "MyBST.h"
#include <iostream>
#include <queue>

using namespace std;

MyBST::MyBST(int globalMax){ //Complejidad: O(1);
    this->root=nullptr;
    this->size=0;
    this->globalMax = globalMax-1;
    //this->access = new int[globalMax];
    //this->ip = new int[globalMax];
    //this->max = new MyNodeBST[globalMax];
}

int MyBST::length(){ //Complejidad: O(1);
    return this->size;
}

bool MyBST::isEmpty(){ //Complejidad: O(1);
    return this->size = 0;
}

bool MyBST::search(int data){ //Complejidad: O(n);
    MyNodeBST* current = this->root;
    while(current!=nullptr){
        if(current->data==data){
            return true;
        }
        else if(data<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    return false;
}

bool MyBST::searchRec(int data){ //Complejidad: O(n);
    return searchRec(data,this->root);
}

bool MyBST::searchRec(int data,MyNodeBST* current){ //Complejidad: O(n), en promedio O(n log n);
    if(current==nullptr){
        return false;
    }
    else if(data==current->data)
    {
        return true;
    }
    else if(data<current->data)
    {
        return searchRec(data,current->left);
    }
    else{
        return searchRec(data,current->right);
    }
}

bool MyBST::insert(int data){ //Complejidad: O(n), en promedio O(n log n);
    if (this->root == nullptr){
        this->root = new MyNodeBST(data);
        this->size++;
        return true;
    }
    MyNodeBST* current = this->root;
    while(current!=nullptr){
        if(data==current->data){
            return false;
        }

        if(data < current->data){
            if(current->left == nullptr){
                current->left = new MyNodeBST(data);
                this->size++;
                return true;
            }
            else{
                current = current->left;
            }
        }
        if(data > current->data){
            if(current->right == nullptr){
                current->right = new MyNodeBST(data);
                this->size++;
                return true;
            }
            else{
                current = current->right;
            }
        }
    }
    return true;
}

bool MyBST::remove(int data){ //Complejidad: O(n), en promedio O(n log n)
    if(isEmpty()){
        return false;
    }
    MyNodeBST* current = this->root;
    MyNodeBST* father = nullptr;
    while(current!=nullptr){
        if(current->data==data){
            break;
        }
        father = current;
        if(data<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }  
    if(current==nullptr){
        return false;
    }

    if(current->left == nullptr && current->right == nullptr){
        if(father == nullptr){
            this->root = nullptr;
        }
        else{
            if(current==father->left){
                father->left = nullptr;
            }
            else{
                father->right = nullptr;
            }
        }
        delete current;
        this->size--;
        return true;
    }

    if(current->left == nullptr){
        if(father == nullptr){
            this->root = current->right;
        }
        else{
            if(current==father->left){
                father->left = current->right;
            }
            else{
                father->right = current->right;
            }
        }
        delete current;
        this->size--;
        return true;
    }

    if(current->right == nullptr){
        if(father == nullptr){
            this->root = current->left;
        }
        else{
            if(current==father->left){
                father->left = current->left;
            }
            else{
                father->right = current->left;
            }
        }
        delete current;
        this->size--;
        return true;
    }
    else{
        MyNodeBST* predecessor = current->left;
        MyNodeBST* fatherPredecessor = current;
        while(predecessor->right != nullptr){
            fatherPredecessor = predecessor;
            predecessor = predecessor->right;
        }
        current->data = predecessor->data;
        if(fatherPredecessor!=current){
            fatherPredecessor->right = predecessor->left;
        }
        else{
            fatherPredecessor->left = predecessor->left;
        }
        delete predecessor;
        this->size--;
        return true;
    }
    return false;
}

void MyBST::preorder(MyNodeBST* current){ //Complejidad: O(n)
    if(current!=nullptr){
        cout<<current->data<<",";
        preorder(current->left);
        preorder(current->right);
    }
}

void MyBST::preorder(){ //Complejidad: O(n)
    preorder(root);
    cout<<endl;
}

void MyBST::inorder(MyNodeBST* current){ //Complejidad: O(n)
    if(current!=nullptr){
        inorder(current->left);
        cout<<current->data<<",";
        inorder(current->right);
    }

}

void MyBST::inorder(){ //Complejidad: O(n)
    inorder(root);
    cout<<endl;
}

void MyBST::postorder(MyNodeBST* current){ //Complejidad: O(n)
    if(current!=nullptr){
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<",";
    }
}

void MyBST::postorder(){ //Complejidad: O(n)
    postorder(root);
    cout<<endl;
}

void MyBST::level(){ //Complejidad: O(n)
    queue<MyNodeBST*> fila;
    fila.push(root);
    while(fila.empty()!=true){
        cout<<fila.front()->data<<",";
        if(fila.front()->left!=NULL){
            fila.push(fila.front()->left);
        }
        if(fila.front()->right!=NULL){
            fila.push(fila.front()->right);
        }
        fila.pop();
    }
    cout<<endl;
}

void MyBST::visit(int type){ //Complejidad: O(1)
    if(type==1){
        preorder();
    }
    if(type==2){
        inorder();
    }
    if(type==3){
        postorder();
    }
    if(type==4){
        level();
    }
}

int MyBST::height(MyNodeBST* current){ 
    if(current == nullptr){
        return 0;
    }
    else{
        int lHeight = height(current->left);
        int rHeight = height(current ->right);
        if(lHeight>rHeight)
        {
            return lHeight+1;
        }
        else{
            return rHeight+1;
        } 
        
    }
}

int MyBST::height(){ //Complejidad: O(n)
        return height(this->root);
}

void MyBST::ancestors(int data){ //Complejidad: O(n)
    MyNodeBST* current = this->root;
    string tmp = "";
    while(current!=nullptr){
        if(current->data==data){
            cout<<tmp;
            break;
        }
        tmp = tmp + to_string(current->data) + ",";
        if(data<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    cout<<endl;
}

int MyBST::whatLevelAmI(int data){ //Complejidad: O(n)
    MyNodeBST* current = this->root;
    int cont = 1;
    while(current!=nullptr){
        if(current->data==data){
            return cont;
        }
        else if(data<current->data){
            current=current->left;
        }
        else{
            current=current->right;
        }
        cont++;
    }
    return -1;
}

void MyBST::maxAccess(MyNodeBST* current){
    if(current->right!=nullptr){
        maxAccess(current->right);
    }
    if(this->globalMax < 0){
            return;
    }
    cout<<"IP: "<<current->data<<endl;
    cout<<"Max access: "<<current->data<<endl;
    this->globalMax--;
    if(this->globalMax < 0){
        return;
    }
    if(current->left != nullptr){
        maxAccess(current->left);
    }


    
    
    
    /*int* maxAccess;
    maxAccess = new int[sizeMax];
    for(int i=0;i>sizeMax;i++){
        
    }*/
    
    /*MyNodeBST* current = this->root;
    MyNodeBST* fatherCurrent;
    while(sizeMax > 0){
        if(current->right != nullptr){
            fatherCurrent = current;
            current = current->right;
            
        }
        else if(current->left != nullptr){
            fatherCurrent = current;
            current = current->left;
        }
        else if(current->right == nullptr){

        }
        
        
    }*/
}

/*int main(){
    MyBST arbol;
    arbol.insert(4);
    arbol.insert(2);
    arbol.insert(1);
    arbol.insert(3);
    cout<<arbol.remove(2)<<endl;
    arbol.visit(1);
    arbol.visit(2);
    arbol.visit(3);
    arbol.visit(4);
    arbol.ancestors(1);
    cout<<arbol.whatLevelAmI(1)<<endl;
    cout<<arbol.height()<<endl;
}*/