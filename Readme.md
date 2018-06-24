<p align="center">
<img src="blinkit.png" />
</p>

<p align="center">
Blinkit Arduino integration <br />Receive notifications on Arduino boards.
</p>

<br />


<p align="center">
  <a href="https://github.com/techtek/Blinkit/archive/master.zip">
    <img src="https://img.shields.io/badge/Download-23%2C4%20Mb-blue.svg" />
  </a>
  <a href="https://github.com/techtek/Blinkit/blob/master/LICENSE">
    <img src="https://img.shields.io/github/license/techtek/Blinkit.svg" />
  </a>
  <a href="https://steemit.com/@electronicsworld">
    <img src="https://img.shields.io/badge/Steemit-%40electronicsworld-blue.svg" />
  </a>
  <a href="https://twitter.com/intent/tweet?url=https://github.com/techtek/Blinkit&text=Download%20%23Blinkit%20interface%20and%20receive%20live%20notifications%20on%20Steem%20related%20actions%20">
    <img src="https://img.shields.io/twitter/url/https/github.com/techtek/Blinkit.svg?style=social" />
  </a>
</p>

<br />


### Blinkit

Blinkit is a Steem notification software for Windows, that notifies you in real time with sound and light about Steem account activity. Blinkit can blink the lights of the following products:

#### Supported devices:
* USB Sticks (status light)
* Philips HUE lamps
* Sonoff devices
* [Arduino Boards](https://steemit.com/@electronicsworld) or compatible (Genuino, etc...)
* Camera status LED blink
* Take photos on upvote/post/follow
* Logitech RGB/Backlight Keyboards 



### Installation instructions for Windows

Download the content of the [Blinkit folder](https://github.com/techtek/Blinkit)
Extract the Blinkit folder
Open the Blinkit folder, and start Blinkit.exe

### Arduino 

In order to be able to use a Arduino with Blinkit, the custom made sketch needs to be downloaded through this repo and needs to be uploaded to your Arduino board with the [Arduino IDE](https://www.arduino.cc/en/main/software). 
The wiring diagram to follow is located in the root folder.

#### How to upload the sketch to your board using Arduino IDE:

#### Add a Library to your list of supported libraries:

Download the 2 library folders through the repo and copy paste them in the path C:\Users\User\Documents\Arduino\libraries

- After having installed Arduino IDE and restarted your PC/Laptop connect to it your Arduino board with its data/power USB cable
- If you have an Arduino Clone board (chinese boards) with integrated chip marked CH340 you can follow my tutorial on how to install its driver [here](https://steemit.com/blinkit/@electronicsworld/blinkit-or-electronicsworld-tutorial-2-how-to-set-up-arduino-for-blinkit-interaction)
- If you have an Original Arduino board or a Genuino board the above step is not required
- Once your PC/laptop recognize the board you can double click the ArduinoBlinkitSketch.ino file which by default will be opened with Arduino IDE
- Check on the bottom right section if you can see your device name and if the COM port selected is the one where your Arduino board is connected to (you can refer to the tutorial mentioned above to double check the COM port to which it is connected)
- If the COM port is not the right one then go to Tools -> Port -> and select the right COM port
- You can now click the UPLOAD button which you can find directly below Edit in the Button Bar.
- Wait for the upload to finish (it will be notified in the bottom loading bar)

Now your board has the sketch uploaded to it and you can now start to use it with Blinkit.


Arduino sketch has been developed by @electronicsworld https://steemit.com/@electronicsworld
Blinkit is made by @techtek https://steemit.com/@techtek


### Adafruit_GFX license:

Software License Agreement (BSD License)

Copyright (c) 2012 Adafruit Industries.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

### Adafruit_SSD1306

Software License Agreement (BSD License)

Copyright (c) 2012, Adafruit Industries
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holders nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Wire Library [License](https://creativecommons.org/licenses/by-sa/3.0/#)

