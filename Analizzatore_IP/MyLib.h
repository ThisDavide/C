#ifndef MYLIB_H
#define MYLIB_H

int ip_uint32(char* ipAddr);
char ipClass(unsigned ip);
char* ipType(unsigned ip);
void ipDotted(unsigned int ip);
int ipCheckValidity(char *ip);

#endif