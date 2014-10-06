#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#include "com_czt_ndkcallback_DataProvider.h"
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
/**
 * env JNIEnv* java�����������ָ��.
 *
 *jobject obj ,�ĸ�������õ����native�ķ��� , obj�ʹ�������ĸ�����
 */
JNIEXPORT void JNICALL Java_com_czt_ndkcallback_DataProvider_callMethod1
  (JNIEnv * env, jobject obj){
	//˼�� java�еķ���
	//1.�ҵ�ĳһ������ֽ���
	//   jclass      (*FindClass)(JNIEnv*, const char*);
	jclass jclazz = (*env)->FindClass(env,"com/czt/ndkcallback/DataProvider");
	if(jclazz==0){
		LOGI("LOAD CLAZZ ERROR");
	}else{
		LOGI("LOAD CLAZZ success");
	}
	//2.�ҵ�����ֽ�������ķ���.
	// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);

	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"helloFromJava","()V");
	if(methodid==0){
		LOGI("LOAD methodid ERROR");
	}else{
		LOGI("LOAD methodid success");
	}

	//3.���÷���
	//void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,methodid);


}
/*
 * Class:     com_czt_ndkcallback_DataProvider
 * Method:    callMethod2
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_czt_ndkcallback_DataProvider_callMethod2
(JNIEnv * env, jobject obj){
	jclass jclazz = (*env)->FindClass(env,"com/czt/ndkcallback/DataProvider");
	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"add","(II)I");
	//    jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
	int result = (*env)->CallIntMethod(env,obj,methodid,3,5);
	LOGI("result=%d",result);
}

/*
 * Class:     com_czt_ndkcallback_DataProvider
 * Method:    callMethod3
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_czt_ndkcallback_DataProvider_callMethod3
(JNIEnv * env, jobject obj){
	jclass jclazz = (*env)->FindClass(env,"com/czt/ndkcallback/DataProvider");
	/*
		typedef union jvalue {
		jboolean    z;
		jbyte       b;
		jchar       c;
		jshort      s;
		jint        i;
		jlong       j;
		jfloat      f;
		jdouble     d;
		jobject     l;
		} jvalue;
		���Դ������jni.h�����п��� ǩ��(Ljava/lang/String;)V�� L��ΪObject��������string�ľ�������
	 */
	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"printString","(Ljava/lang/String;)V");
	(*env)->CallVoidMethod(env,obj,methodid,(*env)->NewStringUTF(env,"haha from c "));
}
