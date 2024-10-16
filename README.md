# Qt-Application-Startup

In terminal cd to application, and make setuph.sh exectuable:
- chmod +x setup.sh

run (to install qt if not already):
- ./setup.sh

run the application using wrapper script:
- ./run_app.sh


----------------------------------

To rebuild app run:
- make

to run application again run:
- ./run_app.sh


---------------------------

after runnig, to clean up files run:
- make clean





---------------------------
if changes are made to the .pro file, make sure to run:
- qmake SampleApp.pro
before running:
- make

