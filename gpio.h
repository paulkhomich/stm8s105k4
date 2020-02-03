/*
Побитовая структура IO регистра
Каждый вывод порта имеет свой бит-представитель
PIN(i) = Вывод(i)
Либо представление всего регистра в целом
VALUE
*/
typedef union IOREG {
    struct {
        unsigned char PIN0 : 1;
        unsigned char PIN1 : 1;
        unsigned char PIN2 : 1;
        unsigned char PIN3 : 1;
        unsigned char PIN4 : 1;
        unsigned char PIN5 : 1;
        unsigned char PIN6 : 1;
        unsigned char PIN7 : 1;
    };
    // Значение регистра как есть, весь байт
    unsigned char RAW;
} IOREG;

/*
Структура регистров ввода/вывода
ODR     Значение, которое ВЫХОДИТ на порт
IDR     Значение, в котором хранится ВХОДНОЕ значение
DDR     Направление порта, ВЫХОД(1) или ВХОД(0)
CR1     Управляющий, ПОДКЛЮЧАЕТ(1) или ОТКЛЮЧАЕТ(0) подтягивающий резистор
CR2     Управляющий, РАЗРЕШАЕТ(1) или ЗАПРЕЩАЕТ(0) прерывания на порте
*/
typedef struct GPIO {
    // Значение, которое ВЫХОДИТ на выводы порта
	IOREG ODR;
    // Значение, в котором хранится ВХОДНОЕ значение
    IOREG IDR;
    // Направление выводов порта, ВЫХОД(1) или ВХОД(0)
    IOREG DDR;
    // Управляющий, ПОДКЛЮЧАЕТ(1) или ОТКЛЮЧАЕТ(0) подтягивающий резистор
    IOREG CR1;
    // Управляющий, РАЗРЕШАЕТ(1) или ЗАПРЕЩАЕТ(0) прерывания на выводах порта
    IOREG CR2;
} GPIO;

/*
Адреса портов (Memory Map)
*/
#define PA ((GPIO *)0x5000)
#define PB ((GPIO *)0x5005)
#define PC ((GPIO *)0x500A)
#define PD ((GPIO *)0x500F)
#define PE ((GPIO *)0x5014)
#define PF ((GPIO *)0x5019)
#define PG ((GPIO *)0x501E)
#define PH ((GPIO *)0x5023)
#define PI ((GPIO *)0x5028)

/*
Значение по умолчанию (сброс)
*/
#define IONULL ((unsigned char)0x00)

/*
Все выводы сразу
*/
#define IOALL ((unsigned char)0xFF)

/*
Номера выводов
*/
#define IO0 ((unsigned char)0x01)
#define IO1 ((unsigned char)0x02)
#define IO2 ((unsigned char)0x04)
#define IO3 ((unsigned char)0x08)
#define IO4 ((unsigned char)0x10)
#define IO5 ((unsigned char)0x20)
#define IO6 ((unsigned char)0x40)
#define IO7 ((unsigned char)0x80)


