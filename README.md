# Medical Application in Qt c++


## How to run The application

Ensure the main setup file is exectuable:
` chmod +x setup.sh `

Run the setup file:
` ./setup.sh `

run the application using wrapper script:
` ./run_app.sh `

To rebuild the app after changes run:
` make `

to run application again run:
` ./run_app.sh `


after running the app, to clean up files run:
` make clean ` 

If at any point changes are made to the .pro file, make sure to run:
` qmake SampleApp.pro `
Then once again run:
` make `




## How do pages connect and transition?

In the mainWindow we create a QStackWisget, this is a stack of widgets. These can be indexed to show a page

We create the views and the controllers, then add them in the main window (mainwindow.cpp):
```
DashboardView *dashboardView = new DashboardView(this);
PrescriptionView *prescriptionView = new PrescriptionView(this);

dashboardController = new DashboardController(new DashboardModel(), dashboardView, this);
prescriptionController = new PrescriptionController(prescriptionView, this);

stackedWidget->addWidget(dashboardView);
stackedWidget->addWidget(prescriptionView);
```

In the dashview(UI) we set up a button and a singal(for when its clicked):
`  QPushButton *refillPrescriptionButton; `
`  void refillPrescriptionClicked(); `

in the cpp we also make a connection for the signal. This connection takes in the buttons singnal indentifying when its clicked, and connects this to the slot we made ( emits a singla when we click the button):
` connect(refillPrescriptionButton, &QPushButton::clicked, this, &DashboardView::refillPrescriptionClicked); ` 


We then must connect this singal signal to our controller (As in the MVC Pattern, it is the controllers job to handle UI interactions).

So when the signal from the view slot is recieved we connect is to the controllers prescription slot. This means is emits a singal for the function shown below:
` connect(view, &DashboardView::refillPrescriptionClicked, this, &DashboardController::onRefillPrescriptionClicked); `


When this signal is emited, it has no connection and activates its relevant funciton:

```
void DashboardController::onRefillPrescriptionClicked() {
    qDebug() << "Refill Prescription clicked";
    emit prescriptionsRequested();
}
```

This function then emits another signal back to the main window which is then picked up by connection slot
```
connect(dashboardController, &DashboardController::prescriptionsRequested, this, &MainWindow::showPrescriptions);
```

Again, this connection releases a signal that does not have a matching connection slot, so the relevant function is called, this function indexes the original stacked widget to the correct page we want:

```
void MainWindow::showPrescriptions() {
    stackedWidget->setCurrentIndex(1);
}
``` 



