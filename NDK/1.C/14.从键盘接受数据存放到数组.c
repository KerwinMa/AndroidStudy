#include <stdio.h>

/**
��ӡ��������ÿһ��Ԫ��
*/ 
void printArr(int* arr, int len){ 
     int i; 
     for(i=0;i<len;i++){
        printf("arr[%d]=%d\n",i,*(arr+i));             
      } 
} 

main()
{    printf("����������ĳ���");
     int  len ;
     scanf("%d", &len); 
     int arr[len]; 
     int i=0;
     for(;i<len;i++){
       printf("�������%d������\n",i); 
       scanf("%d",&arr[i]);           
     } 
      //��ӡ��ʾ��������Ԫ�� 
      printArr(arr,len); 
      system("pause"); 
}
