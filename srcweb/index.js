var worker

function sendCommand(){
	let ce = document.getElementById("command")

	let command = ce.value

	execute_uci_command(command)

	ce.value = ""
}

function handleKeyUp(ev){
	if(ev.keyCode == 13){
		sendCommand()
	}
}

function onLoad(){
	console.log("document loaded")

	document.getElementById("command").addEventListener("keyup", handleKeyUp)
}
