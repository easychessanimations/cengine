const fs = require('fs');
const buf = fs.readFileSync('./simple.wasm');

WebAssembly.instantiate(new Uint8Array(buf)).then(res => {
	const moduleExports = res.instance.exports

	const addTwo = moduleExports.addTwo

	console.log("addTwo(1,1) = ", addTwo(1,1))
})
