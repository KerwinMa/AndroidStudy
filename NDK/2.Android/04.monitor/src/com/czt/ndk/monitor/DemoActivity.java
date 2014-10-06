package com.czt.ndk.monitor;

import java.util.Timer;
import java.util.TimerTask;

import com.czt.ndk.monitor.R;

import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;

public class DemoActivity extends Activity {
	static {
		System.loadLibrary("Hello");
	}

	public native int getCurrentPressure();

	private Timer timer; // ����һ����ʱ��
	private TimerTask task; // ������ʱ��ִ�е�����
	
	private Handler handler = new Handler(){
		public void handleMessage(android.os.Message msg) {
			int pressure = (Integer) msg.obj;
			
			if(pressure>275){
				//������, ���ʼ�, ���ű�������.
				MediaPlayer player = MediaPlayer.create(getApplicationContext(), R.raw.ylzs);
				player.setLooping(false);
				player.setVolume(1.0f, 1.0f);
				player.start();
				if (task != null && timer != null) {
					task.cancel();
					timer.cancel();
					task = null;
					timer = null;
				}
				TextView tv  = new TextView(getApplicationContext());
				tv.setTextSize(30);
				tv.setText("��¯��Ҫ��ը��,�Ͻ��ܰ�");
				setContentView(tv);
				return;
			}
			
			
			setContentView(new MyView(getApplicationContext(), pressure));
		};
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		timer = new Timer();
		task = new TimerTask() {

			@Override
			public void run() {
				int pressure = getCurrentPressure();
				//System.out.println("pressure:" + pressure);
				Message msg = Message.obtain();
				msg.obj = pressure;
				handler.sendMessage(msg);
			}
		};
		// ���ڵĻ�ȡ��¯��ѹ��.
		timer.schedule(task, 1000, 1000);
	}
	/**
	 * ��onDestory���治�ã���С���ֻ��Ͻ���ر�һ���֮�������Ӧ��
	 * ��øĳ���finish���߼��back��Ӧ��
	 */
	@Override
	protected void onDestroy() {
		if (task != null && timer != null) {
			task.cancel();
			timer.cancel();
			task = null;
			timer = null;
		}
		super.onDestroy();
	}
}