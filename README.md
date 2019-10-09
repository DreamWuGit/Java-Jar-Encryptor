# Java-Jar-Encryptor
this is an utility to encrypt a java package
Java Jar包加密工具，不包含混淆操作

目录结构及文件：

./JarEncrypt2/encrypt   ## 加密库

—– encrypt.cpp

—– Makefile

./JarEncrypt2/decrypt    ## 解密库

—–decrypt.cpp

—– Makefile

./JarEncrypt2/Encrypt.java   ## Java加密执行文件

需要注意的几个地方：

Encrypt.java

if(name.endsWith(“.class”) && name.startsWith(“org/test/”)){

//org.test开头的文件进行加密

decrypt.cpp

if(name&&strncmp(name,”org/test/”,12)==0){ 

//只对包名以org/test/

进入encrypt目录，执行make，编译生成libencrypt.so：

[liuxiaowen@produce-gateway encrypt]$ make

g++ -fPIC  -I /usr/java/default/include -I /usr/java/default/include/linux -c encrypt.cpp

g++ -fPIC  -shared  -o libencrypt.so encrypt.o

 

进入decrypt目录，执行make，编译生成liblinux.so：

[liuxiaowen@produce-gateway decrypt]$ make

g++ -fPIC  -I /usr/java/default/include -I /usr/java/default/include/linux -c decrypt.cpp

g++ -fPIC  -shared  -o liblinux.so decrypt.o

 

回到上级目录，编译Encrypt.java

javac Encrypt.java

生成Encrypt.class

 

执行加密：假设要对目标jar包Test.jar 执行加密

 java -Djava.library.path=./encrypt/ -cp . Encrypt -src Test.jar

encode jar file: [Test.jar ==> Test_encrypt.jar ]

encrypt org.test.Test.class

encrypt org.test.Test2.class

生成了加密后的jar包：Test_encrypt.jar

可以先试运行一下这个jar包：

java -cp Test_encrypt.jar com.lxw1234.test.Test

Exception in thread “main” java.lang.ClassFormatError: Incompatible magic value 3455696313 in class file com/lxw1234/test/Test

at java.lang.ClassLoader.defineClass1(Native Method)

at java.lang.ClassLoader.defineClass(ClassLoader.java:800)

at java.security.SecureClassLoader.defineClass(SecureClassLoader.java:142)

at java.net.URLClassLoader.defineClass(URLClassLoader.java:449)

at java.net.URLClassLoader.access$100(URLClassLoader.java:71)

at java.net.URLClassLoader$1.run(URLClassLoader.java:361)

at java.net.URLClassLoader$1.run(URLClassLoader.java:355)

at java.security.AccessController.doPrivileged(Native Method)

at java.net.URLClassLoader.findClass(URLClassLoader.java:354)

at java.lang.ClassLoader.loadClass(ClassLoader.java:425)

at sun.misc.Launcher$AppClassLoader.loadClass(Launcher.java:308)

at java.lang.ClassLoader.loadClass(ClassLoader.java:358)

at sun.launcher.LauncherHelper.checkAndLoadMain(LauncherHelper.java:482)

使用jd-gui反编译：

java

已经无法反编译。

 

使用解密库文件解密后执行：

export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/home/liuxiaowen/JarEncrypt2/decrypt

java -agentlib:linux -jar Test_encrypt.jar 
-jar 后面填写目标要执行的jar包

可以正常执行。

这样，再发布时候，需要把Test_encrypt.jar 和 liblinux.so 发布出去，执行时候引入liblinux即可。

参考文章：http://www.alonemonkey.com/2016/05/25/encrypt-jar-class/
