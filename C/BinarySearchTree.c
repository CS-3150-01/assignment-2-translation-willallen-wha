#include <stdio.h>

//Represent the node of the binary tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} NODE;

//Represent the root of the binary tree
struct binarySearchTree {
    struct Node root;
} BST;

//factorial() will return the factorial of a number
int factorial(int num);

//numOfBST() will calculate the total number of possible BST by calculating Catalan Number for given key   
int numOfBST(int key);

int main() {
    
    //Create three nodes
    NODE n1, n2, n3;
    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n1.left = &n2;
    n1.right = &n3;

    //Make node n1 the child of BST
    BST.root = n1;

    //Print node n1 and its children
    printf("Node 1 has value %i with children %i and %i", n1.data, n1.left->data, n1.right->data);

}

int factorial(int num) {
    int fact = 1;
    for(int i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int numOfBst(int key) {
    int catalanNum = factorial(2 * key)/(factorial(2 * key) * factorial (1 * key));
    return catalanNum;
}