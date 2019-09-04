#
#   Copyright 2004-2008, by the California Institute of Technology.
#   ALL RIGHTS RESERVED. United States Government Sponsorship
#   acknowledged. Any commercial use must be negotiated with the Office
#   of Technology Transfer at the California Institute of Technology.
#

# This is a template for the mod.mk file that goes in each module
# and each module's subdirectories.
# With a fresh checkout, "make gen_make" should be invoked. It should also be
# run if any of the variables are updated. Any unused variables can 
# be deleted from the file.

# There are some standard files that are included for reference

TEST_SRC = 	TesterBase.cpp \
			Tester.cpp \
			main.cpp

TEST_MODS = SnapdragonFlight/BlspSerialDriver \
			SnapdragonFlight/RpcCommon \
			SnapdragonFlight/DspRelay \
			SnapdragonFlight/DspRpcAllocator \
			Drv/SerialDriverPorts \
			Fw/Tlm \
			Fw/Comp \
			Fw/Cmd \
			Fw/Log \
			Fw/Obj \
			Fw/Port \
			Fw/Time \
			Fw/Types \
			Fw/Com \
			Fw/Buffer \
			Svc/Sched \
			Os
