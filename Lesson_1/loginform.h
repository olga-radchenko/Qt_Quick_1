#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDir>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QStyleOption>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QPropertyAnimation>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

#include "custom_widgets.h"

class LogInForm : public QMainWindow
{
    Q_OBJECT

public:
    LogInForm(QWidget *parent = nullptr);
    ~LogInForm();

private:
    AnimatedLabel  *loginLable{nullptr};
    QLineEdit *loginLineEdit{nullptr};
    AnimatedLabel  *passwordLable{nullptr};
    QPushButton *logInButton{nullptr};
    QLineEdit *passwordLineEdit{nullptr};
    QGraphicsScene *scene{nullptr};
    QGraphicsRectWidget *rect{nullptr};
    QGraphicsRectWidget *rect2{nullptr};
    GraphicsView *graphicsView{nullptr};
    QGraphicsLinearLayout *layout{nullptr};
    QParallelAnimationGroup *animationGroup{nullptr};

signals:
    void startShakeAnimation();

private slots:
    void blink();
};

#endif // LOGINFORM_H
