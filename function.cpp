#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.hpp"
#include <stdbool.h>

//<, <=, >, >=
int comp(Node * $1, char $2, Node * $3){
  if($2 == 'LT'){
    if($1.value < $3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if($2 == 'LE'){
    if($1.value <= $3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if($2 == 'GT'){
    if($1.value > $3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
  else if($2 == 'GE'){
    if($1.value >= $3.value){
        return 1;
    }
    else{
        return 0;
    }
  }
}


//==, !=

int NEEQ(Node * $1, char * $2, Node * $3) {
    if (strcmp($2, "EQ") == 0) {
        if( $1.value == $3.value){
          return 1;
        }
        else{
          return 0;
        }
    } else if (strcmp($2, "NEQ") == 0) {
      if($1.value != $3.value){
        return 1;
      }
      else{
        return 0;
      }
    }
}


//+,-,*,/

int calc(Node * $1, char * $2, Node * $3){
  int result;
  if($2 == 'ADD'){
    result = $1.value + $3.value;
    return result;
  }
  else if($2 == 'SUB'){
    result = $1.value - $3.value;
    return result;
  }
  else if($2 == 'MUL'){
    result = $1.value * $3.value;
    return result;
  }
  else if($2 == 'DIV'){
    result = $1.value / $3.value;
    return result;
  }
}

Node *makeNode(Node * $1){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = $1.value;
  return newnode;
}


Node *compNode(Node * $1, char * $2, Node * $3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = comp($1, $2, $3);
  return newnode;
}


Node *NEEQNode(Node * $1, char * $2, Node * $3) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->value = NEEQ($1, $2, $3);
    return newnode;
}


Node *calcNode(Node * $1, char *$2, Node * $3){
  Node *newnode = (Node *)malloc(sizeof(Node));
  newnode->value = calc($1, $2, $3);
  return newnode;
}