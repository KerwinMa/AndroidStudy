#include <stdio.h>
/*
java  8�������������.
byte short int long char float double boolean
1     2    4     8   2    4     8      1

C�Ļ�����������,

char, int, float, double, signed, unsigned, long, short and void

sizeof();���߷�������ȡĳ����ռ�ü����ֽ� 
c������float int double short������java�ĳ�����һ���ġ�
c������char��һ���ֽڡ� ����ǿ������������õģ���������Ҫ��չ�ַ���
c99��û�ж���byte�� �������ǿ�����java�е�byte������c�����е�char��
c���Ա�ʾ booleanֵ������0�ͷ�0��ʾ
c������long������4���ֽڣ�java��long������8���ֽڡ� c������ֻ�涨��long >= int������c������long4���ֽڣ�int 4���ֽ� 
*/
main()
{
      printf("char����Ϊ%d\n",sizeof(char)); 
      printf("int����Ϊ%d\n",sizeof(int)); 
      printf("float����Ϊ%d\n",sizeof(float)); 
      printf("double����Ϊ%d\n",sizeof(double)); 
      printf("long����Ϊ%d\n",sizeof(long)); 
      printf("short����Ϊ%d\n",sizeof(short)); 
      
      system("pause");
} 
