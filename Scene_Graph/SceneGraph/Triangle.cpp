#include "Triangle.h"

#include <QSGSimpleRectNode>
#include <QVector2D>
#include <QDebug>

Triangle::Triangle():m_color(Qt::red) {
    setFlag(ItemHasContents);
}

void Triangle::setColor(const QColor& pColor)
{
    m_color = pColor;
    update();
    emit colorChanged();
}

QColor Triangle::color() const
{
    return m_color;
}

QSGNode *Triangle::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *updatePaintNodeData)
{
    QSGGeometryNode *node = nullptr;
    QSGGeometry *geometry = nullptr;

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 3);
        geometry->setDrawingMode(QSGGeometry::DrawTriangles);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        material->setColor(m_color);
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        QSGFlatColorMaterial *material = static_cast<QSGFlatColorMaterial *>(node->material());

        if (material->color() != m_color) {
            material->setColor(m_color);
            node->markDirty(QSGNode::DirtyMaterial);
        }
    }


    QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
    vertices[0].set(0, height());
    vertices[1].set(width() / 2, 0);
    vertices[2].set(width(), height());

    node->markDirty(QSGNode::DirtyGeometry);

    return node;

}
