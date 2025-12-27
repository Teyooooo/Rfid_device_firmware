# RFID Device Firmware
  NodeMCU-based RFID Reader

## Prerequisite

### Software
- PlatformIO in VSCode

### Hardware / Modules

![RC522 RFID Reader Module](https://lastminuteengineers.com/wp-content/uploads/arduino/RC522-RFID-Reader-Writer-Module-Pinout.png)

- RC522 RFID Reader Module

![NodeMCU](https://components101.com/sites/default/files/component_pin/NodeMCU-ESP8266-Pinout.jpg)

- NodeMCU


## Installation

- Clone this repo
  ```
    git clone https://github.com/Teyooooo/Rfid_device_firmware.git
  ```
- Connect two component using this pinout configuration
  | RC522 RFID Reader | NodeMCU       |
  | ----------------- | ------------- |
  | SDA               | D4            |
  | SCK               | D5            |
  | MOSI              | D7            |
  | MISO              | D6            |
  | IRQ               | Not Connected |
  | GND               | GND           |
  | RST               | D3            |
  | VCC               | 3.3V          |

- Connect NodeMCU in the PC
- Then Flash it with the Firmware

## Testing

- Open the Serial Monitor
- Scan a RFID Card
- Then it will Print its UID

## Images
![rfid](https://github.com/Teyooooo/Rfid_device_firmware/blob/main/docs/rfid.jpg)
![rfid](https://github.com/Teyooooo/Rfid_device_firmware/blob/main/docs/rfid_2.jpg)
