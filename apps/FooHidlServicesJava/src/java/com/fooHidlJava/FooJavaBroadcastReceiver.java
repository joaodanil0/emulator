package com.fooHidlJava;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class FooJavaBroadcastReceiver extends BroadcastReceiver {
    private static final String TAG = "FoohidlBR";

    @Override
    public void onReceive(Context context, Intent intent) {

        String scalingGovernor = intent.getStringExtra("setTest");

        if(scalingGovernor != null) {

            try {
                Log.d(TAG, "Current ScalingGovernor(" + FooJavaServices.getCpuHJ().getTest() + ")");

                if(FooJavaServices.getCpuHJ().setTest(scalingGovernor)) {
                    Log.d(TAG, "Succesfuly setScalingGovernor(" + scalingGovernor + ")");
                } 
                else {
                    Log.e(TAG, "Failed calling setScalingGovernor(" + scalingGovernor + ")");
                }
            }
            catch (android.os.RemoteException e) {
                Log.e(TAG, "ITest error", e);
            
            }
           
        }
    }
}