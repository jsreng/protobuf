//
// See http://docs.python.org/extending/extending.html#providing-a-c-api-for-an-extension-module
//
#ifndef GOOGLE_PROTOBUF_PYTHON_PYTHON_PROTO2_H__
#define GOOGLE_PROTOBUF_PYTHON_PYTHON_PROTO2_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <Python.h>

  /* C API functions */
#define PyProtobuf_GetCProtoInsidePyProtobuf_NUM 0
#define PyProtobuf_GetCProtoInsidePyProtobuf_RETURN const google::protobuf::Message*
#define PyProtobuf_GetCProtoInsidePyProtobuf_PROTO (PyObject* msg)

#define PyProtobuf_MutableCProtoInsidePyProtobuf_NUM 1
#define PyProtobuf_MutableCProtoInsidePyProtobuf_RETURN google::protobuf::Message*
#define PyProtobuf_MutableCProtoInsidePyProtobuf_PROTO (PyObject* msg)

#define PyProtobuf_NewPyProtoFromCProto_NUM 2
#define PyProtobuf_NewPyProtoFromCProto_RETURN PyObject*
#define PyProtobuf_NewPyProtoFromCProto_PROTO (google::protobuf::Message*)
  
#define PyProtobuf_ClonePyProtoFromCProto_NUM 3
#define PyProtobuf_ClonePyProtoFromCProto_RETURN PyObject*
#define PyProtobuf_ClonePyProtoFromCProto_PROTO (const google::protobuf::Message*)

#define PyProtobuf_DisownCProto_NUM 4
#define PyProtobuf_DisownCProto_RETURN void
#define PyProtobuf_DisownCProto_PROTO (PyObject*)

  /* Total number of C API pointers */
#define PyProtobuf_API_pointers 5

#define PyProtobuf_GetCProtoInsidePyProtobuf \
  (*(PyProtobuf_GetCProtoInsidePyProtobuf_RETURN (*)PyProtobuf_GetCProtoInsidePyProtobuf_PROTO) (GetPyProtobuf_API())[PyProtobuf_GetCProtoInsidePyProtobuf_NUM])

#define PyProtobuf_MutableCProtoInsidePyProtobuf \
  (*(PyProtobuf_MutableCProtoInsidePyProtobuf_RETURN (*)PyProtobuf_MutableCProtoInsidePyProtobuf_PROTO) (GetPyProtobuf_API())[PyProtobuf_MutableCProtoInsidePyProtobuf_NUM])

#define PyProtobuf_NewPyProtoFromCProto \
  (*(PyProtobuf_NewPyProtoFromCProto_RETURN (*)PyProtobuf_NewPyProtoFromCProto_PROTO) (GetPyProtobuf_API())[PyProtobuf_NewPyProtoFromCProto_NUM])

#define PyProtobuf_ClonePyProtoFromCProto \
  (*(PyProtobuf_ClonePyProtoFromCProto_RETURN (*)PyProtobuf_ClonePyProtoFromCProto_PROTO) (GetPyProtobuf_API())[PyProtobuf_ClonePyProtoFromCProto_NUM])

#define PyProtobuf_DisownCProto \
  (*(PyProtobuf_DisownCProto_RETURN (*)PyProtobuf_DisownCProto_PROTO) (GetPyProtobuf_API())[PyProtobuf_DisownCProto_NUM])

  // Singleton access
  static void** GetPyProtobuf_API()
  {
    static void **PyProtobuf_API = NULL;

    // Load the table if not already done
    if(!PyProtobuf_API)
    {
      PyObject *c_api_object;
      PyObject *module;

      // Load module _net_proto2___python
      module = PyImport_ImportModule("google.protobuf.internal._net_proto2___python");
      if (module == NULL)
      {
        PyErr_SetString(PyExc_RuntimeError, "Unable to load module <_net_proto2___python>");
        return NULL;
      }

      // Get the c api
      c_api_object = PyObject_GetAttrString(module, "_C_API");
      if (NULL == c_api_object) 
      {
        Py_DECREF(module);
        PyErr_SetString(PyExc_RuntimeError, "Unable to find \"_C_API\" string in module <_net_proto2___python>");
        return NULL;
      }

      // Check the c api type
      if(!PyCObject_Check(c_api_object))
      {
        Py_DECREF(c_api_object);
        Py_DECREF(module);
        PyErr_SetString(PyExc_RuntimeError, "Invalid type for \"_C_API\" string in module <_net_proto2___python>");
        return NULL;
      }

      // Get the protobuf api functions table
      PyProtobuf_API = (void **)PyCObject_AsVoidPtr(c_api_object);

      // ok decrease reference
      Py_DECREF(c_api_object);
      Py_DECREF(module);
    }

    return PyProtobuf_API;
  }

#ifdef __cplusplus
}
#endif

#endif /* !defined(GOOGLE_PROTOBUF_PYTHON_PYTHON_PROTO2_H__) */
