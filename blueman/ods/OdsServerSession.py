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

import gobject
from blueman.ods.OdsBase import OdsBase

class OdsServerSession(OdsBase):
	__gsignals__ = {
		'cancelled' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, ()),
		'disconnected' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, ()),
		'transfer-started' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, (gobject.TYPE_PYOBJECT, gobject.TYPE_PYOBJECT, gobject.TYPE_PYOBJECT,)),
		'transfer-progress' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, (gobject.TYPE_PYOBJECT,)),
		'transfer-completed' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, ()),
		'error-occurred' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, (gobject.TYPE_PYOBJECT, gobject.TYPE_PYOBJECT,)),
	}
	
	def __init__(self, obj_path):
		OdsBase.__init__(self, "org.openobex.ServerSession", obj_path)
		
		self.Handle("Cancelled", self.on_cancelled)
		self.Handle("Disconnected", self.on_disconnected)
		self.Handle("TransferStarted", self.on_trans_started)
		self.Handle("TransferProgress", self.on_trans_progress)
		self.Handle("TransferCompleted", self.on_trans_complete)
		self.Handle("ErrorOccurred", self.on_error)
		
	def __del__(self):
		dprint("deleting session")
		
	def on_cancelled(self):
		self.emit("cancelled")
		#self.DisconnectAll()
		
	def on_disconnected(self):
		self.emit("disconnected")
		#self.DisconnectAll()
		
	def on_trans_started(self, filename, path, size):
		self.emit("transfer-started", filename, path, size)
		
	def on_trans_progress(self, bytes):
		self.emit("transfer-progress", bytes)
		
	def on_trans_complete(self):
		self.emit("transfer-completed")
		
	def on_error(self, name, msg):
		self.emit("error-occurred", name, msg)
		#self.DisconnectAll()
