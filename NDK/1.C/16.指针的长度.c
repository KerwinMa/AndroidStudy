//˼�� Ϊʲôָ����ô���� ��ͬ��ָ������ ,��֪���ƶ���Ӧ���ڴ泤��.
// ��ͬ��ָ����� �ڼӼ���ʱ�� �ƶ����ڴ�ĳ����ǲ���ͬ��,���� ��ͬ��ָ������֪���Լ��ڴ���Ҫ�ƶ�(ƫ��)���ٸ��ֽ�. 

#include <stdio.h>
main()
{ 
         int i =3;
         double d = 3.1416;
         float f = 6.28;
         short s = 55;
         
         int*  ip = &i; 
         double* dp =&d;
         float* fp = &f;
         short* sp = &s;
         
         printf("ip�ĳ���Ϊ%d\n",sizeof(ip));
         printf("dp�ĳ���Ϊ%d\n",sizeof(dp));
         printf("fp�ĳ���Ϊ%d\n",sizeof(fp));
         printf("sp�ĳ���Ϊ%d\n",sizeof(sp));
          
      
      
          system("pause"); 
}
 
