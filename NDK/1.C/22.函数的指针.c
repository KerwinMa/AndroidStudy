/**1.����int��(*pf)(int x,��int y);
2.��ֵ pf = add;
3.���� pf(3,5);
*/
#include <stdio.h>

int add(int x,int y){ 
    return x+y; 
}
main()
{ 
     int (*pf)(int x, int y); //����һ��������ָ�� 
      
     pf = add; 
      
      
   printf("result=%d\n",  pf(3,5)); 
      
   system("pause"); 
}

