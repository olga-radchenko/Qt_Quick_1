#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFormStyle();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setFormStyle()
{
    QFile file(":/style.qss");

    if(!file.open(QIODevice::ReadOnly))
        qDebug() << "can't load qss file!\nCurrent path:  ";

    const QString cssStyle{file.readAll()};
    qApp->setStyleSheet(cssStyle);
}

void MainWindow::on_logInFormBttn_clicked()
{
    if(logInForm == nullptr)
        logInForm = new LogInForm(this);

    logInForm->show();
}

void MainWindow::on_qtQuickBttn_clicked()
{
    if(engine == nullptr)
        engine = new QQmlApplicationEngine(this);

    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
}
