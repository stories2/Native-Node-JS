# Native-Node-JS
Create node module using c++


## Setup

```
npm install node-gyp -g
npm install bindings --save
npm --add-python-to-path='true' --debug install --global windows-build-tools 

# windows
set PYTHON=C:\Users\user\.windows-build-tools\python27\python.exe
```

## configure

```
node-gyp configure
```

## Build

```
node-gyp build
```

## Run from NodeJS

```
node app.js
```