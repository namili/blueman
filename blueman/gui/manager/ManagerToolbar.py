from blueman.Functions import dprint# Copyright (C) 2008 Valmantas Paliksa <walmis at balticum-tv dot lt>
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
from blueman.Sdp import *

class ManagerToolbar:

	def __init__(self, blueman):
		self.blueman = blueman
		
		self.blueman.List.connect("device-selected", self.on_device_selected)
		self.blueman.List.connect("device-property-changed", self.on_device_propery_changed)
		self.blueman.List.connect("adapter-changed", self.on_adapter_changed)
		self.blueman.List.connect("adapter-property-changed", self.on_adapter_property_changed)
		
		#toolbar = blueman.Builder.get_object("toolbar2")
		#for c in toolbar.get_children():
		#	c.set_expand(True)
		
		self.b_search = blueman.Builder.get_object("b_search")
		self.b_search.connect("clicked", lambda button: blueman.inquiry())
		
		self.b_bond = blueman.Builder.get_object("b_bond")
		self.b_bond.connect("clicked", self.on_action, self.blueman.bond)
		
		self.b_trust = blueman.Builder.get_object("b_trust")
		self.b_trust.connect("clicked", self.on_action, self.blueman.toggle_trust)
		self.b_trust.set_homogeneous(False)
		
		self.b_trust.props.label = _("Untrust")
		size = self.b_trust.size_request()
		self.b_trust.props.label = _("Trust")
		size2 = self.b_trust.size_request()
		
		self.b_trust.props.width_request = max(size[0], size2[0])
		
		
		self.b_remove = blueman.Builder.get_object("b_remove")
		self.b_remove.connect("clicked", self.on_action, self.blueman.remove)
		
		self.b_add = blueman.Builder.get_object("b_add")
		self.b_add.connect("clicked", self.on_action, self.blueman.add_device)
		
		self.b_setup = blueman.Builder.get_object("b_setup")
		self.b_setup.connect("clicked", self.on_action, self.blueman.setup)
		self.b_setup.set_homogeneous(False)
		
		self.b_send = blueman.Builder.get_object("b_send")
		self.b_send.props.sensitive = False
		self.b_send.connect("clicked", self.on_action, self.blueman.send)
		self.b_send.set_homogeneous(False)
		
		self.b_browse = blueman.Builder.get_object("b_browse")
		self.b_browse.props.sensitive = False
		self.b_browse.connect("clicked", self.on_action, self.blueman.browse)
		#self.b_browse.set_homogeneous(False)
		
		self.on_adapter_changed(blueman.List, blueman.List.GetAdapterPath())
		
	def on_action(self, button, func):
		device = self.blueman.List.GetSelectedDevice()
		if device != None:
			func(device)

		
		
	def on_adapter_property_changed(self, List, adapter, (key, value)):
		if key == "Discovering":
			if value:
				self.b_search.props.sensitive = False
			else:
				self.b_search.props.sensitive = True
		
	def on_adapter_changed(self, list, adapter_path):
		dprint("toolbar adapter", adapter_path)
		if adapter_path == None:
			self.b_search.props.sensitive = False
			self.update_send_browse(None)
		else:
			self.b_search.props.sensitive = True
		
	def on_device_selected(self, dev_list, device, iter):
		if device == None or iter == None:
			self.b_bond.props.sensitive = False
			self.b_remove.props.sensitive = False
			self.b_trust.props.sensitive = False
			self.b_setup.props.sensitive = False
			self.b_add.props.sensitive = False
		else:
			row = dev_list.get(iter, "bonded", "trusted", "fake")
			self.b_setup.props.sensitive = True
			if row["bonded"]:
				self.b_bond.props.sensitive = False
			else:
				self.b_bond.props.sensitive = True
			
			if row["trusted"]:
				self.b_trust.props.sensitive = True
				self.b_trust.props.icon_name = "blueman-untrust"
				self.b_trust.props.label = _("Untrust")

			else:
				self.b_trust.props.sensitive = True
				self.b_trust.props.icon_name = "blueman-trust"
				self.b_trust.props.label = _("Trust")				
			
			if row["fake"]:
				self.b_remove.props.sensitive = False
				self.b_add.props.sensitive = True
				self.b_trust.props.sensitive = False
				self.b_bond.props.sensitive = True
			else:
				self.b_remove.props.sensitive = True
				self.b_add.props.sensitive = False
				
		self.update_send_browse(device)
			
	def update_send_browse(self, device):
		self.b_send.props.sensitive = False
		self.b_browse.props.sensitive = False
		if device != None and not device.Fake:
			for uuid in device.UUIDs:
				uuid16 = uuid128_to_uuid16(uuid)
				if uuid16 == OBEX_OBJPUSH_SVCLASS_ID:
					self.b_send.props.sensitive = True

				if uuid16 == OBEX_FILETRANS_SVCLASS_ID:
					self.b_browse.props.sensitive = True
		if device and device.Fake:
			self.b_send.props.sensitive = True
			
			
	def on_device_propery_changed(self, dev_list, device, iter, (key, value)):
		if dev_list.compare(iter, dev_list.selected()):
			if key == "Trusted" or key == "Paired":
				self.on_device_selected(dev_list, device, iter)
				
			elif key == "Fake":
				self.on_device_selected(dev_list, device, iter)
				self.update_send_browse(device)

			elif key == "UUIDs":
				self.update_send_browse(device)
				
		
		
