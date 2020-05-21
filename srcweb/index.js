var worker

var sendCommand = function(){}

function handleKeyUp(ev){
	if(ev.keyCode == 13){
		sendCommand()
	}
}

class LogItem_{
constructor(propsOpt){
  this.props = propsOpt || {
    msg: "Empty message."
  }

  this.msg = this.props.msg

  this.kind = this.props.kind || "normal"

  this.prefix = this.props.prefix || ( this.kind == "warn" ? "!" : "<<" )

  this.time = Math.round(performance.now())
}

asTableRow(){
  let tr = document.createElement("tr")
  let timeTd = document.createElement("td")
  timeTd.style.textAlign = "center"
  timeTd.style.color = "#077"
  timeTd.innerHTML = "" + this.time
  let msgTd = document.createElement("td")
  if(this.kind == "normal") msgTd.style.color = "#070"
  if(this.kind == "info") msgTd.style.color = "#007"
  if(this.kind == "warn") msgTd.style.color = "#770"
  msgTd.innerHTML = "<pre style='margin: 0px;'>" + this.msg + "</pre>"
  tr.appendChild(timeTd)
  tr.appendChild(msgTd)

  return tr
}
}
function LogItem(props){return new LogItem_(props)}

class Logger_{
constructor(propsOpt){
  this.props = propsOpt || {}

  this.capacity = this.props.capacity || 250

  this.id = this.props.id || "logroot"

  this.items = []
}

log(logItem){
  this.items.unshift(logItem)

  while(this.items.length > this.capacity) this.items.pop()
}

asTable(){
  let table = document.createElement("table")
  table.setAttribute("cellpadding", 3)
  table.setAttribute("cellspacing", 3)
  let thead = document.createElement("thead")
  thead.style.fontStyle = "italic"
  let timeTd = document.createElement("td")
  timeTd.innerHTML = "Performance now [ms]"
  timeTd.style.minWidth = "150px"
  timeTd.style.textAlign = "center"
  let msgTd = document.createElement("td")
  msgTd.innerHTML = "Message"          
  let theadTr = document.createElement("tr")
  theadTr.appendChild(timeTd)
  theadTr.appendChild(msgTd)
  thead.appendChild(theadTr)
  table.appendChild(thead)
  let tbody = document.createElement("tbody")
  table.appendChild(tbody)

  for(let item of this.items){
    tbody.appendChild(item.asTableRow())
  }

  return table
}

renderAsTable(){
  let le = document.getElementById(this.id)
  le.innerHTML = ""
  le.appendChild(this.asTable())
}
}
function Logger(props){return new Logger_(props)}

const logger = Logger()

function onLoad(){
	console.log("document loaded")

	Module.onRuntimeInitialized = function(){
		sendCommand = function (){
			let ce = document.getElementById("command")

			let command = ce.value

			logger.log(LogItem({msg: command, kind: "info", prefix: ">>"}))
		    logger.renderAsTable()

			execute_uci_command(command)

			ce.value = ""
		}
		
		document.getElementById("command").addEventListener("keyup", handleKeyUp)

		// define a new console
		let console=(function(oldCons){
		  return {
		      log: function(text){
		        logger.log(LogItem({msg: text, kind: "normal"}))
		        logger.renderAsTable()
		      },
		      info: function (text) {
		        logger.log(LogItem({msg: text, kind: "info"}))
		        logger.renderAsTable()
		      },
		      warn: function (text) {
		        logger.log(LogItem({msg: text, kind: "warn"}))
		        logger.renderAsTable()
		      },
		      error: function (text) {
		        logger.log(LogItem({msg: text, kind: "error"}))
		        logger.renderAsTable()
		      }
		  }
		}(window.console))

		// redefine the old console
		window.console = console

		console.log("engine up and running")		
	}
}
