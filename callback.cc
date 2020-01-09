#include <node.h>
#include <nan.h>

namespace function_arg
{
    // using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Context;
    using v8::Number;
    using v8::Function;

    void CallbackFunc(const Nan::FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = args.GetIsolate()->GetCurrentContext();

        if(args.Length() < 1) {
            Nan::ThrowTypeError("Wrong number of arguments");
            return;
        }

        Local<Function> cb = args[0].As<Function>();
        const unsigned argc = 1;
        Local<Value> argv[argc] = {
            Nan::New("Hello World from c++").ToLocalChecked()
        };

        Nan::MakeCallback(context->Global(), cb, argc, argv);
    }
    void init(Local<Object> exports, Local<Object> module)
    {
        // NODE_SET_METHOD(exports, "add", Add);
        Nan::SetMethod(module, "exports", CallbackFunc);
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace demo