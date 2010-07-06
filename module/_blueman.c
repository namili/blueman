/* 0.9.7.2 on Thu Sep 24 13:02:29 2009 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)	PyInt_AsLong(o)
#endif
#ifndef WIN32
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>
#include "malloc.h"
#include "string.h"
#include "bluetooth/bluetooth.h"
#include "bluetooth/hci.h"
#include "bluetooth/hci_lib.h"
#include "bluetooth/rfcomm.h"
#include "libblueman.h"
#include "X11/X.h"
#include "libsn/sn-common.h"
#include "libsn/sn-launcher.h"
#include "stdio.h"
#include "glib-object.h"
#include "pygobject.h"
#include "gdk/gdkx.h"
#include "modem-prober.h"
#include "glib.h"


typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); /*proto*/

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static PyObject *__Pyx_CreateClass(PyObject *bases, PyObject *dict, PyObject *name, char *modname); /*proto*/

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); /*proto*/

static PyObject *__Pyx_GetItemInt(PyObject *o, Py_ssize_t i); /*proto*/

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from _blueman */

struct __pyx_obj_8_blueman_conn_info {
  PyObject_HEAD
  struct conn_info_handles ci;
  int hci;
};

struct __pyx_obj_8_blueman_sn_launcher {
  PyObject_HEAD
  struct SnLauncherContext *ctx;
};



static PyTypeObject *__pyx_ptype_8_blueman_conn_info = 0;
static PyTypeObject *__pyx_ptype_8_blueman_sn_launcher = 0;
static PyObject *__pyx_k25;
static PyObject *__pyx_k27;
static PyObject *__pyx_k29;
static PyObject *__pyx_k30;
static PyObject *__pyx_k32;
static PyObject *__pyx_k34;
__PYX_EXTERN_C DL_EXPORT(struct SnLauncherContext) *GetSnLauncherContext(void); /*proto*/
static void __pyx_f_8_blueman_sn_error_trap_push(SnDisplay *,Display *); /*proto*/
static void __pyx_f_8_blueman_sn_error_trap_pop(SnDisplay *,Display *); /*proto*/


/* Implementation of _blueman */

static char __pyx_k1[] = "Can't allocate memory";
static char __pyx_k2[] = "HCI device open failed";
static char __pyx_k3[] = "Not connected";
static char __pyx_k4[] = "Get connection info failed";
static char __pyx_k5[] = "Read RSSI failed";
static char __pyx_k6[] = "Read transmit power level request failed";
static char __pyx_k7[] = "Read Link quality failed";
static char __pyx_k8[] = "Getting rfcomm list failed";

static PyObject *__pyx_n_ERR_SOCKET_FAILED;
static PyObject *__pyx_n_ERR_CANT_READ_PAGE_TIMEOUT;
static PyObject *__pyx_n_ERR_READ_PAGE_TIMEOUT;
static PyObject *__pyx_n_ERR;
static PyObject *__pyx_n_unknown;
static PyObject *__pyx_n_connected;
static PyObject *__pyx_n_clean;
static PyObject *__pyx_n_bound;
static PyObject *__pyx_n_listening;
static PyObject *__pyx_n_connecting;
static PyObject *__pyx_n_config;
static PyObject *__pyx_n_disconnecting;
static PyObject *__pyx_n_closed;
static PyObject *__pyx_n_RFCOMM_STATES;
static PyObject *__pyx_n_RFCOMM_REUSE_DLC;
static PyObject *__pyx_n_RFCOMM_RELEASE_ONHUP;
static PyObject *__pyx_n_RFCOMM_HANGUP_NOW;
static PyObject *__pyx_n_RFCOMM_TTY_ATTACHED;
static PyObject *__pyx_n_exceptions;
static PyObject *__pyx_n_BridgeException;
static PyObject *__pyx_n_Exception;
static PyObject *__pyx_n___init__;
static PyObject *__pyx_n___str__;
static PyObject *__pyx_n_pan1;
static PyObject *__pyx_n_hci0;
static PyObject *__pyx_n_SpecialDirType;
static PyObject *__pyx_n_DESKTOP;
static PyObject *__pyx_n_DOCUMENTS;
static PyObject *__pyx_n_DOWNLOAD;
static PyObject *__pyx_n_MUSIC;
static PyObject *__pyx_n_PICTURES;
static PyObject *__pyx_n_PUBLIC_SHARE;
static PyObject *__pyx_n_TEMPLATES;
static PyObject *__pyx_n_VIDEOS;

static PyObject *__pyx_k1p;
static PyObject *__pyx_k2p;
static PyObject *__pyx_k3p;
static PyObject *__pyx_k4p;
static PyObject *__pyx_k5p;
static PyObject *__pyx_k6p;
static PyObject *__pyx_k7p;
static PyObject *__pyx_k8p;

static PyObject *__pyx_f_8_blueman_get_net_address(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_get_net_address(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_iface = 0;
  char *__pyx_v_addr;
  PyObject *__pyx_r;
  int __pyx_1;
  char *__pyx_2;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {"iface",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_iface)) return 0;
  Py_INCREF(__pyx_v_iface);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":93 */
  if (PyObject_Cmp(__pyx_v_iface, Py_None, &__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
  __pyx_1 = __pyx_1 != 0;
  if (__pyx_1) {

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":94 */
    __pyx_2 = PyString_AsString(__pyx_v_iface); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 94; goto __pyx_L1;}
    __pyx_v_addr = get_net_address(__pyx_2);

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":95 */
    __pyx_1 = (__pyx_v_addr == NULL);
    if (__pyx_1) {
      Py_INCREF(Py_None);
      __pyx_r = Py_None;
      goto __pyx_L0;
      goto __pyx_L3;
    }
    /*else*/ {
      __pyx_3 = PyString_FromString(__pyx_v_addr); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 98; goto __pyx_L1;}
      __pyx_r = __pyx_3;
      __pyx_3 = 0;
      goto __pyx_L0;
    }
    __pyx_L3:;
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.get_net_address");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_iface);
  return __pyx_r;
}

static PyObject *__pyx_n_append;
static PyObject *__pyx_n_id;
static PyObject *__pyx_n_channel;
static PyObject *__pyx_n_flags;
static PyObject *__pyx_n_state;
static PyObject *__pyx_n_src;
static PyObject *__pyx_n_dst;


static PyObject *__pyx_f_8_blueman_rfcomm_list(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_rfcomm_list(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  struct rfcomm_dev_list_req *__pyx_v_dl;
  char __pyx_v_src[18];
  char __pyx_v_dst[18];
  PyObject *__pyx_v_res;
  PyObject *__pyx_v_devs;
  PyObject *__pyx_v_i;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  long __pyx_4;
  unsigned short __pyx_5;
  Py_ssize_t __pyx_6;
  PyObject *__pyx_7 = 0;
  PyObject *__pyx_8 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  __pyx_v_res = Py_None; Py_INCREF(Py_None);
  __pyx_v_devs = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":138 */
  __pyx_1 = PyInt_FromLong(get_rfcomm_list((&__pyx_v_dl))); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 138; goto __pyx_L1;}
  Py_DECREF(__pyx_v_res);
  __pyx_v_res = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":139 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 139; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_res, __pyx_1, &__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 139; goto __pyx_L1;}
  __pyx_2 = __pyx_2 < 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_ERR); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 140; goto __pyx_L1;}
    __pyx_3 = PyObject_GetItem(__pyx_1, __pyx_v_res); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 140; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(PyExc_Exception, __pyx_3, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 140; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":142 */
  __pyx_1 = PyList_New(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 142; goto __pyx_L1;}
  Py_DECREF(__pyx_v_devs);
  __pyx_v_devs = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":143 */
  __pyx_5 = __pyx_v_dl->dev_num;
  for (__pyx_4 = 0; __pyx_4 < __pyx_5; ++__pyx_4) {
    __pyx_3 = PyInt_FromLong(__pyx_4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 143; goto __pyx_L1;}
    Py_DECREF(__pyx_v_i);
    __pyx_v_i = __pyx_3;
    __pyx_3 = 0;

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":144 */
    __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 144; goto __pyx_L1;}
    ba2str((&(__pyx_v_dl->dev_info[__pyx_6]).src),__pyx_v_src);

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":145 */
    __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 145; goto __pyx_L1;}
    ba2str((&(__pyx_v_dl->dev_info[__pyx_6]).dst),__pyx_v_dst);

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":147 */
    __pyx_1 = PyObject_GetAttr(__pyx_v_devs, __pyx_n_append); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; goto __pyx_L1;}
    __pyx_3 = PyDict_New(); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    __pyx_7 = PyInt_FromLong((__pyx_v_dl->dev_info[__pyx_6]).id); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    if (PyDict_SetItem(__pyx_3, __pyx_n_id, __pyx_7) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; goto __pyx_L1;}
    __pyx_7 = PyInt_FromLong((__pyx_v_dl->dev_info[__pyx_6]).channel); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 149; goto __pyx_L1;}
    if (PyDict_SetItem(__pyx_3, __pyx_n_channel, __pyx_7) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 150; goto __pyx_L1;}
    __pyx_7 = PyLong_FromUnsignedLong((__pyx_v_dl->dev_info[__pyx_6]).flags); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 150; goto __pyx_L1;}
    if (PyDict_SetItem(__pyx_3, __pyx_n_flags, __pyx_7) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    __pyx_7 = __Pyx_GetName(__pyx_m, __pyx_n_RFCOMM_STATES); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 151; goto __pyx_L1;}
    __pyx_6 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 151; goto __pyx_L1;}
    __pyx_8 = __Pyx_GetItemInt(__pyx_7, (__pyx_v_dl->dev_info[__pyx_6]).state); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 151; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    if (PyDict_SetItem(__pyx_3, __pyx_n_state, __pyx_8) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    Py_DECREF(__pyx_8); __pyx_8 = 0;
    __pyx_7 = PyString_FromString(__pyx_v_src); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 152; goto __pyx_L1;}
    if (PyDict_SetItem(__pyx_3, __pyx_n_src, __pyx_7) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    __pyx_8 = PyString_FromString(__pyx_v_dst); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 154; goto __pyx_L1;}
    if (PyDict_SetItem(__pyx_3, __pyx_n_dst, __pyx_8) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 148; goto __pyx_L1;}
    Py_DECREF(__pyx_8); __pyx_8 = 0;
    __pyx_7 = PyTuple_New(1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_7, 0, __pyx_3);
    __pyx_3 = 0;
    __pyx_8 = PyObject_CallObject(__pyx_1, __pyx_7); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 147; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    Py_DECREF(__pyx_8); __pyx_8 = 0;
  }

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":156 */
  free(__pyx_v_dl);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":158 */
  Py_INCREF(__pyx_v_devs);
  __pyx_r = __pyx_v_devs;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_7);
  Py_XDECREF(__pyx_8);
  __Pyx_AddTraceback("_blueman.rfcomm_list");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_res);
  Py_DECREF(__pyx_v_devs);
  Py_DECREF(__pyx_v_i);
  return __pyx_r;
}

static PyObject *__pyx_n_value;

static PyObject *__pyx_f_8_blueman_15BridgeException___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_8_blueman_15BridgeException___init__ = {"__init__", (PyCFunction)__pyx_f_8_blueman_15BridgeException___init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_8_blueman_15BridgeException___init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_value = 0;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"self","value",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_self, &__pyx_v_value)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_value);
  if (PyObject_SetAttr(__pyx_v_self, __pyx_n_value, __pyx_v_value) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 163; goto __pyx_L1;}

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("_blueman.BridgeException.__init__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_value);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_15BridgeException___str__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_8_blueman_15BridgeException___str__ = {"__str__", (PyCFunction)__pyx_f_8_blueman_15BridgeException___str__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_f_8_blueman_15BridgeException___str__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"self",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_self)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_1 = PyObject_GetAttr(__pyx_v_self, __pyx_n_value); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 166; goto __pyx_L1;}
  __pyx_2 = PyObject_Repr(__pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 166; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("_blueman.BridgeException.__str__");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_create_bridge(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_create_bridge(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_name = 0;
  PyObject *__pyx_v_err;
  PyObject *__pyx_r;
  char *__pyx_1;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"name",0};
  __pyx_v_name = __pyx_k25;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|O", __pyx_argnames, &__pyx_v_name)) return 0;
  Py_INCREF(__pyx_v_name);
  __pyx_v_err = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":171 */
  __pyx_1 = PyString_AsString(__pyx_v_name); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 171; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(_create_bridge(__pyx_1)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 171; goto __pyx_L1;}
  Py_DECREF(__pyx_v_err);
  __pyx_v_err = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":172 */
  __pyx_2 = PyInt_FromLong(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 172; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_err, __pyx_2, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 172; goto __pyx_L1;}
  __pyx_3 = __pyx_3 < 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_BridgeException); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    __pyx_4 = PyNumber_Negative(__pyx_v_err); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    __pyx_3 = PyInt_AsLong(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_4 = PyString_FromString(strerror(__pyx_3)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_4);
    __pyx_4 = 0;
    __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("_blueman.create_bridge");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_err);
  Py_DECREF(__pyx_v_name);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_destroy_bridge(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_destroy_bridge(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_name = 0;
  PyObject *__pyx_v_err;
  PyObject *__pyx_r;
  char *__pyx_1;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"name",0};
  __pyx_v_name = __pyx_k27;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|O", __pyx_argnames, &__pyx_v_name)) return 0;
  Py_INCREF(__pyx_v_name);
  __pyx_v_err = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":176 */
  __pyx_1 = PyString_AsString(__pyx_v_name); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(_destroy_bridge(__pyx_1)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
  Py_DECREF(__pyx_v_err);
  __pyx_v_err = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":177 */
  __pyx_2 = PyInt_FromLong(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 177; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_err, __pyx_2, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 177; goto __pyx_L1;}
  __pyx_3 = __pyx_3 < 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_BridgeException); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    __pyx_4 = PyNumber_Negative(__pyx_v_err); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    __pyx_3 = PyInt_AsLong(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_4 = PyString_FromString(strerror(__pyx_3)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    __pyx_5 = PyTuple_New(1); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_5, 0, __pyx_4);
    __pyx_4 = 0;
    __pyx_4 = PyObject_CallObject(__pyx_2, __pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __Pyx_Raise(__pyx_4, 0, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("_blueman.destroy_bridge");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_err);
  Py_DECREF(__pyx_v_name);
  return __pyx_r;
}

static int __pyx_f_8_blueman_9conn_info___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_8_blueman_9conn_info___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_addr = 0;
  PyObject *__pyx_v_hci_name = 0;
  PyObject *__pyx_v_res;
  int __pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  char *__pyx_4;
  static char *__pyx_argnames[] = {"addr","hci_name",0};
  __pyx_v_hci_name = __pyx_k29;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O|O", __pyx_argnames, &__pyx_v_addr, &__pyx_v_hci_name)) return -1;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_addr);
  Py_INCREF(__pyx_v_hci_name);
  __pyx_v_res = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":188 */
  __pyx_1 = PySequence_GetSlice(__pyx_v_hci_name, 3, PY_SSIZE_T_MAX); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 188; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 188; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_1);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(((PyObject *)(&PyInt_Type)), __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 188; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_3 = PyInt_AsLong(__pyx_1); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 188; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  ((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->hci = __pyx_3;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":189 */
  __pyx_4 = PyString_AsString(__pyx_v_addr); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 189; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(connection_init(((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->hci,__pyx_4,(&((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->ci))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 189; goto __pyx_L1;}
  Py_DECREF(__pyx_v_res);
  __pyx_v_res = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":190 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 190; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_res, __pyx_1, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 190; goto __pyx_L1;}
  __pyx_3 = __pyx_3 < 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_3) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_ERR); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; goto __pyx_L1;}
    __pyx_1 = PyObject_GetItem(__pyx_2, __pyx_v_res); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(PyExc_Exception, __pyx_1, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 191; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("_blueman.conn_info.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF(__pyx_v_res);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_addr);
  Py_DECREF(__pyx_v_hci_name);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_9conn_info_deinit(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_9conn_info_deinit(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);
  connection_close((&((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->ci));

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_9conn_info_get_rssi(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_9conn_info_get_rssi(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char __pyx_v_rssi;
  PyObject *__pyx_v_res;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_res = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":198 */
  __pyx_1 = PyInt_FromLong(connection_get_rssi((&((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->ci),(&__pyx_v_rssi))); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 198; goto __pyx_L1;}
  Py_DECREF(__pyx_v_res);
  __pyx_v_res = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":199 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 199; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_res, __pyx_1, &__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 199; goto __pyx_L1;}
  __pyx_2 = __pyx_2 < 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_ERR); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; goto __pyx_L1;}
    __pyx_3 = PyObject_GetItem(__pyx_1, __pyx_v_res); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(PyExc_Exception, __pyx_3, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 200; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":202 */
  __pyx_1 = PyInt_FromLong(__pyx_v_rssi); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 202; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.conn_info.get_rssi");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_res);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_9conn_info_get_lq(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_9conn_info_get_lq(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  unsigned char __pyx_v_lq;
  PyObject *__pyx_v_res;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_res = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":206 */
  __pyx_1 = PyInt_FromLong(connection_get_lq((&((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->ci),(&__pyx_v_lq))); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 206; goto __pyx_L1;}
  Py_DECREF(__pyx_v_res);
  __pyx_v_res = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":207 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 207; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_res, __pyx_1, &__pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 207; goto __pyx_L1;}
  __pyx_2 = __pyx_2 < 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_2) {
    __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_ERR); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 208; goto __pyx_L1;}
    __pyx_3 = PyObject_GetItem(__pyx_1, __pyx_v_res); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 208; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    __Pyx_Raise(PyExc_Exception, __pyx_3, 0);
    Py_DECREF(__pyx_3); __pyx_3 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 208; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":210 */
  __pyx_1 = PyInt_FromLong(__pyx_v_lq); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 210; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.conn_info.get_lq");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_res);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_9conn_info_get_tpl(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_9conn_info_get_tpl(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_tp = 0;
  char __pyx_v_tpl;
  PyObject *__pyx_v_res;
  PyObject *__pyx_r;
  unsigned char __pyx_1;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  static char *__pyx_argnames[] = {"tp",0};
  __pyx_v_tp = __pyx_k30;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|O", __pyx_argnames, &__pyx_v_tp)) return 0;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_tp);
  __pyx_v_res = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":214 */
  __pyx_1 = PyInt_AsLong(__pyx_v_tp); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(connection_get_tpl((&((struct __pyx_obj_8_blueman_conn_info *)__pyx_v_self)->ci),(&__pyx_v_tpl),__pyx_1)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 214; goto __pyx_L1;}
  Py_DECREF(__pyx_v_res);
  __pyx_v_res = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":215 */
  __pyx_2 = PyInt_FromLong(0); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_res, __pyx_2, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 215; goto __pyx_L1;}
  __pyx_3 = __pyx_3 < 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (__pyx_3) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_ERR); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 216; goto __pyx_L1;}
    __pyx_4 = PyObject_GetItem(__pyx_2, __pyx_v_res); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 216; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(PyExc_Exception, __pyx_4, 0);
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 216; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":218 */
  __pyx_2 = PyInt_FromLong(__pyx_v_tpl); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 218; goto __pyx_L1;}
  __pyx_r = __pyx_2;
  __pyx_2 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("_blueman.conn_info.get_tpl");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_res);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_tp);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_page_timeout(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_page_timeout(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_hci_name = 0;
  PyObject *__pyx_v_dev_id;
  PyObject *__pyx_v_ret;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  static char *__pyx_argnames[] = {"hci_name",0};
  __pyx_v_hci_name = __pyx_k32;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|O", __pyx_argnames, &__pyx_v_hci_name)) return 0;
  Py_INCREF(__pyx_v_hci_name);
  __pyx_v_dev_id = Py_None; Py_INCREF(Py_None);
  __pyx_v_ret = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":221 */
  __pyx_1 = PySequence_GetSlice(__pyx_v_hci_name, 3, PY_SSIZE_T_MAX); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 221; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 221; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_1);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(((PyObject *)(&PyInt_Type)), __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 221; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_dev_id);
  __pyx_v_dev_id = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":222 */
  __pyx_3 = PyInt_AsLong(__pyx_v_dev_id); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 222; goto __pyx_L1;}
  __pyx_2 = PyFloat_FromDouble(get_page_timeout(__pyx_3)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 222; goto __pyx_L1;}
  Py_DECREF(__pyx_v_ret);
  __pyx_v_ret = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":223 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 223; goto __pyx_L1;}
  if (PyObject_Cmp(__pyx_v_ret, __pyx_1, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 223; goto __pyx_L1;}
  __pyx_3 = __pyx_3 < 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (__pyx_3) {
    __pyx_2 = __Pyx_GetName(__pyx_m, __pyx_n_ERR); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 224; goto __pyx_L1;}
    __pyx_1 = PyObject_GetItem(__pyx_2, __pyx_v_ret); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 224; goto __pyx_L1;}
    Py_DECREF(__pyx_2); __pyx_2 = 0;
    __Pyx_Raise(PyExc_Exception, __pyx_1, 0);
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 224; goto __pyx_L1;}
    goto __pyx_L2;
  }
  /*else*/ {
    Py_INCREF(__pyx_v_ret);
    __pyx_r = __pyx_v_ret;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("_blueman.page_timeout");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_dev_id);
  Py_DECREF(__pyx_v_ret);
  Py_DECREF(__pyx_v_hci_name);
  return __pyx_r;
}

static PyObject *__pyx_n_err_rx;
static PyObject *__pyx_n_err_tx;
static PyObject *__pyx_n_cmd_tx;
static PyObject *__pyx_n_evt_rx;
static PyObject *__pyx_n_acl_tx;
static PyObject *__pyx_n_acl_rx;
static PyObject *__pyx_n_sco_tx;
static PyObject *__pyx_n_sco_rx;
static PyObject *__pyx_n_byte_rx;
static PyObject *__pyx_n_byte_tx;
static PyObject *__pyx_n_dev_id;
static PyObject *__pyx_n_name;
static PyObject *__pyx_n_bdaddr;
static PyObject *__pyx_n_type;
static PyObject *__pyx_n_features;
static PyObject *__pyx_n_pkt_type;
static PyObject *__pyx_n_link_policy;
static PyObject *__pyx_n_link_mode;
static PyObject *__pyx_n_acl_mtu;
static PyObject *__pyx_n_acl_pkts;
static PyObject *__pyx_n_sco_mtu;
static PyObject *__pyx_n_stat;


static PyObject *__pyx_f_8_blueman_device_info(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_device_info(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_hci_name = 0;
  struct hci_dev_info __pyx_v_di;
  PyObject *__pyx_v_dev_id;
  PyObject *__pyx_v_res;
  char __pyx_v_addr[32];
  PyObject *__pyx_v_feats;
  PyObject *__pyx_v_i;
  PyObject *__pyx_v_x;
  PyObject *__pyx_v_z;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  long __pyx_4;
  Py_ssize_t __pyx_5;
  PyObject *__pyx_6 = 0;
  PyObject *__pyx_7 = 0;
  PyObject *__pyx_8 = 0;
  PyObject *__pyx_9 = 0;
  PyObject *__pyx_10 = 0;
  PyObject *__pyx_11 = 0;
  PyObject *__pyx_12 = 0;
  PyObject *__pyx_13 = 0;
  PyObject *__pyx_14 = 0;
  PyObject *__pyx_15 = 0;
  PyObject *__pyx_16 = 0;
  PyObject *__pyx_17 = 0;
  static char *__pyx_argnames[] = {"hci_name",0};
  __pyx_v_hci_name = __pyx_k34;
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|O", __pyx_argnames, &__pyx_v_hci_name)) return 0;
  Py_INCREF(__pyx_v_hci_name);
  __pyx_v_dev_id = Py_None; Py_INCREF(Py_None);
  __pyx_v_res = Py_None; Py_INCREF(Py_None);
  __pyx_v_feats = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);
  __pyx_v_x = Py_None; Py_INCREF(Py_None);
  __pyx_v_z = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":232 */
  __pyx_1 = PySequence_GetSlice(__pyx_v_hci_name, 3, PY_SSIZE_T_MAX); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 232; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 232; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_1);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(((PyObject *)(&PyInt_Type)), __pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 232; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_v_dev_id);
  __pyx_v_dev_id = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":234 */
  __pyx_3 = PyInt_AsLong(__pyx_v_dev_id); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 234; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(hci_devinfo(__pyx_3,(&__pyx_v_di))); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 234; goto __pyx_L1;}
  Py_DECREF(__pyx_v_res);
  __pyx_v_res = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":237 */
  ba2str((&__pyx_v_di.bdaddr),__pyx_v_addr);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":239 */
  __pyx_1 = PyList_New(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 239; goto __pyx_L1;}
  Py_DECREF(__pyx_v_feats);
  __pyx_v_feats = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":240 */
  for (__pyx_4 = 0; __pyx_4 < 8; ++__pyx_4) {
    __pyx_2 = PyInt_FromLong(__pyx_4); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 240; goto __pyx_L1;}
    Py_DECREF(__pyx_v_i);
    __pyx_v_i = __pyx_2;
    __pyx_2 = 0;
    __pyx_1 = PyObject_GetAttr(__pyx_v_feats, __pyx_n_append); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 241; goto __pyx_L1;}
    __pyx_5 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 241; goto __pyx_L1;}
    __pyx_2 = PyInt_FromLong((__pyx_v_di.features[__pyx_5])); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 241; goto __pyx_L1;}
    __pyx_6 = PyTuple_New(1); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 241; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_6, 0, __pyx_2);
    __pyx_2 = 0;
    __pyx_2 = PyObject_CallObject(__pyx_1, __pyx_6); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 241; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_6); __pyx_6 = 0;
    Py_DECREF(__pyx_2); __pyx_2 = 0;
  }

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":243 */
  __pyx_1 = PyLong_FromUnsignedLong(__pyx_v_di.stat.err_rx); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 243; goto __pyx_L1;}
  __pyx_6 = PyTuple_New(2); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 243; goto __pyx_L1;}
  Py_INCREF(__pyx_n_err_rx);
  PyTuple_SET_ITEM(__pyx_6, 0, __pyx_n_err_rx);
  PyTuple_SET_ITEM(__pyx_6, 1, __pyx_1);
  __pyx_1 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.err_tx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 244; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 244; goto __pyx_L1;}
  Py_INCREF(__pyx_n_err_tx);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_n_err_tx);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.cmd_tx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; goto __pyx_L1;}
  __pyx_7 = PyTuple_New(2); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 245; goto __pyx_L1;}
  Py_INCREF(__pyx_n_cmd_tx);
  PyTuple_SET_ITEM(__pyx_7, 0, __pyx_n_cmd_tx);
  PyTuple_SET_ITEM(__pyx_7, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.evt_rx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 246; goto __pyx_L1;}
  __pyx_8 = PyTuple_New(2); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 246; goto __pyx_L1;}
  Py_INCREF(__pyx_n_evt_rx);
  PyTuple_SET_ITEM(__pyx_8, 0, __pyx_n_evt_rx);
  PyTuple_SET_ITEM(__pyx_8, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.acl_tx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 247; goto __pyx_L1;}
  __pyx_9 = PyTuple_New(2); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 247; goto __pyx_L1;}
  Py_INCREF(__pyx_n_acl_tx);
  PyTuple_SET_ITEM(__pyx_9, 0, __pyx_n_acl_tx);
  PyTuple_SET_ITEM(__pyx_9, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.acl_rx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 248; goto __pyx_L1;}
  __pyx_10 = PyTuple_New(2); if (!__pyx_10) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 248; goto __pyx_L1;}
  Py_INCREF(__pyx_n_acl_rx);
  PyTuple_SET_ITEM(__pyx_10, 0, __pyx_n_acl_rx);
  PyTuple_SET_ITEM(__pyx_10, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.sco_tx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; goto __pyx_L1;}
  __pyx_11 = PyTuple_New(2); if (!__pyx_11) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 249; goto __pyx_L1;}
  Py_INCREF(__pyx_n_sco_tx);
  PyTuple_SET_ITEM(__pyx_11, 0, __pyx_n_sco_tx);
  PyTuple_SET_ITEM(__pyx_11, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.sco_rx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 250; goto __pyx_L1;}
  __pyx_12 = PyTuple_New(2); if (!__pyx_12) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 250; goto __pyx_L1;}
  Py_INCREF(__pyx_n_sco_rx);
  PyTuple_SET_ITEM(__pyx_12, 0, __pyx_n_sco_rx);
  PyTuple_SET_ITEM(__pyx_12, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.byte_rx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 251; goto __pyx_L1;}
  __pyx_13 = PyTuple_New(2); if (!__pyx_13) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 251; goto __pyx_L1;}
  Py_INCREF(__pyx_n_byte_rx);
  PyTuple_SET_ITEM(__pyx_13, 0, __pyx_n_byte_rx);
  PyTuple_SET_ITEM(__pyx_13, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyLong_FromUnsignedLong(__pyx_v_di.stat.byte_tx); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 252; goto __pyx_L1;}
  __pyx_14 = PyTuple_New(2); if (!__pyx_14) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 252; goto __pyx_L1;}
  Py_INCREF(__pyx_n_byte_tx);
  PyTuple_SET_ITEM(__pyx_14, 0, __pyx_n_byte_tx);
  PyTuple_SET_ITEM(__pyx_14, 1, __pyx_2);
  __pyx_2 = 0;
  __pyx_2 = PyList_New(10); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 243; goto __pyx_L1;}
  PyList_SET_ITEM(__pyx_2, 0, __pyx_6);
  PyList_SET_ITEM(__pyx_2, 1, __pyx_1);
  PyList_SET_ITEM(__pyx_2, 2, __pyx_7);
  PyList_SET_ITEM(__pyx_2, 3, __pyx_8);
  PyList_SET_ITEM(__pyx_2, 4, __pyx_9);
  PyList_SET_ITEM(__pyx_2, 5, __pyx_10);
  PyList_SET_ITEM(__pyx_2, 6, __pyx_11);
  PyList_SET_ITEM(__pyx_2, 7, __pyx_12);
  PyList_SET_ITEM(__pyx_2, 8, __pyx_13);
  PyList_SET_ITEM(__pyx_2, 9, __pyx_14);
  __pyx_6 = 0;
  __pyx_1 = 0;
  __pyx_7 = 0;
  __pyx_8 = 0;
  __pyx_9 = 0;
  __pyx_10 = 0;
  __pyx_11 = 0;
  __pyx_12 = 0;
  __pyx_13 = 0;
  __pyx_14 = 0;
  Py_DECREF(__pyx_v_x);
  __pyx_v_x = __pyx_2;
  __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":254 */
  __pyx_6 = PyLong_FromUnsignedLong(__pyx_v_di.dev_id); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 254; goto __pyx_L1;}
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 254; goto __pyx_L1;}
  Py_INCREF(__pyx_n_dev_id);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_n_dev_id);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_6);
  __pyx_6 = 0;
  __pyx_7 = PyString_FromString(__pyx_v_di.name); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 255; goto __pyx_L1;}
  __pyx_8 = PyTuple_New(2); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 255; goto __pyx_L1;}
  Py_INCREF(__pyx_n_name);
  PyTuple_SET_ITEM(__pyx_8, 0, __pyx_n_name);
  PyTuple_SET_ITEM(__pyx_8, 1, __pyx_7);
  __pyx_7 = 0;
  __pyx_9 = PyString_FromString(__pyx_v_addr); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 256; goto __pyx_L1;}
  __pyx_10 = PyTuple_New(2); if (!__pyx_10) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 256; goto __pyx_L1;}
  Py_INCREF(__pyx_n_bdaddr);
  PyTuple_SET_ITEM(__pyx_10, 0, __pyx_n_bdaddr);
  PyTuple_SET_ITEM(__pyx_10, 1, __pyx_9);
  __pyx_9 = 0;
  __pyx_11 = PyLong_FromUnsignedLong(__pyx_v_di.flags); if (!__pyx_11) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 257; goto __pyx_L1;}
  __pyx_12 = PyTuple_New(2); if (!__pyx_12) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 257; goto __pyx_L1;}
  Py_INCREF(__pyx_n_flags);
  PyTuple_SET_ITEM(__pyx_12, 0, __pyx_n_flags);
  PyTuple_SET_ITEM(__pyx_12, 1, __pyx_11);
  __pyx_11 = 0;
  __pyx_13 = PyInt_FromLong(__pyx_v_di.type); if (!__pyx_13) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 258; goto __pyx_L1;}
  __pyx_14 = PyTuple_New(2); if (!__pyx_14) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 258; goto __pyx_L1;}
  Py_INCREF(__pyx_n_type);
  PyTuple_SET_ITEM(__pyx_14, 0, __pyx_n_type);
  PyTuple_SET_ITEM(__pyx_14, 1, __pyx_13);
  __pyx_13 = 0;
  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 259; goto __pyx_L1;}
  Py_INCREF(__pyx_n_features);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_n_features);
  Py_INCREF(__pyx_v_feats);
  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_v_feats);
  __pyx_6 = PyLong_FromUnsignedLong(__pyx_v_di.pkt_type); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 260; goto __pyx_L1;}
  __pyx_7 = PyTuple_New(2); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 260; goto __pyx_L1;}
  Py_INCREF(__pyx_n_pkt_type);
  PyTuple_SET_ITEM(__pyx_7, 0, __pyx_n_pkt_type);
  PyTuple_SET_ITEM(__pyx_7, 1, __pyx_6);
  __pyx_6 = 0;
  __pyx_9 = PyLong_FromUnsignedLong(__pyx_v_di.link_policy); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; goto __pyx_L1;}
  __pyx_11 = PyTuple_New(2); if (!__pyx_11) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 261; goto __pyx_L1;}
  Py_INCREF(__pyx_n_link_policy);
  PyTuple_SET_ITEM(__pyx_11, 0, __pyx_n_link_policy);
  PyTuple_SET_ITEM(__pyx_11, 1, __pyx_9);
  __pyx_9 = 0;
  __pyx_13 = PyLong_FromUnsignedLong(__pyx_v_di.link_mode); if (!__pyx_13) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 262; goto __pyx_L1;}
  __pyx_6 = PyTuple_New(2); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 262; goto __pyx_L1;}
  Py_INCREF(__pyx_n_link_mode);
  PyTuple_SET_ITEM(__pyx_6, 0, __pyx_n_link_mode);
  PyTuple_SET_ITEM(__pyx_6, 1, __pyx_13);
  __pyx_13 = 0;
  __pyx_9 = PyLong_FromUnsignedLong(__pyx_v_di.acl_mtu); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 263; goto __pyx_L1;}
  __pyx_13 = PyTuple_New(2); if (!__pyx_13) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 263; goto __pyx_L1;}
  Py_INCREF(__pyx_n_acl_mtu);
  PyTuple_SET_ITEM(__pyx_13, 0, __pyx_n_acl_mtu);
  PyTuple_SET_ITEM(__pyx_13, 1, __pyx_9);
  __pyx_9 = 0;
  __pyx_9 = PyLong_FromUnsignedLong(__pyx_v_di.acl_pkts); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; goto __pyx_L1;}
  __pyx_15 = PyTuple_New(2); if (!__pyx_15) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 264; goto __pyx_L1;}
  Py_INCREF(__pyx_n_acl_pkts);
  PyTuple_SET_ITEM(__pyx_15, 0, __pyx_n_acl_pkts);
  PyTuple_SET_ITEM(__pyx_15, 1, __pyx_9);
  __pyx_9 = 0;
  __pyx_9 = PyLong_FromUnsignedLong(__pyx_v_di.sco_pkts); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 265; goto __pyx_L1;}
  __pyx_16 = PyTuple_New(2); if (!__pyx_16) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 265; goto __pyx_L1;}
  Py_INCREF(__pyx_n_sco_mtu);
  PyTuple_SET_ITEM(__pyx_16, 0, __pyx_n_sco_mtu);
  PyTuple_SET_ITEM(__pyx_16, 1, __pyx_9);
  __pyx_9 = 0;
  __pyx_9 = PyTuple_New(1); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 266; goto __pyx_L1;}
  Py_INCREF(__pyx_v_x);
  PyTuple_SET_ITEM(__pyx_9, 0, __pyx_v_x);
  __pyx_17 = PyObject_CallObject(((PyObject *)(&PyDict_Type)), __pyx_9); if (!__pyx_17) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 266; goto __pyx_L1;}
  Py_DECREF(__pyx_9); __pyx_9 = 0;
  __pyx_9 = PyTuple_New(2); if (!__pyx_9) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 266; goto __pyx_L1;}
  Py_INCREF(__pyx_n_stat);
  PyTuple_SET_ITEM(__pyx_9, 0, __pyx_n_stat);
  PyTuple_SET_ITEM(__pyx_9, 1, __pyx_17);
  __pyx_17 = 0;
  __pyx_17 = PyList_New(13); if (!__pyx_17) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 254; goto __pyx_L1;}
  PyList_SET_ITEM(__pyx_17, 0, __pyx_1);
  PyList_SET_ITEM(__pyx_17, 1, __pyx_8);
  PyList_SET_ITEM(__pyx_17, 2, __pyx_10);
  PyList_SET_ITEM(__pyx_17, 3, __pyx_12);
  PyList_SET_ITEM(__pyx_17, 4, __pyx_14);
  PyList_SET_ITEM(__pyx_17, 5, __pyx_2);
  PyList_SET_ITEM(__pyx_17, 6, __pyx_7);
  PyList_SET_ITEM(__pyx_17, 7, __pyx_11);
  PyList_SET_ITEM(__pyx_17, 8, __pyx_6);
  PyList_SET_ITEM(__pyx_17, 9, __pyx_13);
  PyList_SET_ITEM(__pyx_17, 10, __pyx_15);
  PyList_SET_ITEM(__pyx_17, 11, __pyx_16);
  PyList_SET_ITEM(__pyx_17, 12, __pyx_9);
  __pyx_1 = 0;
  __pyx_8 = 0;
  __pyx_10 = 0;
  __pyx_12 = 0;
  __pyx_14 = 0;
  __pyx_2 = 0;
  __pyx_7 = 0;
  __pyx_11 = 0;
  __pyx_6 = 0;
  __pyx_13 = 0;
  __pyx_15 = 0;
  __pyx_16 = 0;
  __pyx_9 = 0;
  Py_DECREF(__pyx_v_z);
  __pyx_v_z = __pyx_17;
  __pyx_17 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":268 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 268; goto __pyx_L1;}
  Py_INCREF(__pyx_v_z);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_z);
  __pyx_8 = PyObject_CallObject(((PyObject *)(&PyDict_Type)), __pyx_1); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 268; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_r = __pyx_8;
  __pyx_8 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_6);
  Py_XDECREF(__pyx_7);
  Py_XDECREF(__pyx_8);
  Py_XDECREF(__pyx_9);
  Py_XDECREF(__pyx_10);
  Py_XDECREF(__pyx_11);
  Py_XDECREF(__pyx_12);
  Py_XDECREF(__pyx_13);
  Py_XDECREF(__pyx_14);
  Py_XDECREF(__pyx_15);
  Py_XDECREF(__pyx_16);
  Py_XDECREF(__pyx_17);
  __Pyx_AddTraceback("_blueman.device_info");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_dev_id);
  Py_DECREF(__pyx_v_res);
  Py_DECREF(__pyx_v_feats);
  Py_DECREF(__pyx_v_i);
  Py_DECREF(__pyx_v_x);
  Py_DECREF(__pyx_v_z);
  Py_DECREF(__pyx_v_hci_name);
  return __pyx_r;
}

static void __pyx_f_8_blueman_sn_error_trap_push(SnDisplay *__pyx_v_display,Display *__pyx_v_xdisplay) {
  gdk_error_trap_push();

}

static void __pyx_f_8_blueman_sn_error_trap_pop(SnDisplay *__pyx_v_display,Display *__pyx_v_xdisplay) {
  gdk_error_trap_pop();

}

static PyObject *__pyx_n_gtk;
static PyObject *__pyx_n_gdk;
static PyObject *__pyx_n_DisplayX11;

static PyObject *__pyx_k66p;
static PyObject *__pyx_k67p;

static char __pyx_k66[] = "Display must be a gtk.gdk.DisplayX11";
static char __pyx_k67[] = "GdkDisplay is NULL";

static int __pyx_f_8_blueman_11sn_launcher___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_8_blueman_11sn_launcher___cinit__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_display = 0;
  int __pyx_v_screen;
  PyObject *__pyx_v_gtk;
  GObject *__pyx_v_dpy;
  SnDisplay *__pyx_v_sn_dpy;
  int __pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  static char *__pyx_argnames[] = {"display","screen",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "Oi", __pyx_argnames, &__pyx_v_display, &__pyx_v_screen)) return -1;
  Py_INCREF(__pyx_v_self);
  Py_INCREF(__pyx_v_display);
  __pyx_v_gtk = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":357 */
  __pyx_1 = __Pyx_Import(__pyx_n_gtk, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 357; goto __pyx_L1;}
  Py_DECREF(__pyx_v_gtk);
  __pyx_v_gtk = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":358 */
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 358; goto __pyx_L1;}
  Py_INCREF(__pyx_v_display);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_display);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyType_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 358; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_v_gtk, __pyx_n_gdk); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 358; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_1, __pyx_n_DisplayX11); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 358; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_Cmp(__pyx_2, __pyx_3, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 358; goto __pyx_L1;}
  __pyx_4 = __pyx_4 != 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (__pyx_4) {
    __Pyx_Raise(PyExc_TypeError, __pyx_k66p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 359; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":364 */
  __pyx_v_dpy = pygobject_get(__pyx_v_display);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":366 */
  __pyx_4 = (__pyx_v_dpy != NULL);
  if (__pyx_4) {

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":367 */
    __pyx_v_sn_dpy = sn_display_new(gdk_x11_display_get_xdisplay(((GdkDisplay *)__pyx_v_dpy)),__pyx_f_8_blueman_sn_error_trap_push,__pyx_f_8_blueman_sn_error_trap_pop);

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":368 */
    ((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx = sn_launcher_context_new(__pyx_v_sn_dpy,__pyx_v_screen);

    /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":369 */
    sn_display_unref(__pyx_v_sn_dpy);
    goto __pyx_L3;
  }
  /*else*/ {
    __Pyx_Raise(PyExc_RuntimeError, __pyx_k67p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 371; goto __pyx_L1;}
  }
  __pyx_L3:;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.sn_launcher.__cinit__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF(__pyx_v_gtk);
  Py_DECREF(__pyx_v_self);
  Py_DECREF(__pyx_v_display);
  return __pyx_r;
}

static PyObject *__pyx_k68p;

static char __pyx_k68[] = "SnLauncherContext is NULL";

static void __pyx_f_8_blueman_11sn_launcher___dealloc__(PyObject *__pyx_v_self); /*proto*/
static void __pyx_f_8_blueman_11sn_launcher___dealloc__(PyObject *__pyx_v_self) {
  int __pyx_1;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":375 */
  __pyx_1 = (((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx == NULL);
  if (__pyx_1) {
    __Pyx_Raise(PyExc_RuntimeError, __pyx_k68p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 376; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":377 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("_blueman.sn_launcher.__dealloc__");
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_initiate(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_initiate(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_launcher_name;
  char *__pyx_v_launchee_name;
  Time __pyx_v_timestamp;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"launcher_name","launchee_name","timestamp",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "ssk", __pyx_argnames, &__pyx_v_launcher_name, &__pyx_v_launchee_name, &__pyx_v_timestamp)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":381 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":382 */
  sn_launcher_context_initiate(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_launcher_name,__pyx_v_launchee_name,__pyx_v_timestamp);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":383 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_complete(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_complete(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":386 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":387 */
  sn_launcher_context_complete(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":388 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_get_startup_id(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_get_startup_id(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_ret;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":393 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":394 */
  __pyx_v_ret = sn_launcher_context_get_startup_id(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":395 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":396 */
  __pyx_1 = (__pyx_v_ret != NULL);
  if (__pyx_1) {
    __pyx_2 = PyString_FromString(__pyx_v_ret); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 397; goto __pyx_L1;}
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {
    Py_INCREF(Py_None);
    __pyx_r = Py_None;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("_blueman.sn_launcher.get_startup_id");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_get_initiated(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_get_initiated(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_ret;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  int __pyx_2;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_ret = Py_None; Py_INCREF(Py_None);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":402 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":403 */
  __pyx_1 = PyInt_FromLong(sn_launcher_context_get_initiated(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 403; goto __pyx_L1;}
  __pyx_2 = PyObject_IsTrue(__pyx_1); if (__pyx_2 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 403; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyInt_FromLong(__pyx_2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 403; goto __pyx_L1;}
  Py_DECREF(__pyx_v_ret);
  __pyx_v_ret = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":404 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":405 */
  Py_INCREF(__pyx_v_ret);
  __pyx_r = __pyx_v_ret;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("_blueman.sn_launcher.get_initiated");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_ret);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_setup_child_process(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_setup_child_process(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":408 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":409 */
  sn_launcher_context_setup_child_process(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":410 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_name(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_name(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_name;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"name",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "s", __pyx_argnames, &__pyx_v_name)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":413 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":414 */
  sn_launcher_context_set_name(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_name);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":415 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_description(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_description(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_descr;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"descr",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "s", __pyx_argnames, &__pyx_v_descr)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":418 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":419 */
  sn_launcher_context_set_description(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_descr);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":420 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_workspace(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_workspace(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_workspace;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"workspace",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "i", __pyx_argnames, &__pyx_v_workspace)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":423 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":424 */
  sn_launcher_context_set_workspace(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_workspace);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":425 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_wmclass(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_wmclass(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_klass;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"klass",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "s", __pyx_argnames, &__pyx_v_klass)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":428 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":429 */
  sn_launcher_context_set_wmclass(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_klass);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":430 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_binary_name(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_binary_name(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_name;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"name",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "s", __pyx_argnames, &__pyx_v_name)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":433 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":435 */
  sn_launcher_context_set_binary_name(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_name);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":436 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_icon_name(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_icon_name(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_name;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"name",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "s", __pyx_argnames, &__pyx_v_name)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":439 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":440 */
  sn_launcher_context_set_icon_name(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_name);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":441 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_set_extra_property(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_set_extra_property(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_key;
  char *__pyx_v_value;
  PyObject *__pyx_r;
  static char *__pyx_argnames[] = {"key","value",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "ss", __pyx_argnames, &__pyx_v_key, &__pyx_v_value)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":444 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":445 */
  sn_launcher_context_set_extra_property(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,__pyx_v_key,__pyx_v_value);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":446 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_get_initiated_time(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_get_initiated_time(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  long __pyx_v_tv_sec;
  long __pyx_v_tv_usec;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":449 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":452 */
  sn_launcher_context_get_initiated_time(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,(&__pyx_v_tv_sec),(&__pyx_v_tv_usec));

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":453 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":454 */
  __pyx_1 = PyInt_FromLong(__pyx_v_tv_sec); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 454; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_tv_usec); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 454; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 454; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_r = __pyx_3;
  __pyx_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.sn_launcher.get_initiated_time");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_11sn_launcher_get_last_active_time(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_11sn_launcher_get_last_active_time(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  long __pyx_v_tv_sec;
  long __pyx_v_tv_usec;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":457 */
  sn_launcher_context_ref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":460 */
  sn_launcher_context_get_last_active_time(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx,(&__pyx_v_tv_sec),(&__pyx_v_tv_usec));

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":461 */
  sn_launcher_context_unref(((struct __pyx_obj_8_blueman_sn_launcher *)__pyx_v_self)->ctx);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":462 */
  __pyx_1 = PyInt_FromLong(__pyx_v_tv_sec); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 462; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong(__pyx_v_tv_usec); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 462; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 462; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_1);
  PyTuple_SET_ITEM(__pyx_3, 1, __pyx_2);
  __pyx_1 = 0;
  __pyx_2 = 0;
  __pyx_r = __pyx_3;
  __pyx_3 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.sn_launcher.get_last_active_time");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_callable;

static PyObject *__pyx_k69p;
static PyObject *__pyx_k70p;

static char __pyx_k69[] = "callback must be callable";
static char __pyx_k70[] = "device node must not be None";

static PyObject *__pyx_f_8_blueman_probe_modem(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_probe_modem(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_node = 0;
  PyObject *__pyx_v_callback = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  int __pyx_4;
  int __pyx_5;
  char *__pyx_6;
  static char *__pyx_argnames[] = {"node","callback",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "OO", __pyx_argnames, &__pyx_v_node, &__pyx_v_callback)) return 0;
  Py_INCREF(__pyx_v_node);
  Py_INCREF(__pyx_v_callback);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":471 */
  __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_callable); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  __pyx_2 = PyTuple_New(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_INCREF(__pyx_v_callback);
  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_v_callback);
  __pyx_3 = PyObject_CallObject(__pyx_1, __pyx_2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_4 = PyObject_IsTrue(__pyx_3); if (__pyx_4 < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 471; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  __pyx_5 = (!__pyx_4);
  if (__pyx_5) {
    __Pyx_Raise(PyExc_TypeError, __pyx_k69p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 472; goto __pyx_L1;}
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":474 */
  if (PyObject_Cmp(__pyx_v_node, Py_None, &__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 474; goto __pyx_L1;}
  __pyx_4 = __pyx_4 != 0;
  if (__pyx_4) {
    __pyx_6 = PyString_AsString(__pyx_v_node); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 475; goto __pyx_L1;}
    probe_modem(__pyx_6,__pyx_v_callback);
    goto __pyx_L3;
  }
  /*else*/ {
    __Pyx_Raise(PyExc_TypeError, __pyx_k70p, 0);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 477; goto __pyx_L1;}
  }
  __pyx_L3:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  __Pyx_AddTraceback("_blueman.probe_modem");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_node);
  Py_DECREF(__pyx_v_callback);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_set_probe_debug(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_set_probe_debug(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_enable = 0;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  int __pyx_3;
  static char *__pyx_argnames[] = {"enable",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_enable)) return 0;
  Py_INCREF(__pyx_v_enable);
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; goto __pyx_L1;}
  Py_INCREF(__pyx_v_enable);
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_v_enable);
  __pyx_2 = PyObject_CallObject(((PyObject *)(&PyInt_Type)), __pyx_1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_3 = PyInt_AsLong(__pyx_2); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 480; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  set_probe_debug(__pyx_3);

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("_blueman.set_probe_debug");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_enable);
  return __pyx_r;
}

static PyObject *__pyx_f_8_blueman_get_special_dir(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyObject *__pyx_f_8_blueman_get_special_dir(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_t = 0;
  char *__pyx_v_d;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  static char *__pyx_argnames[] = {"t",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "O", __pyx_argnames, &__pyx_v_t)) return 0;
  Py_INCREF(__pyx_v_t);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":498 */
  __pyx_1 = PyInt_AsLong(__pyx_v_t); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 498; goto __pyx_L1;}
  __pyx_v_d = g_get_user_special_dir(__pyx_1);

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":499 */
  __pyx_1 = (__pyx_v_d == NULL);
  if (__pyx_1) {
    Py_INCREF(Py_None);
    __pyx_r = Py_None;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_2 = PyString_FromString(__pyx_v_d); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 502; goto __pyx_L1;}
    __pyx_r = __pyx_2;
    __pyx_2 = 0;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("_blueman.get_special_dir");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_t);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_BridgeException, "BridgeException"},
  {&__pyx_n_DESKTOP, "DESKTOP"},
  {&__pyx_n_DOCUMENTS, "DOCUMENTS"},
  {&__pyx_n_DOWNLOAD, "DOWNLOAD"},
  {&__pyx_n_DisplayX11, "DisplayX11"},
  {&__pyx_n_ERR, "ERR"},
  {&__pyx_n_ERR_CANT_READ_PAGE_TIMEOUT, "ERR_CANT_READ_PAGE_TIMEOUT"},
  {&__pyx_n_ERR_READ_PAGE_TIMEOUT, "ERR_READ_PAGE_TIMEOUT"},
  {&__pyx_n_ERR_SOCKET_FAILED, "ERR_SOCKET_FAILED"},
  {&__pyx_n_Exception, "Exception"},
  {&__pyx_n_MUSIC, "MUSIC"},
  {&__pyx_n_PICTURES, "PICTURES"},
  {&__pyx_n_PUBLIC_SHARE, "PUBLIC_SHARE"},
  {&__pyx_n_RFCOMM_HANGUP_NOW, "RFCOMM_HANGUP_NOW"},
  {&__pyx_n_RFCOMM_RELEASE_ONHUP, "RFCOMM_RELEASE_ONHUP"},
  {&__pyx_n_RFCOMM_REUSE_DLC, "RFCOMM_REUSE_DLC"},
  {&__pyx_n_RFCOMM_STATES, "RFCOMM_STATES"},
  {&__pyx_n_RFCOMM_TTY_ATTACHED, "RFCOMM_TTY_ATTACHED"},
  {&__pyx_n_SpecialDirType, "SpecialDirType"},
  {&__pyx_n_TEMPLATES, "TEMPLATES"},
  {&__pyx_n_VIDEOS, "VIDEOS"},
  {&__pyx_n___init__, "__init__"},
  {&__pyx_n___str__, "__str__"},
  {&__pyx_n_acl_mtu, "acl_mtu"},
  {&__pyx_n_acl_pkts, "acl_pkts"},
  {&__pyx_n_acl_rx, "acl_rx"},
  {&__pyx_n_acl_tx, "acl_tx"},
  {&__pyx_n_append, "append"},
  {&__pyx_n_bdaddr, "bdaddr"},
  {&__pyx_n_bound, "bound"},
  {&__pyx_n_byte_rx, "byte_rx"},
  {&__pyx_n_byte_tx, "byte_tx"},
  {&__pyx_n_callable, "callable"},
  {&__pyx_n_channel, "channel"},
  {&__pyx_n_clean, "clean"},
  {&__pyx_n_closed, "closed"},
  {&__pyx_n_cmd_tx, "cmd_tx"},
  {&__pyx_n_config, "config"},
  {&__pyx_n_connected, "connected"},
  {&__pyx_n_connecting, "connecting"},
  {&__pyx_n_dev_id, "dev_id"},
  {&__pyx_n_disconnecting, "disconnecting"},
  {&__pyx_n_dst, "dst"},
  {&__pyx_n_err_rx, "err_rx"},
  {&__pyx_n_err_tx, "err_tx"},
  {&__pyx_n_evt_rx, "evt_rx"},
  {&__pyx_n_exceptions, "exceptions"},
  {&__pyx_n_features, "features"},
  {&__pyx_n_flags, "flags"},
  {&__pyx_n_gdk, "gdk"},
  {&__pyx_n_gtk, "gtk"},
  {&__pyx_n_hci0, "hci0"},
  {&__pyx_n_id, "id"},
  {&__pyx_n_link_mode, "link_mode"},
  {&__pyx_n_link_policy, "link_policy"},
  {&__pyx_n_listening, "listening"},
  {&__pyx_n_name, "name"},
  {&__pyx_n_pan1, "pan1"},
  {&__pyx_n_pkt_type, "pkt_type"},
  {&__pyx_n_sco_mtu, "sco_mtu"},
  {&__pyx_n_sco_rx, "sco_rx"},
  {&__pyx_n_sco_tx, "sco_tx"},
  {&__pyx_n_src, "src"},
  {&__pyx_n_stat, "stat"},
  {&__pyx_n_state, "state"},
  {&__pyx_n_type, "type"},
  {&__pyx_n_unknown, "unknown"},
  {&__pyx_n_value, "value"},
  {0, 0}
};

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_k1p, __pyx_k1, sizeof(__pyx_k1)},
  {&__pyx_k2p, __pyx_k2, sizeof(__pyx_k2)},
  {&__pyx_k3p, __pyx_k3, sizeof(__pyx_k3)},
  {&__pyx_k4p, __pyx_k4, sizeof(__pyx_k4)},
  {&__pyx_k5p, __pyx_k5, sizeof(__pyx_k5)},
  {&__pyx_k6p, __pyx_k6, sizeof(__pyx_k6)},
  {&__pyx_k7p, __pyx_k7, sizeof(__pyx_k7)},
  {&__pyx_k8p, __pyx_k8, sizeof(__pyx_k8)},
  {&__pyx_k66p, __pyx_k66, sizeof(__pyx_k66)},
  {&__pyx_k67p, __pyx_k67, sizeof(__pyx_k67)},
  {&__pyx_k68p, __pyx_k68, sizeof(__pyx_k68)},
  {&__pyx_k69p, __pyx_k69, sizeof(__pyx_k69)},
  {&__pyx_k70p, __pyx_k70, sizeof(__pyx_k70)},
  {0, 0, 0}
};

static PyObject *__pyx_tp_new_8_blueman_conn_info(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  return o;
}

static void __pyx_tp_dealloc_8_blueman_conn_info(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static struct PyMethodDef __pyx_methods_8_blueman_conn_info[] = {
  {"deinit", (PyCFunction)__pyx_f_8_blueman_9conn_info_deinit, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_rssi", (PyCFunction)__pyx_f_8_blueman_9conn_info_get_rssi, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_lq", (PyCFunction)__pyx_f_8_blueman_9conn_info_get_lq, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_tpl", (PyCFunction)__pyx_f_8_blueman_9conn_info_get_tpl, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_conn_info = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_conn_info = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_conn_info = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_conn_info = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_8_blueman_conn_info = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "_blueman.conn_info", /*tp_name*/
  sizeof(struct __pyx_obj_8_blueman_conn_info), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_8_blueman_conn_info, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_conn_info, /*tp_as_number*/
  &__pyx_tp_as_sequence_conn_info, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_conn_info, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_conn_info, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_8_blueman_conn_info, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_8_blueman_9conn_info___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_8_blueman_conn_info, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_8_blueman_sn_launcher(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  if (__pyx_f_8_blueman_11sn_launcher___cinit__(o, a, k) < 0) {
    Py_DECREF(o); o = 0;
  }
  return o;
}

static void __pyx_tp_dealloc_8_blueman_sn_launcher(PyObject *o) {
  {
    PyObject *etype, *eval, *etb;
    PyErr_Fetch(&etype, &eval, &etb);
    ++o->ob_refcnt;
    __pyx_f_8_blueman_11sn_launcher___dealloc__(o);
    if (PyErr_Occurred()) PyErr_WriteUnraisable(o);
    --o->ob_refcnt;
    PyErr_Restore(etype, eval, etb);
  }
  (*o->ob_type->tp_free)(o);
}

static struct PyMethodDef __pyx_methods_8_blueman_sn_launcher[] = {
  {"initiate", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_initiate, METH_VARARGS|METH_KEYWORDS, 0},
  {"complete", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_complete, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_startup_id", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_get_startup_id, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_initiated", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_get_initiated, METH_VARARGS|METH_KEYWORDS, 0},
  {"setup_child_process", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_setup_child_process, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_name", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_name, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_description", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_description, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_workspace", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_workspace, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_wmclass", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_wmclass, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_binary_name", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_binary_name, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_icon_name", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_icon_name, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_extra_property", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_set_extra_property, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_initiated_time", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_get_initiated_time, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_last_active_time", (PyCFunction)__pyx_f_8_blueman_11sn_launcher_get_last_active_time, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_sn_launcher = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_sn_launcher = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_sn_launcher = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_sn_launcher = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_8_blueman_sn_launcher = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "_blueman.sn_launcher", /*tp_name*/
  sizeof(struct __pyx_obj_8_blueman_sn_launcher), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_8_blueman_sn_launcher, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_sn_launcher, /*tp_as_number*/
  &__pyx_tp_as_sequence_sn_launcher, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_sn_launcher, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_sn_launcher, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_8_blueman_sn_launcher, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_8_blueman_sn_launcher, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
  {"get_net_address", (PyCFunction)__pyx_f_8_blueman_get_net_address, METH_VARARGS|METH_KEYWORDS, 0},
  {"rfcomm_list", (PyCFunction)__pyx_f_8_blueman_rfcomm_list, METH_VARARGS|METH_KEYWORDS, 0},
  {"create_bridge", (PyCFunction)__pyx_f_8_blueman_create_bridge, METH_VARARGS|METH_KEYWORDS, 0},
  {"destroy_bridge", (PyCFunction)__pyx_f_8_blueman_destroy_bridge, METH_VARARGS|METH_KEYWORDS, 0},
  {"page_timeout", (PyCFunction)__pyx_f_8_blueman_page_timeout, METH_VARARGS|METH_KEYWORDS, 0},
  {"device_info", (PyCFunction)__pyx_f_8_blueman_device_info, METH_VARARGS|METH_KEYWORDS, 0},
  {"probe_modem", (PyCFunction)__pyx_f_8_blueman_probe_modem, METH_VARARGS|METH_KEYWORDS, 0},
  {"set_probe_debug", (PyCFunction)__pyx_f_8_blueman_set_probe_debug, METH_VARARGS|METH_KEYWORDS, 0},
  {"get_special_dir", (PyCFunction)__pyx_f_8_blueman_get_special_dir, METH_VARARGS|METH_KEYWORDS, 0},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC init_blueman(void); /*proto*/
PyMODINIT_FUNC init_blueman(void) {
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("_blueman", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 3; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 3; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 3; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 3; goto __pyx_L1;};
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 3; goto __pyx_L1;};
  if (PyType_Ready(&__pyx_type_8_blueman_conn_info) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 181; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "conn_info", (PyObject *)&__pyx_type_8_blueman_conn_info) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 181; goto __pyx_L1;}
  __pyx_ptype_8_blueman_conn_info = &__pyx_type_8_blueman_conn_info;
  if (PyType_Ready(&__pyx_type_8_blueman_sn_launcher) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 352; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "sn_launcher", (PyObject *)&__pyx_type_8_blueman_sn_launcher) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 352; goto __pyx_L1;}
  __pyx_ptype_8_blueman_sn_launcher = &__pyx_type_8_blueman_sn_launcher;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":100 */
  __pyx_1 = PyDict_New(); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  __pyx_2 = PyInt_FromLong((-1)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 101; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k1p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-2)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 102; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k2p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-3)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 103; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k3p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-4)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 104; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k4p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-5)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 105; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k5p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-6)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 106; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k6p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-7)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 107; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k7p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-8)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 108; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_k8p) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-9)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 109; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_n_ERR_SOCKET_FAILED) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-10)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 110; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_n_ERR_CANT_READ_PAGE_TIMEOUT) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  __pyx_2 = PyInt_FromLong((-11)); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 111; goto __pyx_L1;}
  if (PyDict_SetItem(__pyx_1, __pyx_2, __pyx_n_ERR_READ_PAGE_TIMEOUT) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_ERR, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":114 */
  __pyx_2 = PyList_New(10); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; goto __pyx_L1;}
  Py_INCREF(__pyx_n_unknown);
  PyList_SET_ITEM(__pyx_2, 0, __pyx_n_unknown);
  Py_INCREF(__pyx_n_connected);
  PyList_SET_ITEM(__pyx_2, 1, __pyx_n_connected);
  Py_INCREF(__pyx_n_clean);
  PyList_SET_ITEM(__pyx_2, 2, __pyx_n_clean);
  Py_INCREF(__pyx_n_bound);
  PyList_SET_ITEM(__pyx_2, 3, __pyx_n_bound);
  Py_INCREF(__pyx_n_listening);
  PyList_SET_ITEM(__pyx_2, 4, __pyx_n_listening);
  Py_INCREF(__pyx_n_connecting);
  PyList_SET_ITEM(__pyx_2, 5, __pyx_n_connecting);
  Py_INCREF(__pyx_n_connecting);
  PyList_SET_ITEM(__pyx_2, 6, __pyx_n_connecting);
  Py_INCREF(__pyx_n_config);
  PyList_SET_ITEM(__pyx_2, 7, __pyx_n_config);
  Py_INCREF(__pyx_n_disconnecting);
  PyList_SET_ITEM(__pyx_2, 8, __pyx_n_disconnecting);
  Py_INCREF(__pyx_n_closed);
  PyList_SET_ITEM(__pyx_2, 9, __pyx_n_closed);
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RFCOMM_STATES, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 114; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":126 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RFCOMM_REUSE_DLC, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 126; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":127 */
  __pyx_2 = PyInt_FromLong(1); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RFCOMM_RELEASE_ONHUP, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 127; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":128 */
  __pyx_1 = PyInt_FromLong(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RFCOMM_HANGUP_NOW, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 128; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":129 */
  __pyx_2 = PyInt_FromLong(3); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 129; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RFCOMM_TTY_ATTACHED, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 129; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":160 */
  __pyx_1 = __Pyx_Import(__pyx_n_exceptions, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_exceptions, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":161 */
  __pyx_2 = PyDict_New(); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  __pyx_1 = __Pyx_GetName(__pyx_m, __pyx_n_exceptions); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  __pyx_3 = PyObject_GetAttr(__pyx_1, __pyx_n_Exception); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyTuple_New(1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_3);
  __pyx_3 = 0;
  __pyx_3 = __Pyx_CreateClass(__pyx_1, __pyx_2, __pyx_n_BridgeException, "_blueman"); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":162 */
  __pyx_1 = PyCFunction_New(&__pyx_mdef_8_blueman_15BridgeException___init__, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 162; goto __pyx_L1;}
  __pyx_4 = PyMethod_New(__pyx_1, 0, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 162; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetAttr(__pyx_3, __pyx_n___init__, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 162; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":165 */
  __pyx_1 = PyCFunction_New(&__pyx_mdef_8_blueman_15BridgeException___str__, 0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 165; goto __pyx_L1;}
  __pyx_4 = PyMethod_New(__pyx_1, 0, __pyx_3); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 165; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  if (PyObject_SetAttr(__pyx_3, __pyx_n___str__, __pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 165; goto __pyx_L1;}
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_BridgeException, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 161; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":170 */
  Py_INCREF(__pyx_n_pan1);
  __pyx_k25 = __pyx_n_pan1;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":175 */
  Py_INCREF(__pyx_n_pan1);
  __pyx_k27 = __pyx_n_pan1;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":185 */
  Py_INCREF(__pyx_n_hci0);
  __pyx_k29 = __pyx_n_hci0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":212 */
  __pyx_1 = PyInt_FromLong(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 212; goto __pyx_L1;}
  __pyx_k30 = __pyx_1;
  __pyx_1 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":220 */
  Py_INCREF(__pyx_n_hci0);
  __pyx_k32 = __pyx_n_hci0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":228 */
  Py_INCREF(__pyx_n_hci0);
  __pyx_k34 = __pyx_n_hci0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":485 */
  __pyx_4 = PyDict_New(); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 485; goto __pyx_L1;}
  __pyx_3 = PyTuple_New(0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 485; goto __pyx_L1;}
  __pyx_2 = __Pyx_CreateClass(__pyx_3, __pyx_4, __pyx_n_SpecialDirType, "_blueman"); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 485; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":486 */
  __pyx_3 = PyInt_FromLong(0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 486; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_DESKTOP, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 486; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":487 */
  __pyx_3 = PyInt_FromLong(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 487; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_DOCUMENTS, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 487; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":488 */
  __pyx_3 = PyInt_FromLong(2); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_DOWNLOAD, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 488; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":489 */
  __pyx_3 = PyInt_FromLong(3); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_MUSIC, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 489; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":490 */
  __pyx_3 = PyInt_FromLong(4); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 490; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_PICTURES, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 490; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":491 */
  __pyx_3 = PyInt_FromLong(5); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_PUBLIC_SHARE, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 491; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":492 */
  __pyx_3 = PyInt_FromLong(6); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_TEMPLATES, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 492; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":493 */
  __pyx_3 = PyInt_FromLong(7); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_2, __pyx_n_VIDEOS, __pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 493; goto __pyx_L1;}
  Py_DECREF(__pyx_3); __pyx_3 = 0;
  if (PyObject_SetAttr(__pyx_m, __pyx_n_SpecialDirType, __pyx_2) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 485; goto __pyx_L1;}
  Py_DECREF(__pyx_2); __pyx_2 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;

  /* "/home/walmis/Desktop/blueman/module/_blueman.pyx":496 */
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  __Pyx_AddTraceback("_blueman");
}

static char *__pyx_filenames[] = {
  "_blueman.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list) {
    PyObject *__import__ = 0;
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    __import__ = PyObject_GetAttrString(__pyx_b, "__import__");
    if (!__import__)
        goto bad;
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    module = PyObject_CallFunction(__import__, "OOOO",
        name, global_dict, empty_dict, list);
bad:
    Py_XDECREF(empty_list);
    Py_XDECREF(__import__);
    Py_XDECREF(empty_dict);
    return module;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
    PyObject *result;
    result = PyObject_GetAttr(dict, name);
    if (!result)
        PyErr_SetObject(PyExc_NameError, name);
    return result;
}

static PyObject *__Pyx_CreateClass(
    PyObject *bases, PyObject *dict, PyObject *name, char *modname)
{
    PyObject *py_modname;
    PyObject *result = 0;
    
    py_modname = PyString_FromString(modname);
    if (!py_modname)
        goto bad;
    if (PyDict_SetItemString(dict, "__module__", py_modname) < 0)
        goto bad;
    result = PyClass_New(bases, dict, name);
bad:
    Py_XDECREF(py_modname);
    return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    Py_XINCREF(type);
    Py_XINCREF(value);
    Py_XINCREF(tb);
    /* First, check the traceback argument, replacing None with NULL. */
    if (tb == Py_None) {
        Py_DECREF(tb);
        tb = 0;
    }
    else if (tb != NULL && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto raise_error;
    }
    /* Next, replace a missing value with None */
    if (value == NULL) {
        value = Py_None;
        Py_INCREF(value);
    }
    #if PY_VERSION_HEX < 0x02050000
    if (!PyClass_Check(type))
    #else
    if (!PyType_Check(type))
    #endif
    {
        /* Raising an instance.  The value should be a dummy. */
        if (value != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        /* Normalize to raise <class>, <instance> */
        Py_DECREF(value);
        value = type;
        #if PY_VERSION_HEX < 0x02050000
            if (PyInstance_Check(type)) {
                type = (PyObject*) ((PyInstanceObject*)type)->in_class;
                Py_INCREF(type);
            }
            else {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception must be an old-style class or instance");
                goto raise_error;
            }
        #else
            type = (PyObject*) type->ob_type;
            Py_INCREF(type);
            if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception class must be a subclass of BaseException");
                goto raise_error;
            }
        #endif
    }
    PyErr_Restore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}

static PyObject *__Pyx_GetItemInt(PyObject *o, Py_ssize_t i) {
    PyTypeObject *t = o->ob_type;
    PyObject *r;
    if (t->tp_as_sequence && t->tp_as_sequence->sq_item)
        r = PySequence_GetItem(o, i);
    else {
        PyObject *j = PyInt_FromLong(i);
        if (!j)
            return 0;
        r = PyObject_GetItem(o, j);
        Py_DECREF(j);
    }
    return r;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
    while (t->p) {
        *t->p = PyString_InternFromString(t->s);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_tuple = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    py_funcname = PyString_FromString(funcname);
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_tuple = PyTuple_New(0);
    if (!empty_tuple) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        empty_tuple,  /*PyObject *consts,*/
        empty_tuple,  /*PyObject *names,*/
        empty_tuple,  /*PyObject *varnames,*/
        empty_tuple,  /*PyObject *freevars,*/
        empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_tuple);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}
