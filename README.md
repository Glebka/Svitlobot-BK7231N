# Svitlobot for BK7231N (work in progress)

This is an attempt to make a custom firmware for a smart socket running BK7231N WiFi MCU in order to make it work as a mains voltage sensor compatible with Svitlobot.

When the mains is on, the firmware sends pings to the api.svitlobot.in.ua every minute.
But when the mains goes off, device doesn't send pings, thus Svitlobot detects "mains off" state and sends a message to the Telegram channel. 

## Build instructions

1. Install VSCode IDE
1. Install PlatformIO extension
1. Clone this repository and open it in VSCode, PlatformIO will automatically detect and configure the project for you.
1. From now you are able to build firmware and flash the device

## TODO
* Test on the real device with BK7231N inside
