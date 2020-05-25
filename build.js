const fs = require('fs')
const { spawn } = require("child_process");

const EXPORTED_FUNCTIONS = [
	"main",
	"execute_uci_command"
]

let optimizeFlag = process.argv[2] == "o" ? "-O2 " : ""

fs.readdir("src", (_,items)=>{
	let srcs = items.filter(item=>item.match(/\.cpp$|\.c$/)).map(item=>"src/"+item).join(" ")

	let emcc = `emcc ${srcs} -s WASM=1 -s TOTAL_MEMORY=500MB -s ALLOW_MEMORY_GROWTH=1 -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=2 -D WASM ${optimizeFlag}-o wasmbuild/cengine.html -s EXPORTED_FUNCTIONS="[${EXPORTED_FUNCTIONS.map(ef => "'_"+ef+"'").join(",")}]" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']"`

	const cmd = spawn('cmd', []);

	cmd.stdout.on('data', data => {
	  if(data.toString().match(/endbuild/)) cmd.kill()
	})

	cmd.stderr.on('data', data => {
		let content = data.toString()
	  if(content.match(/[^\s]+/)){
	  	if(!content.match(/wasmbuild|srcweb/))
	  	console.log("err", content)
	  }
	})

	cmd.stdin.write("s\\e\n")

	console.log("building wasm", optimizeFlag)

	console.log(emcc)

	cmd.stdin.write(emcc+"\n")

	cmd.stdin.write("s\\bo\n")

	echo = true

	cmd.stdin.write("echo endbuild\n")
})

