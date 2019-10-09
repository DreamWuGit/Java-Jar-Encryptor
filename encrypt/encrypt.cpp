#include "jni.h"
#include <iostream>
 
extern"C" JNIEXPORT jbyteArray JNICALL 
Java_Encrypt_encrypt(
    JNIEnv * _env, 
    jobject _obj,
    jbyteArray _buf
)
{
    jsize len =_env->GetArrayLength(_buf);   

    unsigned char* dst = (unsigned char*)_env->GetByteArrayElements(_buf, 0);
 	
    // below code will skip when len == 1
 	for (int i = 0; i < len ; ++i)
 	{
         dst[i] = dst[i] ^ (i % 255)^0x12;// work
        // dst[i] = dst[i] ^ dst[2 * i + 1]; not work
 		// dst[i] = dst[i] ^ dst[i-1];  not work                                                                                                                ;
 	}
 
    _env->SetByteArrayRegion(_buf, 0, len, (jbyte *)dst);
    return _buf;
}
