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

    void ObjectFactory(const Nan::FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = args.GetIsolate()->GetCurrentContext();

        if(args.Length() < 1) {
            Nan::ThrowTypeError("Wrong number of arguments");
            return;
        }

        Local<Object> obj = Nan::New<Object>();
        obj->Set(context,
                    Nan::New("msgKey").ToLocalChecked(),
                    args[0]->ToString(context).ToLocalChecked());
        
        args.GetReturnValue().Set(obj);
    }
    void init(Local<Object> exports, Local<Object> module)
    {
        Local<Context> context = exports->CreationContext();
        module->Set(context,
                        Nan::New("exports").ToLocalChecked(),
                        Nan::New<FunctionTemplate>(ObjectFactory)
                                ->GetFunction(context)
                                .ToLocalChecked());
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME, init)
}