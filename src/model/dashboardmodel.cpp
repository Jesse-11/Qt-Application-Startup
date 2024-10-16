#include "dashboardmodel.h"

DashboardModel::DashboardModel() : welcomeMessage("Welcome to your personal health management system") {}

QString DashboardModel::getWelcomeMessage() const {
    return welcomeMessage;
}

void DashboardModel::setWelcomeMessage(const QString &message) {
    welcomeMessage = message;
}