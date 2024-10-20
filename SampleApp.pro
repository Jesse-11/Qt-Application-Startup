QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/model/dashboardmodel.cpp \
    src/model/prescriptionmodel.cpp \
    src/model/telemedicinemodel.cpp \
    src/model/appointmentmodel.cpp \
    src/model/doctorsearchmodel.cpp \
    src/model/confirmappointmentmodel.cpp \
    src/model/languageselectionmodel.cpp \
    src/view/dashboardview.cpp \
    src/view/prescriptionview.cpp \
    src/view/telemedicineview.cpp \
    src/view/appointmentview.cpp \
    src/view/doctorsearchview.cpp \
    src/view/confirmappointmentview.cpp \
    src/view/languageselectionview.cpp \
    src/controller/dashboardcontroller.cpp \
    src/controller/prescriptioncontroller.cpp \
    src/controller/appointmentcontroller.cpp \
    src/controller/doctorsearchcontroller.cpp \
    src/controller/confirmappointmentcontroller.cpp \
    src/controller/languageselectioncontroller.cpp \
    src/controller/telemedicinecontroller.cpp

HEADERS += \
    include/mainwindow.h \
    src/model/dashboardmodel.h \
    src/model/prescriptionmodel.h \
    src/model/telemedicinemodel.h \
    src/model/appointmentmodel.h \
    src/model/doctorsearchmodel.h \
    src/model/confirmappointmentmodel.h \
    src/model/languageselectionmodel.h \
    src/view/dashboardview.h \
    src/view/prescriptionview.h \
    src/view/telemedicineview.h \
    src/view/appointmentview.h \
    src/view/doctorsearchview.h \
    src/view/confirmappointmentview.h \
    src/view/languageselectionview.h \
    src/controller/dashboardcontroller.h \
    src/controller/prescriptioncontroller.h \
    src/controller/appointmentcontroller.h \
    src/controller/doctorsearchcontroller.h \
    src/controller/confirmappointmentcontroller.h \
    src/controller/languageselectioncontroller.h \
    src/controller/telemedicinecontroller.h
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