

#include <stdio.h>
struct Student
{
	int age;  //4
	float score; //4
	long id; //4
	char sex; //1 ������Ϊ�˷������ ���˴��� 
};
int main(void)
{
	struct Student st={80,55.6f,10001,'F'};
	printf("st.age=%d\n",st.age);
	
	printf("�ṹ��ĳ���Ϊ%d\n",sizeof(st)); 
	
	struct Student* pst = &st; 
	
		printf("st.age=%d\n",(*pst).age);
		
	    printf("age=%d\n",pst->age); 
    system("pause"); 

}
