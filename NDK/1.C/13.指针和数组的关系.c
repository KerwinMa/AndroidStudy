#include <stdio.h>
main()
{ 
        int  intarr[] ={1,3,4,5,6,7,9}; 
        char chararr[] ={'1','b','d','5'}; 
      
        printf("�����һ��Ԫ��ֵ:%d\n",intarr[0]); 
        printf("����ڶ���Ԫ��ֵ:%d\n",intarr[1]); 
        
        printf("��һ��Ԫ�صĵ�ַΪ%#x\n" ,&intarr[0]);
        printf("�ڶ���Ԫ�صĵ�ַΪ%#x\n" ,&intarr[1]);
        printf("������Ԫ�صĵ�ַΪ%#x\n" ,&intarr[2]);
        
        printf("chararr��һ��Ԫ�صĵ�ַΪ%#x\n" ,&chararr[0]);
        printf("chararr�ڶ���Ԫ�صĵ�ַΪ%#x\n" ,&chararr[1]);
        
        
        printf("intarr������ = %#x\n",intarr);
        printf("chararr������ = %#x\n",chararr);
         
        //��ʵ����ı����� ����ľ��� ���������һ��Ԫ�صĵ�ַ. 
      
        system("pause"); 
}
