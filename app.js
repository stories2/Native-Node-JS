const addons_helloworld = require('./build/Release/helloworld.node');
console.log(addons_helloworld.helloworld());

const addons_function_arg = require('./build/Release/function_arg.node');
console.log(addons_function_arg.add(3, 4))

const addons_callback = require('./build/Release/callback.node');
addons_callback((msg) => {
    console.log('result:', msg);
})