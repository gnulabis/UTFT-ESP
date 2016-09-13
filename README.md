# UTFT-ESP8266

## Project Summary
This project brings support for the [ESP8266](https://en.wikipedia.org/wiki/ESP8266) microcontroller to the popular [UTFT library](http://www.rinkydinkelectronics.com/library.php?id=51). For now, only displays with serial interfaces are supported (no 8-bit parallel mode, etc).

To use it, simply copy the UTFT folder to your [Arduino library folder](https://www.arduino.cc/en/Guide/Libraries).

In addition to the original [bit-banging](https://en.wikipedia.org/wiki/Bit_banging) communication method of the UTFT library, this project also introduces support for true hardware SPI communication (only supported on ESP8266 for now, sorry for that) for serial interface displays. A new UTFT constructor has been added for this purpose:

`UTFT(byte model, int CS, int RST, int SER=0);`

When the above constructor is invoked, the library will automatically use the hardware SPI pins for SCK and MOSI (GPIO14 and GPIO13 respectively on the ESP8266).

You might want to have a look at the included Arduino IDE examples for ideas on how to establish the communication between the ESP8266 and your TFT display.

This work has been tested with an ESP-12 module, several ILI9341-based and ST7735-based serial displays, Arduino IDE 1.6.5, 1.6.6 and 1.6.11, using stable versions 2.0.0 and 2.3.0 of the excellent [esp8266 platform package for Arduino](https://github.com/esp8266/Arduino).

*Please keep in mind that this is still work in progress. Use it at your own risk.*

For bug fixes and code improvements, please submit a pull request.

## License and Credits
This project is based on the original [UTFT library](http://www.rinkydinkelectronics.com/library.php?id=51) developed and maintained by Henning Karlsen, and licensed under [CC BY-NC-SA 3.0](http://creativecommons.org/licenses/by-nc-sa/3.0/).

As a derivative work of the original UTFT library, this project is licensed under:

[![license](graphics/by-nc-sa.eu.png)](http://creativecommons.org/licenses/by-nc-sa/4.0/)

[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/)

#### Personal view on the non-commercial clause of the license
I personally disagree with the non-commercial clause of the license, I'd much prefer a license which does not restrict commercial reuse, but I'm legally bound by the original author's choice of license.

Interesting articles on this topic:

 * [Understanding Free Cultural Works](http://creativecommons.org/freeworks)
 * [The case for Free use: reasons not to use a Creative Commons -NC license](http://freedomdefined.org/Licenses/NC)

#### Required procedure for commercial re-use of this project
If you plan to use this project for commercial purpose, you need to obtain an approval from both myself and Henning Karlsen. Please contact me via email (or just leave a comment to one of my commits) and I will gladly approve your project free of charge, but keep in mind that since this is a derivative work, you also need to [contact Hennning Karlsen](http://www.rinkydinkelectronics.com/contact.php) and get a commercial license for the original UTFT library as well.

## Donations
I do not currently accept any donations, but if you find this project useful, you should consider donating to Hennning Karlsen for his great effort in providing and maintaining the original UTFT library.
