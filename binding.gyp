{
"targets": [
   {
     "target_name": "helloworld",
     "sources": [ "helloworld.cc" ], 
   },
   {
     "target_name": "function_arg",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
    ],
    "sources": [
      "function_arg.cc"
    ]
   },
   {
     "target_name": "callback",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
    ],
    "sources": [
      "callback.cc"
    ]
   },
   {
     "target_name": "object_factory",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
    ],
    "sources": [
      "object_factory.cc"
    ]
   },
   {
     "target_name": "function_factory",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
    ],
    "sources": [
      "function_factory.cc"
    ]
   }
  ]
}