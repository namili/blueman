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

import gtk
from blueman.Constants import *
from blueman.plugins.ServicePlugin import ServicePlugin

import blueman.main.NetConf as NetConf
from blueman.main.Config import Config
from blueman.main.Mechanism import Mechanism
from blueman.main.AppletService import AppletService
from random import randint

class Network(ServicePlugin):
	__plugin_info__ = (_("Network"), "gtk-network")
	def on_load(self, container):
		
		self.Builder = gtk.Builder()
		self.Builder.set_translation_domain("blueman")
		self.Builder.add_from_file(UI_PATH +"/services-network.ui")
		self.widget = self.Builder.get_object("network")
		
		self.ignored_keys = []
		
		container.pack_start(self.widget)
		self.setup_network()
		
		return (_("Network"), "gtk-network")
		
	def on_enter(self):
		self.widget.props.visible = True
		
	def on_leave(self):
		self.widget.props.visible = False

	def on_property_changed(self, netconf, key, value):
		dprint(self.ignored_keys)
		if key in self.ignored_keys:
			self.ignored_keys.remove(key)
			return
		if key == "rb_blueman" or key == "dhcp_client":
			if value:
				self.Builder.get_object("rb_blueman").props.active = True
			else:
				self.Builder.get_object("rb_nm").props.active = True
			return
		if key == "rb_nm":
			return
		
		if key == "gn_enable":
			self.Builder.get_object(key).props.active = value
			return
		
		if key == "nap_enable":
			dprint("nap_enable", value)
			self.Builder.get_object(key).props.active = value
			nap_frame = self.Builder.get_object("nap_frame")
			if value:
				nap_frame.props.sensitive = True
			else:
				nap_frame.props.sensitive = False
		
		if key == "ip":
			self.option_changed_notify(key, False)
		else:
			self.option_changed_notify(key)
	
	def on_apply(self):

		if self.on_query_apply_state() == True:
			dprint("network apply")
			

			m = Mechanism()
			nap_enable = self.Builder.get_object("nap_enable")
			if nap_enable.props.active:
				
				r_dnsmasq = self.Builder.get_object("r_dnsmasq")
				if r_dnsmasq.props.active:
					stype = "dnsmasq"
				else:
					stype = "dhcpd"
				
				net_ip = self.Builder.get_object("net_ip")
				net_nat = self.Builder.get_object("net_nat")
				
				try:
					m.NetworkSetup(net_ip.props.text, net_nat.props.active, stype)
					if not self.NetConf.props.nap_enable: #race condition workaround
						self.ignored_keys.append("nap_enable")
					self.NetConf.props.nap_enable = True
				except Exception, e:
					lines = str(e).splitlines()
					
					d = gtk.MessageDialog( None, buttons=gtk.BUTTONS_OK, type=gtk.MESSAGE_ERROR)
					d.props.icon_name = "gtk-dialog-error"
					d.props.text = _("Failed to apply network settings")
					d.props.secondary_text = lines[-1]
					d.run()
					d.destroy()
					return
			else:
				if self.NetConf.props.nap_enable: #race condition workaround
					self.ignored_keys.append("nap_enable")
				self.NetConf.props.nap_enable = False
				m.NetworkSetup("0",0,"0")
				#disable
			
			self.clear_options()

	
	def on_query_apply_state(self):
		changed = False
		opts = self.get_options()
		if opts == []:
			return False
		else:
			if "ip" in opts:
				if not NetConf.ip_chk(self.Builder.get_object("net_ip").props.text):
					return -1
					
			return True

			
	def setup_network(self):
		self.NetConf = Config("network")
		self.NetConf.connect("property-changed", self.on_property_changed)

		gn_enable = self.Builder.get_object("gn_enable")
		nap_enable = self.Builder.get_object("nap_enable")
		r_dnsmasq = self.Builder.get_object("r_dnsmasq")
		r_dhcpd = self.Builder.get_object("r_dhcpd")
		net_ip = self.Builder.get_object("net_ip")
		net_nat = self.Builder.get_object("net_nat")
		rb_nm = self.Builder.get_object("rb_nm")
		rb_blueman = self.Builder.get_object("rb_blueman")
		rb_dun_nm = self.Builder.get_object("rb_dun_nm")
		rb_dun_blueman = self.Builder.get_object("rb_dun_blueman")
				
		nap_frame = self.Builder.get_object("nap_frame")
		warning = self.Builder.get_object("warning")
		
		rb_blueman.props.active = self.NetConf.props.dhcp_client
		nap_enable.props.active = self.NetConf.props.nap_enable
		gn_enable.props.active = self.NetConf.props.gn_enable
		
		net_ip.props.text = "10.%d.%d.1" % (randint(0, 255), randint(0, 255))
		
		if not self.NetConf.props.nap_enable:
			nap_frame.props.sensitive = False
			
		ns = NetConf.netstatus()
		if ns["ip"] != '0':
			net_ip.props.text = ns["ip"]
			#if not self.NetConf.props.nap_enable:
			#	self.ignored_keys.append("nap_enable")
			self.NetConf.props.nap_enable = True

		
		if ns["masq"] != 0:
			net_nat.props.active = ns["masq"]
			
		if ns["dhcp"] == 0:
			nap_frame.props.sensitive = False
			nap_enable.props.active = False
			if self.NetConf.props.nap_enable or self.NetConf.props.nap_enable == None:
				self.ignored_keys.append("nap_enable")
			self.NetConf.props.nap_enable = False
			
			
		if ns["type"] != 0:
			if ns["type"] == "dnsmasq":
				r_dnsmasq.props.active = True
			else:
				r_dhcpd.props.active = True

		if not NetConf.have("dnsmasq") and not NetConf.have("dhcpd3"):
			nap_frame.props.sensitive = False
			warning.props.visible = True
			warning.props.sensitive = True
			nap_enable.props.sensitive = False
			if self.NetConf.props.nap_enable or self.NetConf.props.nap_enable == None:
				self.ignored_keys.append("nap_enable")
			self.NetConf.props.nap_enable = False
			
		if not NetConf.have("dnsmasq"):
			r_dnsmasq.props.sensitive = False
			r_dnsmasq.props.active = False
			r_dhcpd.props.active = True
		
		if not NetConf.have("dhcpd3"):
			r_dhcpd.props.sensitive = False
			r_dhcpd.props.active = False
			r_dnsmasq.props.active = True
		
		net_nat.connect("toggled", lambda x: self.on_property_changed(self.NetConf, "nat", x.props.active))
		net_ip.connect("changed", lambda x: self.on_property_changed(self.NetConf, "ip", x.props.text))
		gn_enable.connect("toggled", lambda x: setattr(self.NetConf.props, "gn_enable", x.props.active))
		nap_enable.connect("toggled", lambda x: self.on_property_changed(self.NetConf, "nap_enable", x.props.active))

		applet = AppletService()
		
		avail_plugins = applet.QueryAvailablePlugins()
		active_plugins = applet.QueryPlugins()
		
		def dun_support_toggled(rb, x):
			if HAL_ENABLED:
				if rb.props.active and x == "nm":
					applet.SetPluginConfig("PPPSupport", False)
					applet.SetPluginConfig("NMIntegration", True)
				elif rb.props.active and x == "blueman":
					applet.SetPluginConfig("NMIntegration", False)
					applet.SetPluginConfig("PPPSupport", True)
			else:
				if rb.props.active and x == "nm":
					applet.SetPluginConfig("PPPSupport", False)
					applet.SetPluginConfig("NMDUNSupport", True)
				elif rb.props.active and x == "blueman":
					applet.SetPluginConfig("NMDUNSupport", False)
					applet.SetPluginConfig("PPPSupport", True)				
				
		def pan_support_toggled(rb, x):
			if rb.props.active and x == "nm":
				applet.SetPluginConfig("DhcpClient", False)
				
				if HAL_ENABLED:
					applet.SetPluginConfig("NMIntegration", True)
				else:
					applet.SetPluginConfig("NMPANSupport", True)
					
			elif rb.props.active and x == "blueman":
				if HAL_ENABLED:
					applet.SetPluginConfig("NMIntegration", False)
				else:
					applet.SetPluginConfig("NMPANSupport", False)
					
				applet.SetPluginConfig("DhcpClient", True)		
	
				
		if "PPPSupport" in active_plugins:
			rb_dun_blueman.props.active = True

		if HAL_ENABLED:
			if not "NMIntegration" in avail_plugins:
				rb_dun_nm.props.sensitive = False
				rb_dun_nm.props.tooltip_text = _("Not currently supported with this setup")

				rb_nm.props.sensitive = False
				rb_nm.props.tooltip_text = _("Not currently supported with this setup")
		else:
			if "NMDUNSupport" in avail_plugins:
				rb_dun_nm.props.sensitive = True
			else:
				rb_dun_nm.props.sensitive = False
				rb_dun_nm.props.tooltip_text = _("Not currently supported with this setup")		
			
			if "NMPANSupport" in avail_plugins:
				rb_nm.props.sensitive = True
			else:
				rb_nm.props.sensitive = False
				rb_nm.props.tooltip_text = _("Not currently supported with this setup")
				
			if "NMPANSupport" in active_plugins:
				rb_nm.props.active = True
		
			if "NMDUNSupport" in active_plugins:
				rb_dun_nm.props.active = True		
				
		rb_nm.connect("toggled", pan_support_toggled, "nm")
		rb_blueman.connect("toggled", pan_support_toggled, "blueman")
				
		rb_dun_nm.connect("toggled", dun_support_toggled, "nm")
		rb_dun_blueman.connect("toggled", dun_support_toggled, "blueman")

				
				
				
