const fs = require('fs');
const buf = fs.readFileSync('./simple.wasm');

const memory = new WebAssembly.Memory({initial:1})

const i32 = new Uint32Array(memory.buffer)

const importObject = { js: { mem: memory } }

function memToString(offset){
	let buff = ""

	while(i32[offset] != 0){
		buff += String.fromCharCode(i32[offset++])
	}

	return buff
}

WebAssembly.instantiate(new Uint8Array(buf), importObject).then(res => {
	const moduleExports = res.instance.exports

	const addTwo = moduleExports.addTwo

	i32[0] = 123

	console.log("addTwo(0,1) = ", addTwo(0,1))

	i32[1] = 456

	console.log("addTwo(1,1) = ", addTwo(1,1))

	for(let i=0;i<2;i++) console.log(i, i32[i])

	console.log(memToString(0))
})
