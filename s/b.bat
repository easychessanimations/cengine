echo off
call emcc src/cengine.cpp src/piece.cpp src/square.cpp src/bitboard.cpp -s WASM=1 -D WASM -o wasmbuild/cengine.html -s EXPORTED_FUNCTIONS="['_init','_execute_uci_command']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap']"
copy srcweb\index.html site\index.html
copy srcweb\index.js site\index.js
type wasmbuild\cengine.js srcweb\preamble.js >site\cengine.js
copy wasmbuild\cengine.wasm site
