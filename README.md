# Speaker Snitch

How can you *really* know when your smart speaker is listening and sending data to the cloud?  There have been documented cases in which up to a minute of speech has been transferred to the cloud without a wake-word having been spoken.

Speaker Snitch can give an absolute answer to this question by sniffing local network traffic and flashing a light sitting next to the speaker any time there is traffic between the speaker and the vendor's cloud service.

![Snitch](https://raw.githubusercontent.com/nickbild/speaker_snitch/main/media/snitch_near_google_home.png)

## How It Works

A Raspberry Pi computer promiscuously sniffs packets on the local network.  A Python script parses these packets, looking for any communication between the smart speaker and the vendor's cloud service.  When detected, an API endpoint on an Arduino Nano 33 IoT microcontroller development board is accessed.  This causes an LED attached to the Arduino to flash, thus alerting you to a speaker sending data to the vendor.

A single Raspberry Pi can trigger alerts on a number of Speaker Snitch devices all throughout your home.

<p align="center">
<img src="https://raw.githubusercontent.com/nickbild/speaker_snitch/main/media/speaker_snitch_setup.jpg">
</p>

## Media

Speaker Snitch, top:
![Snitch](https://raw.githubusercontent.com/nickbild/speaker_snitch/main/media/snitch_top_sm.jpg)

Speaker Snitch, angle:
![Snitch Angle](https://raw.githubusercontent.com/nickbild/speaker_snitch/main/media/snitch_angle_sm.jpg)

Raspberry Pi 3 B+:
![Pi](https://raw.githubusercontent.com/nickbild/speaker_snitch/main/media/raspberry_pi_3_sm.jpg)

## Bill of Materials

- 1 x Raspberry Pi 3 B+ (or similar)
- 1 x Arduino Nano 33 IoT
- 1 x NeoPixel RGB LED
- 1 x Battery pack (for Arduino)
- Miscellaneous wires

## About the Author

[Nick A. Bild, MS](https://nickbild79.firebaseapp.com/#!/)
