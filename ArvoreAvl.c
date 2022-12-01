#include <stdlib.h>
#include <stdio.h>
#include "ArvoreAvl.h"
 //Criar um nó



TreeNode* novoNo (int element){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode!=NULL){
        newNode->element=element;
        newNode->left=NULL;
        newNode->right=NULL;
        newNode->height=0;
    }
    return newNode;
}

TreeNode* add(int valor, TreeNode* root) {
    if(root==NULL)
        root=novoNo(valor);   
  
    else{
        if(valor<root->element)
            root->left=add(valor,root->left);
        else if(valor> root->element)
            root->right=add(valor,root->right);    
    } 
    root->height=maior(height(root->left),height(root->right))+1;;
    root=toBalance(root);

    return root;
}


int height (TreeNode *root) {
    if (root == NULL)
        return -1; // altura da árvore vazia
    else {
        int hl = height(root->left); //altura esquerda
        int hr = height(root->right); //altura direita
        if (hl < hr) 
            return hr + 1;
        return hl + 1;
    }
}


int fatorDeBalanceamento(TreeNode *root){
    if (root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}

int maior(int valor1, int valor2){
    return (valor1>valor2)? valor1 : valor2;
}

int alturaDoNo(TreeNode *node){
    if(node==NULL)
        return -1;
    else
        return node->height;
}

TreeNode* rotationLeft(TreeNode* node){
    TreeNode *new;
    TreeNode* aux;
    new= node->right;
    aux= new->left;
    new->left=node;
    node->right=aux;

    node->height = maior(height(node->left),height(node->right))+1;
    node->height = maior(height(new->left), height(new->right))+1;
    return new;
}
TreeNode* rotationRight(TreeNode* node){
    TreeNode *new;
    TreeNode* aux;
    new= node->left;
    aux= new->right;
    new->right=node;
    node->left=aux;

    node->height = maior(height(node->left),height(node->right))+1;
    node->height = maior(height(new->left), height(new->right))+1;
    return new;
}

TreeNode* rotationLeftRight(TreeNode* node){
    node->left = rotationLeft(node->left);
    return rotationRight(node);
}

TreeNode* rotationRightLeft(TreeNode* node){
    node->right=rotationRight(node->right);
    return rotationLeft(node);
}

TreeNode* toBalance(TreeNode* node){
    int fb = fatorDeBalanceamento(node);
    if(fb<-1 && fatorDeBalanceamento(node->right)<=0)
        node=rotationLeft(node);
    else if(fb>1 && fatorDeBalanceamento(node->left)>=0)
        node=rotationRight(node);
    else if(fb>1 && fatorDeBalanceamento(node->left)<0)
        node=rotationLeftRight(node);
    else if(fb<-1 && fatorDeBalanceamento(node->right)>0)
        node=rotationRightLeft(node);
        
    return node;
}

void menu(){
    TreeNode* node = NULL;
    int escolha = 0;
    while(escolha!=4){    
        printf("Bem Vindo a Arvore AVL! \n\n");
        printf("1 - Adicione valores à árvore\n");
        printf("2 - Remova valores da árvore\n");
        printf("3 - Visualizar a árvore com os valores atuais\n");
        printf("4 - Sair do programa\n"); 
        scanf("%d",&escolha);
        switch(escolha){
            
            case 1:  node=adicionarNo(node);
                    break;
            case 2:  node=removerNo(node);
                    break;
            case 3: imprimir(node,1); printf("\n\n");
                    break;
        }   
    }
}

TreeNode* adicionarNo(TreeNode* node){
    int valor;
    printf("Digite o valor\n");
    scanf("%d",&valor);
    node=add(valor,node);
    return node;
}

TreeNode* removerNo(TreeNode* node){
    int valor;
    printf("Digite o valor\n");
    scanf("%d",&valor);
    node=remover(node,valor);
    return node;
}


void imprimir(TreeNode* node, int nivel){
    if(node!=NULL){
        imprimir(node->right,nivel+1);
        printf("\n\n");

        for(int i=0; i<nivel;i++)
            printf("\t");

        printf("%d", node->element);
        imprimir(node->left,nivel+1);
    }  
}

TreeNode* remover(TreeNode* node, int element){
    if(node==NULL){
        printf("Valor não encontrado!\n");
        return NULL;
    }
    else{
        if(node->element==element){
            if(node->left==NULL && node->right==NULL){
                free(node);
                return NULL;
            }
            else{
                if(node->left!=NULL && node->right!=NULL){
                    TreeNode *  aux = node->left;
                    while(aux->right!=NULL)
                        aux=aux->right;
                    node->element= aux->element;
                    aux->element=element;
                    node->left = remover(node->left,element);
                    return node;
                }
            else{
                TreeNode* aux;
                if(node->left!=NULL)
                    aux=node->left;
                if(node->right!=NULL)
                    aux=node->right;
                return aux;
            }
            }
        }
        else{
            if(element<node->element)
                node->left = remover(node->left, element);
            else
                node->right = remover(node->right, element);
        }
        node->height=maior(height(node->left),height(node->right))+1;;
        node=toBalance(node);
        return node;
    }
}