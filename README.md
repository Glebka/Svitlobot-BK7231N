# Svitlobot for BK7231N (work in progress)

This is an attempt to make a custom firmware for smart socket running BK7231N WiFi MCU in order to make it work as a mains voltage sensor compatible with Svitlobot.

When the mains is on, the firmware sends pings to the api.svitlobot.in.ua every minute.

But when the mains goes off, after 5 minutes of inactivity the Svitlobot BE changes the sensor status and send appropriate message to the Telegram.

## TODO
* Fix linker issue related to ``strptime()``
