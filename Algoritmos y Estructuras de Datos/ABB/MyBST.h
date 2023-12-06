#ifndef MYBST_H
#define MYBST_H

struct MyNodeBST{
    int data;
    MyNodeBST *left, *right;

    /*MyNodeBST()
    {
        left = right = nullptr;
    }*/
    MyNodeBST(int data){
        this->data = data;
        this->left=this->right=nullptr;
    }

    MyNodeBST(int data, MyNodeBST *left, MyNodeBST *right){
        this->data = data;
        this->left= left;
        this->right = right;
    }
};

class MyBST{
    public:
        int size;
        int globalMax;
        MyNodeBST* root;
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        MyBST(int globalMax);
        int length();
        bool isEmpty();
        bool search(int data);//opcional
        bool searchRec(int data);
        bool searchRec(int data, MyNodeBST* current);
        bool insert(int data);//true si lo inserto o no
        bool remove(int data);//si el valor estaba en el árbol lo borra
                              //y regresa true, caso contrario sólo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level
        int height();//regresa la altura del BST.
        int height(MyNodeBST* current);
        void ancestors(int data);//imprime los ancestros del valor pasado.
                                 //el orden de impresión debe ser de la raíz
                                 //hacía abajo.
                                //Si valor no se localiza en el árbol no imprime nada
        int whatLevelAmI(int data);//regresa el nivel en que se encuentra el valor
                                   //dentro del árbol. Si el valor no está en árbol imprime -1
        void maxAccess(MyNodeBST* current);
};

#endif