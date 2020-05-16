call emcc src/cengine.cpp -s WASM=1 -o wasmbuild/cengine.html
copy wasmbuild\cengine.html site\index.html
copy wasmbuild\cengine.js site
copy wasmbuild\cengine.wasm site