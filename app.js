const addons_helloworld = require('./build/Release/helloworld.node');
console.log(addons_helloworld.helloworld());

const addons_function_arg = require('./build/Release/function_arg.node');
console.log(addons_function_arg.add(3, 4))

const addons_callback = require('./build/Release/callback.node');
addons_callback((msg) => {
    console.log('result:', msg);
})

const addons_object_factory = require('./build/Release/object_factory.node');
var aObj = addons_object_factory('Yo! bro.');
var bObj = addons_object_factory('Sup!');
console.log('result:', aObj.msgKey + ' ---> ' + bObj.msgKey);

const addons_function_factory = require('./build/Release/function_factory.node');
var func = addons_function_factory();
console.log('result:', func());