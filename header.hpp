#include <stdio.h>
#include <stdbool.h>

//構造体の宣言

typedef struct Node{
int value;
}Node;

int NEEQ(Node * $1, char * $2, Node * $3);
int comp(Node * $1, char * $2, Node * $3);
int calc(Node * $1, char * $2, Node * $3);
Node *makeNode(Node * $1);
Node *compNode(Node * $1, char * $2, Node * $3);
Node *NEEQNode(Node * $1, char * $2, Node * $3);
Node *calcNode(Node * $1, char * $2, Node * $3);
