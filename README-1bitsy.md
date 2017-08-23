# 1Bitsy Arduino

This Arduino core is completely based on the [stm32duino](https://github.com/stm32duino) project!

# Installation

As the 1bitsy arduino port is very early alpha there is no board manager file set up for the project yet. It should not be considered feature full or finished. Please send in all the pull requests with bug fixes and examples that you can provide. :)

To install 1bitsy dev board support first install the stm32duino as it pulls in all the needed dependencies. You can find the needed steps in the [stm32duino wiki](https://github.com/stm32duino/wiki/wiki/Boards-Manager).

Now enter into your Arduino sketch directory, and create a `hardware/1bitsquared` subdirectory.

You can find the Arduino sketch directory in the Documents folder on Windows and MacOS.

In that newly created directory you have to clone this repository into the `stm32` subdirectory and change the branch to 1bitsy.

```
cd hardware/1bitsquared
git clone https://github.com/esden/stm32duino-Arduino_Core_STM32.git stm32
cd stm32
git checkout 1bitsy
```

You will also have to clone the modified Arduino tools in a similar way next to the stm32 directory.

```
cd ..
git clone https://github.com/esden/stm32duino-Arduino_Tools.git tools
cd tools
git checkout 1bitsy
```

Now when you start the Arduino IDE you should see an additional 1bitsy board entry.

Before you send in issues make sure that you read the above at least 10 times and made sure you read it correctly and you did not make a typo. Then send in pull requests if anything above was not clear. We will make screenshots at some point in the future when all this is more stable...

Good luck! :D
