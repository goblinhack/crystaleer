/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include <SDL.h>

#include "python.h"
#include "py_tp.h"
#include "py_thing.h"
#include "py_wid.h"
#include "py_game.h"
#include "python.h"
#include "py_sdl.h"
#include "string_util.h"
#include "frameobject.h"
#include "config.h"
#include "wid.h"

static PyObject *mm_mod;
PyMODINIT_FUNC python_m_y_module_create(void);

PY_PROTO(wid_mouse_hide)
PY_BODY_INT_FN(wid_mouse_hide, value)

void py_call_void_module_int (const char *module, const char *name, int val1)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(i)", val1);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();
}

void py_call_void_int (const char *name, int val1)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *pFunc = PyObject_GetAttrString(mm_mod, name);
    if (PyCallable_Check(pFunc)) {
        PyObject *pArgs = Py_BuildValue("(i)", val1);
        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python function %s(%d)", name, val1);
    }

    py_err();
}

void py_call_void (const char *name)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *pFunc = PyObject_GetAttrString(mm_mod, name);
    if (PyCallable_Check(pFunc)) {
        PyObject *pValue = PyObject_CallObject(pFunc, 0);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python function %s", name);
    }

    py_err();
}

int py_call_int_module_ptr_iiiiii (const char *module, const char *name, void *val1, int val2, int val3, int val4, int val5, int val6, int val7)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiiiii)", (uintptr_t) val1, val2, val3, val4, val5, val6, val7);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

int py_call_int_module_ptr_iiiii (const char *module, const char *name, void *val1, int val2, int val3, int val4, int val5, int val6)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiiii)", (uintptr_t) val1, val2, val3, val4, val5, val6);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

int py_call_int_module_ptr_iiii (const char *module, const char *name, void *val1, int val2, int val3, int val4, int val5)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiii)", (uintptr_t) val1, val2, val3, val4, val5);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

int py_call_int_module_ptr_iii (const char *module, const char *name, void *val1, int val2, int val3, int val4)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiii)", (uintptr_t) val1, val2, val3, val4);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

int py_call_int_module_ptr_ii (const char *module, const char *name, void *val1, int val2, int val3)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kii)", (uintptr_t) val1, val2, val3);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

int py_call_int_module_ptr_int (const char *module, const char *name, void *val1, int val2)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Ki)", (uintptr_t) val1, val2);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

void py_call_void_module_ptr_iiiiiiiiiiiiiiiiiii (const char *module,
                                                  const char *name,
                                                  void *val1,
                                                  int val2,
                                                  int val3,
                                                  int val4,
                                                  int val5,
                                                  int val6,
                                                  int val7,
                                                  int val8,
                                                  int val9,
                                                  int val10,
                                                  int val11,
                                                  int val12,
                                                  int val13,
                                                  int val14,
                                                  int val15,
                                                  int val16,
                                                  int val17,
                                                  int val18,
                                                  int val19,
                                                  int val20)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiiiiiiiiiiiiiiiiii)",
                                        (uintptr_t) val1,
                                        val2,
                                        val3,
                                        val4,
                                        val5,
                                        val6,
                                        val7,
                                        val8,
                                        val9,
                                        val10,
                                        val11,
                                        val12,
                                        val13,
                                        val14,
                                        val15,
                                        val16,
                                        val17,
                                        val18,
                                        val19,
                                        val20);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

void py_call_void_module_ptr_iiiiii (const char *module, const char *name, void *val1, int val2, int val3, int val4, int val5, int val6, int val7)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiiiii)", (uintptr_t) val1, val2, val3, val4, val5, val6, val7);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

void py_call_void_module_ptr_iiiii (const char *module, const char *name, void *val1, int val2, int val3, int val4, int val5, int val6)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiiii)", (uintptr_t) val1, val2, val3, val4, val5, val6);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

void py_call_void_module_ptr_iiii (const char *module, const char *name, void *val1, int val2, int val3, int val4, int val5)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiiii)", (uintptr_t) val1, val2, val3, val4, val5);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

void py_call_void_module_ptr_iii (const char *module, const char *name, void *val1, int val2, int val3, int val4)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kiii)", (uintptr_t) val1, val2, val3, val4);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

void py_call_void_module_ptr_ii (const char *module, const char *name, void *val1, int val2, int val3)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Kii)", (uintptr_t) val1, val2, val3);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

void py_call_void_module_ptr_int (const char *module, const char *name, void *val1, int val2)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(Ki)", (uintptr_t) val1, val2);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

int py_call_int_module_ptr (const char *module, const char *name, void *val1)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(K)", (uintptr_t) val1);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

void py_call_void_module_ptr (const char *module, const char *name, void *val1)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(K)", (uintptr_t) val1);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

int py_call_int_module_ptr_ptr (const char *module, const char *name, void *val1, void *val2)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(KK)",
                                        (uintptr_t) val1,
                                        (uintptr_t) val2);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

void py_call_void_module_ptr_ptr (const char *module, const char *name, void *val1, void *val2)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(KK)",
                                        (uintptr_t) val1,
                                        (uintptr_t) val2);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return;
}

int py_call_int_module_int (const char *module, const char *name, int val1)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pArgs = Py_BuildValue("(i)", val1);
        PyObject *pValue = PyObject_CallObject(fn, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

int py_call_int_module_void (const char *module, const char *name)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return (ret);
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return (ret);
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return (ret);
    }

    if (PyCallable_Check(fn)) {
        PyObject *pValue = PyObject_CallObject(fn, 0);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);

            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();

    return (ret);
}

void py_call_void_module_void (const char *module, const char *name)
{
    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *v = PyObject_GetAttrString(mm_mod, module);
    if (!v) {
        ERR("cannot find python module %s", module);
        return;
    }

    PyObject *dict = PyModule_GetDict(v);
    if (!dict) {
        ERR("cannot find python module %s dict", module);
        return;
    }

    PyObject *fn = PyDict_GetItemString(dict, name);
    if (!fn) {
        ERR("cannot find python module %s fn %s", module, name);
        return;
    }

    if (PyCallable_Check(fn)) {
        PyObject *pValue = PyObject_CallObject(fn, 0);
        if (pValue != NULL) {
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python module %s fn %s", module, name);
    }

    py_err();
}

int py_call_ii (const char *name, int val1)
{
    int ret = -1;

    if (!mm_mod) {
        DIE("python module not inited yet");
    }

    PyObject *pFunc = PyObject_GetAttrString(mm_mod, name);
    if (PyCallable_Check(pFunc)) {
        PyObject *pArgs = Py_BuildValue("(i)", val1);
        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        Py_DECREF(pArgs);
        if (pValue != NULL) {
            ret = py_obj_to_int(pValue);
            Py_DECREF(pValue);
        }
    } else {
        ERR("cannot call python function %s(%d)", name, val1);
    }

    py_err();

    return (ret);
}

char *py_obj_to_str (const PyObject *py_str)
{
    PyObject *py_encstr;
    char *outstr = 0;
    char *str;

    py_encstr = 0;
    str = 0;

    if (!PyUnicode_Check((PyObject *)py_str)) {
        ERR("Object is a %s, not a string object.",
            Py_TYPE((PyObject *)py_str)->tp_name);
        goto err_out;
    }

    py_encstr = PyUnicode_AsEncodedString((PyObject *)py_str, "utf-8", 0);
    if (!py_encstr) {
        goto err_out;
    }

    str = PyBytes_AS_STRING(py_encstr);
    if (!str) {
        goto err_out;
    }

    outstr = dupstr(str, __FUNCTION__);

err_out:

    if (py_encstr) {
        Py_XDECREF(py_encstr);
    }

    return (outstr);
}

int py_obj_to_int (PyObject *py_obj)
{
    int val;

    val = 0;

    if (!PyLong_Check((PyObject *)py_obj)) {
        ERR("Object is a %s, not a int object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    val = PyLong_AsLong(py_obj);

err_out:

    if (PyErr_Occurred()) {
        ERR("int conversion failed");
    }

    return (val);
}

uint64_t py_obj_to_uint64 (PyObject *py_obj)
{
    uint64_t val;

    val = 0;

    if (!PyLong_Check((PyObject *)py_obj)) {
        ERR("Object is a %s, not a uint64 object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    val = PyLong_AsUnsignedLongLong(py_obj);

err_out:

    if (PyErr_Occurred()) {
        ERR("int conversion failed");
    }

    return (val);
}

double py_obj_to_double (PyObject *py_obj)
{
    double val;

    val = 0;

    if (PyLong_Check((PyObject *)py_obj)) {
        val = PyLong_AsDouble(py_obj);
    } else if (PyFloat_Check((PyObject *)py_obj)) {
        val = PyFloat_AsDouble(py_obj);
    } else {
        ERR("Object is a %s, not a double object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

err_out:

    if (PyErr_Occurred()) {
        ERR("int conversion failed");
    }

    return (val);
}

int py_obj_attr_int (const PyObject *py_obj, const char *attr)
{
    PyObject *py_encstr;
    int i = 0;

    py_encstr = 0;

    if (!PyObject_HasAttrString((PyObject *)py_obj, attr)) {
        ERR("Object is a %s, not a string object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    py_encstr = PyObject_GetAttrString((PyObject *)py_obj, attr);
    if (!py_encstr) {
        goto err_out;
    }

    i = py_obj_to_int(py_encstr);

err_out:
    if (py_encstr) {
        Py_XDECREF(py_encstr);
    }

    if (PyErr_Occurred()) {
        ERR("int conversion failed");
    }

    return (i);
}

uint64_t py_obj_attr_uint64 (const PyObject *py_obj, const char *attr)
{
    PyObject *py_encstr;
    uint64_t i = 0;

    py_encstr = 0;

    if (!PyObject_HasAttrString((PyObject *)py_obj, attr)) {
        ERR("Object is a %s, not a string object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    py_encstr = PyObject_GetAttrString((PyObject *)py_obj, attr);
    if (!py_encstr) {
        goto err_out;
    }

    i = py_obj_to_uint64(py_encstr);

err_out:
    if (py_encstr) {
        Py_XDECREF(py_encstr);
    }

    if (PyErr_Occurred()) {
        ERR("int conversion failed");
    }

    return (i);
}

double py_obj_attr_double (const PyObject *py_obj, const char *attr)
{
    PyObject *py_encstr;
    double i = 0;

    py_encstr = 0;

    if (!PyObject_HasAttrString((PyObject *)py_obj, attr)) {
        ERR("Object is a %s, not a string object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    py_encstr = PyObject_GetAttrString((PyObject *)py_obj, attr);
    if (!py_encstr) {
        goto err_out;
    }

    i = py_obj_to_double(py_encstr);

err_out:
    if (py_encstr) {
        Py_XDECREF(py_encstr);
    }

    if (PyErr_Occurred()) {
        ERR("int conversion failed");
    }

    return (i);
}

char *py_obj_attr_str (const PyObject *py_obj, const char *attr)
{
    PyObject *py_encstr;
    char *outstr = 0;
    char *str;

    py_encstr = 0;
    str = 0;

    if (!PyObject_HasAttrString((PyObject *)py_obj, attr)) {
        ERR("Object is a %s, not a string object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    py_encstr = PyObject_GetAttrString((PyObject *)py_obj, attr);
    if (!py_encstr) {
        goto err_out;
    }

    str = py_obj_to_str(py_encstr);
    if (!str) {
        goto err_out;
    }

    outstr = str;

err_out:

    if (py_encstr) {
        Py_XDECREF(py_encstr);
    }

    return (outstr);
}

PyObject *py_obj_attr (const PyObject *py_obj, const char *attr)
{
    PyObject *py_encstr;

    py_encstr = 0;

    if (!PyObject_HasAttrString((PyObject *)py_obj, attr)) {
        ERR("Object is a %s, not a string object.",
            Py_TYPE((PyObject *)py_obj)->tp_name);
        goto err_out;
    }

    py_encstr = PyObject_GetAttrString((PyObject *)py_obj, attr);
    if (!py_encstr) {
        goto err_out;
    }

    return (py_encstr);

err_out:
    if (py_encstr) {
        Py_XDECREF(py_encstr);
    }

    if (PyErr_Occurred()) {
        ERR("obj lookup conversion failed");
    }

    Py_RETURN_NONE;
}

static PyObject *con_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    if (a) {
        CON("%s", a);
    }

    Py_RETURN_NONE;
}

static PyObject *tip_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    if (a) {
        TIP("%s", a);
    }

    Py_RETURN_NONE;
}

static PyObject *tip2_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    if (a) {
        TIP2("%s", a);
    }

    Py_RETURN_NONE;
}

static PyObject *puts_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    fputs(a, MY_STDOUT);
    fflush(MY_STDOUT);
    printf("%s", a);

    Py_RETURN_NONE;
}

static PyObject *log_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    if (a) {
        LOG("%s", a);
    }

    Py_RETURN_NONE;
}

static PyObject *err_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    if (a) {
        ERR("%s", a);
    }

    Py_RETURN_NONE;
}

static PyObject *die_ (PyObject *obj, PyObject *args, PyObject *keywds)
{
    char *a = 0;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return (0);
    }

    if (a) {
        DIE("%s", a);
    }

    Py_RETURN_NONE;
}

static PyMethodDef python_c_METHODS[] =
{
    /*
     * The cast of the function is necessary since PyCFunction values
     * only take two PyObject *parameters, and some take three.
     */
    {"con",
        (PyCFunction)con_,
        METH_VARARGS,
        "log to the console"},

    {"tip",
        (PyCFunction)tip_,
        METH_VARARGS,
        "tooltip"},

    {"tip2",
        (PyCFunction)tip2_,
        METH_VARARGS,
        "tooltip2"},

    {"puts",
        (PyCFunction)puts_,
        METH_VARARGS,
        "log to the console"},

    {"err",
        (PyCFunction)err_,
        METH_VARARGS,
        "error to the log file"},

    {"log",
        (PyCFunction)log_,
        METH_VARARGS,
        "log to the log file"},

    {"die",
        (PyCFunction)die_,
        METH_VARARGS,
        "exit game with error"},

    PY_DECL(wid_mouse_hide)

    PY_DECL(game_map_create)
    PY_DECL(game_map_destroy)

    {"wid_tiles_load",
        (PyCFunction)wid_tiles_load_,
        METH_VARARGS | METH_KEYWORDS,
        "load a block of wid tiles"},

    {"text_size",
        (PyCFunction)ttf_text_size_,
        METH_VARARGS | METH_KEYWORDS,
        "text size in pixels"},

    {"text_size_pct",
        (PyCFunction)ttf_text_size_pct_,
        METH_VARARGS | METH_KEYWORDS,
        "text size in percent"},

    {"tex_load",
        (PyCFunction)tex_load_,
        METH_VARARGS | METH_KEYWORDS,
        "load a texture"},

    {"tex_load_tiled",
        (PyCFunction)tex_load_tiled_,
        METH_VARARGS | METH_KEYWORDS,
        "load a texture"},

    {"tex_size",
        (PyCFunction)tex_size_,
        METH_VARARGS | METH_KEYWORDS,
        "tex info"},

    {"tex_pixel",
        (PyCFunction)tex_pixel_,
        METH_VARARGS | METH_KEYWORDS,
        "get pixels"},

    {"tile_load_arr",
        (PyCFunction)tile_load_arr_,
        METH_VARARGS | METH_KEYWORDS,
        "load a tile array"},

    {"tile_size",
        (PyCFunction)tile_get_size_,
        METH_VARARGS | METH_KEYWORDS,
        "tile size in pixels"},

    {"tile_size_pct",
        (PyCFunction)tile_get_size_pct_,
        METH_VARARGS | METH_KEYWORDS,
        "tile size in pct"},

    {"tp_load",
        (PyCFunction)tp_load_,
        METH_VARARGS | METH_KEYWORDS,
        "load a thing template"},

    {"thing_new",
        (PyCFunction)thing_new_,
        METH_VARARGS | METH_KEYWORDS,
        "create a thing template"},

    THING_DECL(thing_set_tilename)
    THING_DECL(thing_set_tp)
    THING_DECL(thing_destroyed)
    THING_DECL(thing_move_delta)
    THING_DECL(thing_push)
    THING_DECL(thing_collision_check)
    THING_DECL(thing_pop)

    {"wid_new",
        (PyCFunction)wid_new_,
        METH_VARARGS | METH_KEYWORDS,
        "create a wid"},

    {"wid_destroy",
        (PyCFunction)wid_destroy_,
        METH_VARARGS | METH_KEYWORDS,
        "destroy a wid"},

    {"wid_new_scrollbar",
        (PyCFunction)wid_new_scrollbar_,
        METH_VARARGS | METH_KEYWORDS,
        "create scrollbars"},

    {"wid_set_shape",
        (PyCFunction)wid_set_shape_,
        METH_VARARGS | METH_KEYWORDS,
        "set wid shape"},

    {"wid_set_tooltip",
        (PyCFunction)wid_set_tooltip_,
        METH_VARARGS | METH_KEYWORDS,
        "set wid tooltip"},

    {"wid_set_tiles",
        (PyCFunction)wid_set_tiles_,
        METH_VARARGS | METH_KEYWORDS,
        "set wid tiles"},

    {"wid_set_pos",
        (PyCFunction)wid_set_pos_,
        METH_VARARGS | METH_KEYWORDS,
        "set bounds"},

    {"wid_set_pos_pct",
        (PyCFunction)wid_set_pos_pct_,
        METH_VARARGS | METH_KEYWORDS,
        "set bounds in percent"},

    {"wid_set_text",
        (PyCFunction)wid_set_text_,
        METH_VARARGS | METH_KEYWORDS,
        "set text"},

    {"wid_set_color",
        (PyCFunction)wid_set_color_,
        METH_VARARGS | METH_KEYWORDS,
        "set color"},

    {"wid_set_tex",
        (PyCFunction)wid_set_tex_,
        METH_VARARGS | METH_KEYWORDS,
        "set texture"},

    {"wid_raise",
        (PyCFunction)wid_set_raise_,
        METH_VARARGS | METH_KEYWORDS,
        "raise wid"},

    {"wid_lower",
        (PyCFunction)wid_set_lower_,
        METH_VARARGS | METH_KEYWORDS,
        "lower wid"},

    {"wid_update",
        (PyCFunction)wid_set_update_,
        METH_VARARGS | METH_KEYWORDS,
        "update wid"},

    {"wid_set_bevel",
        (PyCFunction)wid_set_bevel_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_bevel"},

    {"wid_set_bevelled",
        (PyCFunction)wid_set_bevelled_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_bevelled"},

    {"wid_set_cursor",
        (PyCFunction)wid_set_cursor_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_cursor"},

    {"wid_set_do_not_lower",
        (PyCFunction)wid_set_do_not_lower_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_do_not_lower"},

    {"wid_set_do_not_raise",
        (PyCFunction)wid_set_do_not_raise_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_do_not_raise"},

    {"wid_set_ignore_events",
        (PyCFunction)wid_set_ignore_events_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_ignore_events"},

    {"wid_set_focusable",
        (PyCFunction)wid_set_focusable_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_focusable"},

    {"wid_set_movable",
        (PyCFunction)wid_set_movable_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_movable"},

    {"wid_set_movable_bounded",
        (PyCFunction)wid_set_movable_bounded_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_movable_bounded"},

    {"wid_set_movable_no_user_scroll",
        (PyCFunction)wid_set_movable_no_user_scroll_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_movable_no_user_scroll"},

    {"wid_set_movable_horiz",
        (PyCFunction)wid_set_movable_horiz_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_movable_horiz"},

    {"wid_set_movable_vert",
        (PyCFunction)wid_set_movable_vert_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_set_movable_vert"},

    {"wid_get_size",
        (PyCFunction)wid_get_size_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_get_size"},

    {"wid_get_size_pct",
        (PyCFunction)wid_get_size_pct_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_get_size_pct"},

    {"wid_get_pos",
        (PyCFunction)wid_get_pos_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_get_pos"},

    {"wid_get_pos_pct",
        (PyCFunction)wid_get_pos_pct_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_get_pos_pct"},

    {"wid_get_parent",
        (PyCFunction)wid_get_parent_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_get_parent"},

    {"wid_get_top_parent",
        (PyCFunction)wid_get_top_parent_,
        METH_VARARGS | METH_KEYWORDS,
        "wid_get_top_parent"},

    WID_DECL(wid_move_to_horiz_vert_pct_in)
    WID_DECL(wid_move_to_abs_centered_in)
    WID_DECL(wid_move_to_centered_in)
    WID_DECL(wid_move_delta_pct_in)
    WID_DECL(wid_move_to_abs_in)
    WID_DECL(wid_move_delta_in)
    WID_DECL(wid_move_to_pct_centered_in)
    WID_DECL(wid_move_to_abs_poffset_in)
    WID_DECL(wid_move_to_pct_in)
    WID_DECL(wid_bounce_to_pct_in)

    WID_DECL(wid_move_delta)
    WID_DECL(wid_move_delta_pct)
    WID_DECL(wid_move_to_abs)
    WID_DECL(wid_move_to_abs_centered)
    WID_DECL(wid_move_to_pct)
    WID_DECL(wid_move_to_pct_centered)
    WID_DECL(wid_move_to_vert_pct_in)
    WID_DECL(wid_move_to_horiz_pct_in)

    WID_DECL(wid_move_to_vert_pct)
    WID_DECL(wid_move_to_horiz_pct)

    WID_DECL(wid_move_to_bottom)
    WID_DECL(wid_move_to_left)
    WID_DECL(wid_move_to_right)
    WID_DECL(wid_move_to_top)
    WID_DECL(wid_move_end)

    WID_DECL(wid_destroy_in)
    WID_DECL(wid_fade_in)
    WID_DECL(wid_fade_out)
    WID_DECL(wid_fade_in_out)
    WID_DECL(wid_visible)
    WID_DECL(wid_hide)
    WID_DECL(wid_toggle_hidden)
    WID_DECL(wid_mouse_hide)

    WID_DECL(wid_set_on_tooltip)
    WID_DECL(wid_set_on_key_down)
    WID_DECL(wid_set_on_key_up)
    WID_DECL(wid_set_on_joy_button)
    WID_DECL(wid_set_on_m_down)
    WID_DECL(wid_set_on_m_motion)
    WID_DECL(wid_set_on_m_focus_b)
    WID_DECL(wid_set_on_m_focus_e)
    WID_DECL(wid_set_on_m_over_b)
    WID_DECL(wid_set_on_m_over_e)
    WID_DECL(wid_set_on_m_up)
    WID_DECL(wid_set_on_destroy)
    WID_DECL(wid_set_on_destroy_b)
    WID_DECL(wid_set_on_tick)
    WID_DECL(wid_set_on_display)
    WID_DECL(wid_set_on_display_win)

    WID_DECL(wid_update)
    WID_DECL(wid_raise)
    WID_DECL(wid_lower)
    WID_DECL(wid_scroll_text)
    WID_DECL(wid_set_focus)
    WID_DECL(wid_set_active)
    WID_DECL(wid_focus_lock)
    WID_DECL(wid_effect_pulses)
    WID_DECL(wid_effect_pulse_forever)
    WID_DECL(wid_effect_pulse_stop)
    WID_DECL(wid_blit_effect_pulses)
    WID_DECL(wid_effect_sways)
    WID_DECL(wid_animate)

    TP_SET_DECL(tile)
    TP_SET_DECL(ms_to_move_one_tile)
    TP_SET_DECL(blit_top_off)
    TP_SET_DECL(blit_bot_off)
    TP_SET_DECL(blit_left_off)
    TP_SET_DECL(blit_right_off)
    TP_SET_DECL(short_name)
    TP_SET_DECL(raw_name)
    TP_SET_DECL(is_animated)
    TP_SET_DECL(is_animated_no_dir)
    TP_SET_DECL(is_animation)
    TP_SET_DECL(is_monst)
    TP_SET_DECL(is_player)
    TP_SET_DECL(is_rrr1)
    TP_SET_DECL(is_rrr2)
    TP_SET_DECL(is_rrr3)
    TP_SET_DECL(is_rrr4)
    TP_SET_DECL(is_rrr5)
    TP_SET_DECL(is_rrr6)
    TP_SET_DECL(is_rrr7)
    TP_SET_DECL(is_rrr8)
    TP_SET_DECL(is_rrr9)
    TP_SET_DECL(is_rrr10)
    TP_SET_DECL(is_rrr11)
    TP_SET_DECL(is_rrr12)
    TP_SET_DECL(is_rrr13)
    TP_SET_DECL(is_rrr14)
    TP_SET_DECL(is_rrr15)
    TP_SET_DECL(is_rrr16)
    TP_SET_DECL(is_rrr17)
    TP_SET_DECL(is_rrr18)
    TP_SET_DECL(is_rrr19)
    TP_SET_DECL(is_rrr20)
    TP_SET_DECL(is_rrr21)
    TP_SET_DECL(is_rrr22)
    TP_SET_DECL(is_rrr23)
    TP_SET_DECL(is_rrr24)
    TP_SET_DECL(is_rrr25)
    TP_SET_DECL(is_rrr26)
    TP_SET_DECL(is_rrr27)
    TP_SET_DECL(is_rrr28)
    TP_SET_DECL(is_rrr29)
    TP_SET_DECL(is_rrr30)
    TP_SET_DECL(is_rrr31)
    TP_SET_DECL(is_rrr32)
    TP_SET_DECL(is_rrr33)
    TP_SET_DECL(is_rrr34)
    TP_SET_DECL(is_rrr35)
    TP_SET_DECL(is_rrr36)
    TP_SET_DECL(is_rrr37)
    TP_SET_DECL(is_rrr38)
    TP_SET_DECL(is_rrr39)
    TP_SET_DECL(is_rrr40)
    TP_SET_DECL(is_rrr41)
    TP_SET_DECL(is_rrr42)
    TP_SET_DECL(is_ladder)
    TP_SET_DECL(is_rrr44)
    TP_SET_DECL(is_rrr45)
    TP_SET_DECL(is_movable)
    TP_SET_DECL(is_solid_ground)
    TP_SET_DECL(is_movement_blocking)
    TP_SET_DECL(is_key)
    TP_SET_DECL(is_wall)
    TP_SET_DECL(is_floor)
    TP_SET_DECL(is_water)
    TP_SET_DECL(is_lava)

    {"game_set_sound_volume",
        (PyCFunction)game_set_sound_volume_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_music_volume",
        (PyCFunction)game_set_music_volume_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_display_sync",
        (PyCFunction)game_set_display_sync_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_full_screen",
        (PyCFunction)game_set_full_screen_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz1",
        (PyCFunction)game_set_zzz1_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz2",
        (PyCFunction)game_set_zzz2_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz3",
        (PyCFunction)game_set_zzz3_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz4",
        (PyCFunction)game_set_zzz4_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz5",
        (PyCFunction)game_set_zzz5_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz6",
        (PyCFunction)game_set_zzz6_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz7",
        (PyCFunction)game_set_zzz7_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz8",
        (PyCFunction)game_set_zzz8_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz9",
        (PyCFunction)game_set_zzz9_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz10",
        (PyCFunction)game_set_zzz10_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz11",
        (PyCFunction)game_set_zzz11_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz12",
        (PyCFunction)game_set_zzz12_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz13",
        (PyCFunction)game_set_zzz13_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz14",
        (PyCFunction)game_set_zzz14_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz15",
        (PyCFunction)game_set_zzz15_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz16",
        (PyCFunction)game_set_zzz16_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz17",
        (PyCFunction)game_set_zzz17_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz18",
        (PyCFunction)game_set_zzz18_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz19",
        (PyCFunction)game_set_zzz19_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz20",
        (PyCFunction)game_set_zzz20_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz21",
        (PyCFunction)game_set_zzz21_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz22",
        (PyCFunction)game_set_zzz22_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz23",
        (PyCFunction)game_set_zzz23_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz24",
        (PyCFunction)game_set_zzz24_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz25",
        (PyCFunction)game_set_zzz25_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz26",
        (PyCFunction)game_set_zzz26_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz27",
        (PyCFunction)game_set_zzz27_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz28",
        (PyCFunction)game_set_zzz28_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz29",
        (PyCFunction)game_set_zzz29_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz30",
        (PyCFunction)game_set_zzz30_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz31",
        (PyCFunction)game_set_zzz31_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz32",
        (PyCFunction)game_set_zzz32_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz33",
        (PyCFunction)game_set_zzz33_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz34",
        (PyCFunction)game_set_zzz34_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz35",
        (PyCFunction)game_set_zzz35_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz36",
        (PyCFunction)game_set_zzz36_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz37",
        (PyCFunction)game_set_zzz37_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz38",
        (PyCFunction)game_set_zzz38_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz39",
        (PyCFunction)game_set_zzz39_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz40",
        (PyCFunction)game_set_zzz40_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz41",
        (PyCFunction)game_set_zzz41_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz42",
        (PyCFunction)game_set_zzz42_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz43",
        (PyCFunction)game_set_zzz43_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz44",
        (PyCFunction)game_set_zzz44_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz45",
        (PyCFunction)game_set_zzz45_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz46",
        (PyCFunction)game_set_zzz46_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz47",
        (PyCFunction)game_set_zzz47_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz48",
        (PyCFunction)game_set_zzz48_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz49",
        (PyCFunction)game_set_zzz49_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz50",
        (PyCFunction)game_set_zzz50_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz51",
        (PyCFunction)game_set_zzz51_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz52",
        (PyCFunction)game_set_zzz52_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz53",
        (PyCFunction)game_set_zzz53_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz54",
        (PyCFunction)game_set_zzz54_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz55",
        (PyCFunction)game_set_zzz55_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz56",
        (PyCFunction)game_set_zzz56_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz57",
        (PyCFunction)game_set_zzz57_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz58",
        (PyCFunction)game_set_zzz58_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz59",
        (PyCFunction)game_set_zzz59_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz60",
        (PyCFunction)game_set_zzz60_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz61",
        (PyCFunction)game_set_zzz61_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz62",
        (PyCFunction)game_set_zzz62_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz63",
        (PyCFunction)game_set_zzz63_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz64",
        (PyCFunction)game_set_zzz64_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz65",
        (PyCFunction)game_set_zzz65_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz66",
        (PyCFunction)game_set_zzz66_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz67",
        (PyCFunction)game_set_zzz67_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz68",
        (PyCFunction)game_set_zzz68_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz69",
        (PyCFunction)game_set_zzz69_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz70",
        (PyCFunction)game_set_zzz70_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz71",
        (PyCFunction)game_set_zzz71_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz72",
        (PyCFunction)game_set_zzz72_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz73",
        (PyCFunction)game_set_zzz73_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz74",
        (PyCFunction)game_set_zzz74_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz75",
        (PyCFunction)game_set_zzz75_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz76",
        (PyCFunction)game_set_zzz76_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz77",
        (PyCFunction)game_set_zzz77_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz78",
        (PyCFunction)game_set_zzz78_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz79",
        (PyCFunction)game_set_zzz79_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz80",
        (PyCFunction)game_set_zzz80_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz81",
        (PyCFunction)game_set_zzz81_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_velocity_air_decay",
        (PyCFunction)game_set_thing_velocity_air_decay_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_jump_speed_max",
        (PyCFunction)game_set_thing_jump_speed_max_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_jump_duration",
        (PyCFunction)game_set_thing_jump_duration_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_accel_max",
        (PyCFunction)game_set_thing_accel_max_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_accel_decay",
        (PyCFunction)game_set_thing_accel_decay_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_jump_step",
        (PyCFunction)game_set_thing_jump_step_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_zzz88",
        (PyCFunction)game_set_zzz88_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_accel_step",
        (PyCFunction)game_set_thing_accel_step_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_velocity_decay",
        (PyCFunction)game_set_thing_velocity_decay_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_velocity_max",
        (PyCFunction)game_set_thing_velocity_max_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_fall_speed_max",
        (PyCFunction)game_set_thing_fall_speed_max_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_thing_fall_speed",
        (PyCFunction)game_set_thing_fall_speed_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    {"game_set_sdl_delay",
        (PyCFunction)game_set_sdl_delay_,
        METH_VARARGS | METH_KEYWORDS,
        ""},

    PYFUNC_REF(SDLGetKeyState),

    {0, 0, 0, 0}   /* sentinel */
};

static struct PyModuleDef python_c_MODULE = {
    PyModuleDef_HEAD_INIT,
    "mm",
    0,
    -1,
    python_c_METHODS,
    0, 0, 0, 0
};

PyMODINIT_FUNC
python_m_y_module_create (void)
{
   PyObject *m = PyModule_Create(&python_c_MODULE);
   if (! m) {
        PyErr_Print();
        DIE("python init");
        return (0);
   }

   return (m);
}

void py_err (void)
{
    PyObject *err = PyErr_Occurred();
    if (!err) {
        return;
    }

    PyObject *ptype, *pvalue, *ptraceback, *pyobj_str;
    PyObject *ret, *list, *string;
    PyObject *mod;
    char *py_str;

    PyErr_Fetch(&ptype, &pvalue, &ptraceback);
    PyErr_NormalizeException(&ptype, &pvalue, &ptraceback);
    PyErr_Display(ptype, pvalue, ptraceback);
    PyTraceBack_Print(ptraceback, pvalue);

    pyobj_str = PyObject_Str(pvalue);
    py_str = py_obj_to_str(pyobj_str);
    ERR("%s", py_str);
    myfree(py_str);

    mod = PyImport_ImportModule("traceback");
    list = PyObject_CallMethod(mod, "format_exception", "OOO", ptype, pvalue, ptraceback);
    if (list) {
        string = PyUnicode_FromString("\n");
        ret = PyUnicode_Join(string, list);
        Py_DECREF(list);
        Py_DECREF(string);

        py_str = py_obj_to_str(ret);
        ERR("%s", py_str);
        myfree(py_str);

        Py_DECREF(ret);
    }

    PyErr_Clear();

    PyThreadState *tstate = PyThreadState_GET();

    if (tstate && tstate->frame) {
        PyFrameObject *frame = tstate->frame;

        ERR("Python stack trace:\n");

        while (frame) {
            int line = frame->f_lineno;
            char *filename = py_obj_to_str(frame->f_code->co_filename);
            char *funcname = py_obj_to_str(frame->f_code->co_name);
            ERR("    %s(%d): %s\n", filename, line, funcname);
            frame = frame->f_back;
            myfree(filename);
            myfree(funcname);
        }
    }
}

void py_exec (const char *str)
{
    char stdOutErr[] =
"import sys\n\
import mm\n\
class CatchOutErr:\n\
    def __init__(self):\n\
        self.value = ''\n\
    def write(self, txt):\n\
        self.value += txt\n\
catchOutErr = CatchOutErr()\n\
sys.stdout = catchOutErr\n\
sys.stderr = catchOutErr\n\
";

    PyObject *pModule = PyImport_AddModule("__main__");

    PyRun_SimpleString(stdOutErr);
    PyRun_SimpleString(str);

    PyObject *catcher = PyObject_GetAttrString(pModule, "catchOutErr");
    PyObject *output = PyObject_GetAttrString(catcher, "value");

    char *text = py_obj_to_str(output);
    if (text) {
        strchopc(text, '\n');
        CON("%s", text);
        myfree(text);
    }
    py_err();
}

static void py_add_to_path (const char *path)
{
    PyObject *py_cur_path, *py_item;
    char *new_path;
    int wc_len, i;
    wchar_t *wc_new_path;
    char *item;

    LOG("Add to PYTHON_PATH: %s", path);

    /*
    LOG("Current system python path:");
     */

    new_path = dupstr(path, __FUNCTION__);
    py_cur_path = PySys_GetObject("path");

    for (i = 0; i < PyList_Size(py_cur_path); i++) {
#ifdef _WIN32
        char *tmp = strappend(new_path, ";");
#else
        char *tmp = strappend(new_path, ":");
#endif
        myfree(new_path);
        new_path = tmp;

        py_item = PyList_GetItem(py_cur_path, i);

        if (!PyUnicode_Check(py_item)) {
            continue;
        }

        item = py_obj_to_str(py_item);
        if (!item) {
            continue;
        }

        /*
        LOG("  %s", item);
         */

        tmp = strappend(new_path, item);
        myfree(new_path);
        new_path = tmp;

        myfree(item);
    }

    /* Convert to wide chars. */
    wc_len = sizeof(wchar_t) * (strlen(new_path) + 1);

    wc_new_path = (wchar_t *) myzalloc(wc_len, "wchar str");
    if (!wc_new_path) {
        DIE("path alloc fail");
    }

    /*
    LOG("Set python path: %s", new_path);
     */

    mbstowcs(wc_new_path, new_path, wc_len);
    PySys_SetPath(wc_new_path);
    myfree(new_path);
    myfree(wc_new_path);
}

static void python_add_consts (void)
{
    PyModule_AddStringConstant(mm_mod, "VERSION", VERSION);
    PyModule_AddIntConstant(mm_mod, "MAP_WIDTH", MAP_WIDTH);
    PyModule_AddIntConstant(mm_mod, "MAP_HEIGHT", MAP_HEIGHT);
    PyModule_AddIntConstant(mm_mod, "MAP_DEPTH", MAP_DEPTH);

    PyModule_AddIntConstant(mm_mod, "KMOD_LSHIFT", KMOD_LSHIFT);
    PyModule_AddIntConstant(mm_mod, "KMOD_RSHIFT", KMOD_RSHIFT);
    PyModule_AddIntConstant(mm_mod, "KMOD_LALT", KMOD_LALT);
    PyModule_AddIntConstant(mm_mod, "KMOD_RALT", KMOD_RALT);
    PyModule_AddIntConstant(mm_mod, "KMOD_LCTRL", KMOD_LCTRL);
    PyModule_AddIntConstant(mm_mod, "KMOD_RCTRL", KMOD_RCTRL);

    PyModule_AddIntConstant(mm_mod, "SDLK_0", SDLK_0);
    PyModule_AddIntConstant(mm_mod, "SDLK_1", SDLK_1);
    PyModule_AddIntConstant(mm_mod, "SDLK_2", SDLK_2);
    PyModule_AddIntConstant(mm_mod, "SDLK_3", SDLK_3);
    PyModule_AddIntConstant(mm_mod, "SDLK_4", SDLK_4);
    PyModule_AddIntConstant(mm_mod, "SDLK_5", SDLK_5);
    PyModule_AddIntConstant(mm_mod, "SDLK_6", SDLK_6);
    PyModule_AddIntConstant(mm_mod, "SDLK_7", SDLK_7);
    PyModule_AddIntConstant(mm_mod, "SDLK_8", SDLK_8);
    PyModule_AddIntConstant(mm_mod, "SDLK_9", SDLK_9);
    PyModule_AddIntConstant(mm_mod, "SDLK_AMPERSAND", SDLK_AMPERSAND);
    PyModule_AddIntConstant(mm_mod, "SDLK_ASTERISK", SDLK_ASTERISK);
    PyModule_AddIntConstant(mm_mod, "SDLK_AT", SDLK_AT);
    PyModule_AddIntConstant(mm_mod, "SDLK_BACKQUOTE", SDLK_BACKQUOTE);
    PyModule_AddIntConstant(mm_mod, "SDLK_BACKSLASH", SDLK_BACKSLASH);
    PyModule_AddIntConstant(mm_mod, "SDLK_BACKSPACE", SDLK_BACKSPACE);
    PyModule_AddIntConstant(mm_mod, "SDLK_CARET", SDLK_CARET);
    PyModule_AddIntConstant(mm_mod, "SDLK_COLON", SDLK_COLON);
    PyModule_AddIntConstant(mm_mod, "SDLK_COMMA", SDLK_COMMA);
    PyModule_AddIntConstant(mm_mod, "SDLK_DELETE", SDLK_DELETE);
    PyModule_AddIntConstant(mm_mod, "SDLK_DOLLAR", SDLK_DOLLAR);
    PyModule_AddIntConstant(mm_mod, "SDLK_EQUALS", SDLK_EQUALS);
    PyModule_AddIntConstant(mm_mod, "SDLK_ESCAPE", SDLK_ESCAPE);
    PyModule_AddIntConstant(mm_mod, "SDLK_EXCLAIM", SDLK_EXCLAIM);
    PyModule_AddIntConstant(mm_mod, "SDLK_GREATER", SDLK_GREATER);
    PyModule_AddIntConstant(mm_mod, "SDLK_HASH", SDLK_HASH);
    PyModule_AddIntConstant(mm_mod, "SDLK_LEFTBRACKET", SDLK_LEFTBRACKET);
    PyModule_AddIntConstant(mm_mod, "SDLK_LEFTPAREN", SDLK_LEFTPAREN);
    PyModule_AddIntConstant(mm_mod, "SDLK_LESS", SDLK_LESS);
    PyModule_AddIntConstant(mm_mod, "SDLK_MINUS", SDLK_MINUS);
    PyModule_AddIntConstant(mm_mod, "SDLK_PERIOD", SDLK_PERIOD);
    PyModule_AddIntConstant(mm_mod, "SDLK_PLUS", SDLK_PLUS);
    PyModule_AddIntConstant(mm_mod, "SDLK_QUESTION", SDLK_QUESTION);
    PyModule_AddIntConstant(mm_mod, "SDLK_QUOTE", SDLK_QUOTE);
    PyModule_AddIntConstant(mm_mod, "SDLK_QUOTEDBL", SDLK_QUOTEDBL);
    PyModule_AddIntConstant(mm_mod, "SDLK_RETURN", SDLK_RETURN);
    PyModule_AddIntConstant(mm_mod, "SDLK_RIGHTBRACKET", SDLK_RIGHTBRACKET);
    PyModule_AddIntConstant(mm_mod, "SDLK_RIGHTPAREN", SDLK_RIGHTPAREN);
    PyModule_AddIntConstant(mm_mod, "SDLK_SEMICOLON", SDLK_SEMICOLON);
    PyModule_AddIntConstant(mm_mod, "SDLK_SLASH", SDLK_SLASH);
    PyModule_AddIntConstant(mm_mod, "SDLK_SPACE", SDLK_SPACE);
    PyModule_AddIntConstant(mm_mod, "SDLK_TAB", SDLK_TAB);
    PyModule_AddIntConstant(mm_mod, "SDLK_UNDERSCORE", SDLK_UNDERSCORE);
    PyModule_AddIntConstant(mm_mod, "SDLK_a", SDLK_a);
    PyModule_AddIntConstant(mm_mod, "SDLK_b", SDLK_b);
    PyModule_AddIntConstant(mm_mod, "SDLK_c", SDLK_c);
    PyModule_AddIntConstant(mm_mod, "SDLK_d", SDLK_d);
    PyModule_AddIntConstant(mm_mod, "SDLK_e", SDLK_e);
    PyModule_AddIntConstant(mm_mod, "SDLK_f", SDLK_f);
    PyModule_AddIntConstant(mm_mod, "SDLK_g", SDLK_g);
    PyModule_AddIntConstant(mm_mod, "SDLK_h", SDLK_h);
    PyModule_AddIntConstant(mm_mod, "SDLK_i", SDLK_i);
    PyModule_AddIntConstant(mm_mod, "SDLK_j", SDLK_j);
    PyModule_AddIntConstant(mm_mod, "SDLK_k", SDLK_k);
    PyModule_AddIntConstant(mm_mod, "SDLK_l", SDLK_l);
    PyModule_AddIntConstant(mm_mod, "SDLK_m", SDLK_m);
    PyModule_AddIntConstant(mm_mod, "SDLK_n", SDLK_n);
    PyModule_AddIntConstant(mm_mod, "SDLK_o", SDLK_o);
    PyModule_AddIntConstant(mm_mod, "SDLK_p", SDLK_p);
    PyModule_AddIntConstant(mm_mod, "SDLK_q", SDLK_q);
    PyModule_AddIntConstant(mm_mod, "SDLK_r", SDLK_r);
    PyModule_AddIntConstant(mm_mod, "SDLK_s", SDLK_s);
    PyModule_AddIntConstant(mm_mod, "SDLK_t", SDLK_t);
    PyModule_AddIntConstant(mm_mod, "SDLK_u", SDLK_u);
    PyModule_AddIntConstant(mm_mod, "SDLK_v", SDLK_v);
    PyModule_AddIntConstant(mm_mod, "SDLK_w", SDLK_w);
    PyModule_AddIntConstant(mm_mod, "SDLK_x", SDLK_x);
    PyModule_AddIntConstant(mm_mod, "SDLK_y", SDLK_y);
    PyModule_AddIntConstant(mm_mod, "SDLK_z", SDLK_z);

#if SDL_MAJOR_VERSION == 1 /* { */
    PyModule_AddIntConstant(mm_mod, "SDLK_KP0", SDLK_KP0);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP1", SDLK_KP1);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP2", SDLK_KP2);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP3", SDLK_KP3);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP4", SDLK_KP4);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP5", SDLK_KP5);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP6", SDLK_KP6);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP7", SDLK_KP7);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP8", SDLK_KP8);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP9", SDLK_KP9);
#else
    PyModule_AddIntConstant(mm_mod, "SDLK_KP0", SDLK_KP_0);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP1", SDLK_KP_1);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP2", SDLK_KP_2);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP3", SDLK_KP_3);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP4", SDLK_KP_4);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP5", SDLK_KP_5);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP6", SDLK_KP_6);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP7", SDLK_KP_7);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP8", SDLK_KP_8);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP9", SDLK_KP_9);
#endif

    PyModule_AddIntConstant(mm_mod, "SDLK_KP_PERIOD", SDLK_KP_PERIOD);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP_DIVIDE", SDLK_KP_DIVIDE);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP_MULTIPLY", SDLK_KP_MULTIPLY);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP_MINUS", SDLK_KP_MINUS);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP_PLUS", SDLK_KP_PLUS);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP_ENTER", SDLK_KP_ENTER);
    PyModule_AddIntConstant(mm_mod, "SDLK_KP_EQUALS", SDLK_KP_EQUALS);
    PyModule_AddIntConstant(mm_mod, "SDLK_UP", SDLK_UP);
    PyModule_AddIntConstant(mm_mod, "SDLK_DOWN", SDLK_DOWN);
    PyModule_AddIntConstant(mm_mod, "SDLK_RIGHT", SDLK_RIGHT);
    PyModule_AddIntConstant(mm_mod, "SDLK_LEFT", SDLK_LEFT);
    PyModule_AddIntConstant(mm_mod, "SDLK_INSERT", SDLK_INSERT);
    PyModule_AddIntConstant(mm_mod, "SDLK_HOME", SDLK_HOME);
    PyModule_AddIntConstant(mm_mod, "SDLK_END", SDLK_END);
    PyModule_AddIntConstant(mm_mod, "SDLK_PAGEUP", SDLK_PAGEUP);
    PyModule_AddIntConstant(mm_mod, "SDLK_PAGEDOWN", SDLK_PAGEDOWN);
    PyModule_AddIntConstant(mm_mod, "SDLK_F1", SDLK_F1);
    PyModule_AddIntConstant(mm_mod, "SDLK_F2", SDLK_F2);
    PyModule_AddIntConstant(mm_mod, "SDLK_F3", SDLK_F3);
    PyModule_AddIntConstant(mm_mod, "SDLK_F4", SDLK_F4);
    PyModule_AddIntConstant(mm_mod, "SDLK_F5", SDLK_F5);
    PyModule_AddIntConstant(mm_mod, "SDLK_F6", SDLK_F6);
    PyModule_AddIntConstant(mm_mod, "SDLK_F7", SDLK_F7);
    PyModule_AddIntConstant(mm_mod, "SDLK_F8", SDLK_F8);
    PyModule_AddIntConstant(mm_mod, "SDLK_F9", SDLK_F9);
    PyModule_AddIntConstant(mm_mod, "SDLK_F10", SDLK_F10);
    PyModule_AddIntConstant(mm_mod, "SDLK_F11", SDLK_F11);
    PyModule_AddIntConstant(mm_mod, "SDLK_F12", SDLK_F12);
    PyModule_AddIntConstant(mm_mod, "SDLK_F13", SDLK_F13);
    PyModule_AddIntConstant(mm_mod, "SDLK_F14", SDLK_F14);
    PyModule_AddIntConstant(mm_mod, "SDLK_F15", SDLK_F15);
    PyModule_AddIntConstant(mm_mod, "SDLK_CAPSLOCK", SDLK_CAPSLOCK);
    PyModule_AddIntConstant(mm_mod, "SDLK_RSHIFT", SDLK_RSHIFT);
    PyModule_AddIntConstant(mm_mod, "SDLK_LSHIFT", SDLK_LSHIFT);
    PyModule_AddIntConstant(mm_mod, "SDLK_RCTRL", SDLK_RCTRL);
    PyModule_AddIntConstant(mm_mod, "SDLK_LCTRL", SDLK_LCTRL);
#if SDL_MAJOR_VERSION > 1
    PyModule_AddIntConstant(mm_mod, "SDLK_RGUI", SDLK_RGUI);
    PyModule_AddIntConstant(mm_mod, "SDLK_LGUI", SDLK_LGUI);
#else
    PyModule_AddIntConstant(mm_mod, "SDLK_RGUI", -1);
    PyModule_AddIntConstant(mm_mod, "SDLK_LGUI", -1);
#endif
    PyModule_AddIntConstant(mm_mod, "SDLK_RALT", SDLK_RALT);
    PyModule_AddIntConstant(mm_mod, "SDLK_LALT", SDLK_LALT);
    PyModule_AddIntConstant(mm_mod, "SDLK_MODE", SDLK_MODE);
    PyModule_AddIntConstant(mm_mod, "SDLK_HELP", SDLK_HELP);
    PyModule_AddIntConstant(mm_mod, "SDLK_SYSREQ", SDLK_SYSREQ);
    PyModule_AddIntConstant(mm_mod, "SDLK_MENU", SDLK_MENU);
    PyModule_AddIntConstant(mm_mod, "SDLK_POWER", SDLK_POWER);
    PyModule_AddIntConstant(mm_mod, "SDLK_UNDO", SDLK_UNDO);


#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_0", SDLK_0);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_0", SDL_SCANCODE_0);
#endif

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_1", SDLK_1);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_1", SDL_SCANCODE_1);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_2", SDLK_2);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_2", SDL_SCANCODE_2);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_3", SDLK_3);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_3", SDL_SCANCODE_3);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_4", SDLK_4);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_4", SDL_SCANCODE_4);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_5", SDLK_5);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_5", SDL_SCANCODE_5);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_6", SDLK_6);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_6", SDL_SCANCODE_6);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_7", SDLK_7);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_7", SDL_SCANCODE_7);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_8", SDLK_8);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_8", SDL_SCANCODE_8);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_9", SDLK_9);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_9", SDL_SCANCODE_9);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_AMPERSAND", SDLK_AMPERSAND);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_AMPERSAND", SDL_SCANCODE_KP_AMPERSAND);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_AT", SDLK_AT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_AT", SDL_SCANCODE_KP_AT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_BACKSLASH", SDLK_BACKSLASH);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_BACKSLASH", SDL_SCANCODE_BACKSLASH);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_BACKSPACE", SDLK_BACKSPACE);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_BACKSPACE", SDL_SCANCODE_BACKSPACE);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_COMMA", SDLK_COMMA);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_COMMA", SDL_SCANCODE_COMMA);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_DELETE", SDLK_DELETE);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_DELETE", SDL_SCANCODE_DELETE);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_EQUALS", SDLK_EQUALS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_EQUALS", SDL_SCANCODE_EQUALS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_ESCAPE", SDLK_ESCAPE);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_ESCAPE", SDL_SCANCODE_ESCAPE);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_GREATER", SDLK_GREATER);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_GREATER", SDL_SCANCODE_KP_GREATER);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_HASH", SDLK_HASH);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_HASH", SDL_SCANCODE_KP_HASH);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LEFTBRACKET", SDLK_LEFTBRACKET);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LEFTBRACKET", SDL_SCANCODE_LEFTBRACKET);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LEFTPAREN", SDLK_LEFTPAREN);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LEFTPAREN", SDL_SCANCODE_KP_LEFTPAREN);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LESS", SDLK_LESS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LESS", SDL_SCANCODE_KP_LESS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_MINUS", SDLK_MINUS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_MINUS", SDL_SCANCODE_MINUS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PERIOD", SDLK_PERIOD);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PERIOD", SDL_SCANCODE_PERIOD);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PLUS", SDLK_PLUS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PLUS", SDL_SCANCODE_KP_PLUS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RETURN", SDLK_RETURN);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RETURN", SDL_SCANCODE_RETURN);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RIGHTBRACKET", SDLK_RIGHTBRACKET);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RIGHTBRACKET", SDL_SCANCODE_RIGHTBRACKET);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RIGHTPAREN", SDLK_RIGHTPAREN);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RIGHTPAREN", SDL_SCANCODE_KP_RIGHTPAREN);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SEMICOLON", SDLK_SEMICOLON);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SEMICOLON", SDL_SCANCODE_SEMICOLON);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SLASH", SDLK_SLASH);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SLASH", SDL_SCANCODE_SLASH);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SPACE", SDLK_SPACE);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SPACE", SDL_SCANCODE_SPACE);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_TAB", SDLK_TAB);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_TAB", SDL_SCANCODE_TAB);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_A", SDLK_a);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_A", SDL_SCANCODE_A);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_B", SDLK_b);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_B", SDL_SCANCODE_B);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_C", SDLK_c);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_C", SDL_SCANCODE_C);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_D", SDLK_d);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_D", SDL_SCANCODE_D);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_E", SDLK_e);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_E", SDL_SCANCODE_E);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F", SDLK_f);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F", SDL_SCANCODE_F);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_G", SDLK_g);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_G", SDL_SCANCODE_G);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_H", SDLK_h);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_H", SDL_SCANCODE_H);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_I", SDLK_i);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_I", SDL_SCANCODE_I);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_J", SDLK_j);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_J", SDL_SCANCODE_J);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_K", SDLK_k);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_K", SDL_SCANCODE_K);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_L", SDLK_l);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_L", SDL_SCANCODE_L);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_M", SDLK_m);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_M", SDL_SCANCODE_M);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_N", SDLK_n);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_N", SDL_SCANCODE_N);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_O", SDLK_o);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_O", SDL_SCANCODE_O);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_P", SDLK_p);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_P", SDL_SCANCODE_P);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_Q", SDLK_q);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_Q", SDL_SCANCODE_Q);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_R", SDLK_r);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_R", SDL_SCANCODE_R);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_S", SDLK_s);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_S", SDL_SCANCODE_S);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_T", SDLK_t);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_T", SDL_SCANCODE_T);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_U", SDLK_u);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_U", SDL_SCANCODE_U);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_V", SDLK_v);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_V", SDL_SCANCODE_V);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_W", SDLK_w);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_W", SDL_SCANCODE_W);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_X", SDLK_x);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_X", SDL_SCANCODE_X);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_Y", SDLK_y);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_Y", SDL_SCANCODE_Y);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_Z", SDLK_z);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_Z", SDL_SCANCODE_Z);
#endif /* } */


#if SDL_MAJOR_VERSION == 1 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP0", SDLk_KP0);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP1", SDLK_KP1);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP2", SDLk_KP2);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP3", SDLK_KP3);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP4", SDLK_KP4);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP5", SDLK_KP5);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP6", SDLK_KP6);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP7", SDLK_KP7);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP8", SDLK_KP8);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP9", SDLK_KP9);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP0", SDLK_KP_0);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP1", SDLK_KP_1);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP2", SDLK_KP_2);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP3", SDLK_KP_3);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP4", SDLK_KP_4);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP5", SDLK_KP_5);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP6", SDLK_KP_6);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP7", SDLK_KP_7);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP8", SDLK_KP_8);
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP9", SDLK_KP_9);
#endif

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_PERIOD", SDLK_KP_PERIOD);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_PERIOD", SDL_SCANCODE_KP_PERIOD);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_DIVIDE", SDLK_KP_DIVIDE);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_DIVIDE", SDL_SCANCODE_KP_DIVIDE);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_MULTIPLY", SDLK_KP_MULTIPLY);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_MULTIPLY", SDL_SCANCODE_KP_MULTIPLY);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_MINUS", SDLK_KP_MINUS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_MINUS", SDL_SCANCODE_KP_MINUS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_PLUS", SDLK_KP_PLUS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_PLUS", SDL_SCANCODE_KP_PLUS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_ENTER", SDLK_KP_ENTER);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_ENTER", SDL_SCANCODE_KP_ENTER);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_EQUALS", SDLK_KP_EQUALS);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_KP_EQUALS", SDL_SCANCODE_KP_EQUALS);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_UP", SDLK_UP);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_UP", SDL_SCANCODE_UP);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_DOWN", SDLK_DOWN);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_DOWN", SDL_SCANCODE_DOWN);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RIGHT", SDLK_RIGHT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RIGHT", SDL_SCANCODE_RIGHT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LEFT", SDLK_LEFT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LEFT", SDL_SCANCODE_LEFT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_INSERT", SDLK_INSERT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_INSERT", SDL_SCANCODE_INSERT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_HOME", SDLK_HOME);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_HOME", SDL_SCANCODE_HOME);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_END", SDLK_END);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_END", SDL_SCANCODE_END);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PAGEUP", SDLK_PAGEUP);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PAGEUP", SDL_SCANCODE_PAGEUP);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PAGEDOWN", SDLK_PAGEDOWN);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_PAGEDOWN", SDL_SCANCODE_PAGEDOWN);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F1", SDLK_F1);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F1", SDL_SCANCODE_F1);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F2", SDLK_F2);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F2", SDL_SCANCODE_F2);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F3", SDLK_F3);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F3", SDL_SCANCODE_F3);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F4", SDLK_F4);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F4", SDL_SCANCODE_F4);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F5", SDLK_F5);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F5", SDL_SCANCODE_F5);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F6", SDLK_F6);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F6", SDL_SCANCODE_F6);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F7", SDLK_F7);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F7", SDL_SCANCODE_F7);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F8", SDLK_F8);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F8", SDL_SCANCODE_F8);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F9", SDLK_F9);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F9", SDL_SCANCODE_F9);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F10", SDLK_F10);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F10", SDL_SCANCODE_F10);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F11", SDLK_F11);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F11", SDL_SCANCODE_F11);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F12", SDLK_F12);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F12", SDL_SCANCODE_F12);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F13", SDLK_F13);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F13", SDL_SCANCODE_F13);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F14", SDLK_F14);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F14", SDL_SCANCODE_F14);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F15", SDLK_F15);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_F15", SDL_SCANCODE_F15);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_CAPSLOCK", SDLK_CAPSLOCK);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_CAPSLOCK", SDL_SCANCODE_CAPSLOCK);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RSHIFT", SDLK_RSHIFT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RSHIFT", SDL_SCANCODE_RSHIFT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LSHIFT", SDLK_LSHIFT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LSHIFT", SDL_SCANCODE_LSHIFT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RCTRL", SDLK_RCTRL);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RCTRL", SDL_SCANCODE_RCTRL);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LCTRL", SDLK_LCTRL);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LCTRL", SDL_SCANCODE_LCTRL);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RALT", SDLK_RALT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_RALT", SDL_SCANCODE_RALT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LALT", SDLK_LALT);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_LALT", SDL_SCANCODE_LALT);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_MODE", SDLK_MODE);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_MODE", SDL_SCANCODE_MODE);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_HELP", SDLK_HELP);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_HELP", SDL_SCANCODE_HELP);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SYSREQ", SDLK_SYSREQ);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_SYSREQ", SDL_SCANCODE_SYSREQ);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_MENU", SDLK_MENU);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_MENU", SDL_SCANCODE_MENU);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_POWER", SDLK_POWER);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_POWER", SDL_SCANCODE_POWER);
#endif /* } */

#if SDL_MAJOR_VERSION == 1 && SDL_MINOR_VERSION == 2 /* { */
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_UNDO", SDLK_UNDO);
#else
    PyModule_AddIntConstant(mm_mod, "SDL_SCANCODE_UNDO", SDL_SCANCODE_UNDO);
#endif /* } */

}

void python_init (char *argv[])
{
#if 0
    PyRun_SimpleString("import sys; sys.path.append('./python3.5/')\n");
    PyRun_SimpleString("import sys; sys.path.append('./python3.5/lib-dynload')\n");
#endif
#ifdef __WIN32
     _putenv_s("PYTHONPATH", "python/;python3.5/;python3.5/lib-dynload;python3.5/site-packages");

    {
        int wc_len;
        wchar_t *wc_new_str;
        const char *str = argv[0];

        /* Convert to wide chars. */
        wc_len = sizeof(wchar_t) * (strlen(str) + 1);

        wc_new_str = (wchar_t *) myzalloc(wc_len, "wchar str");
        if (!wc_new_str) {
            DIE("program name alloc fail");
        }

        LOG("Set python program name: \"%s\"", str);

        mbstowcs(wc_new_str, str, wc_len);
        Py_SetProgramName(wc_new_str);
        myfree(wc_new_str);
    }
#endif

    LOG("Adding mm module");
    PyImport_AppendInittab("mm", python_m_y_module_create);
    LOG("Done adding mm module");

    LOG("Calling Py_Initialize");
    Py_Initialize();
    LOG("Done calling Py_Initialize");

#if  0
    py_add_to_path("./python3.5/");
    py_add_to_path("./python3.5/lib-dynload");
#endif

    py_add_to_path(GFX_PATH);
    py_add_to_path(WORLD_PATH);
    py_add_to_path(DATA_PATH);
    py_add_to_path(PYTHON_PATH);

#ifdef __APPLE__
    py_add_to_path("/Library/Frameworks/Python.framework/Versions/3.5/lib/python3.5/site-packages/");
#endif

    mm_mod = PyImport_ImportModule("mm");
    if (!mm_mod) {
        py_err();
        DIE("module mm import failed");
    }

    python_add_consts();

    mm_mod = PyImport_ImportModule("init");
    if (!mm_mod) {
        py_err();
        DIE("module init import failed");
    }
}

void python_fini (void)
{
   Py_Finalize();
}
