PARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -fno-stack-protector -nostartfiles -nodefaultlibs -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -m elf_i386

files = loader.o kernel.o

%_o: %.cpp
	g++ $(PARAMS) -o $@ -c $< 
%_o: %.s
	as $(ASPARAMS) -o $@ $<

kernel.bin: linker.ld $(files)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: kernel.bin 
	sudo cp $< /boot/kernel.bin