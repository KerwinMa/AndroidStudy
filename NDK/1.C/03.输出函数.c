#include <stdio.h>
/*
ռλ���� 
%d  -  int
%ld �C long int
%c  - char
%f -  float
%u �C �޷�����
%hd �C ������
%lf �C double
%x �C ʮ��������� int ����long int ����short int
%o -  �˽������
%s �C �ַ���

*/
main()
{
      int i = 3;
      double d = 3.1415926;
      char c = 'a';
      short s = 28;
      
      //ע��һ��ԭ�����ݵ�����һ��Ҫ�໥��Ӧ�� 
      printf("i=%d\n", i);
      printf("d=%lf\n", d);
      printf("c=%c\n", c);
      printf("s=%hd\n", s);
      system("pause");
      
      
}      
