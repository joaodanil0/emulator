package com.fooHidlJava;

import android.app.Application;
import android.util.Log;
import android.content.IntentFilter;
import mypackage.mysubpackage.foo.V1_0.ITest;

public class FooJavaServices extends Application {
    private static final String TAG = "FooJavaServices";

    FooJavaBroadcastReceiver fooJavaBroadcastReceiver = new FooJavaBroadcastReceiver();
    private static ITest cpuHJ; // HIDL Java Proxy

    public void onCreate() {
        super.onCreate();

        Log.d(TAG, "onCreate()");

        try {
            cpuHJ = ITest.getService(true);
        } 
        catch (android.os.RemoteException e) {
            Log.e(TAG, "ITest error", e);
        }

        IntentFilter filter = new IntentFilter("com.fooHIDL.fooHIDL");
        registerReceiver(fooJavaBroadcastReceiver, filter);
    }

    public void onTerminate() {
        super.onTerminate();
        Log.d(TAG, "Terminated");
    }

    // HIDL Java Proxy
    public static ITest getCpuHJ() {
        return cpuHJ;
    }
}