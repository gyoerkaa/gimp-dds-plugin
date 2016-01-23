
GIMPTOOL=gimptool-2.0

all:
	$(GIMPTOOL) --build src/file-dds.c
	
install:
	$(GIMPTOOL) --install src/file-dds.c

