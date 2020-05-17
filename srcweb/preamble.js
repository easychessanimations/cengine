// preamble

var execute_uci_command = Module.cwrap('execute_uci_command', '', ['string'])

onmessage = ev => {
	let data = ev.data

	console.log("app sent", ev.data)

	let kind = data.kind

	if(kind == "welcome"){
		postMessage({
			kind: "welcomeack",
			content: "hi, app !"
		})
	}

	if(kind == "command"){
		execute_uci_command(data.content)
	}
}

