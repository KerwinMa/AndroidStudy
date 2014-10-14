#include <stdio.h>
#include <jni.h>
#include "com_czt_lame_MainActivity.h"
#include "lame.h"
#include <malloc.h>
#include <string.h>

/**
 * ��־λ��1Ϊת����0Ϊֹͣת����
 */
int flag = 1;
/**
 * ���߷���
 */
char* Jstring2CStr(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env, "GB2312");
	jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
			"(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
			strencode); // String .getByte("GB2312");
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1); //"\0"
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0); //
	return rtn;
}
/**
 * ��ȡlame�汾��
 */
JNIEXPORT jstring JNICALL Java_com_czt_lame_MainActivity_getVersion
  (JNIEnv * env, jobject obj){
	return (*env)->NewStringUTF(env, get_lame_version());
}
/**
 * ֹͣת����
 */
JNIEXPORT void JNICALL Java_com_czt_lame_MainActivity_stopConvert
  (JNIEnv *env, jobject obj){
	flag = 0;
}
/**
 * ����java����
 */
void updateUI(JNIEnv * env, jobject obj,int process){
	//  jclass      (*FindClass)(JNIEnv*, const char*);
	jclass jclazz = (*env)->FindClass(env,"com/czt/lame/MainActivity");
// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID methodid = (*env)->GetMethodID(env,jclazz,"setCurrentProcess","(I)V");

	// void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,methodid,process);
}
/**
 * ��wavתΪMP3
 */
JNIEXPORT void JNICALL Java_com_czt_lame_MainActivity_convert
  (JNIEnv * env, jobject obj , jstring jWavPath, jstring jMp3Path){
	flag = 1;
	char* cWavPath = Jstring2CStr(env, jWavPath);
	char* cMp3Path = Jstring2CStr(env,jMp3Path);

	FILE* wav = fopen(cWavPath, "rb");
	FILE* mp3 = fopen(cMp3Path, "wb"); //�������ļ�

	short int wav_buffer[8192*2];//��ȡ��������������,������
	unsigned char mp3_buffer[8192];//�����mp3�Ļ�����

	//1.���ļ� 2.ת�� 3.ת����浽mp3�ļ�.
	//��ʼ�� lame������
	lame_global_flags * lame = lame_init();
	//���ò�����
	lame_set_in_samplerate(lame, 44100);
	//����������
	lame_set_num_channels(lame, 2);

	//���ñ��뷽ʽ.
	lame_set_VBR(lame, vbr_default);
	lame_init_params(lame);
	int read;//�ɹ��Ķ��˶��ٸ��ֽ�
	int write;//д�˶��ٸ��ֽ�

	int process = 0;

	do {
		if(flag == 0){
			return;
		}
		read = fread(wav_buffer, sizeof(short int)*2, 8192, wav);
		if(read == 0) {
			//ʹ��do-while��Ϊ����0��ʱ��flushһ�¡� ���һ��Ĳ����ǲ�һ���ġ�
			write = lame_encode_flush(lame, mp3_buffer, 8192);
		}else{
			write = lame_encode_buffer_interleaved(lame, wav_buffer, read, mp3_buffer, 8192);
		}
		fwrite(mp3_buffer, sizeof(unsigned char), write, mp3);
		process += sizeof(short int)*2*read;
		//c����java���� ֪ͨ�������
		updateUI(env,obj,process);
	}while(read != 0);
	lame_close(lame);
	fclose(wav);
	fclose(mp3);
}
