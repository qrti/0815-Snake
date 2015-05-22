// js/pebble-js-app.js 0815 snake V1.0 qrt 160714

var KEY_DISPDATE = "0815_KEY_DISPDATE";    // localStorage keys
var KEY_DIVIDE   = "0815_KEY_DIVIDE";
var KEY_INVERT   = "0815_KEY_INVERT";
var KEY_DATEFORM = "0815_KEY_DATEFORM";

function addKeyVal(key)
{
    return encodeURIComponent(key) + "=" + encodeURIComponent(localStorage.getItem(key));
}

Pebble.addEventListener("ready", 
    function(e){
        // console.log("PebbleKit JS ready!");
    }
);

Pebble.addEventListener("showConfiguration",
    function(e){
        var url = 'https://dl.dropboxusercontent.com/u/37673991/0815_snake_10.html';
        url += "?" + addKeyVal(KEY_DISPDATE) + "&";
        url += addKeyVal(KEY_DIVIDE) + "&";
        url += addKeyVal(KEY_INVERT) + "&";
        url += addKeyVal(KEY_DATEFORM);
        Pebble.openURL(url);
    }
);

Pebble.addEventListener("webviewclosed",
    function(e){
        var configuration = JSON.parse(decodeURIComponent(e.response));     
        // console.log("Configuration window returned: " + JSON.stringify(configuration));
        
        if(Object.keys(configuration).length > 0){      // cancel length=0, submit length>0
            localStorage.setItem(KEY_DISPDATE, configuration.dispDate);
            localStorage.setItem(KEY_DIVIDE, configuration.divide);
            localStorage.setItem(KEY_INVERT, configuration.invert);
            localStorage.setItem(KEY_DATEFORM, configuration.dateForm);
            
            Pebble.sendAppMessage(
                {"KEY_DISPDATE": configuration.dispDate,    // keys defined in project settings
                 "KEY_INVERT": configuration.invert,
                 "KEY_DIVIDE": configuration.divide,
                 "KEY_DATEFORM": configuration.dateForm},    
                
                function(e){
                    // console.log("Sending settings data ...");
                },
                
                function(e){
                    // console.log("Settings feedback failed!");
                }
            );
        }
    }
);













