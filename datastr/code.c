#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n1, &n2 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 10, NULL, NULL };
TreeNode n7 = { 11, NULL, NULL };
TreeNode n8 = { 8, NULL, NULL };
TreeNode n9 = { 9, &n6, &n7 };
TreeNode n10 = { 7, &n8, &n9 };
TreeNode n11 = { 1, &n5, &n10 };
TreeNode* root = &n11;

// �迭�� ����Ͽ� ��ȸ ����� ������ ���� 11�� �迭�� �ʱ�ȭ�մϴ�.
int resultArr[11];
int idx = 0;

// infix traversal
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left); // ���� ����Ʈ�� ��ȸ
        resultArr[idx++] = root->data; // ��� �湮
        inorder(root->right); // ������ ����Ʈ�� ��ȸ
    }
}

// Prefix traversal
void preorder(TreeNode* root) {
    if (root) {
        resultArr[idx++] = root->data; // ��� �湮
        preorder(root->left); // ���� ����Ʈ�� ��ȸ
        preorder(root->right); // ������ ����Ʈ�� ��ȸ
    }
}

// post-order traversal
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left); // ���� ����Ʈ�� ��ȸ
        postorder(root->right); // ������ ����Ʈ�� ��ȸ
        resultArr[idx++] = root->data; // ��� �湮
    }
}

int main(void)
{
    printf("��ũ�� ����� ���� ��ȸ=");
    inorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    // �迭 �� �ε��� �ʱ�ȭ
    memset(resultArr, 0, sizeof(resultArr));
    idx = 0;

    printf("��ũ�� ����� ���� ��ȸ=");
    preorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    // �迭 �� �ε��� �ʱ�ȭ
    memset(resultArr, 0, sizeof(resultArr));
    idx = 0;

    printf("��ũ�� ����� ���� ��ȸ=");
    postorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    // �迭 �� �ε��� �ʱ�ȭ
    memset(resultArr, 0, sizeof(resultArr));
    idx = 0;

    printf("�迭�� ����� ���� ��ȸ=");
    inorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    printf("�迭�� ����� ���� ��ȸ=");
    preorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    printf("�迭�� ����� ���� ��ȸ=");
    postorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    return 0;
}
