#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.hpp"
#include <stdbool.h>

//<, <=, >, >=
int comp(Node * node1, char node2, Node * node3){
  if(node2 == 'LT'){
    if(node1.value < node3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(node2 == 'LE'){
    if(node1.value <= node3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(node2 == 'GT'){
    if(node1.value > node3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if(node2 == 'GE'){
    if(node1.value >= node3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
}


//==, !=

int NEEQ(Node * node1, char * node2, Node * node3) {
    if (strcmp(node2, "EQ") == 0) {
        if( node1.value == node3.value){
          return 1;
        }
        else{
          return 0;
        }
    } else if (strcmp(node2, "NEQ") == 0) {
      if(node1.value != node3.value){
        return 1;
      }
      else{
        return 0;
      }
    }
}


//+,-,*,/

int calc(Node * node1, char * node2, Node * node3){
  int result;
  if(node2 == 'ADD'){
    result = node1.value + node3.value;
    return result;
  }
  else if(node2 == 'SUB'){
    result = node1.value - node3.value;
    return result;
  }
  else if(node2 == 'MUL'){
    result = node1.value * node3.value;
    return result;
  }
  else if(node2 == 'DIV'){
    result = node1.value / node3.value;
    return result;
  }
}

Node *makeNode(Node * node1){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = node1.value;
  return newnode;
}


Node *compNode(Node * node1, char * node2, Node * node3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = comp(node1, node2, node3);
  return newnode;
}


Node *NEEQNode(Node * node1, char * node2, Node * node3) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->value = NEEQ(node1, node2, node3);
    return newnode;
}


Node *calcNode(Node * node1, char *node2, Node * node3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = calc(node1, node2, node3);
  return newnode;
}