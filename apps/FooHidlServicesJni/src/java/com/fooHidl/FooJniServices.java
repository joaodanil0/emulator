package com.fooHidl;

import android.app.Application;
import android.util.Log;
import android.content.IntentFilter;
import com.fooJniJava.FooJniJava;

public class FooJniServices extends Application {
    private static final String TAG = "FooJniServices";

    FooJniBroadcastReceiver fooJniBroadcastReceiver = new FooJniBroadcastReceiver();
    private static FooJniJava cpu; // JAVA -> JNI -> HIDL

    public void onCreate() {
        super.onCreate();

        Log.d(TAG, "onCreate()");
        cpu = new FooJniJava();




        
        
        
        IntentFilter filter = new IntentFilter("com.fooHIDL.fooHIDL");
        registerReceiver(fooJniBroadcastReceiver, filter);
    }

    public void onTerminate() {
        super.onTerminate();
        Log.d(TAG, "Terminated");
    }


    public static FooJniJava getCpu() {
        return cpu;
    }
}