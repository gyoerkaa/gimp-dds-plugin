
GIMPTOOL = gimptool-2.0
#	$(GIMPTOOL) --build src/ddsplugin.c

CC = g++

LIBS := $(shell $(GIMPTOOL) --libs)

CFLAGS := $(shell $(GIMPTOOL) --cflags)

OUTDIR = bin

TARGET = $(OUTDIR)/file-dds

SOURCES +=  src/ddsplugin.c \
			src/ddsimport.cpp 

HEADERS  += src/ddsplugin.h \
			src/options.h \
			src/ddsheader.h \
    		src/ddsimport.hpp

all:
	mkdir -p $(OUTDIR)
	$(CC) $(SOURCES) $(HEADERS) $(CFLAGS) $(LIBS) -o $(TARGET) -std=c++11

clean:
	rm -f *.o $(TARGET)
	
install:
	$(GIMPTOOL) --install-bin $(TARGET)

