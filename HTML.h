#pragma once


const char* Heat_front = "heatFront";
const char* Heat_back = "heatBack";
const char* Heat_left = "heatLeft";
const char* Heat_right = "heatRight";

const char* Cool_off = "coolOff";
const char* Cool_low = "coolLow";
const char* Cool_medium = "coolMedium";
const char* Cool_high = "coolHigh";


const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>My clothes</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; border-radius: 34px}
    .slider:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px; background-color: #fff; -webkit-transition: .4s; transition: .4s; border-radius: 68px}
    input:checked+.slider {background-color: #2196F3}
    input:checked+.slider:before {-webkit-transform: translateX(52px); -ms-transform: translateX(52px); transform: translateX(52px)}
  </style>
</head>


<body>
    <div style="background-image: linear-gradient(to left, #ff99cc, #99ffcc);">
          <h1  style="color: purple;">Manage your clothes right here!!!</h1>
          
                 <h2 style="color: red;">Power:%POWER%</h2>
                 
 
                    <h2 style="color: red;">Heat</h2>
         <h4>Heat front<input type="range" id="HeatFront" min="15" max="40" step="1" value="20"></h4>
         <p id="outputHeatFront">20</p>%FRONT%
         <h4>Heat back<input type="range" id="HeatBack" min="15" max="40" step="1" value="20"></h4>
         <p id="outputHeatBack">20</p>
         <h4>Heat left<input type="range" id="HeatLeft" min="15" max="40" step="1" value="20"></h4>
         <p id="outputHeatLeft">20</p>
         <h4>Heat right<input type="range" id="HeatRight" min="15" max="40" step="1" value="20"></h4>
         <p id="outputHeatRight">20</p>

                    <h2 style="color: green;">Backlight</h2>
         <p> 
          <input id="CoolingOff" type="radio" name="Cooling" checked/> <label for="CoolingOff">Off</label> 
          <input id="CoolingLow" type="radio" name="Cooling"/> <label for="CoolingLow">Blue</label>
          <input id="CoolingMedium" type="radio" name="Cooling"/> <label for="Medium">Green</label>
          <input id="CoolingHigh" type="radio" name="Cooling"/> <label for="CoolingHigh">Red</label>
        </p>
        
                    <h2 style="color: blue;">Cooling</h2>
                    %BUTTONPLACEHOLDER%
          
          <p><a href="https:/github.com/shlkarl/Smart-clothes"><strong><em><font size="5" >>>>The page of the project<<<</font></strong></a></p>
          /*  <h4> <strong>Contacts:</strong> </h4>
            <h5> Phone: +7 (999) 668-36-39 </h5>
            <h5>E-mail: <i>aitov.av@edu.spbstu.ru</i></h5>*/
      </div> 

                              <script>          
   
                                                    CoolingOff.addEventListener("change", function() {
                                                      CoolingOff.textContent = this.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?coolOff=" + this.value, true);
                                                      xhr.send();});
                                                    
                                                    CoolingLow.addEventListener("change", function() {
                                                      CoolingLow.textContent = this.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?coolLow=" + this.value, true);
                                                      xhr.send();});
                                                    
                                                    CoolingMedium.addEventListener("change", function() {
                                                      CoolingMedium.textContent = this.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?coolMedium=" + this.value, true);
                                                      xhr.send();});
                                                    
                                                    CoolingHigh.addEventListener("change", function() {
                                                      CoolingHigh.textContent = this.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?coolHigh=" + this.value, true);
                                                      xhr.send();});


                                                    HeatFront.addEventListener("input", function() {
                                                      outputHeatFront.textContent = HeatFront.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?heatFront=" + HeatFront.value, true); 
                                                      xhr.send();});
                                                      
                                                    HeatBack.addEventListener("input", function() {
                                                      outputHeatBack.textContent = HeatBack.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?heatBack=" + HeatBack.value, true); 
                                                      xhr.send(); });
                                                      
                                                    HeatLeft.addEventListener("input", function() {
                                                      outputHeatLeft.textContent = HeatLeft.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?heatLeft=" + HeatLeft.value, true); 
                                                      xhr.send();});
                                                      
                                                    HeatRight.addEventListener("input", function() {
                                                      outputHeatRight.textContent = HeatRight.value;
                                                      var xhr = new XMLHttpRequest();
                                                      xhr.open("GET", "/update?heatRight=" + HeatRight.value, true); 
                                                      xhr.send(); });

                                                    function toggleCheckbox(element) {
                                                      var xhr = new XMLHttpRequest();
                                                      if(element.checked){ xhr.open("GET", "/update?state=1", true); }
                                                      else { xhr.open("GET", "/update?state=0", true); }
                                                      xhr.send();}
                                                              
 setInterval(function ( ) {

var xhttp = new XMLHttpRequest();
xhttp.open("GET", "index.html", true);
xhttp.onreadystatechange = function() { 
            if (this.readyState == 4 && this.status == 200) {  
              document.querySelector("pow").innerHTML = xhttp.responseText;
              //document.querySelector("front").innerHTML = xhttp.responseText;
          }
};

xhttp.open("GET", "/state", true); 
xhttp.send();
}, 1000 ) ;






                           </script>
                                           
</body>
</html>
)rawliteral";
