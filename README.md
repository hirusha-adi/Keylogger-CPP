# Keylogger

a lightweight keylogger made with C++

## [`Virus Total Score 8/69`](https://www.virustotal.com/gui/file/b80be8ceb8f055539aa0893919d094d4ce5f0404d17de424bd86b0222435d05e/detection)

## Information

- the source can be found in [`./src`](https://github.com/hirusha-adi/Keylogger-CPP/tree/main/Keylogger) directory (both the `main.cpp` and the codeblocks project file). The code does not depend on any other external libraries. Its completely built with built in libraries.

- undetected by most Anviruses. [Click here](https://www.virustotal.com/gui/file/b80be8ceb8f055539aa0893919d094d4ce5f0404d17de424bd86b0222435d05e/detection) for VirusTotal results

## Features

- logs to file
- auto start on startup

## Customizing Guide

for `main.cpp`

### Line `17`

- Log File Name (defaults to `WindowsData.txt`)

### Line `18`

- Invisible Mode (hide console window) (defaults to `true`)

### Line `19`

- Auto start on startup (defaults to `true`)

### Line `486`

- Console Text (shows up only if Invisible Mode is set to False) 