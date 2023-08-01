#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.hpp"
#include <stdbool.h>

//<, <=, >, >=
int comp(Node * node1, char str, Node * node3){
  if(str == 'LT'){
    if(node1->value < node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(str == 'LE'){
    if(node1->value <= node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(str == 'GT'){
    if(node1->value > node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(str == 'GE'){
    if(node1->value >= node3->value){
        return 1;
    }
    else{
        return 0;
    }
  }
}


//==, !=

int NEEQ(Node * node1, char * str, Node * node3) {
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
}


//+,-,*,/

int calc(Node * node1, char * str, Node * node3) {
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
  newnode->value = node1->value;
  return newnode;
}


Node *compNode(Node * node1, char * str, Node * node3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = comp(node1, str, node3);
  return newnode;
}


Node *NEEQNode(Node * node1, char * str, Node * node3) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->value = NEEQ(node1, str, node3);
    return newnode;
}


Node *calcNode(Node * node1, char *str, Node * node3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = calc(node1, str, node3);
  return newnode;
}