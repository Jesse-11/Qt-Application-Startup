# Medical Application in Qt c++


## How to run The application

1. Make main setup file executale:
` chmod +x setup.sh `

2. Run the setup file:
` ./setup.sh `

3. run the application using the wrapper script:
` ./run_app.sh `

## Development Workflow

1. After making changes, rebuild the app
` make `

2. Run the application again:
` ./run_app.sh `

3. To clean up files:
` make clean ` 

4. If changes are made to the .pro file:
```
qmake SampleApp.pro 
make 
```


## How do pages connect and transition?

The application uses Model-View-Controller (MVC) patterns. This means that the application seperates interactions between the view (UI), Model (Data/Logic) & Controller (Middle-man).

1. Main Window setup
*  Firsly we create a QStackWidget. This is a stack of widgets and how we control the current page
* We also create the views and controllers, ensruing we add them to the main window

```
DashboardView *dashboardView = new DashboardView(this);
PrescriptionView *prescriptionView = new PrescriptionView(this);

dashboardController = new DashboardController(new DashboardModel(), dashboardView, this);
prescriptionController = new PrescriptionController(prescriptionView, this);

stackedWidget->addWidget(dashboardView);
stackedWidget->addWidget(prescriptionView);
```

2. View setup
* We need to setup a button and signal. In the dashview(UI) we set up a button and a singal(for when its clicked):
``` 
QPushButton *refillPrescriptionButton; 
void refillPrescriptionClicked(); 
```
* In the views cpp we create a connection. This takes in the signal that is made when the button is clicked, and connects ot the the views slot. This slot emits a signal:
```
connect(refillPrescriptionButton, &QPushButton::clicked, this, &DashboardView::refillPrescriptionClicked); 
``` 

3. Controller connection
* As we are using MVC, we must connect the view to the controller. To do when we connect the previous view signal to our new slot in the controller.
* This connection will also emit its own signal
```
connect(view, &DashboardView::refillPrescriptionClicked, this, &DashboardController::onRefillPrescriptionClicked); 
```

4. Controller action
* The controler then handles the signal. As thier is no slot for the signal to conenct, it calls its relevant function. This emits its own signal:
```
void DashboardController::onRefillPrescriptionClicked() {
    qDebug() << "Refill Prescription clicked";
    emit prescriptionsRequested();
}
```

5. Main window connection
* We then connect this signal back to a main window connection slot to change our applicaiton to the relevant page(stackedWidget)
```
connect(dashboardController, &DashboardController::prescriptionsRequested, this, &MainWindow::showPrescriptions);
```

6. Transition Page
* Again, this connection released a signal that does not have a connection slot, so it calls its relevant function; this indexes us to the required page:
```
void MainWindow::showPrescriptions() {
    stackedWidget->setCurrentIndex(1);
}
``` 



