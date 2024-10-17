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







-------------------------------------------------------------------
How to connect page transitions?

In mainWindow we create a QStackedWidgte, this is a stack of widgets (later we just index to the page we want)

We create the views and add them in the main window:

- DashboardView *dashboardView = new DashboardView(this);
- PrescriptionView *prescriptionView = new PrescriptionView(this);

- stackedWidget->addWidget(dashboardView);
- stackedWidget->addWidget(prescriptionView);

We also make the controllers for each view (PLEASE LOOK IN THE FILE, NOT HERE FOR THEM).

-----------
We then must connect the signals (this is the controllers job, responisble for ui interactions)

if a user requests to go from the dash to prescription this happens:
-> PrescriptionsRequested signal from DashboardContorller is connected
-> It is connected to the showPrescription() slot in MainWindow
- connect(view, &DashboardView::refillPrescriptionClicked, this, &DashboardController::onRefillPrescriptionClicked);


---------
When the user clicks on the button, it emits a sginal (refillPrescriptionClciked())
This is connected to the slot onRefillPrescriptionClicked().

This can be seen in the connection above. 

When onRefillPrescriptionClicked() is singaled, the controller emits the prescriptionResquested() signal. 
- void DashboardController::onRefillPrescriptionClicked() {
    qDebug() << "Refill Prescription clicked";
    emit prescriptionsRequested();
    }


---------
This emit signal triggers the showPrecriptions() slot: 
- connect(dashboardController, &DashboardController::prescriptionsRequested, this, &MainWindow::showPrescriptions);

This then runs the function to choose the correct stackedWidget:
- void MainWindow::showPrescriptions() {
    stackedWidget->setCurrentIndex(1);
    }
