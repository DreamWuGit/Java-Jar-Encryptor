ifeq ($(shell uname), Linux)
  CC         = g++ -fPIC 
  LIBLINK    = -shared 
  INCLUDEDIR = -I /usr/java/default/include -I /usr/java/default/include/linux
  TARGET     = libencrypt.so
endif

ifeq ($(shell uname), Darwin)
  CC		 = g++ 
  LIBLINK    = -dynamiclib
  TARGET     = libencrypt.dylib
  INCLUDEDIR = -I/usr/java/default/include -I /Library/Java/JavaVirtualMachines/jdk-10.0.2.jdk/Contents/Home/include -I /Library/Java/JavaVirtualMachines/jdk-10.0.2.jdk/Contents/Home/include/darwin
endif

OBJS = encrypt.o

$(TARGET):$(OBJS)
	$(CC) $(LIBLINK) -o $(TARGET) $(OBJS)

encrypt.o: encrypt.cpp
	$(CC) $(INCLUDEDIR) -c encrypt.cpp

.PHONY:clean
clean:
	rm $(TARGET) $(OBJS)
