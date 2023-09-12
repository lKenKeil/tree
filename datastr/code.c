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

// 배열을 사용하여 순회 결과를 저장할 길이 11인 배열을 초기화합니다.
int resultArr[11];
int idx = 0;

// infix traversal
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left); // 왼쪽 서브트리 순회
        resultArr[idx++] = root->data; // 노드 방문
        inorder(root->right); // 오른쪽 서브트리 순회
    }
}

// Prefix traversal
void preorder(TreeNode* root) {
    if (root) {
        resultArr[idx++] = root->data; // 노드 방문
        preorder(root->left); // 왼쪽 서브트리 순회
        preorder(root->right); // 오른쪽 서브트리 순회
    }
}

// post-order traversal
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left); // 왼쪽 서브트리 순회
        postorder(root->right); // 오른쪽 서브트리 순회
        resultArr[idx++] = root->data; // 노드 방문
    }
}

int main(void)
{
    printf("링크를 사용한 중위 순회=");
    inorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    // 배열 및 인덱스 초기화
    memset(resultArr, 0, sizeof(resultArr));
    idx = 0;

    printf("링크를 사용한 전위 순회=");
    preorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    // 배열 및 인덱스 초기화
    memset(resultArr, 0, sizeof(resultArr));
    idx = 0;

    printf("링크를 사용한 후위 순회=");
    postorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    // 배열 및 인덱스 초기화
    memset(resultArr, 0, sizeof(resultArr));
    idx = 0;

    printf("배열을 사용한 중위 순회=");
    inorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    printf("배열을 사용한 전위 순회=");
    preorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    printf("배열을 사용한 후위 순회=");
    postorder(root);
    for (int i = 0; i < 11; i++) {
        printf("%d ", resultArr[i]);
    }
    printf("\n");

    return 0;
}
