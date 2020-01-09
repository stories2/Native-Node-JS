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
   }
  ]
}