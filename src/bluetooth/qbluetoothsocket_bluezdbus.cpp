/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qbluetoothsocket.h"
#include "qbluetoothsocket_bluezdbus_p.h"

QT_BEGIN_NAMESPACE
QBluetoothSocketPrivateBluezDBus::QBluetoothSocketPrivateBluezDBus()
{
    secFlags = QBluetooth::NoSecurity;
}

QBluetoothSocketPrivateBluezDBus::~QBluetoothSocketPrivateBluezDBus()
{
}

bool QBluetoothSocketPrivateBluezDBus::ensureNativeSocket(QBluetoothServiceInfo::Protocol type)
{
    socketType = type;
    return false;
}

void QBluetoothSocketPrivateBluezDBus::connectToServiceHelper(const QBluetoothAddress &address, quint16 port, QIODevice::OpenMode openMode)
{
    Q_UNUSED(openMode);
    Q_UNUSED(address);
    Q_UNUSED(port);
}

void QBluetoothSocketPrivateBluezDBus::abort()
{
}

QString QBluetoothSocketPrivateBluezDBus::localName() const
{
    return QString();
}

QBluetoothAddress QBluetoothSocketPrivateBluezDBus::localAddress() const
{
    return QBluetoothAddress();
}

quint16 QBluetoothSocketPrivateBluezDBus::localPort() const
{
    return 0;
}

QString QBluetoothSocketPrivateBluezDBus::peerName() const
{
    return QString();
}

QBluetoothAddress QBluetoothSocketPrivateBluezDBus::peerAddress() const
{
    return QBluetoothAddress();
}

quint16 QBluetoothSocketPrivateBluezDBus::peerPort() const
{
    return 0;
}

qint64 QBluetoothSocketPrivateBluezDBus::writeData(const char *data, qint64 maxSize)
{
    Q_UNUSED(data);
    Q_UNUSED(maxSize);

    Q_Q(QBluetoothSocket);

    if (state != QBluetoothSocket::ConnectedState) {
        errorString = QBluetoothSocket::tr("Cannot write while not connected");
        q->setSocketError(QBluetoothSocket::OperationError);
        return -1;
    }
    return -1;
}

qint64 QBluetoothSocketPrivateBluezDBus::readData(char *data, qint64 maxSize)
{
    Q_UNUSED(data);
    Q_UNUSED(maxSize);

    Q_Q(QBluetoothSocket);

    if (state != QBluetoothSocket::ConnectedState) {
        errorString = QBluetoothSocket::tr("Cannot read while not connected");
        q->setSocketError(QBluetoothSocket::OperationError);
        return -1;
    }

    return -1;
}

void QBluetoothSocketPrivateBluezDBus::close()
{
}

bool QBluetoothSocketPrivateBluezDBus::setSocketDescriptor(int socketDescriptor, QBluetoothServiceInfo::Protocol socketType,
                                           QBluetoothSocket::SocketState socketState, QBluetoothSocket::OpenMode openMode)
{
    Q_UNUSED(socketDescriptor);
    Q_UNUSED(socketType)
    Q_UNUSED(socketState);
    Q_UNUSED(openMode);
    return false;
}

qint64 QBluetoothSocketPrivateBluezDBus::bytesAvailable() const
{
    return 0;
}

bool QBluetoothSocketPrivateBluezDBus::canReadLine() const
{
    return false;
}

qint64 QBluetoothSocketPrivateBluezDBus::bytesToWrite() const
{
    return 0;
}
QT_END_NAMESPACE