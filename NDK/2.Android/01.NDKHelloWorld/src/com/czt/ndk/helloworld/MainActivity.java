package com.czt.ndk.helloworld;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	/**
	 * 1.����һ��native�ķ�����
	 * @return
	 */
	public native String helloFromC();
	public native String hello_from_c();
	//5.��Ҫ���õ�c��������ص�java��������档
	static{
		System.loadLibrary("Hello");
	}
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
	/**
	 * ���õײ�c����
	 * @param view
	 */
	public void click(View view) {
		//6. ����c���롣
		Toast.makeText(this, helloFromC(), Toast.LENGTH_LONG).show();
	}
	/**
	 * ���õײ�c����
	 * @param view
	 */
	public void click2(View view) {
		//6. ����c���롣
		Toast.makeText(this, hello_from_c(), Toast.LENGTH_LONG).show();
	}
}
