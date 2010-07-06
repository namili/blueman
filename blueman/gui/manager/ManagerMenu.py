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
import blueman.bluez as Bluez
from blueman.Functions import *
from blueman.gui.manager.ManagerDeviceMenu import ManagerDeviceMenu
from blueman.gui.manager.ManagerProgressbar import ManagerProgressbar
from blueman.Functions import adapter_path_to_name
from blueman.gui.CommonUi import *

class ManagerMenu:

	def __init__(self, blueman):
		self.blueman = blueman
		
		self.Menubar = blueman.Builder.get_object("menu")
		
		self.adapter_items = []
		self.Search = None
		
		self.item_adapter = gtk.MenuItem(_("_Adapter"))
		self.item_device = gtk.MenuItem(_("_Device"))
		self.item_device.connect("activate", self.on_device_activate)
		
		self.item_view = gtk.MenuItem(_("_View"))
		self.item_help = gtk.MenuItem(_("_Help"))
		
		self.Menubar.append(self.item_adapter)
		self.Menubar.append(self.item_device)
		self.Menubar.append(self.item_view)
		self.Menubar.append(self.item_help)
		
		
		help_menu = gtk.Menu()
		
		self.item_help.set_submenu(help_menu)
		help_menu.show()
		
		item = create_menuitem(_("Get Help Online..."), get_icon("gnome-help", 16))
		item.connect("activate", lambda x: spawn(["xdg-open", WEBSITE+"/forum"], True))
		help_menu.append(item)
		item.show()
		
		item = create_menuitem(_("Translate This Application..."), get_icon("config-language", 16))
		item.connect("activate", lambda x: spawn(["xdg-open", "https://translations.launchpad.net/blueman"], True))
		help_menu.append(item)
		item.show()
		
		item = create_menuitem(_("Report a Problem"), get_icon("gtk-dialog-warning", 16))
		item.connect("activate", lambda x: spawn(["xdg-open", "https://bugs.launchpad.net/blueman"], True))
		help_menu.append(item)
		item.show()
		
		item = gtk.SeparatorMenuItem()
		help_menu.append(item)
		item.show()
		
		item = gtk.ImageMenuItem("gtk-about")
		item.connect("activate", lambda x: show_about_dialog('Blueman '+_('Device Manager')))
		help_menu.append(item)
		item.show()
		
		view_menu = gtk.Menu()
		self.item_view.set_submenu(view_menu)
		view_menu.show()
		
		item = gtk.CheckMenuItem(_("Show Toolbar"))
		if self.blueman.Config.props.show_toolbar == None:
			item.props.active = True
		else:
			if not self.blueman.Config.props.show_toolbar:
				item.props.active = False
			else:
				item.props.active = True
		item.connect("activate", lambda x: setattr(self.blueman.Config.props, "show_toolbar", x.props.active))
		view_menu.append(item)
		item.show()
		
		item = gtk.CheckMenuItem(_("Show Statusbar"))
		if self.blueman.Config.props.show_statusbar == None:
			item.props.active = True
		else:
			if not self.blueman.Config.props.show_statusbar:
				item.props.active = False
			else:
				item.props.active = True
		item.connect("activate", lambda x: setattr(self.blueman.Config.props, "show_statusbar", x.props.active))
		view_menu.append(item)
		item.show()
		
		item = gtk.SeparatorMenuItem()
		view_menu.append(item)
		item.show()
		
		itemf = gtk.RadioMenuItem(None, _("Latest Device First"))
		view_menu.append(itemf)
		itemf.show()
		
		iteml = gtk.RadioMenuItem(itemf, _("Latest Device Last"))
		view_menu.append(iteml)
		iteml.show()
		
		if self.blueman.Config.props.latest_last:
			iteml.props.active = True
		else:
			itemf.props.active = True
		itemf.connect("activate",  lambda x: setattr(self.blueman.Config.props, "latest_last", not x.props.active))
		iteml.connect("activate",  lambda x: setattr(self.blueman.Config.props, "latest_last", x.props.active))
		
		self.item_adapter.show()
		self.item_view.show()
		self.item_help.show()
		self.item_device.show()
		self.item_device.props.sensitive = False
		
		blueman.List.connect("adapter-added", self.on_adapter_added)
		blueman.List.connect("adapter-removed", self.on_adapter_removed)
		blueman.List.connect("adapter-property-changed", self.on_adapter_property_changed)
		blueman.List.connect("device-selected", self.on_device_selected)
		blueman.List.connect("adapter-changed", self.on_adapter_changed)
		
		self.adapters = blueman.List.Manager.ListAdapters()
		
		self.on_adapter_changed(blueman.List, blueman.List.GetAdapterPath())
		
		self.device_menu = None
		
	def on_device_activate(self, item):
		if self.device_menu:
			device = self.blueman.List.GetSelectedDevice()
			if not self.device_menu.SelectedDevice or device.Address != self.device_menu.SelectedDevice.Address:
				gobject.idle_add(self.device_menu.Generate, priority=gobject.PRIORITY_HIGH)

	def on_device_selected(self, List, device, iter):
		if iter and device:
			self.item_device.props.sensitive = True

			if self.device_menu == None:
				self.device_menu = ManagerDeviceMenu(self.blueman)
				self.item_device.set_submenu(self.device_menu)
		
		else:
			self.item_device.props.sensitive = False


	def on_adapter_property_changed(self, list, adapter, kv):
		(key, value) = kv
		if key == "Name":
			self.generate_adapter_menu()
		elif key == "Discovering":
			if self.Search:
				if value:
					self.Search.props.sensitive = False
				else:
					self.Search.props.sensitive = True
		
	def generate_adapter_menu(self):
		menu = gtk.Menu()
		
		sep = gtk.SeparatorMenuItem()
		sep.show()
		menu.append(sep)
		
		settings = gtk.ImageMenuItem("gtk-preferences")
		settings.connect("activate", lambda x: self.blueman.adapter_properties())
		settings.show()
		menu.append(settings)
		
		group = None
		for adapter in self.adapters:
			props = adapter.GetProperties()
			item = gtk.RadioMenuItem(group, props["Name"])
			if group == None:
				group = item
			
			item.connect("activate", self.on_adapter_selected, adapter.GetObjectPath())
			if adapter.GetObjectPath() == self.blueman.List.Adapter.GetObjectPath():
				item.props.active = True
			
			item.show()
			menu.prepend(item)
		
		sep = gtk.SeparatorMenuItem()
		sep.show()
		menu.prepend(sep)
		
		item = create_menuitem(_("Search"), get_icon("gtk-find", 16))
		item.connect("activate", lambda x: self.blueman.inquiry())
		item.show()
		menu.prepend(item)
		self.Search = item
		
		
		m = self.item_adapter.get_submenu()
		if m != None:
			m.deactivate()
		self.item_adapter.set_submenu(menu)

		sep = gtk.SeparatorMenuItem()
		sep.show()
		menu.append(sep)		

		item = gtk.ImageMenuItem("gtk-quit")
		item.connect("activate", lambda x: gtk.main_quit())
		item.show()
		menu.append(item)
		
	def on_adapter_selected(self, menuitem, adapter_path):
		if menuitem.props.active:
			if adapter_path != self.blueman.List.Adapter.GetObjectPath():
				dprint("selected", adapter_path)
				self.blueman.Config.props.last_adapter = adapter_path_to_name(adapter_path)
				self.blueman.List.SetAdapter(adapter_path)
		
		
		
	def on_adapter_added(self, device_list, adapter_path):
		self.adapters.append(Bluez.Adapter(adapter_path))
		self.generate_adapter_menu()
		
	def on_adapter_removed(self, device_list, adapter_path):
		for adapter in self.adapters:
			if adapter.GetObjectPath() == adapter_path:
				self.adapters.remove(adapter)
		self.generate_adapter_menu()
		
	def on_adapter_changed(self, List, path):
		if path == None:
			self.item_adapter.props.sensitive = False
		else:
			self.item_adapter.props.sensitive = True
			self.generate_adapter_menu()
		

