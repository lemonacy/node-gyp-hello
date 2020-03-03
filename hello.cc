/**
 * node-13.9.0 npm-6.13.7 node-gyp-6.1.0
 * npm install -g node-gyp
 * npm configure
 * npm build
 * require('./build/Release/addon.node').hello()
 */

#include <node.h>

namespace demo
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world", NewStringType::kNormal).ToLocalChecked());
}

void Initialize(Local<Object> exports)
{
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace demo