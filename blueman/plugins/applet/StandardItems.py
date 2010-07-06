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
from blueman.Functions import *
from blueman.plugins.AppletPlugin import AppletPlugin
from blueman.gui.CommonUi import show_about_dialog
from blueman.gui.applet.PluginDialog import PluginDialog

import gobject
import gtk

class StandardItems(AppletPlugin):
	__depends__ = ["StatusIcon", "Menu", "PowerManager"]
	__unloadable__ = False
	
	def on_load(self, applet):
		self.Applet = applet
		
		applet.Plugins.Menu.Register(self, gtk.SeparatorMenuItem(), 21)
		
		self.new_dev = create_menuitem(_("_Setup new device")+"...", get_icon("gtk-new", 16))
		self.new_dev.connect("activate", self.on_setup_new)
		
		self.Applet.Plugins.Menu.Register(self, self.new_dev, 30)
		
		self.Applet.Plugins.Menu.Register(self, gtk.SeparatorMenuItem(), 31)
		
		self.send = create_menuitem(_("Send _files to device")+"...", get_icon("blueman-send-file", 16))
		self.send.connect("activate", self.on_send)

		self.Applet.Plugins.Menu.Register(self, self.send, 40)

		self.browse = create_menuitem(_("_Browse files on device")+"...", get_icon("gtk-open", 16))
		self.browse.connect("activate", self.on_browse)
		
		self.Applet.Plugins.Menu.Register(self, self.browse, 50)
		
		self.Applet.Plugins.Menu.Register(self, gtk.SeparatorMenuItem(), 51)
		

		self.devices = gtk.MenuItem(_("_Devices")+"...")
		self.devices.connect("activate", self.on_devices)
		
		self.Applet.Plugins.Menu.Register(self, self.devices, 60)
		
		self.adapters = create_menuitem(_("Adap_ters")+"...", get_icon("blueman-device", 16))
		self.adapters.connect("activate", self.on_adapters)
		
		self.Applet.Plugins.Menu.Register(self, self.adapters, 70)
		
		self.services = create_menuitem(_("_Local Services")+"...", get_icon("gtk-preferences", 16))
		self.services.connect("activate", self.on_local_services)
		
		self.Applet.Plugins.Menu.Register(self, self.services, 80)
		
		self.Applet.Plugins.Menu.Register(self, gtk.SeparatorMenuItem(), 81)
		
		about = gtk.ImageMenuItem(gtk.STOCK_ABOUT)
		self.Applet.Plugins.Menu.Register(self, about, 90)
		
		self.plugins = create_menuitem(_("_Plugins"), get_icon("blueman-plugin", 16))
		self.plugins.connect("activate", self.on_plugins)
		
		self.Applet.Plugins.Menu.Register(self, self.plugins, 85)
		
		about.connect("activate", self.on_about)
		
		def on_activate(status_icon):
			self.on_devices(None)
			
			
		
		self.Applet.Plugins.StatusIcon.connect("activate", on_activate)
		
	def change_sensitivity(self, sensitive):
		dprint(sensitive, self.Applet.Plugins.PowerManager.GetBluetoothStatus())
		sensitive = sensitive and self.Applet.Manager and self.Applet.Plugins.PowerManager.GetBluetoothStatus() 
		self.new_dev.props.sensitive = sensitive
		self.send.props.sensitive = sensitive
		self.browse.props.sensitive = sensitive
		self.devices.props.sensitive = sensitive
		self.adapters.props.sensitive = sensitive
		
	def on_manager_state_changed(self, state):
		self.change_sensitivity(state)
		
	def on_bluetooth_power_state_changed(self, state):
		self.change_sensitivity(state)
	
	
	def on_setup_new(self, menu_item):
		sn = startup_notification("Bluetooth Assistant", _("Starting Bluetooth Assistant"), bin_name="blueman-assistant", icon="blueman")
		spawn("blueman-assistant", sn=sn)
		
	def on_send(self, menu_item):
		sn = startup_notification("Blueman Sendto", _("Starting File Sender"), bin_name="blueman-sendto", icon="blueman")
		spawn("blueman-sendto", sn=sn)
		
	def on_browse(self, menu_item):
		sn = startup_notification("Blueman Browse", _("Starting File Browser"), bin_name="blueman-browse", icon="blueman")
		spawn("blueman-browse", sn=sn)
		
	def on_devices(self, menu_item):
		sn = startup_notification("Blueman Manager", _("Starting Device Manager"), bin_name="blueman-manger", icon="blueman")
		spawn("blueman-manager", sn=sn)
		
	def on_adapters(self, menu_item):
		sn = startup_notification("Blueman Adapters", _("Starting Adapter Preferences"), bin_name="blueman-adapters", icon="blueman")
		spawn("blueman-adapters", sn=sn)
		
	def on_local_services(self, menu_item):
		sn = startup_notification("Blueman Services", _("Starting Service Preferences"), bin_name="blueman-services", icon="blueman")
		spawn("blueman-services", sn=sn)
		
	def on_about(self, menu_item):
		about = show_about_dialog("Blueman "+_("applet"), run=False)
		
		button = gtk.Button(_("Plugins"))
		button.set_image(gtk.image_new_from_icon_name("blueman-plugin", gtk.ICON_SIZE_BUTTON))
		button.show()
		
		button.connect("clicked", self.on_plugins)
		
		about.action_area.pack_start(button)
		about.action_area.reorder_child(button, 0)
		
		about.run()
		about.destroy()
		
	def on_plugins(self, button):
		dialog = PluginDialog(self.Applet)
		dialog.run()
		dialog.destroy()
		
		
				
