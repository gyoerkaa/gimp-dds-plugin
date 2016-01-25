
GIMPTOOL = gimptool-2.0
#	$(GIMPTOOL) --build src/file-dds.c

CC = gcc

LIBS := $(shell $(GIMPTOOL) --libs)

CFLAGS := $(shell $(GIMPTOOL) --cflags)

OUTDIR = bin

TARGET = $(OUTDIR)/file-dds

all:
	mkdir -p $(OUTDIR)
	$(CC) src/plugin.c $(CFLAGS) $(LIBS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
	
install:
	$(GIMPTOOL) --install-bin $(TARGET)

