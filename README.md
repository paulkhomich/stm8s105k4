# Регистровая библиотека для работы с stm8s105k4

Библиотека неполная, дополняется по мере изучения

Подробные комментарии помогают изучить назначение тех или иных регистров и успешно использовать их при написании своих программ без использования _высокоабстрактных_ библиотек для работы с stm8

В качестве редактора используется **VS Code**


Используется **SDCC** для компиляции .c в .ihx:

```sdcc -mstm8 ****.c```

И **stm8flash** для прошивки через ST-Link v2:

```stm8flash -c stlinkv2 -p stm8s105k4 -w ****.ihx```