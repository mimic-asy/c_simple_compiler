#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


//構造体の宣言

typedef struct Node{
int value;
}Node;

int NEEQ(Node * node1, const char * str, Node * node3);
int comp(Node * node1, const char * str, Node * node3);
int calc(Node * node1, const char * str, Node * node3);
Node *makeNode(Node * node1);
Node *compNode(Node * node1, const char * str, Node * node3);
Node *NEEQNode(Node * node1, const char * str, Node * node3);
Node *calcNode(Node * node1, const char * str, Node * node3);
