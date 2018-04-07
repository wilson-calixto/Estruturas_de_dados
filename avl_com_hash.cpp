#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*
O Codigo abaixo é uma tabela hash onde cada elemento é composto por uma arvore avl e cada nó da arvore é Item genérico

*/
template <typename T>
class Item {
private:
    T key;
    
public:
    Item() {}
    
    Item(T key) {
        this->key = key;
    }
    
    T getKey() {
        return key;
    }
    
    void display(){
        cout << key;
    }
};

class Node {
public:
    Item<string> item;
    Node *left, *right;
    int height;
};

class AVL {
private:
    Node *root;
    string keys;
public:
    AVL() {
        root = NULL;
    }
    
    void insert(Item<string> *x) {
        root = insert(x, &root);
    }
    
    Node* insert(Item<string> *x, Node **p) {
        if(*p == NULL) {    
            *p = new Node();            
            (*p)->left = NULL;
            (*p)->right = NULL;
            (*p)->height = 1;
            (*p)->item = *x;
            return *p;
        } else if(x->getKey() > (*p)->item.getKey()) {
            (*p)->right = insert(x, &((*p)->right));
        } else if(x->getKey() < (*p)->item.getKey()) {
            (*p)->left = insert(x, &((*p)->left));
        } else {
            cout << "Item ja existe!" << endl;
        }
        
        (*p)->height = max(getHeight((*p)->left), getHeight((*p)->right)) + 1;
 
        int balance = getBalance(*p);
 
         if (balance > 1 && x->getKey() < (*p)->left->item.getKey())
            return turnRight(*p);

         if (balance < -1 && x->getKey() > (*p)->right->item.getKey())
            return turnLeft(*p);
 
        if (balance > 1 && x->getKey() > (*p)->left->item.getKey())
        {
            (*p)->left =  turnLeft((*p)->left);
            return turnRight(*p);
        }
     
        if (balance < -1 && x->getKey() < (*p)->right->item.getKey())
        {
            (*p)->right = turnRight((*p)->right);
            return turnLeft(*p);
        }
        return *p;
    }
    
    Node* turnLeft(Node *x) {
        Node *p = x->right;
        x->right = p->left;
        p->left = x;
        
        x->height = max(getHeight(x->left), getHeight(x->right))+1;
        p->height = max(getHeight(p->left), getHeight(p->right))+1;
    
        return p;
    }
    
    Node* turnRight(Node *x) {
        Node *p = x->left;
        x->left = p->right;
        p->right = x;
        
        x->height = max(getHeight(x->left), getHeight(x->right))+1;
        p->height = max(getHeight(p->left), getHeight(p->right))+1;
        return p;
    }
    
    int max(int a, int b) {
        return (a > b)? a : b;
    }
    
    int getHeight(Node *n) {
        if (n == NULL)
            return 0;
        
        return n->height;
    }
    
    int getBalance(Node *n) {
        if (n == NULL)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }
    
    void inOrder() { 
        if(root != NULL) {
            keys = "";
            inOrder(root);
            cout << keys << endl;
        }
        else {
            cout << "Chave nao encontrada\n";
        }
    }
    
    void inOrder(Node *p) {
        if(p != NULL){
            inOrder(p->left);
            if(keys.size() != 0) keys += " ";
            keys += p->item.getKey();
            inOrder(p->right);    
        }
    }
};

template <typename T>
class Element {
private:
    T key;
    AVL tree;

public:
    Element () {}
    Element(T key) {
        this->key = key;
    }
    
    void display() {
        tree.inOrder();
    }
    
    void insert(T key) {
        if(key.size() == 1) {
            key = "000"+key;
        }
        else if(key.size() == 2) {
            key = "00"+key;
        }
        else if(key.size() == 3) {
            key = "0"+key;
        }
        tree.insert(new Item<string>(key));
    }
};

class HashTable {
private:
    int size;
    Element<string> *array;
public:
    HashTable(int size) {
        this->size = size;
        array = new Element<string>[size];
    }
    
    unsigned hash(string key) {
        int numberHash = 0;
        
        for(int i = 0, j = key.size() - 1; i < key.size(); i++, j--) {
            numberHash += key[i] * pow(128, j);
        }
        return numberHash % size;
    }
    
    void insert(string key) {
        array[hash(key)].insert(key);
    }
    
    void search(string key) {
        array[hash(key)].display();
    }
};

int main() {
    HashTable table(1000);
    ifstream file;
    file.open("chaves.txt");
    
    if(file) {
        string line;
        while(getline(file, line))
            table.insert(line);
    }
    file.close();
    
    string entry2;
    do {
        cin >> entry2;
        if(entry2 != "-1") table.search(entry2);
    } while(entry2 != "-1");
    
    return 0;
}





