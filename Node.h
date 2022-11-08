/* ▪ the Node structure definition,
   ▪ an error code enumeration, and
   ▪ the function signatures for the functions required to create your node file */

#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <string.h>
#define NETWORK_SIZE 20 //only for part 1

typedef struct __NET_NODE Node;
struct __NET_NODE 
{
unsigned int nodeID;
unsigned int connCount;
unsigned int* listConn;
};

typedef enum{
ERR_OK,
ERR_INVALID_FILE,
ERR_INVALID_FORMAT,
ERR_INVALID_DATA,
ERR_UNEXPECTED_EOF
}ErrorCode;

Node* createNode(int nodeID, int connCount);
void destroyNode(Node*);
void printNode(Node* node);



#endif