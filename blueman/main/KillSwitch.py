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
import dbus
import gobject
from blueman.main.HalManager import HalManager

class WrongType(Exception):
	pass

class NotAKillSwitch(Exception):
	pass

class KillSwitch(dbus.proxies.Interface):
	class __Switch(dbus.proxies.Interface):
		def __init__(self, udi):
			bus = dbus.SystemBus()
			obj = bus.get_object('org.freedesktop.Hal', udi)
			dbus.proxies.Interface.__init__(self, obj, 'org.freedesktop.Hal.Device.KillSwitch')			
	
	def __init__(self, udi):
		self.udi = udi
		bus = dbus.SystemBus()
		obj = bus.get_object('org.freedesktop.Hal', udi)
		dbus.proxies.Interface.__init__(self, obj, 'org.freedesktop.Hal.Device')
		if self.QueryCapability("killswitch"):
			t = self.GetPropertyString("killswitch.type")
			if t != "bluetooth":
				raise WrongType
		else:
			raise NotAKillSwitch
			
		self.__switch = KillSwitch.__Switch(udi)
		
		self.hard = 0
		self.idx = self.udi
		self.type = 2 #RfkillType.BLUETOOTH
		
	def __getattr__(self, key):
		if key == "soft":
			return self.GetPower()
		else:
			return dbus.proxies.Interface.__getattr__(self, key)
		
	def SetPower(self, state):
		try:
			self.__switch.SetPower(state)
		except dbus.DBusException:
			dprint("Failed to toggle killswitch")
		
	def GetPower(self):
		return self.__switch.GetPower()
		
	
class Manager(gobject.GObject):
	__inst = None
	__gsignals__ = {
		'switch-changed' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, (gobject.TYPE_PYOBJECT,)),
		'switch-added' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, (gobject.TYPE_PYOBJECT,)),
		'switch-removed' : (gobject.SIGNAL_NO_HOOKS, gobject.TYPE_NONE, (gobject.TYPE_PYOBJECT,)),
	}
	def __new__(cls):
		if not Manager.__inst:
			return super(Manager, cls).__new__(cls)

		return Manager.__inst
	
	def __init__(self):
		if not Manager.__inst:
			gobject.GObject.__init__(self)
			Manager.__inst = self
			self.devices = []
			self.state = True
			dbus.SystemBus().watch_name_owner("org.freedesktop.Hal", self.hal_name_owner_changed)

	def hal_name_owner_changed(self, owner):
		for dev in self.devices:
			self.emit("switch-removed", dev)
		self.devices = []
		if owner != "":
			self.Hal = HalManager()
			self.__enumerate()
		else:
			self.Hal = None

	def __enumerate(self):
		self.state = True
	
		devs = self.Hal.FindDeviceByCapability("killswitch")
		for dev in devs:
			try:
				sw = KillSwitch(dev)
				self.devices.append(sw)
				self.state &= sw.GetPower()
				self.emit("switch-added", sw)
			except WrongType:
				pass
				
	def SetGlobalState(self, state):
		dprint("Setting killswitches to", state)

		for dev in self.devices:
			print "Setting", dev.udi, "to", state
			dev.SetPower(state)
		if len(self.devices) == 0:
			self.state = True
		else:
			self.state = state

		
	def GetGlobalState(self):
		try:
			self.state &= self.devices[0]
		except:
			return self.state
		else:
			return self.state


