#include <node.h>
#include <nan.h>

namespace object_factory
{
    // using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Context;
    using v8::Number;
    using v8::Function;

    void SampleFunc(const Nan::FunctionCallbackInfo<Value> &args) {
        args.GetReturnValue().Set(Nan::New("Hello world from SampleFunc").ToLocalChecked());
    }

    void FunctionFactory(const Nan::FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = args.GetIsolate()->GetCurrentContext();

        Local<FunctionTemplate> funcTemplate = Nan::New<FunctionTemplate>(SampleFunc);
        Local<Function> func = funcTemplate->GetFunction(context).ToLocalChecked();

        func->SetName(Nan::New("sampleFunction").ToLocalChecked());

        args.GetReturnValue().Set(func);
    }

    void init(Local<Object> exports, Local<Object> module)
    {
        Nan::SetMethod(module, "exports", FunctionFactory);
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME, init)
}