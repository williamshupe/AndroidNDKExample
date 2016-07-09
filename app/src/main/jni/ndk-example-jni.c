#include <jni.h>
#include <gameRandomness.h>
#include <android/log.h>
#include <stdio.h>

JNIEXPORT jstring JNICALL
Java_com_example_androidndkexample_Player_shoot(JNIEnv *env, jobject instance, jint power) {

    char buffer [100];
    snprintf(buffer, 100, "Player shot with a power of %d.", power);
    __android_log_print(ANDROID_LOG_DEBUG, "AndroidNDKExample-JNI", buffer);

    //Get a reference to the shots member variable field
    jclass cls = (*env)->GetObjectClass(env, instance);
    jfieldID shot_field_id = (*env)->GetFieldID(env, cls, "shots", "I");

    //Get and set shots in Player class
    int shots = (*env)->GetIntField(env, instance, shot_field_id);
    shots++;
    (*env)->SetIntField(env, instance, shot_field_id, shots);

    //See if we scored
    if(shotBecameGoal(power)){

        __android_log_print(ANDROID_LOG_DEBUG, "AndroidNDKExample-JNI", "Player's shot became a goal.");

        jfieldID goal_field_id = (*env)->GetFieldID(env, cls, "goals", "I");

        //Get and set goals in Player class
        int goals = (*env)->GetIntField(env, instance, goal_field_id);
        goals++;
        (*env)->SetIntField(env, instance, goal_field_id, goals);

        return (*env)->NewStringUTF(env, "Shot scored!");
    }

    return (*env)->NewStringUTF(env, "Shot missed...");
}

JNIEXPORT jstring JNICALL
Java_com_example_androidndkexample_Player_pass(JNIEnv *env, jobject instance) {

    __android_log_print(ANDROID_LOG_DEBUG, "AndroidNDKExample-JNI", "Player passed.");

    if(passBecameAssist()){

        __android_log_print(ANDROID_LOG_DEBUG, "AndroidNDKExample-JNI", "Player's pass became an assist.");

        //Get a reference to the shots member variable field
        jclass cls = (*env)->GetObjectClass(env, instance);
        jfieldID assist_field_id = (*env)->GetFieldID(env, cls, "assists", "I");

        //Get and set assists in Player class
        int assists = (*env)->GetIntField(env, instance, assist_field_id);
        assists++;
        (*env)->SetIntField(env, instance, assist_field_id, assists);

        return (*env)->NewStringUTF(env, "Pass became an assist!");
    }

    return (*env)->NewStringUTF(env, "Player passed the ball.");
}