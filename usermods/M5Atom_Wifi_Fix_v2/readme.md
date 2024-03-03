# M5Atom Wifi Fix V2

This usermod raises GPIO0 to HIGH to fix the M5Atom's Wifi issue.
See: [M5Unified/src/M5Unified.cpp at d26d2415f409b664631ff066ceeaffd6a753a4ff · m5stack/M5Unified · GitHub](https://github.com/m5stack/M5Unified/blob/d26d2415f409b664631ff066ceeaffd6a753a4ff/src/M5Unified.cpp#L506) for more information.

I am not 100% sure if this is needed on the most recent M5Atom devices, but it doesn't hurt to have it in the code. I am also not 100% sure that the pin should be pulled high. Some sources say it should be pulled low. I am not sure what the correct answer is, but until I have time to measure the voltage on the pin, I will defer to the M5Stack library solution.

## More info

[M5Stack Atom Lite: Long response times and wifi connection losses | M5Stack Community](https://forum.m5stack.com/topic/4527/m5stack-atom-lite-long-response-times-and-wifi-connection-losses)
[Bugs and measures for M5Stack ATOM | macsbug](https://macsbug.wordpress.com/2021/10/10/bugs-and-measures-for-m5stack-atom/)
[ESP32と5V IOのUSB UARTデバイスによるWifi問題まとめ（FW更新方法） | docs](https://sohtamei.github.io/docs/esp32AndUsbUartWith5V_IO_Issue2.html)

## Installation

Then to activate this usermod add `#define USERMOD_M5ATOM_WIFI_FIX` to the `usermods_list.cpp` file,
or add `-D USERMOD_M5ATOM_WIFI_FIX` to your `platformio.ini` (or `platformio_override.ini`).