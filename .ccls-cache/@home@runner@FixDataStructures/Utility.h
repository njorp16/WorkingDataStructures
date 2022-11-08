#ifndef __UTILITY_H
#define __UTILITY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Node.h"
#include "rns.h"
#define BLEN 1024 //buffer size

/*Node* createNode(int nodeID, int connCount;){
Node* node = (Node*)malloc(sizeof(Node));
node->nodeID = nodeID;
node->connCount = connCount;
node->listConn = (unsigned int*)malloc(sizeof(int)*listConn);
return node;
}*/

void removeComment(char buffer[BLEN]) {
    char* isComment = strchr(buffer, '#');
    if (isComment != NULL) {
      size_t nullBytes = strlen(buffer);
      memset(isComment, '\0', nullBytes);
}
}

/*void ParseCommandLine(char param1[LEN_MAX_FILENAME]) {
  
}*/

/*void HelpMethod() {
   
}*/

#endif