VERSION="1.21"
PACKAGE="blueman"
WEBSITE="http://blueman-project.org"
PREFIX="/usr"
BIN_DIR="/usr/bin"
ICON_PATH = "/usr/share/blueman/icons"
UI_PATH = "/usr/share/blueman/ui"
OBEX_BROWSE_AVAILABLE = True
DHCP_CONFIG_FILE = "/etc/dhcp3/dhcpd.conf"
POLKIT = "yes" == "yes"
HAL_ENABLED = "no" == "yes"

DEF_BROWSE_COMMAND = "nautilus --browser obex://[%d]"

import os
import gettext
import __builtin__

translation = gettext.translation("blueman", "/usr/share/locale", fallback=True)
translation.install(unicode=True)
__builtin__.ngettext = translation.ungettext

if os.path.exists("../apps") and os.path.exists("../data"):
	BIN_DIR = "./"
	ICON_PATH = "../data/icons"
	UI_PATH = "../data/ui"
