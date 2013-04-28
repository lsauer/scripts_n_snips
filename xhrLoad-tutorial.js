/*
author: lo sauer - 2010, lsauer.com,
 XMLHttpRequest object :
	
	Allows to POST or GET data and processes it as DOM, thanks to its methods and attributes.
	 **Attributes:**
		readyState: code successively changes value from 0 to 4 that means for "ready".
		status:	200 is OK, 404 if the page is not found.
		responseText:	holds loaded data as a string of characters.
		responseXml:	holds an XML loaded file, DOM's method allows to extract data.
		onreadystatechange:	property that takes a function as value that is invoked when the readystatechange event is dispatched.
	
	 **Methods:**
		 open(method,url,async,uname,pswd)
			mode: type of request, GET or POST
			url: the location of the file, with a path.
			async: true (asynchronous) / false (synchronous).
			uname, a login and a...
			pswd: password may be added to arguments.
		send("string") 	null for a GET command.
	
	**Synchronous example:**
		
		var request = new XMLHttpRequest();
		request.open('GET', 'http://www.url.org/', false); 
		request.send(null);
		
		if (request.status == 200)
			console.log(request.responseText);
		//cecks the status code after the transaction is completed.  If the result is 200: HTTP is "OK"
		
*/
function xhrLoad(){
	var formInput = document.getElementById("loadurl");
	var xhr = new XMLHttpRequest();
	xhr.open("GET", formInput.value, true); //true...asynchronous mode, i.e. AJAX

	xhr.onreadystatechange = function() { // callback for the response handling
		if (xhr.readyState == 4) {
		   // Received, OK
			if(xhr.status == 200) {
				//console.log(xhr.responseText)
				//set text:
				document.getElementById("words").innerText = xhr.responseText;
			} else{
				console.log('Error', xhr.statusText);
			}
		} else {
		  // Error
		}
	};
	xhr.send(null); //send headers only, to actually initiate the request
}
//xhr.setRequestHeader('Access-Control-Allow-Origin', '*'); bypass XSS