#include <stdio.h>
 main()
{ 
         printf("60�뵹��ʱ\n"); 
         int time = 60;
         printf("time ���ڴ��е�ַΪ%#x\n",&time); 
         for(;time>0;){
             time --;  
             printf("ʣ��ʱ��Ϊ:%d\n",time);  
                    
             sleep(4000);//c����Ҳ��sleep 
         }
       
         printf("ʱ�䵽!!!\n"); 
       
         system("pause"); 
}
