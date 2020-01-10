#ifndef OBJECT_WRAP_H
#define OBJECT_WRAP_H

#include <nan.h>

    using v8::Context;
    using v8::Function;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

class object_wrap : public Nan::ObjectWrap
{
    public:
        static void Init(Local<Object> exports);
    
    private:
        explicit object_wrap(double value = 0);
        ~object_wrap();

        static void New(const Nan::FunctionCallbackInfo<Value> &args);
        static void GetValue(const Nan::FunctionCallbackInfo<Value> &args);
        static void PlusOne(const Nan::FunctionCallbackInfo<Value> &args);
        static void Multiply(const Nan::FunctionCallbackInfo<Value> &args);
        static Nan::Persistent<Function> constructor;
        double value_;
};

#endif