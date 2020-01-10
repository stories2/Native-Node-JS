#include "object_wrap.h"

Nan::Persistent<Function> object_wrap::constructor;

object_wrap::object_wrap(double value) : value_(value) {}

object_wrap::~object_wrap() {}

void object_wrap::Init(Local<Object> exports)
{
    Local<Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("object_wrap").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "value", GetValue);
    Nan::SetPrototypeMethod(tpl, "plusOne", PlusOne);
    Nan::SetPrototypeMethod(tpl, "multiply", Multiply);

    constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
    exports->Set(context,
                 Nan::New("object_wrap").ToLocalChecked(),
                 tpl->GetFunction(context).ToLocalChecked());
}

void object_wrap::New(const Nan::FunctionCallbackInfo<Value> &args)
{
    Local<Context> context = args.GetIsolate()->GetCurrentContext();
    if (args.IsConstructCall())
    {
        // Invoked as constructor: `new MyObject(...)`
        double value =
            args[0]->IsUndefined() ? 0 : args[0]->NumberValue(context).FromJust();
        object_wrap *obj = new object_wrap(value);
        obj->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }
    else
    {
        // Invoked as plain function `MyObject(...)`, turn into construct call.
        const int argc = 1;
        Local<Value> argv[argc] = {args[0]};
        Local<Function> cons = Nan::New<Function>(constructor);
        args.GetReturnValue().Set(
            cons->NewInstance(context, argc, argv).ToLocalChecked());
    }
}

void object_wrap::GetValue(const Nan::FunctionCallbackInfo<Value> &args)
{
    object_wrap *obj = ObjectWrap::Unwrap<object_wrap>(args.Holder());
    args.GetReturnValue().Set(Nan::New(obj->value_));
}

void object_wrap::PlusOne(const Nan::FunctionCallbackInfo<Value> &args)
{
    object_wrap *obj = ObjectWrap::Unwrap<object_wrap>(args.Holder());
    obj->value_ += 1;
    args.GetReturnValue().Set(Nan::New(obj->value_));
}

void object_wrap::Multiply(const Nan::FunctionCallbackInfo<Value> &args)
{
    Local<Context> context = args.GetIsolate()->GetCurrentContext();
    object_wrap *obj = ObjectWrap::Unwrap<object_wrap>(args.Holder());
    double multiple =
        args[0]->IsUndefined() ? 1 : args[0]->NumberValue(context).FromJust();

    Local<Function> cons = Nan::New<Function>(constructor);

    const int argc = 1;
    Local<Value> argv[argc] = {Nan::New(obj->value_ * multiple)};

    args.GetReturnValue().Set(
        cons->NewInstance(context, argc, argv).ToLocalChecked());
}