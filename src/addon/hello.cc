#include <napi.h>

Napi::Value Add(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong arguments numbers").ThrowAsJavaScriptException();
    return env.Null();
  }

  double result = 0;
  for (int i = 0; i < info.Length(); i++) {
    if (!info[i].IsNumber()) {
      Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
      return env.Null();
    }
    double arg = info[i].As<Napi::Number>().DoubleValue();
    result += arg;
  }
  Napi::Number resultVal = Napi::Number::New(env, result);
  return resultVal;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);