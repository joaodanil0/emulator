
package com.fooJniJava;
import android.util.Log;

public class FooJniJava {
    static final String TAG = "com.fooJniJava";
    static final boolean DEBUG = false;

    private native void nativeInit();
    private static native boolean nativeSetTest(String governor);
    private static native String nativeGetTest();

    public FooJniJava() {
        Log.d(TAG, "FooJniJava onCreate()");
        synchronized (this) {
            nativeInit();
        }
    }

    public boolean setTest(String governor) {
        return nativeSetTest(governor);
    }

    public String getTest() {
        return nativeGetTest();
    }

    static {
        Log.d(TAG, "FooJniJava static");
        System.loadLibrary("fooJNI"); // libeightman.so
    }
}