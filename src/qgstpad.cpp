/*
    Copyright (C) 2009  George Kiagiadakis <kiagiadakis.george@gmail.com>

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "qgstpad.h"
#include <gst/gstpad.h>

namespace QtGstreamer {

QGstPad::QGstPad(GstPad *gstPad, QObject *parent)
    : QGstObject(GST_OBJECT(gstPad), parent)
{
}

QGstPad::~QGstPad()
{
}

bool QGstPad::isLinked() const
{
    return gst_pad_is_linked(GST_PAD(m_object));
}

QGstPad::LinkReturn QGstPad::link(QGstPad *other)
{
    return static_cast<LinkReturn>(gst_pad_link(GST_PAD(m_object), GST_PAD(other->m_object)));
}

bool QGstPad::unlink(QGstPad *other)
{
    return gst_pad_unlink(GST_PAD(m_object), GST_PAD(other->m_object));
}

bool QGstPad::canLink(QGstPad *other)
{
    return gst_pad_can_link(GST_PAD(m_object), GST_PAD(other->m_object));
}

}

#include "qgstpad.moc"
