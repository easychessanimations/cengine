echo off
call emcc src/cengine.cpp src/piece.cpp src/square.cpp src/bitboard.cpp src/attack.cpp src/state.cpp -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -D WASM -O2 -o wasmbuild/cengine.html -s EXPORTED_FUNCTIONS="['_main','_execute_uci_command']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']"
copy srcweb\index.html site\index.html
copy srcweb\index.js site\index.js
type wasmbuild\cengine.js srcweb\preamble.js >site\cengine.js
copy wasmbuild\cengine.wasm site
