#include <stdio.h>

swap(int i, int j){//ֵ���� 
         
       int temp;
       printf("�Ӻ��� i�ĵ�ַ%#x\n",&i);
       printf("�Ӻ��� j�ĵ�ַ%#x\n",&j);
        
       temp = i;
       i = j;
       j = temp; 
      
         
         
} 


swap2(int* p, int* q){//���ô��� (ʵ��:ֵ�Ŀ���)
      
       int temp;
       printf("�Ӻ��� p��ֵ%#x\n",p);
       printf("�Ӻ��� q��ֵ%#x\n",q);
        
       temp = *p; //*p��ʵ������������i���� 
       *p = *q;   //*q ��ʵ������������j���� 
       *q = temp; 
      
                 
}


 main()
{ 
       int i = 3;
       int j = 5;
        printf("������ i�ĵ�ַ%#x\n",&i);
       printf("������ j�ĵ�ַ%#x\n",&j);
       //swap(i,j); 
       swap2(&i,&j); 
       printf("i=%d\n",i);
       printf("j=%d\n",j); 
       system("pause"); 
}

