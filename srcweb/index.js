var worker

function sendCommand(){
	let ce = document.getElementById("command")

	let command = ce.value

	worker.postMessage({
		kind: "command",
		content: command,
	})

	ce.value = ""
}

function handleKeyUp(ev){
	if(ev.keyCode == 13){
		sendCommand()
	}
}

function onLoad(){
	console.log("document loaded")

	worker = new Worker("cengine.js")

	worker.onmessage = ev => {
		console.log("worker sent", ev.data)
	}

	worker.postMessage({
		kind: "welcome",
		content: "hi, worker !",
	})

	document.getElementById("command").addEventListener("keyup", handleKeyUp)
}
