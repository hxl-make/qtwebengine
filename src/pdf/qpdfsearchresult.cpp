/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtPDF module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qpdfsearchresult.h"
#include "qpdfsearchresult_p.h"

QT_BEGIN_NAMESPACE

QPdfSearchResult::QPdfSearchResult() :
    QPdfSearchResult(new QPdfSearchResultPrivate()) { }

QPdfSearchResult::QPdfSearchResult(int page, QVector<QRectF> rects, QString context) :
    QPdfSearchResult(new QPdfSearchResultPrivate(page, rects, context)) { }

QPdfSearchResult::QPdfSearchResult(QPdfSearchResultPrivate *d) :
    QPdfDestination(static_cast<QPdfDestinationPrivate *>(d)) { }

QString QPdfSearchResult::context() const
{
    return static_cast<QPdfSearchResultPrivate *>(d.data())->context;
}

QVector<QRectF> QPdfSearchResult::rectangles() const
{
    return static_cast<QPdfSearchResultPrivate *>(d.data())->rects;
}

QDebug operator<<(QDebug dbg, const QPdfSearchResult &searchResult)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace();
    dbg << "QPdfSearchResult(page=" << searchResult.page()
        << " context=" << searchResult.context()
        << " rects=" << searchResult.rectangles();
    dbg << ')';
    return dbg;
}

QT_END_NAMESPACE

#include "moc_qpdfsearchresult.cpp"
