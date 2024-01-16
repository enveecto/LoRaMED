###################################################################################################################################################################
# LoRaMED
LoRa Based Patient Monitoring System
####################################################################################################################################################################

LoRaMED is a LoRaWAN Based Patient Monitoring System which uses ESP32 as Main Microcontrollers and has following architecture:

Sensor Node:
 We use the MAX30102 sensor which is capable of accurately measuring body vitals that we focus on, heart rate, oxygen levels and temperature simultaneously. The MAX30102 is a sensor module that integrates a red and infrared (IR) LED, a photodetector, and other components to facilitate the measurement of the same vitals. 

The MAX30102 sensor works by emitting red and infrared light into the skin using built-in LEDs. A photodetector then measures the amount of light that passes through or reflects back from the tissue. The analog signals from the photodetector are processed to extract the pulsatile component caused by heartbeats. Heart rate is calculated by identifying peaks in this pulsatile component, and blood oxygen saturation (SpO2) is determined by comparing the absorbance of red and infrared light. The sensor outputs the calculated heart rate and SpO2 levels through its interface (I2C or SPI). Integrated into wearable devices and medical instruments, the MAX30102 provides real-time, non-invasive monitoring of vital signs.


Microcontroller:
 ESP32 Microcontroller, The ESP32 serves as the main controller, responsible for data acquisition from the MAX30100 sensor, processing, and communication with the LoRaWAN network.

The ESP32 is a popular wireless system-on-chip (SoC) developed by Espressif Systems. Here's a summary of its key specifications:

Microcontroller:
Dual-core Tensilica Xtensa LX6 microprocessors
Clock frequency: Up to 240 MHz
Wireless Connectivity:

Wi-Fi:
IEEE 802.11 b/g/n (2.4 GHz)
IEEE 802.11 a/n/ac (5 GHz, HT40 support)
Bluetooth:
Bluetooth Low Energy (BLE) support
Bluetooth Classic
Memory:

Internal RAM: Up to 520 KB
External SPI RAM support
Flash memory: Up to 16 MB

Peripherals:
GPIO (General Purpose Input/Output) pins
I2C, SPI, UART, I2S, PWM
ADC (Analog-to-Digital Converter)
DAC (Digital-to-Analog Converter)

Operating Voltage:
2.2V to 3.6V

LoRaWAN Transceiver:
  The ESP32 communicates with the LoRaWAN network using a LoRaWAN transceiver module. It sends the processed health data to the LoRaWAN gateway. 

	The RA-02 LoRa (Long Range) module is a wireless communication module designed for low-power, long-range communication in various applications. Here's a brief overview:

Communication Technology:
LoRa (Long Range) modulation technology, known for its long communication range and low power consumption.

Frequency Bands:
Supports different frequency bands (e.g., 433MHz, 868MHz, 915MHz), depending on the specific variant.

Transceiver Chip:
Typically based on the SX1278 transceiver chip from Semtech, which is a popular choice for LoRa communication.


Communication Interface:
Commonly uses a serial communication interface (UART) for easy integration with microcontrollers and other devices.

Operating Voltage:
Operates at low voltage levels, often around 3.3V.

Transmission Range:
Provides long-range communication capabilities, reaching several kilometers in open spaces, depending on the frequency, environment, and other factors.

Power Consumption:
Designed for low power consumption, making it suitable for battery-powered applications and IoT devices.

Interface:
The prototype uses ESP32-Access Point Web Server to display the vitals which are received by the LoRaWAN module. An ESP32 Access Point (AP) Web Server is a common use case where an ESP32 module creates its own Wi-Fi network (Access Point) and hosts a web server, allowing users to connect to it and interact with a web interface. This setup is often used in IoT projects for configuration, monitoring, or control purposes. Here's a brief overview of how it works:

ESP32 Configuration:
The ESP32 is programmed to act as an Access Point by configuring its Wi-Fi settings accordingly.
It sets up an SSID (Wi-Fi network name) and a password for the Access Point.



Web Server Setup:
The ESP32 creates an HTTP web server using the appropriate libraries (e.g., Arduino core for ESP32).
It defines routes and handles HTTP requests. Each route corresponds to a different endpoint on the server.

HTML/CSS/JavaScript Files:
The web server serves HTML, CSS, and JavaScript files to the connected clients.
These files define the structure, style, and behavior of the web interface.

Handling Requests:
When a client (e.g., a web browser on a smartphone or computer) connects to the ESP32's Wi-Fi network, it can send HTTP requests to the ESP32's IP address.
The ESP32's web server processes these requests and sends back appropriate responses.

Interacting with ESP32:
Users can interact with the ESP32 by accessing the web interface through a web browser.
For example, they can submit forms, toggle buttons, or send commands via the web interface.

####################################################################################################################################################################
