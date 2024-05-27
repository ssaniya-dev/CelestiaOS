void printf(char* str) {
    static unsigned short* vidMem = (unsigned short*)0xb8000;
    for(int i = 0; str[i] != '\0'; ++i) {
        vidMem[i] = (vidMem[i] & 0xFF00) | str[i];
    }
}

extern "C" void sleep(int seconds) {
    for(int i = 0; i < seconds; ++i) {
        for(int j = 0; j < 100000000; ++j) {
            // Do nothing
        }
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void constructors() {
    for(constructor* i = &start_ctors; i != &end_ctors; ++i) {
        (*i)();
    }
}

extern "C" void kernelSetup(void *multiboot_structure, unsigned int magic) {
    printf("Kernel setup\n");
    while(1) {
        printf("Kernel loop\n");
        sleep(1);
    }
}