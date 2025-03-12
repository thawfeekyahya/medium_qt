#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QColor>
class Triangle : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged FINAL)
public:
    Triangle();
    explicit Triangle(QColor m_color) : m_color(m_color) {}
    void setColor(const QColor& color);
    QColor color() const;
protected:
    QSGNode* updatePaintNode(QSGNode* oldNode,QQuickItem::UpdatePaintNodeData* updatePaintNodeData);
signals:
    void colorChanged();
private:
    QColor m_color;
};

#endif // TRIANGLE_H
