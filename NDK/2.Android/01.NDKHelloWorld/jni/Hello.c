#include <stdio.h>
#include <jni.h>
//2.ʵ��Java���涨���c������
//���������������������֣�1.��������2.�����ķ���ֵ�ͽ��ܵĲ���
jstring Java_com_czt_ndk_helloworld_MainActivity_helloFromC(JNIEnv* env,jobject obj){
	//����һ��Java��string
//	   jstring     (*NewStringUTF)(JNIEnv*, const char*);

	//return (*(*env)).NewStringUTF(env, "hello from c!");
	return (*env)->NewStringUTF(env, "hello from c!");
}
jstring Java_com_czt_ndk_helloworld_MainActivity_hello_1from_1c(JNIEnv* env,jobject obj){
	//����һ��Java��string
//	   jstring     (*NewStringUTF)(JNIEnv*, const char*);

	//return (*(*env)).NewStringUTF(env, "hello from c!");
	return (*env)->NewStringUTF(env, "hello_from_c!");
}
//3.c����д�ú���Ҫ��c��������һ����ִ�еĶ������ļ���--->.so
//4.��дandroid.mk�ļ���c��������һ��so�ļ���
