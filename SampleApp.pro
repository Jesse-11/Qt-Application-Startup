QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Custom clean target
QMAKE_CLEAN += $(TARGET) $(OBJECTS) $(DESTDIR_TARGET) Makefile
clean.commands = rm -rf $(OBJECTS_DIR)/*.o $(MOC_DIR)/*.cpp $(DESTDIR)$(TARGET) $(DESTDIR_TARGET)
clean.depends = FORCE
QMAKE_EXTRA_TARGETS += clean