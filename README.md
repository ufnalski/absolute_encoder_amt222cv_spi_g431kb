# Absolute multi-turn encoder with SPI interface  (STM32G431KB)
An STM32 HAL example of communicating with an absolute encoder over the SPI interface. A multi-turn 12-bit encoder from Same Sky (formerly CUI Devices) is taken as an example. The relevant evaluation kit is AMT222C-V.

![Multi-turn absolute encoder in action](/Assets/Images/cui_devices_multi_turn_spi_in_action.jpg)

# Missing files?
Don't worry :slightly_smiling_face: Just hit Alt-K to generate /Drivers/CMCIS/ and /Drivers/STM32G4xx_HAL_Driver/ based on the .ioc file. After a couple of seconds your project will be ready for building.

# Libraries
* OLED: [stm32-ssd1306](https://github.com/afiskon/stm32-ssd1306) (MIT license)

# Hardware
* [Bidirectional 4-channel logic level shifter](https://sklep.msalamon.pl/produkt/konwerter-poziomow-logicznych-33v-5v-4-kanalowy/)
* [OLED display 1.3" (SH1106 or SSD1306)](https://sklep.msalamon.pl/produkt/wyswietlacz-oled-13-i2c-bialy/)
* [AMT Cable AMT-06C-1-036](https://www.mouser.pl/ProductDetail/CUI-Devices/AMT-06C-1-036?qs=fAHHVMwC%252BbhzTLN9MYRSPg%3D%3D)

# Serial peripheral interface (SPI)
* [SPI modes](https://www.analog.com/en/resources/analog-dialogue/articles/introduction-to-spi-interface.html) (Analog Devices)
* [SPI Bus](https://www.mikroe.com/blog/spi-bus) (MIKROE)

![SPI mode 0](/Assets/Images/spi_mode_0.JPG)

# Call for action
Create your own [home laboratory/workshop/garage](http://ufnalski.edu.pl/control_engineering_for_hobbyists/2024_dzien_otwarty_we/Dzien_Otwarty_WE_2024_Control_Engineering_for_Hobbyists.pdf)! Get inspired by [ControllersTech](https://www.youtube.com/@ControllersTech), [DroneBot Workshop](https://www.youtube.com/@Dronebotworkshop), [Andreas Spiess](https://www.youtube.com/@AndreasSpiess), [GreatScott!](https://www.youtube.com/@greatscottlab), [ElectroBOOM](https://www.youtube.com/@ElectroBOOM), [Phil's Lab](https://www.youtube.com/@PhilsLab), [atomic14](https://www.youtube.com/@atomic14), [That Project](https://www.youtube.com/@ThatProject), [Paul McWhorter](https://www.youtube.com/@paulmcwhorter), and many other professional hobbyists sharing their awesome projects and tutorials! Shout-out/kudos to all of them!

> [!WARNING]
> Control in power electronics and drives - do try this at home :exclamation:

190+ challenges to start from: [Control Engineering for Hobbyists at the Warsaw University of Technology](http://ufnalski.edu.pl/control_engineering_for_hobbyists/Control_Engineering_for_Hobbyists_list_of_challenges.pdf).

Stay tuned!
