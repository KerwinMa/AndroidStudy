#include <stdio.h>
//malloc ��̬�ڴ�����.
#include<malloc.h> 
main()
{   
   int* p =  malloc(sizeof(int)); //����һ��int���͵Ĳ��� ,������������ ������ٸ�byte�ռ���ڴ� 
                         //�����ķ���ֵ ����һ���ڴ�ռ���׵�ַ. 
                         // int* p;  p =  malloc(sizeof(int));
                         
   *p = 4;
   printf("*p=%d\n",*p); 
   free(p); 
   printf("*p=%d\n",*p); 
    system("pause"); 
}

