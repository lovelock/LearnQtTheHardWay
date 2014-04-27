#include "mainwindow.h"
#include <QAction>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
//    QDialog dialog;
//    QDialog dialog(this);
    QDialog *dialog = new QDialog;
    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->exec(); // exec()是非模态对话框
//    dialog->show(); // show()是模态对话框
//    dialog.setWindowTitle(tr("Hello, dialog!"));
//    dialog.show();
//    dialog.exec();
}
