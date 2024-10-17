QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/model/dashboardmodel.cpp \
    src/model/prescriptionmodel.cpp \
    src/view/dashboardview.cpp \
    src/view/prescriptionview.cpp \
    src/controller/dashboardcontroller.cpp \
    src/controller/prescriptioncontroller.cpp

HEADERS += \
    include/mainwindow.h \
    src/model/dashboardmodel.h \
    src/model/prescriptionmodel.h \
    src/view/dashboardview.h \
    src/view/prescriptionview.h \
    src/controller/dashboardcontroller.h \
    src/controller/prescriptioncontroller.h

RESOURCES += resources.qrc

INCLUDEPATH += \
    include \
    src

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Custom clean target
QMAKE_CLEAN += $(TARGET) $(OBJECTS) $(DESTDIR_TARGET) Makefile
clean.commands = rm -rf $(OBJECTS_DIR)/*.o $(MOC_DIR)/*.cpp $(DESTDIR)$(TARGET) $(DESTDIR_TARGET)
clean.depends = FORCE
QMAKE_EXTRA_TARGETS += clean