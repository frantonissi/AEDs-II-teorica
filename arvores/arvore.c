#include <stdio.h>    
#include <stdlib.h>

struct item {
    int cod;
};

typedef struct item Item;

struct node {
    
    Item item;
    struct node *left;
    struct node *right;

};

typedef struct node Node;

Node *rootinitialize(){

    return NULL;

}

Item itemcreate(int cod){

    Item item;
    item.cod = cod;
    return item;
}

Node *treeInsert (Node *root, Item x){

    if (root == NULL){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux -> item = x;
        aux -> right = NULL;
        aux -> left = NULL;
        return aux;
    }else{

        if (x.cod < root->item.cod){
        root -> left = treeInsert(root -> left, x);
        }

        else if (x.cod > root->item.cod){
        root -> right = treeInsert(root -> right, x);
        }

    }
    return root;
}

Node *treeSearch (Node *root, Item x){

    if (root == NULL)
        return NULL;

    else{
        if (x.cod > root->item.cod){
            return treeSearch(root -> right, x);
        }

        else if (x.cod < root->item.cod){
            return treeSearch(root -> left, x);
        }

        else if (root->item.cod == x.cod){
           return root; 
        }
    }
    return NULL;
}

Node *minTree (Node *root){

if (root != NULL){
    Node *aux = root -> left;
    while (aux -> left != NULL){

        aux = aux -> left;

    }

    return aux;

}
return NULL;

}

Node *treeRemove(Node *root, Item x){

    if (root != NULL){
   
    if (x.cod > root -> item.cod){
        root -> right = treeRemove(root -> right, x);
    }else if (x.cod < root -> item.cod){
        root -> left = treeRemove(root -> left, x);
    }else{
        if (root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }
     
    else if (root -> left == NULL && root -> right != NULL)
        {
        Node *aux = root -> right;
       free(root);
       return aux;
    }else if (root -> left != NULL && root -> right == NULL)
        {
        Node *aux = root -> left;
       free(root);
       return aux;
    } else{

        Node *aux = minTree(root -> right);
        Item itemAux = aux -> item;
        root = treeRemove(root, itemAux);
        root -> item = itemAux;
        return root;
    }

}
}
}

void treePrint(Node *root){

    if (root != NULL){  
        printf ("%d", root -> item.cod);
        treePrint(root -> right);
        treePrint(root -> left);
    }

}

void treeFree(Node *root){

    if (root != NULL){
        treeFree(root -> right);
        treeFree(root -> left);
        free(root);
    }

}

int main (){

    Node *root = rootinitialize();

    root = treeInsert(root, itemcreate(10));
    root = treeInsert(root, itemcreate(15));
    root = treeInsert(root, itemcreate(12));
    treePrint(root);

    Node *tmp = treeSearch(root, itemcreate(12));

    if(tmp == NULL){
        printf ("Elemento nao encontrado");
    }else{
        printf("\nElemento encontrado!");
    }

    printf ("\n");
    treeFree(root);
    root = NULL;

    return 0;
}