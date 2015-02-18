# Stanford IoT Power Strip

## Overview

This is a Smart Power Strip project for the Stanford IoT group, which aims to create a simple, relatively cheap interface for a power strip that can be home-built and is open source/open hardware.

This repository provides a sample server in Python, an API, and the Arduino
code for the project.

For more information about the Stanford IoT group, please visit the IoT website. Or email me at the email found on my profile.

## Arduino

This folder provides all of the Arduino code for the project. In general, this code should not be modified unless its being tailored to specific applications, or unless a patch is being submitted. This project needs to be compiled with the [PlatformIO](http://platformio.org/) platform.

To do so, go to the PowerStripArduino directory and type

    platformio run -t upload

in order to compile and run the code. Additionally, if this is the first time that PlatformIO is run, then you will need to install Atmel's AVR platform. This can be done by the command

    platformio install atmelavr

Note also that this code will only work with the Arduino Micro as it requires a second, dedicated serial RX/TX, which are found on pins 0 and 1 of the Micro.

## PowerStripTCPAPI 

This subproject contains the API (written in Python) for the PowerStrip project. It also contains a sample server, a sample client, and the whole reference for TCP commands over the net.

## How to Contribute
If you wish to contribute to the project, please feel free to fork the project and then issue a pull request. Of course, you will certainly be added to the list of contributors if your fork is pulled into the main branch.

## Contributors
This project is currently being developed by Guillermo Andres Angeris, Dan Yu, and Christopher Mehdi Elamri of the Stanford IoT team.

