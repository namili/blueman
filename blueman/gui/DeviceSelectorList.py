# Copyright (C) 2008 Valmantas Paliksa <walmis at balticum-tv dot lt>
# Copyright (C) 2008 Tadas Dailyda <tadas at dailyda dot com>
#
# Licensed under the GNU General Public License Version 3
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# 

import gtk
import pango
import cgi
from blueman.gui.DeviceList import DeviceList
from blueman.Functions import *

class DeviceSelectorList(DeviceList):

	def __init__(self, adapter=None):
		cr = gtk.CellRendererText()
		cr.props.ellipsize = pango.ELLIPSIZE_END
		data = [
			#device picture
			["found_pb", 'GdkPixbuf', gtk.CellRendererPixbuf(), {"pixbuf":0}, None, {"spacing": 0, "sizing": gtk.TREE_VIEW_COLUMN_AUTOSIZE}],
			["device_pb", 'GdkPixbuf', gtk.CellRendererPixbuf(), {"pixbuf":1}, None],
			
			#device caption
			["caption", str, cr, {"markup":2}, None, {"expand": True}],

			["bonded_icon", 'GdkPixbuf', gtk.CellRendererPixbuf(), {"pixbuf":3}, None],
			["trusted_icon", 'GdkPixbuf', gtk.CellRendererPixbuf(), {"pixbuf":4}, None]
			
			#["connected", bool], #used for quick access instead of device.GetProperties
			#["bonded", bool], #used for quick access instead of device.GetProperties
			#["trusted", bool], #used for quick access instead of device.GetProperties	
			#["fake", bool], #used for quick access instead of device.GetProperties, 
					#fake determines whether device is "discovered" or a real bluez device
		]
		
		DeviceList.__init__(self, adapter, data)
		self.props.headers_visible = False
		
	def row_setup_event(self, iter, device):
		if not device.Fake:
			self.row_update_event(iter, "Trusted", device.Trusted)
			self.row_update_event(iter, "Paired", device.Paired)
		self.row_update_event(iter, "Fake", device.Fake)
		self.row_update_event(iter, "Alias", device.Alias)
		self.row_update_event(iter, "Icon", device.Icon)
		
	def device_add_event(self, device):
		if device.Fake:
			self.PrependDevice(device)
		else:
			self.AppendDevice(device)
	
	def row_update_event(self, iter, key, value):
		if key == "Trusted":
			if value:
				self.set(iter, trusted_icon=get_icon("blueman-trust", 16))
			else:
				self.set(iter, trusted_icon=None)
			
		
		elif key == "Paired":
			if value:
				self.set(iter, bonded_icon=get_icon("gtk-dialog-authentication", 16))
			else:
				self.set(iter, bonded_icon=None)
				
		elif key == "Fake":
			if value:
				self.set(iter, found_pb=get_icon("gtk-search", 16))
			else:
				self.set(iter, found_pb=None)
				
		elif key == "Alias":
			self.set(iter, caption=cgi.escape(value))
			
		elif key == "Icon":
			self.set(iter, device_pb=get_icon(value, 16))
	
	
	
	
	
	
