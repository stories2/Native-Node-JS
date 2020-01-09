#include <node.h>
#include <nan.h>

namespace function_arg
{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Context;
    using v8::Number;

    void Add(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = args.GetIsolate()->GetCurrentContext();

        if (args.Length() < 2) {
            Nan::ThrowTypeError("Wrong number of arguments");
            return;
        }

        if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
            Nan::ThrowTypeError("Wrong arguments");
            return;
        }

        double a = args[0]->NumberValue(context).FromJust();
        double b = args[1]->NumberValue(context).FromJust();

        Local<Number> num = Nan::New(a + b);

        args.GetReturnValue().Set(num);
    }
    void init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "add", Add);
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace demo