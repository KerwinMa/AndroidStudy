#include <stdio.h>
 main()
{ 
       
       /**
       һ������� ��ͬ�������ݵ�ָ�벻���໥ת��. 

       **/
       unsigned short i = 666; 
       
       int* p = &i;
       
       short*  sp = &i;
       //printf("*sp=%hd\n",*sp);
       printf("*p=%d\n",*p); 
                     
       system("pause"); 
}
