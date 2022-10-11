package com.fooAidlJava;

import android.app.Application;
import android.util.Log;
import android.content.IntentFilter;
import android.os.ServiceManager;
import android.os.IBinder;

public class FooAidlServices extends Application {
    private static final String TAG = "FooAidlServices";

    private static final String ICPU_AIDL_INTERFACE = "mypackage.mysubpackage.fooAIDL.ITest/default";

    FooAidlBroadcastReceiver fooAidlBroadcastReceiver = new FooAidlBroadcastReceiver();
    private static mypackage.mysubpackage.fooAIDL.ITest cpuAJ; // AIDL Java Proxy

    public void onCreate() {
        super.onCreate();

        Log.d(TAG, "onCreate()");

        IBinder binder = ServiceManager.getService(ICPU_AIDL_INTERFACE);

        if (binder == null) {
            Log.e(TAG, "Getting " + ICPU_AIDL_INTERFACE + " service daemon binder failed");
        } 
        else {
            cpuAJ = mypackage.mysubpackage.fooAIDL.ITest.Stub.asInterface(binder);
            
            if (cpuAJ == null) {
                Log.e(TAG, "Getting ICpu Aidl daemon interface failed");
            } 
        }

        IntentFilter filter = new IntentFilter("com.fooHIDL.fooHIDL");
        registerReceiver(fooAidlBroadcastReceiver, filter);
    }

    public void onTerminate() {
        super.onTerminate();
        Log.d(TAG, "Terminated");
    }

    // AIDL Java Proxy
    public static mypackage.mysubpackage.fooAIDL.ITest getCpuAJ() {
        return cpuAJ;
    }
}