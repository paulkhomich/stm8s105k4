// Макрос вызова одной Ассемблерной команды cmd
#define ASM(cmd) __asm cmd; __endasm

// Макрос для задержки на n тактовых-пачек
#define DELAY(n) for (unsigned int i = n; i > 0; i--) { }