
#include <iostream> 
using namespace std;
int main() 
{ 
   int ar[]={12,10,11,18,13,6},*p; 
   p=&ar[0]; 
   printf("%d ",*p);
   p=&ar[3];
   printf("%d ",*p);
   *p=*p+100; 
   printf("%d ",ar[3]);
   p=p-2;
  	printf("%d ",*p);
    return 0;
} 
