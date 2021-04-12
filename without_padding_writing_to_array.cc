#include<iostream>

using namespace std;

typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;

int main()
{
 char array[2000] = {0};
 
 structc_t abc;
 abc.c = 'x';
 abc.d = 100.32;
 abc.s = 10;

 //Writing to array without padding
 memcpy(array, &abc.c, sizeof(abc.c));
 memcpy(array+sizeof(abc.c), &abc.d, sizeof(abc.d));
 memcpy(array+sizeof(abc.c)+sizeof(abc.d), &abc.s, sizeof(abc.s));

 
 //Reading from array without padding
 structc_t xyz;
 char *arrPtr = array;
 memcpy(&xyz.c, arrPtr, sizeof(xyz.c)); 
 arrPtr += sizeof(xyz.c);

 memcpy(&xyz.d, arrPtr, sizeof(xyz.d)); 
 arrPtr += sizeof(xyz.d);

 memcpy(&xyz.s, arrPtr, sizeof(xyz.s)); 
 
 cout << "char:" << (char)xyz.c << ", double:" << xyz.d << ", int:" << xyz.s << endl; 

 return 1;
}
