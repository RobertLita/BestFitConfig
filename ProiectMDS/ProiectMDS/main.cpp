#include "ProiectMDS.h"
#include <QtWidgets/QApplication>
#include "RepositoryAbonamente.h"
#include "RepositoryClienti.h"
#include "RepositoryFacilitati.h"
#include "ServiceAbonamente.h"
#include "ServiceClienti.h"
#include "ServiceFacilitati.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w{};
    RepositoryFacilitati repositoryFacilitati;
    RepositoryAbonamente repositoryAbonamente;
    RepositoryClienti repositoryClienti;
    ServiceFacilitati serviceFacilitati(repositoryFacilitati);
    ServiceAbonamente serviceAbonamente(repositoryAbonamente);
    ServiceClienti serviceClienti(repositoryClienti);
    
    GUI gui(serviceFacilitati, serviceAbonamente, serviceClienti);
    gui.show();
    
    return a.exec();
}
