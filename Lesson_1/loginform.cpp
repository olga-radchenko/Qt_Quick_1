#include "loginform.h"

LogInForm::LogInForm(QWidget *parent)
    :  QMainWindow(parent)
{
    resize(300, 500);

    scene   = new QGraphicsScene(this);
    layout  = new QGraphicsLinearLayout(Qt::Vertical);

    loginLineEdit    = new QLineEdit;
    passwordLineEdit = new QLineEdit;
    loginLable       = new AnimatedLabel{"Login"};
    passwordLable    = new AnimatedLabel{"Password"};
    logInButton      = new QPushButton{"Log In"};

    logInButton->setAttribute(Qt::WA_TranslucentBackground);
    loginLable->setAttribute(Qt::WA_TranslucentBackground);
    passwordLable->setAttribute(Qt::WA_TranslucentBackground);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    rect = new QGraphicsRectWidget(20, 60, 260, 140, Qt::black);
    rect->makeHalfTransparent();

    auto rect2 = new QGraphicsRectWidget(30, 60, 240, 110, Qt::transparent);
    rect2->setLayout(layout);

    scene->addItem(rect);
    scene->addItem(rect2);

    QGraphicsWidget *loginLableWidget    = scene->addWidget(loginLable);
    QGraphicsWidget *logInButtonWidget   = scene->addWidget(logInButton);
    QGraphicsWidget *loginLineEditWidget = scene->addWidget(loginLineEdit);
    QGraphicsWidget *passwordLableWidget = scene->addWidget(passwordLable);
    QGraphicsWidget *passwordLineEditWidget = scene->addWidget(passwordLineEdit);

    connect(logInButton, SIGNAL(clicked()), rect, SLOT(shake()));
    connect(logInButton, SIGNAL(clicked()), this, SLOT(blink()));

    layout->addItem(loginLableWidget);
    layout->addItem(loginLineEditWidget);
    layout->addItem(passwordLableWidget);
    layout->addItem(passwordLineEditWidget);
    layout->addItem(passwordLineEditWidget);
    layout->setSpacing(8);
    layout->addItem(logInButtonWidget);

    graphicsView = new GraphicsView(scene);
    graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
    graphicsView->setScene(scene);
    graphicsView->setFrameStyle(0);
    graphicsView->setAlignment(Qt::AlignCenter);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dadbde, stop:1 #ffb6c1);");
    setCentralWidget(graphicsView);
}

LogInForm::~LogInForm()
{

}

void LogInForm::blink()
{
    QParallelAnimationGroup group;

    QPropertyAnimation *animation22 = new QPropertyAnimation(loginLable, "color");
    animation22->setDuration(700);
    animation22->setStartValue(QColor(Qt::black));
    animation22->setKeyValueAt(0.5,QColor(Qt::red));
    animation22->setEndValue(QColor(Qt::black));

    QPropertyAnimation *animation11 = new QPropertyAnimation(passwordLable, "color");
    animation11->setDuration(700);
    animation11->setStartValue(QColor(Qt::black));
    animation11->setKeyValueAt(0.5,QColor(Qt::red));
    animation11->setEndValue(QColor(Qt::black));

    group.addAnimation(animation22);
    group.addAnimation(animation11);
    group.setLoopCount(2);
    group.start();

    while(group.state() == QAbstractAnimation::Running)
    {
        delay(1);
    }
}
