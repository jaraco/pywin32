// This file implements the IOleClientSite Interface and Gateway for Python.
// Generated by makegw.py

#include "axcontrol_pch.h"
#include "PyIOleClientSite.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIOleClientSite::PyIOleClientSite(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIOleClientSite::~PyIOleClientSite() {}

/* static */ IOleClientSite *PyIOleClientSite::GetI(PyObject *self) { return (IOleClientSite *)PyIUnknown::GetI(self); }

// @pymethod |PyIOleClientSite|SaveObject|Description of SaveObject.
PyObject *PyIOleClientSite::SaveObject(PyObject *self, PyObject *args)
{
    IOleClientSite *pIOCS = GetI(self);
    if (pIOCS == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":SaveObject"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIOCS->SaveObject();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIOleClientSite|GetMoniker|Description of GetMoniker.
PyObject *PyIOleClientSite::GetMoniker(PyObject *self, PyObject *args)
{
    IOleClientSite *pIOCS = GetI(self);
    if (pIOCS == NULL)
        return NULL;
    // @pyparm int|dwAssign||Description for dwAssign
    // @pyparm int|dwWhichMoniker||Description for dwWhichMoniker
    DWORD dwAssign;
    DWORD dwWhichMoniker;
    IMoniker *ppmk;
    if (!PyArg_ParseTuple(args, "ii:GetMoniker", &dwAssign, &dwWhichMoniker))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIOCS->GetMoniker(dwAssign, dwWhichMoniker, &ppmk);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    return PyCom_PyObjectFromIUnknown(ppmk, IID_IMoniker, FALSE);
}

// @pymethod |PyIOleClientSite|GetContainer|Description of GetContainer.
PyObject *PyIOleClientSite::GetContainer(PyObject *self, PyObject *args)
{
    IOleClientSite *pIOCS = GetI(self);
    if (pIOCS == NULL)
        return NULL;
    IOleContainer *ppContainer;
    if (!PyArg_ParseTuple(args, ":GetContainer"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIOCS->GetContainer(&ppContainer);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    return PyCom_PyObjectFromIUnknown(ppContainer, IID_IOleContainer, FALSE);
}

// @pymethod |PyIOleClientSite|ShowObject|Description of ShowObject.
PyObject *PyIOleClientSite::ShowObject(PyObject *self, PyObject *args)
{
    IOleClientSite *pIOCS = GetI(self);
    if (pIOCS == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":ShowObject"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIOCS->ShowObject();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIOleClientSite|OnShowWindow|Description of OnShowWindow.
PyObject *PyIOleClientSite::OnShowWindow(PyObject *self, PyObject *args)
{
    IOleClientSite *pIOCS = GetI(self);
    if (pIOCS == NULL)
        return NULL;
    // @pyparm int|fShow||Description for fShow
    BOOL fShow;
    if (!PyArg_ParseTuple(args, "i:OnShowWindow", &fShow))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIOCS->OnShowWindow(fShow);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIOleClientSite|RequestNewObjectLayout|Description of RequestNewObjectLayout.
PyObject *PyIOleClientSite::RequestNewObjectLayout(PyObject *self, PyObject *args)
{
    IOleClientSite *pIOCS = GetI(self);
    if (pIOCS == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":RequestNewObjectLayout"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIOCS->RequestNewObjectLayout();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @object PyIOleClientSite|Description of the interface
static struct PyMethodDef PyIOleClientSite_methods[] = {
    {"SaveObject", PyIOleClientSite::SaveObject, 1},      // @pymeth SaveObject|Description of SaveObject
    {"GetMoniker", PyIOleClientSite::GetMoniker, 1},      // @pymeth GetMoniker|Description of GetMoniker
    {"GetContainer", PyIOleClientSite::GetContainer, 1},  // @pymeth GetContainer|Description of GetContainer
    {"ShowObject", PyIOleClientSite::ShowObject, 1},      // @pymeth ShowObject|Description of ShowObject
    {"OnShowWindow", PyIOleClientSite::OnShowWindow, 1},  // @pymeth OnShowWindow|Description of OnShowWindow
    {"RequestNewObjectLayout", PyIOleClientSite::RequestNewObjectLayout,
     1},  // @pymeth RequestNewObjectLayout|Description of RequestNewObjectLayout
    {NULL}};

PyComTypeObject PyIOleClientSite::type("PyIOleClientSite", &PyIUnknown::type, sizeof(PyIOleClientSite),
                                       PyIOleClientSite_methods, GET_PYCOM_CTOR(PyIOleClientSite));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGOleClientSite::SaveObject(void)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("SaveObject", &result);
    if (FAILED(hr))
        return hr;
    hr = PyLong_AsLong(result);
    return hr;
}

STDMETHODIMP PyGOleClientSite::GetMoniker(
    /* [in] */ DWORD dwAssign,
    /* [in] */ DWORD dwWhichMoniker,
    /* [out] */ IMoniker __RPC_FAR *__RPC_FAR *ppmk)
{
    PY_GATEWAY_METHOD;
    if (ppmk == NULL)
        return E_POINTER;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetMoniker", &result, "ii", dwAssign, dwWhichMoniker);

    return E_NOTIMPL; /* TODO: change this as soon as we support IOleContainer */

    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppmk;
    if (!PyArg_Parse(result, "O", &obppmk))
        return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obppmk, IID_IMoniker, (void **)ppmk, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGOleClientSite::GetContainer(
    /* [out] */ IOleContainer __RPC_FAR *__RPC_FAR *ppContainer)
{
    PY_GATEWAY_METHOD;
    if (ppContainer == NULL)
        return E_POINTER;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetContainer", &result);

    return E_NOINTERFACE; /* TODO: change this as soon as we support IOleContainer */

    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppContainer;
    if (!PyArg_Parse(result, "O", &obppContainer))
        return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obppContainer, IID_IOleContainer, (void **)ppContainer,
                                               TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGOleClientSite::ShowObject(void)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("ShowObject", NULL);

    return E_NOTIMPL; /* TODO: change this as soon as we support IOleContainer */
                      //	return OLE_E_NOT_SUPPORTED;  /* TODO: change this as soon as we support IOleContainer */

    return hr;
}

STDMETHODIMP PyGOleClientSite::OnShowWindow(
    /* [in] */ BOOL fShow)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("OnShowWindow", NULL, "i", fShow);
    return S_OK;
    //	return hr;
}

STDMETHODIMP PyGOleClientSite::RequestNewObjectLayout(void)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("RequestNewObjectLayout", NULL);

    return E_NOTIMPL; /* TODO: change this as soon as we support IOleContainer */

    return hr;
}
