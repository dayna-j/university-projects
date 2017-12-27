APP=Assignment_10
LL_OPTS=/LTCG:OFF /INCREMENTAL:NO  /SUBSYSTEM:CONSOLE /DEBUG:FULL
CC_OPTS=/Od /Ob0 /wd4255 /wd4710 /wd4100  /wd4189 /Zi /MTd /Wall

all: $(APP).exe

$(APP).exe: $(APP).obj
	LINK $(LL_OPTS) /PDB:$(APP).pdb /OUT:$(APP).exe $(APP).obj

$(APP).obj: $(APP).c
	cl $(CC_OPTS) $(APP).c

clean:
	del /Q $(APP).obj $(APP).asm $(APP).exe  $(APP).pdb vc140.pdb *.bak