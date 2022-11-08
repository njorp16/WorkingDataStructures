/* ▪ The main program!
   ▪ Implementations for methods in the header file.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Node.h"
#include "Node.c"
#include "rns.h"

#define BLEN 1024 //buffer size

int main (int argc, char* argv[]) {
  FILE* inFile = fopen("basic.ntwk" , "r"); 
  if (inFile == NULL) {
    return 1;
    }
  
char buffer[BLEN];
Node listNode[NETWORK_SIZE];
unsigned int nodeID, connCount, idx = 0; 
char temp;
  
while (!feof(inFile)) {
  fgets(buffer, BLEN, inFile);

  //removing comment
  
  char* isComment = strchr(buffer, '#');
    if (isComment != NULL) {
      size_t nullBytes = strlen(buffer);
      memset(isComment, '\0', nullBytes);
      continue;
    }
  int endingResult = (strcmp(buffer, "endNode\n"));
  int endingNet = (strcmp(buffer, "endNet\n"));
  if (endingResult == 0 || endingNet == 0) {
    continue;
    }
   
  unsigned int tempConn = 0;
  sscanf(buffer, "%u%c%c%u", &listNode[idx].nodeID, &temp, &temp, &tempConn);

   listNode[idx].listConn = (unsigned int*)malloc(sizeof(unsigned int)*tempConn);

  
  printf("NodeID: %u\n", listNode[idx].nodeID);
  listNode[idx].connCount = tempConn;
  printf("Number of connections: %u\n", listNode[idx].connCount);
 
  int j = 0;
  int counter = 0;
  while((j < tempConn) && (counter < tempConn)) {
    unsigned int dummy;
    fgets(buffer, BLEN, inFile);
    sscanf(buffer, "%u", &dummy);
    listNode[idx].listConn[j] = dummy;
      
    printf("Connection %d: %u\n", counter, listNode[idx].listConn[j]);
    j++;
    counter++;
    
    }
  }
  printf("\n");
  fclose(inFile);
  
/*-------------------------------------------------------*/
//begin part 2
  
  FILE* simFile = fopen("simple.sim" , "r");
  while(!feof(simFile)) {
    fgets(buffer, BLEN, simFile);
    
    char* isComment = strchr(buffer, '#');
    if (isComment != NULL) {
       size_t nullBytes = strlen(buffer);
       memset(isComment, '\0', nullBytes);
       continue;
    }
    unsigned int timestamp;
    char messageChar1[1], messageChar2[1], messageChar3[1];
    unsigned int messageNode;
    unsigned int messageNodeStart;
    unsigned int messageNodeEnd;
    

    //printf("%s\n", buffer);
    
    sscanf(buffer, "%u,%c%c%c,%u,%u,%u", &timestamp, messageChar1, messageChar2, messageChar3, &messageNode, &messageNodeStart, &messageNodeEnd);

    int endSim = strcmp(buffer, "endSim\n");
    if (timestamp >= 50) {
      break;
    }
    
    printf("Time Start: %u\nStart Node: %u\nEnd Node: %u\nCurr Node: -\nTime End: -\n\n", timestamp, messageNodeStart, messageNodeEnd);
    
  }
    return 0;
}