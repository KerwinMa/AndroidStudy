#include <stdio.h>
#include <malloc.h>
void f(int** paddress){
   // int i = 3; 
    int* p = malloc(sizeof(int)*2);//�ڶ��ڴ�����һ��ռ� 
    *p = 5;                      //����һ���ռ丳ֵ 5; 
    *(p+1) = 10; 
    *paddress  = p;             //�ѿռ���׵�ַ ���ݸ������� 
    printf("�Ӻ���p��ֵΪ%#x\n",p); 
    free(p); //֪ͨ����ϵͳ �ղ�������ڴ�ռ� ���Ա�����ʹ����.  
   
} 


main()
{            //����: ������������ ��ȡ���Ӻ��� i�����ĵ�ַ. 
      int* p ;//������� i�����ĵ�ַ��. 
      f(&p); 
      printf("������ p =%#x\n",p); 
      
      printf("*p=%d\n",*p); 
      printf("*(p+1)=%d\n",*(p+1)); 
      
      system("pause"); 
}
