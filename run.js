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

function stringToMem(str, offset){
	for(let i=0;i<str.length;i++){
		i32[offset+i]=str.charCodeAt(i)
	}
}

WebAssembly.instantiate(new Uint8Array(buf), importObject).then(res => {
	const moduleExports = res.instance.exports

	const toUpper = moduleExports.toUpper
	const toLower = moduleExports.toLower

	stringToMem("123abcDEF", 0)

	toUpper(4)

	console.log(memToString(0))

	stringToMem("123ABCdef", 0)

	toLower(4)

	console.log(memToString(0))
})
