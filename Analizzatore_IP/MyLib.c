#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ip_uint32(char* ipAddr){
  int ipAddr1, ipAddr2, ipAddr3, ipAddr4;
  unsigned int ip32bit = 0;
  sscanf(ipAddr,"%d.%d.%d.%d", &ipAddr1, &ipAddr2, &ipAddr3, &ipAddr4);

  ip32bit |= ipAddr1 << 24;
  ip32bit |= ipAddr2 << 16;
  ip32bit |= ipAddr3 << 8;
  ip32bit |= ipAddr4;

  return ip32bit;
}
char ipClass(unsigned ip){
  int firstOctet = 0;
  int leadingBit[8] = {0};
  int i = 0;
  int j = 0;
  int k = 0;
  int n = 0;
  
//prendo il primo ottetto
  firstOctet = (ip >> 24) & 0xff;
  
//trasformo il primo ottetto in binario
  n = firstOctet;
  while(n > 0 || i < 8){
    leadingBit[i] = n % 2; 
    n = n / 2;
    i++;
  }
  for(i = 7; i >= 0; i--){
    leadingBit[j] = leadingBit[i];
    j++;
  }
  
//stabilisco la classe analizzando il leading bit
  if(leadingBit[0] == 0){
    return 'A';
  }
  else if(leadingBit[0] == 1 && leadingBit[1] == 0){
    return 'B';
  }
  else if(leadingBit[0] == 1 && leadingBit[1] == 1 && leadingBit[2] == 0){
    return 'C';
  }
  else if(leadingBit[0] == 1 && leadingBit[1] == 1 && leadingBit[2] == 1 && leadingBit[3] == 0){
    return 'D';
  }
  else if(leadingBit[0] == 1 && leadingBit[1] == 1 && leadingBit[2] == 1 && leadingBit[3] == 1){
    return 'E';
  }
}
char* ipType(unsigned ip){
//Controllo se l'indirizzo IP è riservato
  if((ip >= 2130706432 && ip <= 2147483647) || (ip >= 3758096384 && ip <= 4026531839) || (ip >= 4026531840 && ip <= 4294967295)){
    return "Riservato";
  }
    
//controllo se l'indirizzo IP è privato
  else if((ip >= 167772160 && ip <= 184549375) || (ip >= 2886729728 && ip <= 2887778303) || (ip >= 3232235520 && ip <= 3232301055)){
    return "Privato";
  }

//se non è né riservato, né privato, allora è pubblico
  else{
    return "Pubblico";
  }
}
void ipDotted(unsigned int ip){
  unsigned char bytes[4];
  bytes[0] = ip & 0xff;
  bytes[1] = (ip >> 8) & 0xff;
  bytes[2] = (ip >> 16) & 0xff;
  bytes[3] = (ip >> 24) & 0xff;   
  printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);      
}
int ipCheckValidity(char *ip){
  int oct1, oct2, oct3, oct4;
  int valido = 0;
  char fine;
  
  if(sscanf(ip,"%d.%d.%d.%d%c", &oct1, &oct2, &oct3, &oct4, &fine) == 4){
    if((oct1 >= 0 && oct1 <= 255) && (oct2 >= 0 && oct2 <= 255) && (oct3 >= 0 && oct3 <= 255) && (oct4 >= 0 && oct4 <= 255)){
      valido = 1;
    }
  }
  return valido;
}