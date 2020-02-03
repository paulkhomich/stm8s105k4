// HSI (16MHz) и LSI (128KHz) + HSE (1-24MHz) 

// Сигнал от любого генератор может быть выдан на ножку CCO

// Генератор частоты (HSI) -> (HSIDIV) -> HSI промежуточная/LSI/HSE (*)
//         (*) HSI промежуточная/LSI/HSE -> (CPUDIV) -> Частота для CPU 
//         (*) HSI промежуточная/LSI/HSE -> на периферию (Таймеры, I2C, SPI, UART...)

// =================================================================================================
//                                              CLK_ICKR
// =================================================================================================

// Побитовая структура Регистра управления HSI и LSI
typedef union DATA_CLK_ICKR {
    struct {
        // Включение HSI (def = 1)
        unsigned char HSIEN : 1;
        // Готов ли HSI к работе (готов = 1)
        unsigned char HSIDRY : 1;
        // Разрешение быстрого выхода из спящего режима
        unsigned char FHW : 1;
        // Включение LSI
        unsigned char LSIEN : 1;
        // Готов ли LSI к работе (готов = 1)
        unsigned char LSIRDY : 1;
        // Регулятор POWER OFF
        unsigned char REGAH : 1;
        unsigned char : 2;
    };
    // Значение регистра как есть, чистый байт
    unsigned char RAW;
} DATA_CLK_ICKR;
// Регистр управления внутренними источниками тактирования (Настройки генераторов HSI и LSI)
#define CLK_ICKR ((DATA_CLK_ICKR *)0x50C0)

// =================================================================================================
//                                              CLK_ECKR
// =================================================================================================

// Побитовая структура Регистра управления HSE
typedef union DATA_CLK_ECKR {
    struct {
        // Включение HSE
        unsigned char HSEEN : 1;
        // Готов ли HSE к работе
        unsigned char HSERDY : 1;
        unsigned char : 6;
    };
    // Значение регистра как есть, чистый байт
    unsigned char RAW;
} DATA_CLK_ECKR;
// Регистр управления HSE
#define CLK_ECKR ((DATA_CLK_ECKR *)0x50C1)

// =================================================================================================
//                                              CLK_SWR
// =================================================================================================

// Регистр выбора источника тактирования (HSI, LSI, HSE)
#define CLK_SWR *((unsigned char *)0x50C4)
/*
Значения регистра CLK_SWR для выбора источника тактирования
*/
#define CLK_SWR_HSI ((unsigned char)0xE1)
#define CLK_SWR_LSI ((unsigned char)0xD2)
#define CLK_SWR_HSE ((unsigned char)0xB4)

// =================================================================================================
//                                              CLK_SWCR
// =================================================================================================

// Побитовая структура Регистра управления переключением тактовой частоты
typedef union DATA_CLK_SWCR {
    struct {
        // Идет процесс переключения источника тактирования (процесс идет = 1)
        unsigned char SWBSY : 1;
        // Разрешение на переключение источника тактовой частоты
        unsigned char SWEN : 1;
        // Разрешает прерывание по переключению источника тактирования
        unsigned char SWIEN : 1;
        // Устанавливается после переключения (Переключение произошло = 1)
        unsigned char SWIF : 1;
        unsigned char : 4;
    };
    // Значение регистра как есть, чистый байт
    unsigned char RAW;
} DATA_CLK_SWCR;
// Регистр управления переключением тактовой частоты
#define CLK_SWCR ((DATA_CLK_SWCR *)0x50C5)

// =================================================================================================
//                                            CLK_CKDIVR
// =================================================================================================

// Побитовая структура Регистра делителя частоты
typedef union DATA_CLK_CKDIVR {
    struct {
        // Делитель частоты для CPU от основной
        unsigned char CPUDIV : 3;
        // Делитель HSI частоты
        unsigned char HSIDIV : 2;
        unsigned char : 3;
    };
    // Значение регистра как есть, чистый байт
    unsigned char RAW;
} DATA_CLK_CKDIVR;
// Регистр делителя частоты (HSI + CPU)
#define CLK_CKDIVR ((DATA_CLK_CKDIVR *)0x50C6)
/*
Значения регистра CLK_CKDIVR для получения нужного такта от HSI (HSIDIV)
*/
#define HSI_DIV1 ((unsigned char)0x0)
#define HSI_DIV2 ((unsigned char)0x1)
#define HSI_DIV4 ((unsigned char)0x2)
#define HSI_DIV8 ((unsigned char)0x3)
/*
Значения регистра CLK_CKDIVR для получения нужного такта для CPU (CPUDIV)
*/
#define CPU_DIV1 ((unsigned char)0x0)
#define CPU_DIV2 ((unsigned char)0x1)
#define CPU_DIV4 ((unsigned char)0x2)
#define CPU_DIV8 ((unsigned char)0x3)
#define CPU_DIV16 ((unsigned char)0x4)
#define CPU_DIV32 ((unsigned char)0x5)
#define CPU_DIV64 ((unsigned char)0x6)
#define CPU_DIV128 ((unsigned char)0x7)

// =================================================================================================
//                                              CLK_CSSR
// =================================================================================================

typedef union DATA_CLK_CSSR {
    struct {
        // Включает Систему безопасности тактирования
        unsigned char CSSEN : 1;
        // Включен ли вспомогательный генератор (HSI/8) 
        unsigned char AUX : 1;
        // Разрешает прерывание по срабатыванию Системы безопасности
        unsigned char CSSDIE : 1;
        // Выставляется в 1 при срабатывании Системы безопасности
        unsigned char CSSD : 1;
        unsigned char : 4;
    };
    // Значение регистра как есть, чистый байт
    unsigned char RAW;
} DATA_CLK_CSSR;
// Регистр управления системой безопасности тактирования
#define CLK_CSSR ((DATA_CLK_CSSR *)0x50C8)