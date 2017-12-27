TARGET=Assignment_5_6
CC_OPTS=/c /Od /Zi /MTd /Wall  /Fa  /wd4710
LINK_OPTS=/DEBUG:FULL /SUBSYSTEM:CONSOLE /LTCG:OFF  /INCREMENTAL:NO

all: $(TARGET)

clean:
	if EXIST $(TARGET).exe del $(TARGET).exe
	if EXIST *.obj del *.obj
	if EXIST *.pdb del *.pdb
	if EXIST *.asm del *.asm
	if EXIST *.ilk del *.ilk

$(TARGET): $(TARGET).o
	link $(LINK_OPTS) /OUT:$(TARGET).exe  /PDB:$(TARGET).pdb  $(TARGET).obj

$(TARGET).o: $(TARGET).c
	cl $(CC_OPTS) /Fo:$(TARGET).obj  $(TARGET).c