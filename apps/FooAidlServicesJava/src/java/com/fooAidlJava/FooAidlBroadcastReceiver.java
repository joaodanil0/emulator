package com.fooAidlJava;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class FooAidlBroadcastReceiver extends BroadcastReceiver {
    private static final String TAG = "FooJavaBroadcastReceiver";

    @Override
    public void onReceive(Context context, Intent intent) {

        String scalingGovernor = intent.getStringExtra("setTest");

        if(scalingGovernor != null) {

            try {
                Log.d(TAG, "Current ScalingGovernor(" + FooAidlServices.getCpuAJ().getTest() + ")");

                if(FooAidlServices.getCpuAJ().setTest(scalingGovernor)) {
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