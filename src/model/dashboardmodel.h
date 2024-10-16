#ifndef DASHBOARDMODEL_H
#define DASHBOARDMODEL_H

#include <QString>

class DashboardModel {
public:
    DashboardModel();
    QString getWelcomeMessage() const;
    void setWelcomeMessage(const QString &message);

private:
    QString welcomeMessage;
};

#endif // DASHBOARDMODEL_H