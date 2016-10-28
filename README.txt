--------------------------------------------
Windows
--------------------------------------------

SFML comes pakaged with all its dependecies, download binaries is fine


--------------------------------------------
Linux
--------------------------------------------

Dependencies :
pthread
opengl
xlib
xrandr
freetype
glew
jpeg
sndfile
openal
cmake
g++

Under Debian/Raspian/Ubuntu :
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install libpthread-stubs0-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libx11-dev 
sudo apt-get install libxrandr-dev
sudo apt-get install libfreetype6-dev
sudo apt-get install libglew1.5-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libgpgme11-dev
sudo apt-get install libsndfile1-dev
sudo apt-get install libopenal-dev


Compile SFML 2.1 From sources : 
http://sfml-dev.org/download/sfml/2.1/index-fr.php

Run cmake -i and fill all the options
Then make and make install

Under Raspian, you'll probably need to specify the lib path, add /usr/local/lib to the path linker will use
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/usrlocal'
sudo ldconfig