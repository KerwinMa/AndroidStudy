#include <stdio.h>
#include <malloc.h>
/**
��ӡ��������ÿһ��Ԫ��
*/ 
void printArr(int* arr, int len){ 
     int i; 
     for(i=0;i<len;i++){
        printf("i=%d\n",i); 
        printf("arr[%d]=%d\n",i,*(arr+i)); 
                    
      } 
      printf("end"); 
} 
main()
{       
     printf("����������ĳ���");
     int  len ;
     scanf("%d", &len); 
    // int arr[len]; 
     
     int* arr =(int* ) malloc(sizeof(int)*len) ; //��̬������ڴ� 
     int i=0;
     for(;i<len;i++){
       printf("�������%d������\n",i); 
       scanf("%d",&arr[i]);           
     } 
      //��ӡ��ʾ��������Ԫ�� 
      printArr(arr,len); 
        
        printf("���������ӵ�����ĳ���"); 
        int increase;
        scanf("%d", &increase); 
        
        arr = realloc(arr,(len+increase)*sizeof(int));
        i =len; 
       for(;i<len+increase ;i++){
       printf("�������%d������\n",i); 
       scanf("%d",&arr[i]);           
     } 
     
      //��ӡ��ʾ��������Ԫ�� 
       printf("�µ����鳤��Ϊ:%d\n",len+increase); 
        printArr(arr,len+increase); 
        
        system("pause"); 
}
