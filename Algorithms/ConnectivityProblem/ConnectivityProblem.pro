TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Connetedness.cpp \
        connectednessarray.cpp \
        connectednessfullunion.cpp \
        connectednesstree.cpp \
        connectednessweightedunion.cpp \
        main.cpp

HEADERS += \
	Connetedness.h \
	connectednessarray.h \
	connectednessfullunion.h \
	connectednesstree.h \
	connectednessweightedunion.h
