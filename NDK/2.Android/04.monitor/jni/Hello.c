#include <stdio.h>
#include <stdlib.h>
#include "com_czt_ndk_monitor_DemoActivity.h"

int getPressure(){
    //��c����ʦʵ�ֵ���.
  return   rand()%300;
}

/**
 * ģ���ȡӲ�����ػ���������
 */

JNIEXPORT jint JNICALL Java_com_czt_ndk_monitor_DemoActivity_getCurrentPressure
  (JNIEnv * env, jobject obj){

	return getPressure();
}
