## How to build for Win MFC?
### core.lib gui.lib sample.lib should be in BuildMFC\BuildMFC\libs\x86(x64), rebuild them if meet link error.
- Open "HostMonitor\BuildMFC\HostMonitor.sln" by Visual studio 2017
- Click `F5` to build/run `HostMonitor`

## How to build for Win console mode?
### core.lib gui.lib should be in BuildWin32\sample_native\libs\x86(x64), rebuild them if meet link error.
- Open "HostMonitor\BuildWinCmd\WinCmd.sln" by Visual studio 2017
- Click `F5` to build/run `WinCmd`, you will see UI in internet browser.

## How to build for ARM Linux device?
### libcore.a libgui.a should be in BuildLinux\libs\arm, rebuild them if meet link error.
### Install cross compiler:
For example: arm-linux-gnueabi-gcc

`sudo apt-get install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi`

- `cd HostMonitor`
- `cmake -D CMAKE_C_COMPILER="/usr/bin/arm-linux-gnueabi-gcc" -D CMAKE_CXX_COMPILER="/usr/bin/arm-linux-gnueabi-g++" -D TARGET_ARCH="ARM" .`
- `make`
- `cd BuildLinux`
- `chmod 777 *`
- `./sample_native /dev/fb0`   /dev/fb0: The path of framebuffer device file.

## How to build for x64 Linux or Rasperry Pi?
### libcore.a libgui.a should be in BuildLinux\libs, rebuild them if meet link error.
1. Build target:
- `cd HostMonitor`
- `cmake .`
- `make`
- `cd BuildLinux`
- `chmod 777 *`

2. Run inside QT APP(display-xxx is a QT APP for display, skip this if you haven't installed QT):
- If x64:`./display-x64 | ./sample_native shared-fb`
- If raspberry pi:`./display-arm | ./sample_native shared-fb`
- The source code of display-xxx here: HostMonitor/BuildLinux/display.src

3. Run with internet explore:
- `./sample_native 1 8`
- Command `ss` you will get snapshot in BuildLinux\sample_native\snapshotx.bmp
- Command `sslp` and open "BuildLinux\Display.html" with internet browser(such like: Firefox, Chrome)

## How to build for iOS?
#### libcore.a libgui.a libsample.a should be in \BuildIos\BuildIos\libs, rebuild them if meet link error.
- `cd HostMonitor\BuildIos`
- Open `BuildIos.xcodeproj` with Xcode
- Build and Run

## How to build for Mac?
- `cd HostMonitor`
- `cmake -D TARGET_OS="MAC" .`
- `make`

### Run in command mode
#### libcore.a libgui.a should be in BuildMacCmd\libs, rebuild them if meet link error.
- `cd BuildMacCmd`
- `./sample_native 1 8`
- Command `ss` you will get snapshot in BuildMacCmd\sample_native\snapshotx.bmp
- Command `sslp` and open "BuildMacCmd\Display.html" with internet browser(such like: Safari, chrome)

### Run in UI mode
#### libcore.a libgui.a libsample.a should be in BuildMacCocoa\GuiLiteDemo\libs, rebuild them if meet link error.
- Open `BuildMacCocoa\GuiLiteDemo.xcodeproj` with Xcode
- Build and Run

## How to build/run for Android?
### Install software:
- `sudo apt-get install gcc-arm-linux-androideabi`
- Install Android NDK.

- `cd HostMonitor`
- `cmake -D CMAKE_C_COMPILER="/usr/bin/arm-linux-androideabi-gcc" -D CMAKE_CXX_COMPILER="/usr/bin/arm-linux-androideabi-g++" .`
- `make`
- `cp SampleCode/libsample.a  BuildAndroid/jni/libs`
- `cd BuildAndroid/jni/libs`
- `./merge-libs.sh`

### Use NDK command, for example: Windows command
- `cd BuildAndroid\jni`
- `ndk-build clean`
- `ndk-build`
- `copy ..\libs\armeabi-v7a\libnative.so ..\app\libs\armeabi-v7a\
- Open "BuildAndroid" with Android studio
- Click `build/debug/run`

Note:
Run `./merge_libs.sh` meet error, maybe you need run `dos2unix merge_libs.sh`

## How to build for Windows UWP?
depdency: Windows 10, visul stdio 2015/2017

- Open "SampleCode\sample.sln" by Visual studio 2017
- Click `build` 
- `copy SampleCode\debug\sample.lib BuildUWP\sample_uwp_cpp\libs\x86(x64)\`
- Open "BuildUWP\HostMonitor.sln" by Visual studio 2017
- Click `build`
- Click `debug/run`

## How to run on VR/MR?
- If VR: run `Mixed Reality Portal`on PC side.
- Take VR/MR device on head, or run simulator.
- press `start`, find the UWP you build and run.

Note: Windows RS3(Build 16299) will be necessary.
