#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.hpp"
#include <stdbool.h>

//<, <=, >, >=
int comp(Node * node1, const char *str, Node * node3){
  if(strcmp(str,"LT") == 0){
    if(node1->value < node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(strcmp(str,"LE") == 0){
    if(node1->value <= node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(strcmp(str,"GT") == 0){
    if(node1->value > node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(strcmp(str,"GE") == 0){
    if(node1->value >= node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  return 0;
}

//==, !=
int NEEQ(Node * node1, const char * str, Node * node3) {
    if (strcmp(str, "EQ") == 0) {
        if( node1->value == node3->value){
          return 1;
        }
        else{
          return 0;
        }
    } else if (strcmp(str, "NEQ") == 0) {
      if(node1->value != node3->value){
        return 1;
      }
      else{
        return 0;
      }
    }
    return 0;
}

//+,-,*,/
int calc(Node * node1, const char * str, Node * node3) {
    int result;
    if (strcmp(str, "ADD") == 0) {
        result = node1->value + node3->value;
    } else if (strcmp(str, "SUB") == 0) {
        result = node1->value - node3->value;
    } else if (strcmp(str, "MUL") == 0) {
        result = node1->value * node3->value;
    } else if (strcmp(str, "DIV") == 0) {
        result = node1->value / node3->value;
    }
    return result;
}

Node *makeNode(Node * node1){
  Node *newnode = (Node *)malloc(sizeof(Node));
  if (newnode != NULL) {
    newnode->value = node1->value;
  }
  return newnode;
}

Node *compNode(Node * node1, const char * str, Node * node3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  if (newnode != NULL) {
    newnode->value = comp(node1, str, node3);
  }
  return newnode;
}

Node *NEEQNode(Node * node1, const char * str, Node * node3) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (newnode != NULL) {
      newnode->value = NEEQ(node1, str, node3);
    }
    return newnode;
}

Node *calcNode(Node * node1, const char *str, Node * node3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  if (newnode != NULL) {
    newnode->value = calc(node1, str, node3);
  }
  return newnode;
}
