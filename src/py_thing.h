/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the README file for license info.
 */

#pragma once

#include <Python.h>

PyObject *thing_new_(PyObject *obj, PyObject *args, PyObject *keywds);

#define THING_SET_PROTO(__field__)                                              \
PyObject *thing_set_ ## __field__ (PyObject *obj, PyObject *args, PyObject *keywds);

#define THING_PROTO(__field__)                                                  \
PyObject *__field__ (PyObject *obj, PyObject *args, PyObject *keywds);

#define THING_SET_DECL(__field__)                                               \
    {"thing_set_" #__field__,                                                   \
        (PyCFunction)thing_set_ ## __field__,                                   \
        METH_VARARGS | METH_KEYWORDS,                                           \
        "set a " #__field__ " in a thing"},                                     \

#define THING_DECL(__field__)                                                   \
    {#__field__,                                                                \
        (PyCFunction)__field__,                                                 \
        METH_VARARGS | METH_KEYWORDS,                                           \
        "call " #__field__ " in a thing"},                                      \

THING_PROTO(thing_set_tilename)
THING_PROTO(thing_set_tp)
THING_PROTO(thing_destroyed)
THING_PROTO(thing_move_delta)
THING_PROTO(thing_push)
THING_PROTO(thing_collision_check)
THING_PROTO(thing_pop)
