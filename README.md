# Moja Droga do Kernela 🛠️

Tu wrzucam wszystko, co kminię, żeby w końcu pisać własne drivery i nie łapać BSOD-a co pięć minut. 

### Co tu już siedzi:
* **malloc_float_test.c** – Moje pierwsze starcie z pamięcią RAM. Rezerwowanie miejsca (`malloc`), żeby nic nie wybuchło, i sprzątanie po sobie (`free`).
* **polymorphism_generic.c** – Wyższa szkoła jazdy. Zrobiłem "szablon" sterownika. Używam wskaźników na funkcje (callbacki) i `void*`, żeby kod był uniwersalny. 

### Plan na przyszłość:
1. Rozwalić system bitami (operacje bitowe).
2. Nie spalić procesora.
3. Wbić do Windows Driver Kit (WDK) i napisać coś, co faktycznie gada ze sprzętem.

**Błędy to tylko logi do poprawy.** 🚀
