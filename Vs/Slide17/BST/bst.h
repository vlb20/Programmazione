#ifndef BST_H
#define BST_H
#include<iostream>
using std::cout;
template<typename Key> class BST;


template<typename Key>
class BSTNode{
    public:
        BSTNode(Key k, BSTNode<Key> *p=nullptr, BSTNode<Key> *l=nullptr, BSTNode<Key> *r=nullptr)
            : key(k), left(l), right(r), parent(p) {}
        friend class BST<Key>;
    private:
        Key key;
        BSTNode<Key> *left;
        BSTNode<Key> *right;
        BSTNode<Key> *parent;
};

template <typename Key>
class BST{
    protected:
        BSTNode<Key> *root;
    public:
        //costructors
        BST(BSTNode<Key> *r=NULL): root(r) {}
        ~BST(){release(root);}

        //traverse
        void inorderTreeWalk(BSTNode<Key>* x);
        void inorderTreeWalk() {inorderTreeWalk(root);}
        void preorderTreeWalk(BSTNode<Key>* x);
        void preorderTreeWalk() {preorderTreeWalk(root);}
        void postorderTreeWalk(BSTNode<Key>* x);
        void postorderTreeWalk() {postorderTreeWalk(root);}

        BSTNode<Key>* getRoot() {return root;}
        BSTNode<Key>* search(Key key);
        BSTNode<Key>* search(BSTNode<Key> *x, Key key);
        BSTNode<Key>* minimum() {return minimum(root);}
        BSTNode<Key>* minimum(BSTNode<Key> *subroot);
        BSTNode<Key>* maximum() {return maximum(root);}
        BSTNode<Key>* maximum(BSTNode<Key> *subroot);
        BSTNode<Key>* predecessor(BSTNode<Key>* x);
        BSTNode<Key>* successor(BSTNode<Key>* x);

        BSTNode<Key>* insert(Key key); //if return NULL, the key already exists
        void release(BSTNode<Key>* x){delete x;}
        BSTNode<Key>* deleteNode(BSTNode<Key> *root,Key key); //if return NULL, the key does not exists
};

template<typename Key>
void BST<Key>::inorderTreeWalk(BSTNode<Key>*x){
    if(x){ //x!=NULL
        inorderTreeWalk(x->left);
        cout<<x->key<<"\n";
        inorderTreeWalk(x->right);
    }
}

template<typename Key>
void BST<Key>::preorderTreeWalk(BSTNode<Key>*x){
    if(x){
        cout<<x->key<<"\n";
        preorderTreeWalk(x->left);
        preorderTreeWalk(x->right); 
    }
}

template<typename Key>
void BST<Key>::postorderTreeWalk(BSTNode<Key>*x){
    if(x){
        postorderTreeWalk(x->left);
        postorderTreeWalk(x->right);
        cout<<x->key<<"\n";
    }
}

template<typename Key>
BSTNode<Key>* BST<Key>::search(BSTNode<Key> *x, Key key){
    //iterative
    while(x){//x!=NULL
        if(x->key==key) break;
        else if (x->key < key){
            x=x->right;
        }else{
            x=x->left;
        }
    }
    return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::search(Key key){
    return search(root, key);
}



/*recursive
search(BSTNode<Key> *x, Key key )
 if(x==NULL){
    return NULL
 }
 if(x->key==key){
    return x
 }
 if(x->key>key){
    return search(x->left, key)
 }else if{
    return(x->right, key)
 }
*/

template<typename Key>
BSTNode<Key>* BST<Key>::minimum(BSTNode<Key> *subroot){
    BSTNode<Key>* x=subroot;
    if(x){
        while(x->left){//diverso da null
            x=x->left;
        }
    }
    return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::maximum(BSTNode<Key> *subroot){
    BSTNode<Key>* x=subroot;
    if(x){
        while(x->right){//diverso da null
            x=x->right;
        }
    }
    return x;
}

template<typename Key>
BSTNode<Key>* BST<Key>::predecessor(BSTNode<Key>* x){
    BSTNode<Key>* prev=nullptr;
    if(x->left){
        prev=maximum(x->left);
    }else{
        prev=x->parent;
        while(prev && prev->left==x){
            x=prev;
            prev=x->parent;
        }
    }
    return prev;
}

template<typename Key>
BSTNode<Key>* BST<Key>::successor(BSTNode<Key>* x){
    BSTNode<Key>* succ=nullptr;
    if(x->right){//diverso da NULL
        succ= minimum(x->right);
    }else{
        succ=x->parent; //risalgo l'albero
        while(succ && succ->right==x){//fintantochè esiste un parent e che l'elemento sia il figlio destro
            x=succ;
            succ=x->parent;
        }
    }
    return succ;
}

template<typename Key>
BSTNode<Key>* BST<Key>::insert(Key key){
    if(search(key)){
        return nullptr;
    }
    BSTNode<Key> *x=root;
    BSTNode<Key> *y=nullptr;
    BSTNode<Key> *z=new BSTNode<Key>(key);//si crea un nodo senza figli
    while(x){ //troviamo la posizione del nodo da inserire
        y=x;
        if(z->key < x->key) x=x->left;
        else x=x->right;
    }
    z->parent=y; //il parent del nodo da inserire è la poszione trovata
    if(y==nullptr)
        root=z; //significa che z va inserito come radice
    else{
        if(z->key < y->key){ //la key di z è più piccola del parent
            y->left=z; //z va inserito come left child di z
        }else{ //key di z > key di y
            y->right=z; //z va inserito come right child
        }
    }
    return z;
}

template<typename Key>
BSTNode<Key>* BST<Key>::deleteNode(BSTNode<Key>* root, Key key){
    if(root==nullptr) return root; //albero vuoto
    else if(key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else //trovato, possiamo iniziare a rimuovere
    {
        //Case 0: No child
        if(root->left==nullptr && root->right==nullptr){
            delete root; //rimuovo il nodo
            root=nullptr;
        }
        //Case 1: One child
        else if(root->left==NULL){
            BSTNode<Key> *temp=root; 
            root=root->right; //right child nuovo root del subtree
            delete temp;
        }
        else if(root->right==NULL){
            BSTNode<Key> *temp=root; 
            root=root->left; //left child nuovo root del subtree
            delete temp;
        }
        //Case 2: Two child
        else{
            BSTNode<Key> *temp=minimum(root->right); //trovo il min nel right subtree
            root->key=temp->key; //copio il valore nel nodo che vogliamo rimuovere
            root->right= delete(root->right, temp->key); //cancelliamo il dubplicato nel right subtree
        }
    }
    return root;
}


/*
template<typename Key>
BSTNode<Key>* BST<Key>::deleteNode(Key key){
    if(search(key)){
        return nullptr;
    }
    BSTNode<Key> *x=nullptr;
    BSTNode<Key> *y=nullptr;
    BSTNode<Key> *z=new BSTNode<Key>(key);
    //BSTNode<Key> *z=search(key);
    if((z->left==nullptr) || (z->right==nullptr)){
        y=z;
    }else{
        y=successor(z);
    }
    if(y->left!=nullptr){
        x=y->left;
    }else{
        x=y->right;
    }
    if(x!=nullptr) x->parent=y->parent;
    if(y->parent==nullptr){
        root=x;
    }else if(y==y->parent->left){
        y->parent->left=x;
    }else{
        y->parent->right=x;
    }
    if(y!=z){
        z->key=y->key; //copia i campi di y in z
    }
    release(y);
    
}*/


#endif