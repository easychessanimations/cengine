# cengine

Visual studio and Emscripten compilable chess engine.

# Building

# Visual Studio

## IDE

Open the project `cengine.vcxproj` in Visual Studio and in `Build` menu click on `Build Solution`.

## Command line

```
vcvarsall x64
msbuild /property:Configuration=Release
```

Note that `vcvarsall` is Visual Studio's script that sets up a build environment. It has to be in your path. The path to it should look something like `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build`.

# Emscripten

## Compiling WASM

```
emcc src/attack.cpp src/bitboard.cpp src/cengine.cpp src/matein4.cpp src/piece.cpp src/search.cpp src/square.cpp src/state.cpp -s WASM=1 -s TOTAL_MEMORY=200MB -s ALLOW_MEMORY_GROWTH=1 -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=2 -D WASM -o wasmbuild/cengine.html -s EXPORTED_FUNCTIONS="['_main','_execute_uci_command']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']"
```

## Building the site

### Windows

Run the build script:

```
s\bo
```

### Other system

Study the `s\bo.bat` build script, and create an equivalent of it on your system and run that script. It essentially copies the necessary files to the site folder, and concats `wasmbuild\cengine.js` and `srcweb\preamble.js` as `cengine.js` in the site folder.

## Serving the site

You can drag and drop the `site` folder to Netlify and it will work as a site.

To use it locally, assuming you have installed `http-server` with `npm install http-server -g` ( but any other simple server that serves up a folder would do ):

```
cd site
http-server
```

Then visit `localhost:8080`.

# GNU C++

```
g++ src/square.cpp src/attack.cpp src/bitboard.cpp src/cengine.cpp src/matein4.cpp src/piece.cpp src/search.cpp src/square.cpp src/state.cpp -D WASM -D GCCBUILD -O3 -pthread
```

Note that `WASM` is turned on in the build, because in the original WASM build the WASM compiler flag in many places only means `g++` style compilation, as `emcc` is similar in behavior to `g++`. The `GCCBUILD` flag compensates for the small difference compared to the real WASM build.
