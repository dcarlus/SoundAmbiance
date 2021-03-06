# Sound Ambience
Sound Ambience is a software that generates a sound atmosphere all around you. You put the sound files you want into the software and that's it!

![Sound Ambience v0.1a](https://raw.githubusercontent.com/dcarlus/SoundAmbience/master/resources/screenshots/SoundAmbiance_0.1a.png)

## Demos
- https://youtu.be/xl3wGDBEMk8
- https://youtu.be/k9xslkX4UZU
- https://youtu.be/HSMKXNJMlnw

## How does it work?
You select a sound that will be the base of your ambience. This sound is ideally long enough because it will loop other again and again until you stop the ambiance generation.
Then you select a list of small sounds that are randomly played in a 3D space, around you. You can get it if you have a 5.1 or 7.1 sound system for example, but Sound Ambience will work with headphones and stereo speakers as well.

Notice that the additional sounds should be in mono format. Otherwise, you could not experiment surrounding sounds! :wink:

## Issues
### The sounds are cracking when played by Sound Ambience (but not with another sound player).
It occurs when sounds are saturated. You should limit your sound of a couple of dB, for example using Audacity.

## How to build it?
**Requirements:**
- Qt5.10 https://www.qt.io/
- OpenAL 1.1 https://www.openal.org/
- libsndfile http://www.mega-nerd.com/libsndfile/
- flatbuffers https://google.github.io/flatbuffers/

### GNU/Linux
Install (or build) these dependencies on your system. Notice that they all are available as official packages on _ArchLinux_ :kiss:.

Then open the SoundAmbience.pro file with QtCreator and build the software from QtCreator. You should be able to get an executable binary. Just hope that all the planets are aligned... :smirk:

#### Building on Ubuntu

1. Install packaged dependencies:
```
sudo apt install libopenal-dev libsndfile1-dev
```

2. Download and install Qt 5.10 or later (**not needed for Ubuntu 18.10 and later**) from [Qt website](https://www.qt.io/download).

3. Build not-yet-packaged dependencies (flatbuffers):
```
git clone https://github.com/google/flatbuffers
cd flatbuffers
git checkout 20a400e940634108bad812f571582eeffc728eac
mkdir build
cd build
cmake ..
make
sudo make install
cd ../..
```

4. Build program executable (replace **5.11.1** by the Qt version you installed):
```
/opt/Qt/5.11.1/gcc_64/bin/qmake .
make
```

### Windows
To build on Windows, download [**win64_dependencies.zip**](https://github.com/dcarlus/SoundAmbience/releases/download/1.1b/win64_dependencies.zip) and put the _lib_ directory in the source code folder (next to the SoundAmbience.pro file). Then open QtCreator and build. You may have to add a `make install` instruction in your build steps to get a nice binary package with all required DLLs.

### MacOS
I do not have any MacOS computer. So, if you really want to build it on MacOS, you can fork this project and make it build on MacOS (or pay me a MacBook? :worried:).

## What's next?
In version 2.0, Sound Ambience will allow you to add parameters on sounds: frequency, pitch range, distance, etc. You will be able to finely control your ambience generation while you will add more randomness to it!

**Stay tuned!** :wink:
