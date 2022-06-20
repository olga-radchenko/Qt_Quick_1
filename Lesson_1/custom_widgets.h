#ifndef CUSTOM_WIDGETS_H
#define CUSTOM_WIDGETS_H

#include <QPen>
#include <QTimer>
#include <QColor>
#include <QLabel>
#include <QObject>
#include <QPainter>
#include <QEventLoop>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QSequentialAnimationGroup>

inline void delay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}

class AnimatedLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    AnimatedLabel(const QString &text) :QLabel(text)
    {
        setStyleSheet(QString("color: black;"));
    }

    void setColor (QColor color)
    {
        setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
    }

    QColor color()
    {
        return Qt::black;
    }
};

class QGraphicsRectWidget : public QGraphicsWidget
{
    Q_OBJECT

private:
    QSequentialAnimationGroup *group{nullptr};
    QGraphicsOpacityEffect *qgoEffect{nullptr};
    QColor m_color;

public:
    int m_x, m_y, m_width, m_height;

    QGraphicsRectWidget(int x, int y, int width, int height, Qt::GlobalColor color) : m_x(x), m_y(y), m_width(width), m_height(height)
    {
        m_color = color;
        setGeometry(m_x,m_y,m_width,m_height);

        group = new QSequentialAnimationGroup;

        QPropertyAnimation *animation1= new QPropertyAnimation(this, "geometry");
        animation1->setDuration(40);
        animation1->setStartValue(QRect(m_x, m_y, m_width, m_height));
        animation1->setEndValue(QRect(m_x+10, m_y, m_width, m_height));
        animation1->setEasingCurve(QEasingCurve::InBounce);

        QPropertyAnimation *animation2= new QPropertyAnimation(this, "geometry");
        animation2->setDuration(40);
        animation2->setStartValue(QRect(m_x+10, m_y, m_width, m_height));
        animation2->setEndValue(QRect(m_x, m_y, m_width, m_height));
        animation2->setEasingCurve(QEasingCurve::InBounce);

        QPropertyAnimation *animation3= new QPropertyAnimation(this, "geometry");
        animation3->setDuration(40);
        animation3->setStartValue(QRect(m_x, m_y, m_width, m_height));
        animation3->setEndValue(QRect(m_x-10, m_y, m_width, m_height));
        animation3->setEasingCurve(QEasingCurve::InBounce);

        QPropertyAnimation *animation4= new QPropertyAnimation(this, "geometry");
        animation4->setDuration(40);
        animation4->setStartValue(QRect(m_x-10, m_y, m_width, m_height));
        animation4->setEndValue(QRect(m_x, m_y, m_width, m_height));
        animation4->setEasingCurve(QEasingCurve::InBounce);

        group->addAnimation(animation1);
        group->addAnimation(animation2);
        group->addAnimation(animation3);
        group->addAnimation(animation4);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) override
    {
        QBrush brush;
        QPen pen;
        pen.setColor(Qt::transparent);
        brush.setStyle(Qt::SolidPattern); //For fill
        brush.setColor(m_color);
        painter->setBrush(brush);
        painter->setPen(pen);
        painter->drawRoundedRect(rect(), 10, 10);
    }

    void makeHalfTransparent()
    {
        qgoEffect = new QGraphicsOpacityEffect(this);
        qgoEffect->setOpacity(0.10);
        setGraphicsEffect(qgoEffect);
        setAutoFillBackground(true);
    }

    QRectF boundingRect() const override
    {
        return QRectF(0, 0, m_width, m_height);
    }

private slots:
    void shake()
    {
        group->start();

        while(group->state() == QAbstractAnimation::Running)
        {
            delay(1);
        }
    }
};

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QGraphicsScene *scene, QWidget *parent = NULL)
        : QGraphicsView(scene, parent) { }

protected:
    void resizeEvent(QResizeEvent *event) override
    {
        Q_UNUSED(event);
        setSceneRect(0, 0, frameSize().width(), frameSize().height());
    }
};

#endif // CUSTOM_WIDGETS_H
