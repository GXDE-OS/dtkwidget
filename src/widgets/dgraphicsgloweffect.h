/*
 * Copyright (C) 2015 ~ 2017 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DGRAPHICSGLOWEFFECT_H
#define DGRAPHICSGLOWEFFECT_H

#include <QGraphicsDropShadowEffect>
#include <QGraphicsEffect>
#include <QPainter>
#include <QPainterPath>

#include "dtkwidget_global.h"

DWIDGET_BEGIN_NAMESPACE

class LIBDTKWIDGETSHARED_EXPORT DGraphicsGlowEffect : public QGraphicsEffect
{
    Q_OBJECT
public:
    explicit DGraphicsGlowEffect(QObject *parent = nullptr);

    void draw(QPainter *painter);
    QRectF boundingRectFor(const QRectF &rect) const;

    inline void setOffset(qreal dx, qreal dy) {m_xOffset = dx; m_yOffset = dy;}

    inline void setXOffset(qreal dx) {m_xOffset = dx;}
    inline qreal xOffset() const {return m_xOffset;}

    inline void setYOffset(qreal dy) {m_yOffset = dy;}
    inline qreal yOffset() const {return m_yOffset;}

    inline void setDistance(qreal distance) { m_distance = distance; updateBoundingRect(); }
    inline qreal distance() const { return m_distance; }

    inline void setBlurRadius(qreal blurRadius) { m_blurRadius = blurRadius; updateBoundingRect(); }
    inline qreal blurRadius() const { return m_blurRadius; }

    inline void setColor(const QColor &color) { m_color = color; }
    inline QColor color() const { return m_color; }

    // TODO: refactor with d-pointer;
    inline qreal opacity() const { return m_opacity; }
    inline void setOpacity(qreal opacity) { m_opacity = opacity; }

private:
    qreal m_opacity = 1.0;
    qreal m_xOffset;
    qreal m_yOffset;
    qreal m_distance;
    qreal m_blurRadius;
    QColor m_color;
};

DWIDGET_END_NAMESPACE

#endif // DGRAPHICSGLOWEFFECT_H
