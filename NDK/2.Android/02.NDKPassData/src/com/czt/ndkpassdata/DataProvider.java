package com.czt.ndkpassdata;

/**
 * �ṩnative�ķ���������.
 *
 */
public class DataProvider {
	static{
		System.loadLibrary("Hello");
	}
	/**
	 * ��������int���͵����ݸ�c����,c���봦��������������ݺ󷵻ظ��ϲ��java
	 * native����ļ�����
	 * @param x
	 * @param y
	 * @return
	 */
	public native int add(int x ,int y); // String[] zhangsan:lisi:wangwu
                                         // kiss : keep it simple and stupid
	
	
	/**
	 * ����һ��java�е�string��c����,c���Դ���������string֮�󷵻�һ���µ��ַ���.
	 * @param s  ��c����������ַ�������
	 * ����string��c����,c������string���� ƴװһ��nihao ���ظ�java
	 * @return
	 */
	public native String sayHelloInC(String s); //����java char����
	
	/**
	 * ����һ��int���͵������ c���� ,c���Դ������int���͵�����,
	 * �Ѵ����������ٷ��ظ�java
	 * ����������Ƶ
	 * @param iNum
	 * @return
	 */
	public native int[] intMethod(int[] iNum); 

}
