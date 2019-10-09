ifeq ($(shell uname), Linux)
  CC         = g++ -fPIC 
  LIBLINK    = -shared 
  INCLUDEDIR = -I /usr/java/default/include -I /usr/java/default/include/linux
  TARGET     = liblinux.so
endif

ifeq ($(shell uname), Darwin)
  CC		 = g++ 
  LIBLINK    = -dynamiclib
  TARGET     = libdecrypt.dylib
  INCLUDEDIR = -I/System/Library/Frameworks/JavaVM.framework/Headers -I /Library/Java/JavaVirtualMachines/jdk-10.0.2.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk-10.0.2.jdk/Contents/Home/include/darwin
endif

OBJS = decrypt.o

$(TARGET):$(OBJS)
	$(CC) $(LIBLINK) -o $(TARGET) $(OBJS)

decrypt.o: decrypt.cpp
	$(CC) $(INCLUDEDIR) -c decrypt.cpp

.PHONY:clean
clean:
	rm $(TARGET) $(OBJS)
