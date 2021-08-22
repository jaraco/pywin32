// This file implements the IInternetProtocolInfo Interface and Gateway for Python.
// Generated by makegw.py

#include "internet_pch.h"
#include "PyIInternetProtocolInfo.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIInternetProtocolInfo::PyIInternetProtocolInfo(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIInternetProtocolInfo::~PyIInternetProtocolInfo() {}

/* static */ IInternetProtocolInfo *PyIInternetProtocolInfo::GetI(PyObject *self)
{
    return (IInternetProtocolInfo *)PyIUnknown::GetI(self);
}

// @pymethod |PyIInternetProtocolInfo|ParseUrl|Description of ParseUrl.
PyObject *PyIInternetProtocolInfo::ParseUrl(PyObject *self, PyObject *args)
{
    IInternetProtocolInfo *pIIPI = GetI(self);
    if (pIIPI == NULL)
        return NULL;
    // @pyparm <o unicode>|pwzUrl||Description for pwzUrl
    // @pyparm int|ParseAction||Description for ParseAction
    // @pyparm int|dwParseFlags||Description for dwParseFlags
    // @pyparm int|cchResult||Description for cchResult
    // @pyparm int|dwReserved||Description for dwReserved
    PyObject *obpwzUrl;
    LPWSTR pwzUrl;
    PARSEACTION ParseAction;
    DWORD dwParseFlags;
    DWORD cchResult;
    DWORD pcchResult;
    DWORD dwReserved;
    if (!PyArg_ParseTuple(args, "Oiiii:ParseUrl", &obpwzUrl, &ParseAction, &dwParseFlags, &cchResult, &dwReserved))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsBstr(obpwzUrl, &pwzUrl))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    WCHAR *pwzResult = new WCHAR[cchResult];
    PY_INTERFACE_PRECALL;
    hr = pIIPI->ParseUrl(pwzUrl, ParseAction, dwParseFlags, pwzResult, cchResult, &pcchResult, dwReserved);
    PY_INTERFACE_POSTCALL;
    SysFreeString(pwzUrl);

    if (FAILED(hr)) {
        delete[] pwzResult;
        return OleSetOleError(hr);
    }
    PyObject *pyretval = PyWinObject_FromOLECHAR(pwzResult, pcchResult);
    delete[] pwzResult;
    return pyretval;
}

// @pymethod |PyIInternetProtocolInfo|CombineUrl|Description of CombineUrl.
PyObject *PyIInternetProtocolInfo::CombineUrl(PyObject *self, PyObject *args)
{
    IInternetProtocolInfo *pIIPI = GetI(self);
    if (pIIPI == NULL)
        return NULL;
    // @pyparm <o unicode>|pwzBaseUrl||Description for pwzBaseUrl
    // @pyparm <o unicode>|pwzRelativeUrl||Description for pwzRelativeUrl
    // @pyparm int|dwCombineFlags||Description for dwCombineFlags
    // @pyparm int|cchResult||Description for cchResult
    // @pyparm int|dwReserved||Description for dwReserved
    PyObject *obpwzBaseUrl;
    PyObject *obpwzRelativeUrl;
    LPWSTR pwzBaseUrl;
    LPWSTR pwzRelativeUrl;
    DWORD dwCombineFlags;
    DWORD cchResult;
    DWORD pcchResult;
    DWORD dwReserved;
    if (!PyArg_ParseTuple(args, "OOiii:CombineUrl", &obpwzBaseUrl, &obpwzRelativeUrl, &dwCombineFlags, &cchResult,
                          &dwReserved))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsBstr(obpwzBaseUrl, &pwzBaseUrl))
        bPythonIsHappy = FALSE;
    if (!PyWinObject_AsBstr(obpwzRelativeUrl, &pwzRelativeUrl))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    WCHAR *pwzResult = new WCHAR[cchResult];
    PY_INTERFACE_PRECALL;
    hr = pIIPI->CombineUrl(pwzBaseUrl, pwzRelativeUrl, dwCombineFlags, pwzResult, cchResult, &pcchResult, dwReserved);
    PY_INTERFACE_POSTCALL;
    SysFreeString(pwzBaseUrl);
    SysFreeString(pwzRelativeUrl);

    if (FAILED(hr)) {
        delete[] pwzResult;
        return OleSetOleError(hr);
    }
    PyObject *pyretval = PyWinObject_FromOLECHAR(pwzResult, pcchResult);
    delete[] pwzResult;
    return pyretval;
}

// @pymethod |PyIInternetProtocolInfo|CompareUrl|Description of CompareUrl.
PyObject *PyIInternetProtocolInfo::CompareUrl(PyObject *self, PyObject *args)
{
    IInternetProtocolInfo *pIIPI = GetI(self);
    if (pIIPI == NULL)
        return NULL;
    // @pyparm <o unicode>|pwzUrl1||Description for pwzUrl1
    // @pyparm <o unicode>|pwzUrl2||Description for pwzUrl2
    // @pyparm int|dwCompareFlags||Description for dwCompareFlags
    PyObject *obpwzUrl1;
    PyObject *obpwzUrl2;
    LPWSTR pwzUrl1;
    LPWSTR pwzUrl2;
    DWORD dwCompareFlags;
    if (!PyArg_ParseTuple(args, "OOi:CompareUrl", &obpwzUrl1, &obpwzUrl2, &dwCompareFlags))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsBstr(obpwzUrl1, &pwzUrl1))
        bPythonIsHappy = FALSE;
    if (!PyWinObject_AsBstr(obpwzUrl2, &pwzUrl2))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIIPI->CompareUrl(pwzUrl1, pwzUrl2, dwCompareFlags);
    PY_INTERFACE_POSTCALL;
    SysFreeString(pwzUrl1);
    SysFreeString(pwzUrl2);

    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod int\|string|PyIInternetProtocolInfo|QueryInfo|Description of QueryInfo.
PyObject *PyIInternetProtocolInfo::QueryInfo(PyObject *self, PyObject *args)
{
    // @comm If the buffer size is the size of an integer, an integer will be returned, otherwise a string.
    IInternetProtocolInfo *pIIPI = GetI(self);
    if (pIIPI == NULL)
        return NULL;
    // @pyparm <o unicode>|pwzUrl||Description for pwzUrl
    // @pyparm int|OueryOption||Description for OueryOption
    // @pyparm int|dwQueryFlags||Description for dwQueryFlags
    // @pyparm int|cbBuffer||Description for cbBuffer
    // @pyparm int|dwReserved||Description for dwReserved
    PyObject *obpwzUrl;
    LPWSTR pwzUrl;
    QUERYOPTION OueryOption;
    DWORD dwQueryFlags;
    DWORD cbBuffer;
    DWORD pcbBuf;
    DWORD dwReserved;
    if (!PyArg_ParseTuple(args, "Oiiii:QueryInfo", &obpwzUrl, &OueryOption, &dwQueryFlags, &cbBuffer, &dwReserved))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsBstr(obpwzUrl, &pwzUrl))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    void *pBuffer;
    void *pFreeBuf = NULL;
    DWORD dwBuf;
    if (cbBuffer == sizeof(DWORD)) {
        pBuffer = &dwBuf;
    }
    else {
        pBuffer = pFreeBuf = malloc(cbBuffer);
    }
    PY_INTERFACE_PRECALL;
    hr = pIIPI->QueryInfo(pwzUrl, OueryOption, dwQueryFlags, pBuffer, cbBuffer, &pcbBuf, dwReserved);
    PY_INTERFACE_POSTCALL;
    SysFreeString(pwzUrl);

    if (FAILED(hr)) {
        if (pFreeBuf)
            free(pFreeBuf);
        return OleSetOleError(hr);
    }
    PyObject *rc = pFreeBuf == NULL ? PyLong_FromLong(dwBuf) : PyBytes_FromStringAndSize((char *)pBuffer, pcbBuf);
    if (pFreeBuf)
        free(pFreeBuf);
    return rc;
}

// @object PyIInternetProtocolInfo|Description of the interface
static struct PyMethodDef PyIInternetProtocolInfo_methods[] = {
    {"ParseUrl", PyIInternetProtocolInfo::ParseUrl, 1},      // @pymeth ParseUrl|Description of ParseUrl
    {"CombineUrl", PyIInternetProtocolInfo::CombineUrl, 1},  // @pymeth CombineUrl|Description of CombineUrl
    {"CompareUrl", PyIInternetProtocolInfo::CompareUrl, 1},  // @pymeth CompareUrl|Description of CompareUrl
    {"QueryInfo", PyIInternetProtocolInfo::QueryInfo, 1},    // @pymeth QueryInfo|Description of QueryInfo
    {NULL}};

PyComTypeObject PyIInternetProtocolInfo::type("PyIInternetProtocolInfo", &PyIUnknown::type,
                                              sizeof(PyIInternetProtocolInfo), PyIInternetProtocolInfo_methods,
                                              GET_PYCOM_CTOR(PyIInternetProtocolInfo));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGInternetProtocolInfo::ParseUrl(
    /* [in] */ LPCWSTR pwzUrl,
    /* [in] */ PARSEACTION ParseAction,
    /* [in] */ DWORD dwParseFlags,
    /* [out] */ LPWSTR pwzResult,
    /* [in] */ DWORD cchResult,
    /* [out] */ DWORD __RPC_FAR *pcchResult,
    /* [in] */ DWORD dwReserved)
{
    PY_GATEWAY_METHOD;
    PyObject *obpwzUrl;
    obpwzUrl = MakeOLECHARToObj(pwzUrl);
    PyObject *result;
    HRESULT hr =
        InvokeViaPolicy("ParseUrl", &result, "Oiiii", obpwzUrl, ParseAction, dwParseFlags, cchResult, dwReserved);
    Py_XDECREF(obpwzUrl);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    BOOL bPythonIsHappy = TRUE;
    BSTR bstrTemp;
    if (!PyWinObject_AsBstr(result, &bstrTemp, FALSE, pcchResult))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    ++(*pcchResult);  // Null terminator
    *pcchResult = min(*pcchResult, cchResult);
    memcpy(pwzResult, bstrTemp, *pcchResult * sizeof(WCHAR));
    SysFreeString(bstrTemp);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGInternetProtocolInfo::CombineUrl(
    /* [in] */ LPCWSTR pwzBaseUrl,
    /* [in] */ LPCWSTR pwzRelativeUrl,
    /* [in] */ DWORD dwCombineFlags,
    /* [out] */ LPWSTR pwzResult,
    /* [in] */ DWORD cchResult,
    /* [out] */ DWORD __RPC_FAR *pcchResult,
    /* [in] */ DWORD dwReserved)
{
    PY_GATEWAY_METHOD;
    PyObject *obpwzBaseUrl;
    PyObject *obpwzRelativeUrl;
    obpwzBaseUrl = MakeOLECHARToObj(pwzBaseUrl);
    obpwzRelativeUrl = MakeOLECHARToObj(pwzRelativeUrl);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("CombineUrl", &result, "OOiii", obpwzBaseUrl, obpwzRelativeUrl, dwCombineFlags,
                                 cchResult, dwReserved);
    Py_XDECREF(obpwzBaseUrl);
    Py_XDECREF(obpwzRelativeUrl);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    BOOL bPythonIsHappy = TRUE;
    BSTR bstrTemp;
    if (!PyWinObject_AsBstr(result, &bstrTemp, FALSE, pcchResult))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
    ++(*pcchResult);  // Null terminator
    *pcchResult = min(*pcchResult, cchResult);
    memcpy(pwzResult, bstrTemp, *pcchResult * sizeof(WCHAR));
    SysFreeString(bstrTemp);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGInternetProtocolInfo::CompareUrl(
    /* [in] */ LPCWSTR pwzUrl1,
    /* [in] */ LPCWSTR pwzUrl2,
    /* [in] */ DWORD dwCompareFlags)
{
    PY_GATEWAY_METHOD;
    PyObject *obpwzUrl1;
    PyObject *obpwzUrl2;
    obpwzUrl1 = MakeOLECHARToObj(pwzUrl1);
    obpwzUrl2 = MakeOLECHARToObj(pwzUrl2);
    HRESULT hr = InvokeViaPolicy("CompareUrl", NULL, "OOi", obpwzUrl1, obpwzUrl2, dwCompareFlags);
    Py_XDECREF(obpwzUrl1);
    Py_XDECREF(obpwzUrl2);
    return hr;
}

STDMETHODIMP PyGInternetProtocolInfo::QueryInfo(
    /* [in] */ LPCWSTR pwzUrl,
    /* [in] */ QUERYOPTION OueryOption,
    /* [in] */ DWORD dwQueryFlags,
    /* [size_is][out][in] */ LPVOID pBuffer,
    /* [in] */ DWORD cbBuffer,
    /* [out][in] */ DWORD __RPC_FAR *pcbBuf,
    /* [in] */ DWORD dwReserved)
{
    if (pcbBuf == NULL)
        return E_POINTER;
    *pcbBuf = 0;
    PY_GATEWAY_METHOD;
    PyObject *obpwzUrl;
    obpwzUrl = MakeOLECHARToObj(pwzUrl);
    PyObject *result;
    HRESULT hr =
        InvokeViaPolicy("QueryInfo", &result, "Oiiii", obpwzUrl, OueryOption, dwQueryFlags, cbBuffer, dwReserved);
    Py_XDECREF(obpwzUrl);
    if (FAILED(hr))
        return hr;
    if (!PyBytes_Check(result)) {
        if (PyLong_Check(result)) {
            if (cbBuffer != sizeof(DWORD)) {
                PyErr_SetString(PyExc_TypeError,
                                "IInternetProtocolInfo::QueryInfo can return an integer only when sizeof(int) bytes "
                                "are requested.");
                return PyCom_HandlePythonFailureToCOM();
            }
            *pcbBuf = sizeof(DWORD);
            *((DWORD *)pBuffer) = PyLong_AsLong(result);
        }
        else {
            PyErr_SetString(
                PyExc_TypeError,
                "IInternetProtocolInfo::QueryInfo must return a string, or an integer iff cbBuffer==sizeof(int)");
            return PyCom_HandlePythonFailureToCOM();
        }
    }
    else {
        *pcbBuf = min(cbBuffer, (ULONG)PyBytes_Size(result));
        memcpy(pBuffer, PyBytes_AsString(result), *pcbBuf);
    }
    Py_DECREF(result);
    return hr;
}
