#ifeq ($(PARAM_FILE), )
#	PARAM_FILE := ../../../Makefile.param
	#PARAM_FILE := ../../../../mpp_big-little/Makefile.param
#	include $(PARAM_FILE)
#endif

CC := gcc
#GST_PATH := $(SDK_PATH)/package/gstreamer
GST_PATH := /home/joel/workspace/linux_x86_64
CFLAGS += `pkg-config --define-variable=prefix=$(GST_PATH) --define-variable=libdir=$(GST_PATH)/lib --cflags $(GST_PATH)/lib/pkgconfig/gstreamer-1.0.pc`
#CFLAGS += -pthread -I$(GST_PATH)/include/gstreamer-1.0 -I$(GST_PATH)/include/glib-2.0 -I$(GST_PATH)/lib/glib-2.0/include
#-I$(GST_PATH)/include/glib-2.0 -I$(GST_PATH)/include/gstreamer-1.0
#LDFLAGS += `pkg-config --libs $(GST_PATH)/lib/pkgconfig/gstreamer-1.0.pc`
LDFLAGS += -L$(GST_PATH)/lib -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0 -lffi 
#-lgmodule-2.0 -liconv -lintl

# target source
SRCS := $(wildcard *.c)
OBJS  := $(SRCS:%.c=%.o)
TARGET := gst000

.PHONY : clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread -lm 

.c.o:
#	@echo $(CFLAGS)
	$(CC) $(CFLAGS) -c $<


clean:
	@rm -f $(TARGET)
	@rm -f $(OBJS)


