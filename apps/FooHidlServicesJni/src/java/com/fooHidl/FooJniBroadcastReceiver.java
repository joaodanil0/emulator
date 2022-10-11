package com.fooHidl;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class FooJniBroadcastReceiver extends BroadcastReceiver {
    private static final String TAG = "FooJniBroadcastReceiver";

    @Override
    public void onReceive(Context context, Intent intent) {

        String scalingGovernor = intent.getStringExtra("setTest");

        if(scalingGovernor != null) {

            Log.d(TAG, "Current ScalingGovernor(" + FooJniServices.getCpu().getTest() + ")");

            if(FooJniServices.getCpu().setTest(scalingGovernor)) {
                Log.d(TAG, "Succesfuly setScalingGovernor(" + scalingGovernor + ")");
            } 
            else {
                Log.e(TAG, "Failed calling setScalingGovernor(" + scalingGovernor + ")");
            }
        }
    }
}