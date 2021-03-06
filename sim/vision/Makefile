#
#   Makefile for V-REP simulator using Hackflight
#
#   Copyright (C) Simon D. Levy and Matt Lubas 2016
#
#   This file is part of Hackflight.
#
#   Hackflight is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   Hackflight is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#   You should have received a copy of the GNU General Public License
#   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
#
 
# Edit this for where you installed V-REP
VREP_DIR = $(HOME)/Software/V-REP_PRO_EDU_V3_3_2_64_Linux

COMMON = $(VREP_DIR)/programming/common/
CFLAGS = -Wall -D_SIM -I$(VREP_DIR)/programming/include/ -I. -I.. -I../../common -I../../firmware -Wall -fPIC -static

# Un-comment if you want to build for the companion board:
# Linux only, requires OpenCV
CFLAGS += -D_COMPANION

PLUGIN = libv_repExtHackflight.so

all: $(PLUGIN) 

libv_repExtHackflight.so: *.cpp ../*.cpp *.hpp ../*.hpp ../../firmware/*.cpp ../../firmware/*.hpp Makefile
	g++ $(CFLAGS) -c  ../v_repExtHackflight.cpp 
	g++ $(CFLAGS) -c -DVREP_DIR=\"$(VREP_DIR)\" extras.cpp 
	g++ $(CFLAGS) -c ../controller_Posix.cpp 
	g++ $(CFLAGS) -c ../controller_Linux.cpp 
	g++ $(CFLAGS) -c ../../common/sockets.cpp 
	g++ $(CFLAGS) -c $(COMMON)/scriptFunctionData.cpp 
	g++ $(CFLAGS) -c $(COMMON)/scriptFunctionDataItem.cpp
	g++ $(CFLAGS) -c $(COMMON)/v_repLib.cpp
	g++ $(CFLAGS) -c ../../firmware/imu.cpp
	g++ $(CFLAGS) -c ../../firmware/mixer.cpp
	g++ $(CFLAGS) -c ../../firmware/msp.cpp
	g++ $(CFLAGS) -c ../../firmware/mw.cpp
	g++ $(CFLAGS) -c ../../firmware/stabilize.cpp
	g++ $(CFLAGS) -c ../../firmware/rc.cpp
	g++ $(CFLAGS) -c ../../firmware/baro.cpp
	g++ $(CFLAGS) -c ../../firmware/sonars.cpp
	g++ $(CFLAGS) -c ../../firmware/hover.cpp
	g++ $(CFLAGS) -c ../../firmware/filters.cpp
	g++ *.o -o libv_repExtHackflight.so -lpthread -shared -lopencv_core -lopencv_highgui $(JOYLIB)

install: $(PLUGIN) hackflight_companion.py
	cp $(PLUGIN) $(VREP_DIR)
	cp hackflight_companion.py $(VREP_DIR)
	cp socket_server.py $(VREP_DIR)

uninstall:
	rm -f $(VREP_DIR)/$(PLUGIN)
	rm -f $(VREP_DIR)/hackflight_companion.py
	rm -f $(VREP_DIR)/image1.jpg
	rm -f $(VREP_DIR)/image2.jpg

vedit:
	vim v_repExtHackflight.cpp

pedit:
	vim hackflight_companion.py

flakes:
	pyflakes hackflight_companion.py

release: $(PLUGIN)
	cp $(PLUGIN) Release

commit:
	git commit -a --allow-empty-message -m ""
	git push

clean:
	rm -f *.o *.so *.pyc *~
