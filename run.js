const fs = require('fs');
const buf = fs.readFileSync('./simple.wasm');

const memory = new WebAssembly.Memory({initial:1})

const i32 = new Uint32Array(memory.buffer)

const importObject = { js: { mem: memory } }

WebAssembly.instantiate(new Uint8Array(buf), importObject).then(res => {
	const moduleExports = res.instance.exports

	const addTwo = moduleExports.addTwo

	i32[0] = 123

	console.log("addTwo(1,1) = ", addTwo(0,1))

	i32[0] = 456

	console.log("addTwo(1,1) = ", addTwo(0,1))
})
