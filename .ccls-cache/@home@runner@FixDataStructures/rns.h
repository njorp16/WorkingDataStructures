#ifndef __RNS_H
#define __RNS_H

#define LEN_MAX_FILENAME 512
#define ERR_OK 0
#define ERR_CMD_LINE 1
#define ERR_LOAD_NET 2


unsigned int ParseCmdLine(int argCount, char* argVal[]);

unsigned int LoadNetwork(const char* fileName);



#endif