// JavaLoader.cpp : Defines the exported functions for the DLL.
//

#include "JavaLoader.h"

#include <jni.h>
#include <iostream>

static JavaVM* javaVM = nullptr;


void CreateJVM()
{
    JNIEnv* env;       /* pointer to native method interface */
    JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
    JavaVMOption* options = new JavaVMOption[1];
    options[0].optionString = _strdup("-Djava.class.path=C:\\Users\\polek\\source\\repos\\JNI_JVM_example\\CustomClassLoader");
    //options[0].optionString = _strdup("-Djava.class.path=C:\\Users\\polek\\source\\repos\\JNI_JVM_example\\SimpleHelloWorldJava");

    vm_args.version = JNI_VERSION_10;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;
    /* load and initialize a Java VM, return a JNI interface
     * pointer in env */
    long flag = JNI_CreateJavaVM(&javaVM, (void**)&env, &vm_args);
    if (flag == JNI_ERR)
    {
        std::cout << "Error creating VM. Exiting...n";
        throw new std::exception("Error creating VM");
    }
}


void RunJavaProgram1(std::string msg)
{
    JNIEnv* env;
    javaVM->GetEnv((void**)&env, JNI_VERSION_10);

    jclass cls = env->FindClass("HelloWorld");
    if (cls == nullptr)
    {
        throw new std::exception("Could not fined HelloWorld");
    }

    jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    if (mid == nullptr)
    {
        throw new std::exception("Could not find HelloWorld.Main(string array)");
    }

    jobjectArray stringArray;
    jstring keyString = env->NewStringUTF(msg.c_str());
    stringArray = env->NewObjectArray(1, env->FindClass("[Ljava/lang/String;"), keyString);

    env->CallStaticVoidMethod(cls, mid, stringArray);
    jthrowable jexc = env->ExceptionOccurred();
    if (jexc != nullptr)
    {
        std::cout << "Error occured" << std::endl;
        env->ExceptionDescribe();
    }
}

void RunJavaProgram2(std::string msg)
{
    JNIEnv* env;
    javaVM->GetEnv((void**)&env, JNI_VERSION_10);

    jclass cls = env->FindClass("CustomClassLoader");
    if (cls == nullptr)
    {
        throw new std::exception("Could not fined CustomClassLoader");
    }

    jmethodID mid = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    if (mid == nullptr)
    {
        throw new std::exception("Could not fined CustomClassLoader.Main(string array)");
    }

    jobjectArray stringArray;
    jstring keyString = env->NewStringUTF(msg.c_str());
    stringArray = env->NewObjectArray(1, env->FindClass("[Ljava/lang/String;"), keyString);

    env->CallStaticVoidMethod(cls, mid, stringArray);
    jthrowable jexc = env->ExceptionOccurred();
    if (jexc != nullptr)
    {
        std::cout << "Error occured" << std::endl;
        env->ExceptionDescribe();
    }
}

void DestroyJVM()
{
    if (javaVM != nullptr)
    {
        javaVM->DestroyJavaVM();
    }
}
