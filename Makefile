
GIMPTOOL = gimptool-2.0
#	$(GIMPTOOL) --build src/file-dds.c

LIBS := $(shell $(GIMPTOOL) --libs)

CFLAGS := $(shell $(GIMPTOOL) --cflags)

OUTDIR = bin

TARGET = $(OUTDIR)/file-dds

all:
	mkdir -p $(OUTDIR)
	gcc src/plugin.c $(CFLAGS) $(LIBS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)
	
install:
	$(GIMPTOOL) --install-bin $(TARGET)

