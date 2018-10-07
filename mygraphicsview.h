#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class MyGraphicsView : public QGraphicsView
{

public:
    MyGraphicsView(QWidget *parent = nullptr);

    void setCursor(const QCursor &cursor);


private:
    QPoint m_lastMousePos;
    bool m_pressed;

protected:
    // the implementation of the next override methods is explanined
    // in "Game Programming Using QT, 1ed, chp 6, page 215"
    virtual void wheelEvent(QWheelEvent *event);
//    virtual void mouseMoveEvent(QMouseEvent *event);
//    virtual void mousePressEvent(QMouseEvent *event);
//    virtual void mouseReleaseEvent(QMouseEvent *event);


};

#endif // MYGRAPHICSVIEW_H
