#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#include <malloc.h>
#include <string.h>
#include "com_czt_ndkpassdata_DataProvider.h"
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
/**
 *Jstring2CStr ��java�е�string ת���� c�е�char����.
 *jstring   jstr Ҫ��ת����java string
 *char*  ��������ַ�����������(�ַ���������׵�ַ)
 */
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
	 char*   rtn   =   NULL;
	 jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");//Ѱ�� java����String.class
	 jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");//����java�ַ��� "gb2312"
	 jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");//Ѱ�ҵ�java String getbytes();
	 jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
	 jsize   alen   =   (*env)->GetArrayLength(env,barr);
	 jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	 if(alen   >   0)
	 {
	  rtn   =   (char*)malloc(alen+1);         //"\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
	 return rtn;
}
JNIEXPORT jint JNICALL Java_com_czt_ndkpassdata_DataProvider_add
  (JNIEnv * env, jobject obj, jint x, jint y){
	LOGI("x=%d",x);
	LOGD("y=%d",y);
	int result = x+y;
	LOGD("result=%d",result);
	return result;
}
JNIEXPORT jstring JNICALL Java_com_czt_ndkpassdata_DataProvider_sayHelloInC
  (JNIEnv * env, jobject obj, jstring jstr){
//������Ҫ��java�е�stringת�����Ǹ�c�����е�char*
	char* cstr = Jstring2CStr(env, jstr);
	LOGI("cstr=%s", cstr);
	char* chello = " ni hao";
	strcat(cstr, chello);
	LOGI("cstr=%s", cstr);
	return (*env)->NewStringUTF(env, cstr);
}
/**
 * ��java���ݹ�����int���������ÿһ��Ԫ��ֵ����10
 * �ٷ��ظ�java����
 */
JNIEXPORT jintArray JNICALL Java_com_czt_ndkpassdata_DataProvider_intMethod
  (JNIEnv * env, jobject obj, jintArray jintarr){
    /**
     * ��jni.h�п����ҵ�����ķ�����
     * jint* (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
     * ��ȡһ��int�������� ��һ��Ԫ�ص��׵�ַ��
     * ���һ�������ٷ����Ͳ�����һ����0���ɡ�
     *  jsize (*GetArrayLength)(JNIEnv*, jarray);
     *  ��ȡһ������ĳ��� ����ֵ ��jsize����
     *  ���Կ��� jsize����jint jint����int
     */
	int len = (*env)->GetArrayLength(env,jintarr);
	LOGI("len=%d",len);
	jint* intarr =  (*env)->GetIntArrayElements(env,jintarr,0);
	int i;
	for(i=0;i<len;i++){
		LOGI("intarr[%d]=%d",i,intarr[i]);//int ����ԭ��ÿһ��Ԫ�صĳ�ʼֵ
		*(intarr+i) += 10;
	}

	return jintarr;
}

