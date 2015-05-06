// Copyright Microsoft. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and / or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "v8.h"
#include "jsrt.h"
#include "jsrtutils.h"

namespace v8 {

uint32_t Array::Length() const {
  unsigned int length;
  jsrt::GetArrayLength((JsValueRef)this, &length);
  return length;
}

Local<Array> Array::New(Isolate* isolate, int length) {
  JsValueRef newArrayRef;

  if (JsCreateArray(length, &newArrayRef) != JsNoError) {
    return Local<Array>();
  }

  return Local<Array>::New(static_cast<Array*>(newArrayRef));
}

Array *Array::Cast(Value *obj) {
  if (!obj->IsArray()) {
    // CHAKRA-TODO: report error?
    return nullptr;
  }

  return static_cast<Array*>(obj);
}

}  // namespace v8
