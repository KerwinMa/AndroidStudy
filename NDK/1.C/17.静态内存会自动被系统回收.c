

#include <stdio.h>
#define PI 3.1415
void f(int** paddress){
    int i = 3; 
    *paddress  = &i; 
    printf("�Ӻ���i�ĵ�ַΪ%#x\n",&i); 
} 


main()
{            //����: ������������ ��ȡ���Ӻ��� i�����ĵ�ַ. 
      int* p ;//������� i�����ĵ�ַ��. 
      f(&p); 
    //printf("������ p =%#x\n",p); //�ſ���䣬*pΪ-1��ע�����Ϊ3.  �ɼ�ϵͳ�ǻ���պ����е�i�����ģ�����ϵͳ����Ҳ����ʱ��ġ� 
      
      printf("*p=%d\n",*p); 
      system("pause"); 
}
