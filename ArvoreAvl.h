#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int element;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} TreeNode;
TreeNode* novoNo (int element);
TreeNode* add(int valor, TreeNode* node);
int height (TreeNode *root);
int fatorDeBalanceamento(TreeNode *root);
int maior(int valor1, int valor2);
int alturaDoNo(TreeNode *node);
TreeNode* rotationLeft(TreeNode* node);
TreeNode* rotationRight(TreeNode* node);
TreeNode* rotationLeftRight(TreeNode* node);
TreeNode* rotationRightLeft(TreeNode* node);
TreeNode* toBalance(TreeNode* node);
void menu();
void imprimir(TreeNode* node, int nivel);
TreeNode* adicionarNo(TreeNode* node);
#endif