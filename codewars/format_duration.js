


  Number.prototype.pad = function(n){
    var s = String(this);
    while(s.length < (n || 2)) { s = "0" + s; }
    return s;
  };



function formatDuration(seconds){
  if(seconds == 0) return "now";
  var sec =  seconds % 60;
  seconds = Math.floor(seconds / 60); 

  var min = seconds % 60;
  seconds = Math.floor(seconds / 60);
  var hr = seconds % 24;
  seconds = Math.floor(seconds / 24);
  var days = seconds % 365;
  seconds = Math.floor(seconds / 365);  
  var year = seconds;

  var s = "";

  if(year > 0) {
    s += `${year} ` + (year > 1 ? "years" : "year");
    var ch = 0;
    if(days > 0) ch++;
    if(hr > 0) ch++;
    if(min > 0) ch++;
    if(sec > 0) ch++;
    if(ch >= 2)
      s += ", ";
    else if (ch == 1)
      s += " and ";
  }
  if(days > 0) {
    s += `${days} ` + (days > 1 ? "days" : "day");
    var ch = 0;
    if(hr > 0) ch++;
    if(min > 0) ch++;
    if(sec > 0) ch++;
    if(ch >= 2)
      s += ", ";
    else if (ch == 1)
      s += " and ";
  }
  if(hr > 0){
    var ch = 0;
    s += `${hr} ` + (hr > 1 ? "hours" : "hour");
    if(min > 0) ch++;
    if(sec > 0) ch++;
    if(ch >= 2)
      s += ", ";
    else if (ch == 1)
      s += " and ";    
  }
  if(min > 0){
    var ch = 0;
    s += `${min} ` + (min > 1 ? "minutes" : "minute");
    if(sec > 0) ch++;
    if(ch >= 2)
      s += ", ";
    else if (ch == 1)
      s += " and ";        
  }
  if(sec > 0){
    s += `${sec} ` + (sec > 1 ? "seconds" : "second");
  }
  
  return s;
}


  function msToTime(ms){
    const toDay = 1000 * 60 * 60 * 24;
    const toHour = 1000 * 60 * 60;
    const toMinutes = 1000 * 60;
    const toSeconds = 1000;

    var day = Math.floor(ms/toDay);
    ms %= toDay;
    var hour = Math.floor(ms/toHour);
    ms %= toHour;
    var minutes = Math.floor(ms/toMinutes);
    ms %= toMinutes;
    var seconds = Math.floor(ms/toSeconds);
    ms %= toSeconds;
    
    return [day.pad() + " Day" , hour.pad() + " Hour" , minutes.pad() + " Min", seconds.pad() + " Sec"].join(" : ");
  }

console.log(formatDuration(120301));
console.log(msToTime(120301*1000));
